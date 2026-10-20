## Problem Statement

**A function that remembers its calls**

Write a function that keeps track of how many times it has been called. The
count must belong to the function, not to `main`.

Implement this function:

```c
int count_call(void);
```

Each time `count_call` runs, it increments a `static` local variable and
returns the updated count. The function must not print anything.

```c
int count_call(void);  // returns 1 on the first call, 2 on the second, etc.
```

`main` reads an integer `n` in the range [0, 99] and calls `count_call` exactly
`n` times. For each returned count, `main` prints
`Even call: <count>` when the count is even and `Odd call: <count>` when the
count is odd. Print the count using two digits, including a leading zero for
counts from 1 to 9. If the input is not valid, print an error and return `1`.
Otherwise, return `0`.

**Examples**

```
Input: 3
Output:
Odd call: 01
Even call: 02
Odd call: 03

Input: 0
Output:

Input: -1
Output:
Error: number of calls must be non-negative
```

**Part 2: compare storage durations.**

1. First implement the counter as a local variable declared with `static`.
2. Remove `static` and run the program again. What happens to the output?
3. Move the variable into `main` and try to use it in `count_call`. What
   compiler error do you get?

**Constraints**

- Use no global variables.
- The counter variable must be declared inside `count_call`.
- Use a `for` loop in `main` to make the calls.
- Declare the prototype above `main` and define `count_call` below `main`.

**Hints**

- A local `static` variable is initialized once and keeps its value between
  calls.
- Initialize the counter to `0` and increment it before returning.
- `count_call` should return the counter; only `main` should print the
  even/odd message.
- Read `n` with `scanf("%2d", &n)`. The field width limits the input to two
  characters, matching the exercise's [0, 99] range.
- Use `printf("%02d", count)` for two-character, zero-padded output.
- `scanf` returns the number of successfully converted values. Check that it
  equals `1`.

## Questions to verify knowledge

- When is a local `static` variable initialized?
- How is a local `static` variable different from an ordinary local variable?
- Why can `main` not name the counter declared inside `count_call`?
- Why is the counter returned instead of printed inside `count_call`?
