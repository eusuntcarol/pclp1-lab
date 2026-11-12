# 3 — Dynamic matrices

Theory: section 3 of `../README.md`. Demo: `../demos/4-matrix.c`.

## 1. Write and observe — Easy

Write a program that does the following, step by step.

1. Declare `int s[3][4];` and print `&s[0][0]`, `&s[0][3]`, `&s[1][0]`, `&s[2][0]`.
2. Allocate `a` with 3 rows and 4 columns: first the array of row pointers, then each row. Check every allocation.
3. Print `a`, `a[0]`, `a[1]`, `a[2]` and `&a[0][3]`.
4. Free: first the rows, then `a`.

Answer:
- In `s`, how many bytes are between `&s[0][3]` and `&s[1][0]`?
- In `a`, does `a[1]` start right after the end of row 0?
- What is the difference between `a` and `a[0]`?
- What goes wrong if you `free(a)` before the rows?

## 2. Transpose — Medium

Write:

- `int **alloc_matrix(int n, int m)`: allocates `n` rows of `m` ints. If any allocation fails, frees everything allocated so far and returns `NULL`.
- `void free_matrix(int **a, int n)`

Read an `n x m` matrix, build its transpose (`m x n`) as a new matrix, print it, free both.

```
rows cols: 2 3
1 2 3
4 5 6
transpose:
1 4
2 5
3 6
```

## 3. Pascal's triangle — Medium

`int **pascal(int n)`

Builds the first `n` rows of Pascal's triangle. Row `i` has exactly `i + 1` elements: the first and the last are 1, every other one is the sum of the two above it (`t[i][j] = t[i-1][j-1] + t[i-1][j]`).

Allocate each row with exactly the size it needs.

```
n: 5
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
```

Answer:
- How many ints does your triangle use for `n = 100`? How many would a `100 x 100` matrix use?
