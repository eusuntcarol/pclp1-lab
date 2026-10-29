## Problem Statement

**[BONUS] k-hop routes**

Exercise 03 counted routes of 2 hops with `a x a`. The same idea goes further: in `a^k` (the matrix multiplied by itself `k` times), element `[i][j]` is the number of routes from `i` to `j` with **exactly `k` hops**.

Read `n` (in [1, NMAX], `#define NMAX 20`), the `n x n` matrix and `k`. Compute `a^k` with `power_matrix` and print it.

```c
void identity_matrix(int n, int a[NMAX][NMAX]);                              // 1 on the diagonal, 0 elsewhere
void power_matrix(int n, int a[NMAX][NMAX], int k, int b[NMAX][NMAX]);      // b = a^k
```

Reuse `copy_matrix`, `multiply_matrix` and `read_matrix` from the previous exercises. `print_matrix` uses `"%10d"` here, because the values grow fast.

`a^0` is the identity matrix (0 hops: each router reaches only itself).

**Important:** `a` and `b` can be the same matrix. The program calls:

```c
power_matrix(n, a, k, a);   // a = a^k
```

Print `Routes of exactly <k> hops:` and the matrix.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input, or `k < 0` |

**Constraint:** `power_matrix` must use `multiply_matrix`. No multiplication loop of its own.

**Examples**

The network from exercise 03:

```
$ ./main
4
0 1 1 0
0 0 1 1
0 0 0 1
1 0 0 0
3
Routes of exactly 3 hops:
         2         0         0         1
         1         1         1         0
         0         1         1         0
         0         0         1         2
```

A matrix that is not 0/1, to test the arithmetic:

```
$ ./main
4
0 1 1 1
1 1 1 1
0 10 0 0
0 10 0 0
2
Routes of exactly 2 hops:
         1        21         1         1
         1        22         2         2
        10        10        10        10
        10        10        10        10

$ ./main
4
0 1 1 1
1 1 1 1
0 10 0 0
0 10 0 0
10
Routes of exactly 10 hops:
   1923434  11014355   2298075   2298075
   2298075  12937789   2733889   2733889
   4358140  22980750   5101950   5101950
   4358140  22980750   5101950   5101950

$ ./main
2
1 1
1 0
0
Routes of exactly 0 hops:
         1         0
         0         1
```

**Hints**
- Start from the identity matrix (like starting a product from `1`) and multiply by `a`, `k` times.
- Keep a copy of `a` before the loop. If `b` is the same matrix as `a`, the first result overwrites `a`.
- Because `multiply_matrix` already handles aliasing, `multiply_matrix(n, n, n, result, base, result)` is safe.

## Questions to verify knowledge
- Why is `a^0` the identity matrix? What is the "1" of matrix multiplication?
- Why must `power_matrix` copy `a` before the loop?
- How many multiplications does `power_matrix` do for `k = 1000`?
- Faster: `a^k = (a^(k/2))^2` when `k` is even, and `a x a^(k-1)` when it is odd. How many multiplications does that need for `k = 1000`? Can you write it recursively (lab 3)?
- `int` holds values up to about 2 billion. What happens to the values of `a^20` in the second example?
