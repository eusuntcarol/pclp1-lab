# 1 — malloc, calloc, free

Theory: sections 0 and 1 of `../README.md`. Demos: `../demos/1-malloc-free.c`, `../demos/2-memory-bugs.c`.

## 1. Write and observe — Easy

Write a program that does the following, step by step.

1. Allocate one `int` with `malloc`, check for `NULL`, store `7` in it. Print `&x` (a local variable), `&p` and `p`.
2. Read `n`. Allocate `n` ints with `malloc` into `v`. Print `sizeof(v)` and `n * sizeof(*v)`.
3. Print `v[0]` ... `v[n-1]` without writing to them first.
4. Allocate `n` ints with `calloc` into `z` and print them.
5. Free everything. After `free(p)`, print `p` again.

```
n: 5
```

Answer:
- Which two of `&x`, `&p`, `p` are close to each other? Why?
- Why is `sizeof(v)` 8, whatever `n` is?
- Which one guarantees zeros, `malloc` or `calloc`? If `malloc` also showed zeros, does that mean it always will?
- After `free(p)`, `p` still holds the same address. May you still use `*p`?

## 2. Dynamic array — Easy

Read `n`, allocate exactly `n` ints, read them, print the average and the elements above the average. Free the array.

No `NMAX` here: the size comes from the input.

```
n: 5
4 8 1 9 3
average: 5.00
above: 8 9
```

## 3. Prefix sums — Easy

`int *prefix_sums(const int *v, int n)`

Returns a **new** array `s` with `s[i] = v[0] + v[1] + ... + v[i]`, or `NULL` if allocation fails. `v` is not modified.

```
n: 5
3 1 4 1 5
prefix: 3 4 8 9 14
```

Answer:
- In lab5, a function returning the address of a local variable was a bug. Why is `prefix_sums` correct?
- Who calls `free` on `s`?

## 4. Bug hunt — Easy

`4-bug-hunt/main.c` compiles and may even print the right result, but it has **at least 4 memory bugs**.

1. Run it normally with `n: 3` and `1 2 3`.
2. Compile with `-g -fsanitize=address` and run again. Read the report: what kind of error, on which line?
3. Fix that bug, recompile, repeat until the sanitizer is silent.
4. Compile without `-fsanitize`, run with `valgrind --leak-check=full ./main` and check that all heap blocks were freed.

Write each bug and its fix as a comment at the end of the file.
