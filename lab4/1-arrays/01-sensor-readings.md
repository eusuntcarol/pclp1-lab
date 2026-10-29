## Problem Statement

**Sensor readings**

A temperature sensor sends a batch of readings (in °C). Write a program that reads the batch into an array and prints it back on one line, to confirm what was received.

Read `n`, the number of readings, then the `n` readings. `n` must be between `1` and `NMAX` (`#define NMAX 100`).

```c
int read_array(int v[]);           // reads n, then n values into v; returns n, or -1 on invalid input
void print_array(int n, int v[]);  // prints the n values on one line, separated by one space, then '\n'
```

`main` prints `<n> readings` and then calls `print_array`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | `n` or one of the values is not a number, or `n` is outside [1, NMAX] |

**Examples**

Lines typed by you are shown right after `$ ./main`, the program output follows:

```
$ ./main
5
10 30 -1 4 5
5 readings
10 30 -1 4 5

$ ./main
3 21 22 23
3 readings
21 22 23

$ ./main
0
Error: invalid input
(exit code 1)

$ ./main
3
21 x 23
Error: invalid input
(exit code 1)
```

The values can be typed on one line or on several, `scanf("%d")` skips spaces and newlines.

**Hints**
- Inside `read_array`, `scanf` needs the address of one element: `&v[i]`.
- Check `n` **before** the reading loop. With `n = 500` the loop would write past the end of the array.
- No space after the last value: print the space **before** every value except the first one.
- `read_array` fills the caller's array, because arrays are not copied when passed to a function.

## Questions to verify knowledge
- Why does `read_array` return `n` instead of storing it in the array?
- What would happen if `n` were not checked and the user typed `1000`?
- Why can `read_array` change `v` from `main`, while `swap(int a, int b)` from lab 3 could not change `x` and `y`?
- What values does `v` hold before `read_array` runs?
- Where is `NMAX` used? What changes if you set it to `10`?
