# Lab 6 — Dynamic memory allocation

Compile (all exercises and demos):

```
gcc -Wall -Wextra main.c -o main
./main
```

While testing, also compile with the address sanitizer. It stops the program at the first memory error and shows the line:

```
gcc -Wall -Wextra -g -fsanitize=address main.c -o main
./main
```

## Structure

| Section | Exercises |
|---|---|
| `1-basics` | 1 write and observe, 2 dynamic array, 3 prefix sums, 4 bug hunt |
| `2-realloc` | 1 write and observe, 2 read until 0, 3 filter (with a function pointer) |
| `3-matrices` | 1 write and observe, 2 transpose, 3 Pascal's triangle |

There is no starting code, except for the bug hunt. For each exercise, create a directory named after it, with a `main.c` inside (e.g. `1-basics/2-dynamic-array/main.c`). Write the answers to the questions as comments at the end of the file.

The programs in `demos/` are complete: compile them, run them and compare with the explanations below.

---

## 0. Recap: the lab5 mistakes that matter here

Everything in this lab goes through pointers, so these come back:

| Wrong | Right | Why |
|---|---|---|
| `swap(a, b)` | `swap(&a, &b)` | the function needs the addresses |
| `if (a > b)` with `int *a, *b` | `if (*a > *b)` | compare the values, not the addresses |
| `sizeof(v) / sizeof(int)` with `int *v` | keep `n` in a variable | `sizeof(v)` is the size of the pointer |
| `printf("%p", p)` | `printf("%p", (void *)p)` | `%p` expects a `void *` |

Function pointers come back in `2-realloc/3-filter`:

```c
int is_even(int x) { return x % 2 == 0; }

int (*keep)(int) = is_even;   // keep: pointer to a function int -> int
keep(4);                      // calls is_even(4)
```

`sizeof` gives a value of type `size_t` (an unsigned integer). Its `printf` format is `%zu`. `%ld` happens to work on 64-bit Linux because `size_t` and `long` have the same size there, but it is not portable.

---

## 1. malloc, calloc, free

### Why

Until now every array had a size fixed at compile time (`#define NMAX 100`), and every local variable disappeared when its function returned. Dynamic memory solves both:

- the size is decided **while the program runs** (for example, read from the keyboard);
- the memory stays valid **until you free it**, even after the function that allocated it returns.

| Where | What lives there | Freed when |
|---|---|---|
| stack | local variables, parameters | the function returns |
| heap | blocks from `malloc` / `calloc` / `realloc` | you call `free` |

### The functions (`stdlib.h`)

```c
void *malloc(size_t size);               // size bytes, NOT initialized
void *calloc(size_t n, size_t size);     // n elements of size bytes, all 0
void free(void *p);                      // gives the block back
```

- Both return the address of the block, or `NULL` if there is no memory.
- `malloc` takes **bytes**: for `n` ints, ask for `n * sizeof(int)`.
- The returned `void *` converts to any pointer type, no cast needed.

```c
int *v = malloc(n * sizeof(*v));  // sizeof(*v) = sizeof(int), stays correct if the type changes
if (v == NULL) {
    printf("not enough memory\n");
    return 1;
}

v[0] = 5;          // used exactly like an array
...
free(v);
v = NULL;          // optional, but a NULL pointer is easy to check
```

- `sizeof(v)` is the size of the pointer (8), not of the block. Keep `n` in a variable.
- `free` does not need the size: the allocator remembers it.
- `free(NULL)` does nothing, so it is always safe.

Demo: `demos/1-malloc-free.c`

### Returning memory from a function

In lab5, returning the address of a local variable was a bug. A block from `malloc` is not local, so this is correct:

```c
int *make_array(int n)
{
    int *v = malloc(n * sizeof(*v));
    return v;     // the caller checks for NULL and calls free
}
```

Whoever receives the pointer is responsible for calling `free`.

### Common mistakes

| Mistake | Example | Effect |
|---|---|---|
| no `NULL` check | `int *v = malloc(...); v[0] = 1;` | crash when memory runs out |
| out of bounds | `malloc(4 * sizeof(int))` then `v[4] = 1` | overwrites someone else's memory |
| use after free | `free(v); printf("%d", v[0]);` | reads memory that is no longer yours |
| double free | `free(v); free(v);` | crash or corrupted heap |
| memory leak | `v = NULL;` before `free(v)` | the block is lost until the program ends |
| free of a non-heap address | `int x; free(&x);` | crash |

Many of these run "fine" on your machine and fail elsewhere. Do not trust a run that looks correct: check with tools.

### Finding them

- `-fsanitize=address`: stops at the first out-of-bounds access, use after free or double free, and reports leaks at exit.
- `valgrind` on a normal build (without `-fsanitize`):
  ```
  gcc -Wall -Wextra -g main.c -o main
  valgrind --leak-check=full ./main
  ```
  At the end, `All heap blocks were freed` means there is no leak.

`-g` makes both tools show file and line numbers.

Demo: `demos/2-memory-bugs.c`

---

## 2. realloc

```c
void *realloc(void *p, size_t size);
```

Changes the size of the block at `p` to `size` bytes and returns its address:

- the old contents are kept (up to the smaller of the two sizes);
- the block may **move**: the returned address can differ from `p`, and then the old address is no longer valid;
- on failure it returns `NULL` and the old block stays untouched;
- `realloc(NULL, size)` works like `malloc(size)`.

Always go through a temporary pointer:

```c
int *tmp = realloc(v, new_cap * sizeof(*v));
if (tmp == NULL) {
    free(v);       // v is still valid, so it can still be freed
    return 1;
}
v = tmp;
```

`v = realloc(v, ...)` is wrong: on failure `v` becomes `NULL` and the old block is leaked.

### Unknown number of elements

Keep two counters: `n` (how many elements are used) and `cap` (how many fit). When `n == cap`, grow the block:

- by a fixed amount (`cap + INCR`): simple, but many `realloc` calls for large inputs;
- by doubling (`cap * 2`): few `realloc` calls, some unused space.

Demo: `demos/3-realloc.c`

---

## 3. Dynamic matrices

A dynamic matrix is an array of row pointers, each pointing to its own row:

```
a ──► [ a[0] ]──► [ 1  2  3  4 ]
      [ a[1] ]──► [ 5  6  7  8 ]
      [ a[2] ]──► [ 9 10 11 12 ]
```

```c
int **a = malloc(n * sizeof(*a));        // n pointers to int
for (i = 0; i < n; i++)
    a[i] = malloc(m * sizeof(**a));      // each row: m ints

a[i][j] = 7;                              // same syntax as a static matrix
```

- Check every allocation. If row `i` fails, free rows `0..i-1` and `a`, then report the error.
- Free in reverse order: first every row, then `a`. Freeing `a` first loses the row addresses.
- Rows are separate blocks, so they can have **different lengths** (a "ragged" matrix):
  ```c
  for (i = 0; i < n; i++)
      a[i] = malloc((i + 1) * sizeof(**a));   // row i has i + 1 elements
  ```

### int ** is not int [][]

A static matrix `int s[3][4]` is one contiguous block of 12 ints, with no row pointers. A function that takes `int **` cannot receive `s`, not even with a cast: it would read the ints as if they were addresses.

Demo: `demos/4-matrix.c`

---

## Lab rules

- Check the result of every `malloc`, `calloc` and `realloc`.
- Every allocated block is freed exactly once.
- `realloc` always goes through a temporary pointer.
- A size read from input means `malloc`, never `int v[n]`. Static arrays still use `#define NMAX`.
- Compile with `-Wall -Wextra`, and test with `-fsanitize=address` or `valgrind`.
