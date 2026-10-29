## Problem Statement

**Rotate an image**

A black-and-white image is a matrix of pixels: `1` is black, `0` is white. Phones rotate photos this way. Write a program that reads an image, prints it, prints its **transpose**, and then rotates it 90° to the right.

Read `n` (rows) and `m` (columns), each in [1, NMAX] (`#define NMAX 20`), then the `n x m` pixels, row by row. Every pixel must be `0` or `1`.

```c
int read_matrix(int n, int m, int a[NMAX][NMAX]);                    // returns 1 if all values were read, otherwise 0
void print_image(int n, int m, int a[NMAX][NMAX]);                   // '#' for 1, '.' for 0, one row per line
void transpose(int n, int m, int a[NMAX][NMAX], int t[NMAX][NMAX]);  // t (m x n) = a transposed
void reverse_rows(int n, int m, int a[NMAX][NMAX]);                  // reverses each row of a, in place
```

Rotating right = transpose, then reverse each row.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input (a size outside [1, NMAX], or a value that can not be read) |
| 1 | a pixel is not `0` or `1` |

**Examples**

```
$ ./main
5 4
1 1 1 1
1 0 0 0
1 1 1 0
1 0 0 0
1 0 0 0
Original:
####
#...
###.
#...
#...
Transposed:
#####
#.#..
#.#..
#....
Rotated right:
#####
..#.#
..#.#
....#

$ ./main
2 2
1 2
0 1
Error: pixels must be 0 or 1
(exit code 1)
```

**Hints**
- The transpose of a `5 x 4` image is `4 x 5`. Print it with `print_image(m, n, t)`, not `(n, m, t)`.
- `transpose` is one line inside two loops: `t[j][i] = a[i][j]`.
- `reverse_rows`: in each row, swap `a[i][j]` with `a[i][m - 1 - j]`, for `j` in the **first half** only (`j < m / 2`).
- After the transpose, the matrix to reverse is `m x n`: call `reverse_rows(m, n, t)`.

## Questions to verify knowledge
- Why does `reverse_rows` stop at `m / 2`? What happens if it goes to `m`?
- How would you rotate 90° to the **left**? And 180°?
- Is the transpose of the transpose the original image?
- Why must the second dimension (`NMAX`) be written in the parameter `int a[NMAX][NMAX]`?
- A real photo has 4000 x 3000 pixels and 3 colors. Would it fit in a local array?
