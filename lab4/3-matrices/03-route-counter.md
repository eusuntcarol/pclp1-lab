## Problem Statement

**Route counter**

A network of routers can be stored as an **adjacency matrix**: `a[i][j] = 1` if router `i` has a direct link to router `j`, otherwise `0`. Links have a direction (`i -> j` does not mean `j -> i`).

Multiplying the matrix by itself counts routes: in `a x a`, the element `[i][j]` is the number of different routes from `i` to `j` that use **exactly 2 links** (2 hops). Each route goes `i -> r -> j` through some router `r`, and `a[i][r] * a[r][j]` is `1` exactly when both links exist.

Read `n` (in [1, NMAX], `#define NMAX 20`) and the `n x n` matrix. Compute `a x a` and store it **in `a` itself**. Print it, then answer queries until the input ends: each query is two routers `from to`.

```c
void copy_matrix(int n, int m, int src[NMAX][NMAX], int dst[NMAX][NMAX]);
void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]);  // c (n x p) = a (n x m) x b (m x p)
void print_matrix(int n, int m, int a[NMAX][NMAX]);   // each value with "%6d", one row per line
```

**Important:** `a`, `b` and `c` can be the **same** matrix in memory. The program calls:

```c
multiply_matrix(n, n, n, a, a, a);   // a = a x a
```

and it must still be correct (see "Aliasing" in the cheatsheet).

For each query print `Routes from <from> to <to>: <count>`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or a router in a query is outside [0, n - 1] |

**Examples**

```
$ ./main
4
0 1 1 0
0 0 1 1
0 0 0 1
1 0 0 0
0 3
0 2
3 1
2 9
2-hop routes:
     0     0     1     2
     1     0     0     1
     1     0     0     0
     0     1     1     0
Routes from 0 to 3: 2
Routes from 0 to 2: 1
Routes from 3 to 1: 1
Error: router must be between 0 and 3
(exit code 1)
```

(From `0` to `3` in 2 hops: `0 -> 1 -> 3` and `0 -> 2 -> 3`.)

**Before you start:** test `multiply_matrix` with matrices that are not square and not 0/1. With

```c
int a[NMAX][NMAX] = {
    { 0,  1,  1,  1},
    { 1,  1,  1,  1},
    { 0, 10,  0,  0},
    { 0, 10,  0,  0}
};
int b[NMAX][NMAX] = {
    { -1, 10,  1},
    { -2, 20,  2},
    { -3, 30,  3},
    { -4, 40,  4}
};
multiply_matrix(4, 4, 3, a, b, c);
```

`c` (4 x 3) must be (printed with `print_matrix(4, 3, c)`):

```
    -9    90     9
   -10   100    10
   -20   200    20
   -20   200    20
```

**Hints**
- Three loops: `i` over the rows of the result, `j` over its columns, `r` over the shared size `m`.
- First write the version that stores directly into `c[i][j]`. Run it with `multiply_matrix(n, n, n, a, a, a)` and see the wrong result. Then fix it with a local `int tmp[NMAX][NMAX]` and `copy_matrix`.
- The result is `n x p`: copy `n` rows and `p` columns.

## Questions to verify knowledge
- Why does writing directly into `c` break when `c` and `a` are the same matrix? Which values get overwritten too early?
- Why does addition (exercise 02) not have this problem?
- What does `[i][i]` mean in `a x a`? (A route that comes back to where it started.)
- Which sizes must match to multiply `a` (n x m) by `b`? What is the size of the result?
- In the example, why is `a x a` different from what you get by just squaring each element?
