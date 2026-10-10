# Control-flow cheatsheet

## Conditions

```c
if (value < 0) {
    printf("negative\n");
    // Displays: negative
} else if (value == 0) {
    printf("zero\n");
    // Displays: zero
} else {
    printf("positive\n");
    // Displays: positive
}
```

Use `==` for comparison and `=` for assignment. In a condition, zero is false and every non-zero value is true.

## `switch`

`switch` selects a constant `case`. Several labels can share one block. Execution continues into the next case unless `break` is used:

```c
switch (status / 100) {
case 2:
    printf("success\n");
    // Displays: success
    break;
case 4:
case 5:
    printf("error\n");
    // Displays: error
    break;
default:
    printf("unknown\n");
    // Displays: unknown
    break;
}
```

## Loops

```c
// Keep reading while scanf successfully converts an integer.
// On a terminal, Ctrl+D (Linux/macOS) or Ctrl+Z then Enter (Windows)
// signals end of input. The loop also stops on invalid input.
while (scanf("%d", &value) == 1) {
    /* test before each iteration */
}

do {
    /* always runs once */
} while (choice != 0);

for (int i = 0; i < 3; i++) {
    /* initialization; condition; update */
}
```

`break` exits the nearest loop or switch. `continue` skips to the next iteration of the nearest loop. A `for` followed immediately by `;` has an empty body. Avoid `goto` unless there is a compelling control-flow reason.
