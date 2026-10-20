# Recursion cheatsheet

A function is **recursive** if it calls itself. Every recursive function needs:
- a **base case**: an input for which the answer is given directly, without another call;
- a **recursive case**: a call on a *smaller* problem, getting closer to the base case.

```c
void countdown(int n) {
    if (n == 0) {                 // base case
        printf("liftoff\n");
        return;
    }
    printf("%d\n", n);
    countdown(n - 1);             // recursive case, n gets smaller
}
// countdown(3) displays: 3, 2, 1, liftoff (one per line)
```

## Work before or after the call

The position of the work around the recursive call changes the order of the output:

```c
void down(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);             // work BEFORE the call
    down(n - 1);
}

void up(int n) {
    if (n == 0) {
        return;
    }
    up(n - 1);
    printf("%d ", n);             // work AFTER the call
}

// down(3) displays: 3 2 1
// up(3) displays: 1 2 3
```

## Call stack

Every call gets its own **frame** on the stack with its parameters, local variables and the return address. The frames are removed in reverse order when the calls return.

```
up(3)               // frame 1, waits for up(2)
  up(2)             // frame 2, waits for up(1)
    up(1)           // frame 3, waits for up(0)
      up(0)         // frame 4, base case, returns
    prints 1
  prints 2
prints 3
```

## Returning values and accumulators

A recursive function can return a value computed from the result of the smaller call. Or it can carry the state it has built so far in an extra **accumulator** parameter (no globals needed):

```c
int count_digits(int n) {
    if (n < 10) {
        return 1;
    }
    return 1 + count_digits(n / 10);
}
// count_digits(4096) returns 4

int sum_to(int n, int sum_so_far) {
    if (n == 0) {
        return sum_so_far;
    }
    return sum_to(n - 1, sum_so_far + n);
}
// sum_to(4, 0) returns 10
```

## Stack overflow

The stack is small (typically 8 MB on Linux). A recursion without a reachable base case, or one that is too deep, fills it and the program is killed (`Segmentation fault`).

```sh
ulimit -s              # stack size limit in KB (often 8192)
(ulimit -s 1024; ./main)    # run once with a 1 MB stack, in a subshell
```

When input controls how deep the recursion goes, bound the depth, otherwise the input can crash the program.

## Recursion or loop?

Anything recursive can be written with a loop and the other way around. A loop is usually faster and does not use the stack. Recursion is shorter for problems that split into smaller copies of themselves.

Time a piece of code the same way as in lab 2:

```c
#include <time.h>

clock_t start = clock();
/* work */
double sec = (double)(clock() - start) / CLOCKS_PER_SEC;
```
