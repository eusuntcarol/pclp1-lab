# Lab 5 — Pointers

Compile (all exercises and demos):

```
gcc -Wall -Wextra main.c -o main
./main
```

`-Wall -Wextra` matters in this lab: many pointer mistakes compile fine but produce warnings. Read them.

## Structure

| Section | Exercises |
|---|---|
| `1-basics` | 1 write and observe, 2 moving pointer, 3 swap |
| `2-out-params` | 1 divide, 2 min_max, 3 bug: address of a local variable |
| `3-arrays` | 1 write and observe, 2 sum without `[]`, 3 reverse, 4 find |
| `4-function-pointers` | 1 write and observe, 2 calculator, 3 sort with comparator, 4 qsort |

The programs in `demos/` are complete: compile them, run them and compare with the explanations below.

---

## 1. What a pointer is

Every variable lives somewhere in memory, at an **address**. A pointer is a variable that stores such an address.

```c
int x = 5;
int *p = &x;   // p stores the address of x
```

| Expression | Meaning |
|---|---|
| `x` | the value of x (5) |
| `&x` | the address of x |
| `p` | what p stores, i.e. the address of x |
| `*p` | the value at the address in p, i.e. x |
| `&p` | the address of p (p lives in memory too) |

- `&` = "address of", works on any variable.
- `*` = "what is at the address", works on a pointer.
- `*p = 10;` writes into `x`. `p` and `x` are two names for the same memory.

Print addresses with `%p` and a cast to `void *`:

```c
printf("%p\n", (void *)&x);
```

Demo: `demos/1-address.c`

### NULL and uninitialized pointers

```c
int *p;        // holds some random value
*p = 1;        // WRONG: writes to an unknown address → crash or worse

int *q = NULL; // "points nowhere", can be checked
if (q != NULL)
    *q = 1;
```

Rule: initialize a pointer when you declare it, with a valid address or with `NULL`.

### Declarations

The `*` belongs to the name, not to the type:

```c
int *a, *b;  // two pointers
int *c, d;   // c is a pointer, d is an int
```

### Size

`sizeof(int *)`, `sizeof(double *)`, `sizeof(char *)` are all equal (8 bytes on 64-bit), whatever type they point to. A pointer only stores an address.

---

## 2. Pointers as parameters

C passes parameters **by value**: the function gets a copy.

```c
void inc_val(int n) { n++; }      // changes only the copy
void inc_ptr(int *n) { (*n)++; }  // changes the original variable

int x = 5;
inc_val(x);   // x stays 5
inc_ptr(&x);  // x becomes 6
```

Mind the parentheses: `*n++` moves the pointer, `(*n)++` increments the value.

Demo: `demos/2-out-param.c`

### Several results from one function

`return` gives back a single value. For more, the function receives addresses and writes to them:

```c
void min_max(int *v, int n, int *min, int *max);

int mn, mx;
min_max(v, n, &mn, &mx);
```

A common pattern: `return` says whether the operation succeeded, and the results come back through pointers.

### Never return the address of a local variable

```c
int *wrong(void)
{
    int x = 42;
    return &x;  // x is gone once the function returns
}
```

Local (non-global, non-static) variables only exist while the function runs. GCC warns: `function returns address of local variable`. The recommended fix: the caller declares the variable or array and passes its address.

---

## 3. Pointers and arrays

An array's name is the address of its first element:

| Indexing | Pointers |
|---|---|
| `v[0]` | `*v` |
| `v[k]` | `*(v + k)` |
| `&v[k]` | `v + k` |

### Pointer arithmetic

`p + 1` does not add 1 byte, it adds `sizeof(*p)` bytes: it moves to the next element.

```c
int v[NMAX];
int *p = v;   // p points to v[0]
p++;          // p points to v[1]; the address grew by sizeof(int)
```

- `p - v` = how many elements lie between p and the start of the array, i.e. the index.
- Two pointers into the same array can be compared: `while (p < v + n)`.
- `v + n` is the address just past the last element: you may compute it and compare with it, but never dereference it.

Demo: `demos/3-arithmetic.c`

### Array vs. pointer

```c
int v[NMAX], *p;
p = v;  // OK
p++;    // OK
v = p;  // ERROR: an array name cannot be changed
```

### An array passed to a function becomes a pointer

```c
void f(int v[]);   // same as
void f(int *v);
```

In `main`, `sizeof(v)` is the size of the whole array. Inside the function, `sizeof(v)` is the size of a pointer. The function cannot know how many elements the array has, which is why `n` is always passed separately.

Demo: `demos/4-array-param.c`

---

## 4. Function pointers

A function has an address too: the one the program jumps to when you call it. The function's name, without `()`, is that address.

```c
int add(int a, int b) { return a + b; }

int (*op)(int, int) = add;  // op: pointer to a function (int, int) -> int
op(2, 3);                   // calls add
```

The parentheses in the declaration are required:

```c
int (*op)(int, int);  // pointer to a function
int *op(int, int);    // function returning int *
```

Demo: `demos/5-function-pointer.c`

### What they are for

1. **Function tables**, instead of `switch`:
   ```c
   int (*ops[])(int, int) = {add, sub};
   ops[opt](a, b);
   ```
2. **Generic functions**: a function receives "what to do" as a parameter. Example: a sorting algorithm that receives the comparator.

### Classic mistake

```c
if (f)    // the address of f: always true, f is NOT called
if (f())  // a call
```

### qsort

`stdlib.h` already has a generic sort:

```c
void qsort(void *base, size_t n, size_t size,
           int (*cmp)(const void *, const void *));
```

- `void *` = "address of something of unknown type". `qsort` does not know the element type, so it also receives `size`.
- A `void *` cannot be dereferenced directly: convert it to the real type first.
- The comparator returns `< 0` if the first goes before, `0` if they are equal, `> 0` if it goes after.

```c
int cmp(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

qsort(v, n, sizeof(v[0]), cmp);
```

---

## Lab rules

- Arrays have a constant size: `#define NMAX 100`, never `int v[n]`.
- Initialize pointers when you declare them (valid address or `NULL`).
- Compile with `-Wall -Wextra` and do not ignore warnings.
