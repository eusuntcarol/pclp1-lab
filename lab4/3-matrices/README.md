# Matrices cheatsheet

A **matrix** is a two-dimensional array: rows and columns. `a[i][j]` is the element on row `i`, column `j`, both counted from `0`.

```c
#define NMAX 20

int a[NMAX][NMAX];                  // up to 20 x 20, uses only n x m of it
int b[2][3] = {
    {1, 2, 3},                      // row 0
    {4, 5, 6}                       // row 1
};                                  // b[1][2] = 6
```

## Reading and printing

Two nested loops: the outer one over rows, the inner one over columns.

```c
for (int i = 0; i < n; i++) {           // row
    for (int j = 0; j < m; j++) {       // column
        scanf("%d", &a[i][j]);
    }
}

for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        printf("%4d", a[i][j]);         // fixed width keeps the columns aligned
    }
    printf("\n");                       // end of row
}
```

## Matrices and functions

The **second** dimension must be written in the parameter, so the compiler knows how long a row is. Like vectors, matrices are not copied: the function works on the caller's matrix.

```c
void print_matrix(int n, int m, int a[NMAX][NMAX]);   // OK
void print_matrix(int n, int m, int a[][NMAX]);       // also OK
void print_matrix(int n, int m, int a[][]);           // error
```

## How a matrix sits in memory

Row after row, in one continuous block (**row-major** order). `a[i][j]` is at position `i * NMAX + j` from the start:

```
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

memory:  | 1 | 2 | 3 | 4 | 5 | 6 |
           row 0       row 1
```

## Operations

**Transpose:** rows become columns. An `n x m` matrix becomes `m x n`.

```
transpose(a, n, m) -> t:            // t is m x n
    for i = 0 .. n-1:
        for j = 0 .. m-1:
            t[j][i] = a[i][j]
```

```
1 2 3        1 4
4 5 6   ->   2 5
             3 6
```

**Addition and subtraction:** element by element. Both matrices must have the same size.

```
c[i][j] = a[i][j] + b[i][j]         // or -
```

**Multiplication:** `a` is `n x m`, `b` is `m x p`, the result is `n x p`. The inner sizes must be equal (`m`). Element `c[i][j]` = row `i` of `a` times column `j` of `b`, element by element, added up.

```
multiply(a, b, n, m, p) -> c:
    for i = 0 .. n-1:
        for j = 0 .. p-1:
            sum = 0
            for r = 0 .. m-1:
                sum += a[i][r] * b[r][j]
            c[i][j] = sum
```

```
| 1 2 |   | 5 6 |   | 1*5 + 2*7   1*6 + 2*8 |   | 19 22 |
| 3 4 | x | 7 8 | = | 3*5 + 4*7   3*6 + 4*8 | = | 43 50 |
```

**Power:** `a^k = a x a x ... x a` (k times). Only for square matrices. `a^0` is the **identity** matrix (1 on the diagonal, 0 elsewhere).

```
power(a, n, k) -> b:
    result = identity(n)
    repeat k times:
        result = multiply(result, a)
    b = result
```

## Aliasing: when input and output are the same matrix

A call like `multiply_matrix(n, n, n, a, a, a)` asks for `a = a x a`. If the function writes `c[i][j]` directly, it overwrites values of `a` that it still needs for the next elements. The result is wrong, with no error message.

Fix: compute into a local temporary matrix, then copy it into `c` at the end.

```
multiply_matrix(n, m, p, a, b, c):
    tmp = the product, computed as above
    copy tmp into c                 // a and b are no longer needed now
```

## Common mistakes

| Mistake | Fix |
|---|---|
| `a[j][i]` instead of `a[i][j]` | name the indexes `row` / `col` if it helps |
| wrong size in a loop (`j < n` instead of `j < m`) | write which size each loop walks |
| multiplying with mismatched sizes | check: columns of `a` = rows of `b` |
| writing the result into an input | use a temporary matrix |
| missing `\n` after each row | print it after the inner loop |
