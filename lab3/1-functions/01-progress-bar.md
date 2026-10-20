## Problem Statement

**Progress bar**

Download managers, installers and build tools show a progress bar. Write a program that reads a percentage and prints it as a text bar.

Read an integer `percent` from standard input. It must be in [0, 100]. Print
a bar of `width` characters between square
brackets, followed by the percentage. The number of filled cells is
`percent * width / 100` (integer division). Filled cells are `#`, empty cells
are `-`.

The drawing must be done by this function:

```c
void print_bar(int percent, int width);
```

It prints the bar and the percentage on one line, with a newline at the end. `main` reads the value, validates it and calls `print_bar(percent, 20)`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the input is not an integer, or `percent` is not in [0, 100] |

**Constraint:** declare `print_bar` with a prototype **above** `main` and define it **below** `main`. Use `for` loops to draw the cells (no `while`).

**Part 2:** call `print_bar` a second time from `main` with width `10`, to see the same function used with a different actual parameter.

**Examples**

```
0    ->  [--------------------]   0%
50   ->  [##########----------]  50%
100  ->  [####################] 100%
33   ->  [######--------------]  33%       (33 * 20 / 100 = 6)
101  ->  Error: percent must be between 0 and 100     (exit code 1)
abc  ->  Error: invalid input                         (exit code 1)
```

**Hints**
- Compute the filled count once, then use one `for` for the `#` cells and one for the `-` cells.
- Use `scanf("%d", &percent)` to read the integer normally.
- Use `printf("%3d%%", percent)` to reserve three character positions and
  print a literal `%`.
- `scanf` returns the number of converted values, not the number of
  characters consumed: check it equals `1`.
- Print the error and `return 1;` from `main` before calling `print_bar`.

## Questions to verify knowledge
- What is the difference between the **declaration** and the **definition** of `print_bar`?
- Which names are the formal parameters and which values are the actual parameters here?
- What happens if you define `print_bar` below `main` and delete the prototype? Read the compiler message.
- Why is `33 * 20 / 100` equal to `6`? What would `33 / 100 * 20` give?
- Why does `print_bar` return `void`?
