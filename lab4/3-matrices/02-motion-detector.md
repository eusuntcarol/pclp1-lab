## Problem Statement

**Motion detector**

A security camera detects motion by comparing two frames taken a moment apart. Each frame is a grayscale image: a matrix of brightness values. Where nothing moved, the two frames are almost equal. Where something moved, the difference is large.

Read `n` and `m` (each in [1, NMAX], `#define NMAX 20`), then frame 1 (`n x m`), then frame 2 (`n x m`), then a threshold `t`.

```c
int read_matrix(int n, int m, int a[NMAX][NMAX]);                                         // exercise 01
void print_matrix(int n, int m, int a[NMAX][NMAX]);                                       // each value with "%4d", one row per line
void add_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]);       // c = a + b
void subtract_matrix(int n, int m, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]);  // c = a - b
```

Print:
1. `Difference:` and the matrix `frame2 - frame1`.
2. `Overlay:` and the matrix `frame1 + frame2` (both frames on top of each other, the "ghost" image of a moving object).
3. `Motion mask:` and one line per row: `#` where the absolute difference is **greater than** `t`, `.` elsewhere.
4. `Changed pixels: <count>`, and `Motion detected` if the count is not `0`.

`main` returns `0` if nothing changed and `2` if motion was detected.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | invalid input |
| 2 | motion detected (not an error, an alarm) |

**Examples**

```
$ ./main
3 4
10 10 10 10
10 50 10 10
10 10 10 10
10 10 10 10
10 12 10 90
10 10 80 10
5
Difference:
   0   0   0   0
   0 -38   0  80
   0   0  70   0
Overlay:
  20  20  20  20
  20  62  20 100
  20  20  90  20
Motion mask:
....
.#.#
..#.
Changed pixels: 3
Motion detected
(exit code 2)
```

(Pixel `[1][1]`: something bright left, `-38`. Pixels `[1][3]` and `[2][2]`: something bright arrived. Small changes, like noise, stay under the threshold.)

**Hints**
- `add_matrix` and `subtract_matrix` are the same two loops, with `+` or `-`.
- The order matters for subtraction: `subtract_matrix(n, m, f2, f1, d)` computes `f2 - f1`.
- Absolute value without `math.h`: `x < 0 ? -x : x`.
- Count and print the mask in the same two loops.

## Questions to verify knowledge
- Why is the absolute value needed? What does a negative difference mean in the image?
- What happens with `t = 0` and a real camera, where every pixel changes a little?
- Why must both frames have the same size for addition and subtraction?
- Can `add_matrix(n, m, a, b, a)` (result stored in `a`) give a wrong result? Why not, unlike multiplication in exercise 03?
- Why is returning `2` useful for the program that turns on the alarm?
