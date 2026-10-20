# Functions cheatsheet

## Declaration and definition

A **declaration** (prototype) tells the compiler the name, parameter types and return type. A **definition** adds the body.

```c
int clamp(int value, int lo, int hi);      // declaration, ends with ;

int clamp(int value, int lo, int hi) {     // definition
    if (value < lo) {
        return lo;
    }
    if (value > hi) {
        return hi;
    }
    return value;
}
```

A function must be **declared before the first call**. The definition can come later in the file, or in another `.c` file.

Typical layout of a one-file program:

```c
#include <stdio.h>

int clamp(int value, int lo, int hi);      // prototypes first

int main(void) {
    printf("%d\n", clamp(150, 0, 100));
    // Displays: 100
    return 0;
}

int clamp(int value, int lo, int hi) {     // definitions after main
    /* ... */
}
```

## Formal and actual parameters

- **Formal** parameters are the names in the declaration/definition: `value`, `lo`, `hi`.
- **Actual** parameters (arguments) are the values given at the call: `150`, `0`, `100`.

## Pass by value

The function receives a **copy** of each argument. Changing the copy does not change the caller's variable:

```c
void bump(int n) {
    n = n + 1;                // changes only the local copy
}

int bumped(int n) {
    return n + 1;
}

int x = 5;
bump(x);
printf("%d\n", x);
// Displays: 5

x = bumped(x);                // the result comes back through return
printf("%d\n", x);
// Displays: 6
```

If a function must give back a result, use `return`. (Other ways of giving back several values need pointers, a later lab.)

## `return` and `void`

- `return expr;` ends the function immediately. A function can have several `return` statements (early exits).
- A function declared `void` returns nothing: use `return;` or just reach the closing brace.
- `f(void)` means "takes no parameters". An empty `f()` in older C means "unspecified parameters" (the compiler does not check the calls). In C23 (default in recent GCC versions) `f()` also means `f(void)`. Always write `f(void)`.

```c
void print_menu(void) {
    printf("1. Show\n");
    printf("0. Exit\n");
}
```

## `main` and the exit code

`main` is a function too. Its return value is the exit code given to the operating system: `0` means success, anything else means an error. Check it in the shell with `echo $?`.

```c
int main(void) {
    return 2;                 // ./main ; echo $?   displays 2
}
```

## Reminders from lab 2 (control flow)

```c
// Repeat while scanf converts one integer. Stops at end of input or invalid input.
while (scanf("%d", &value) == 1) {
    /* ... */
}

// Always runs at least once.
do {
    /* ... */
} while (choice != 0);

for (int i = 0; i < 5; i++) {
    /* initialization; condition; update */
}

switch (cmd) {
case 'a':
    /* ... */
    break;                    // without break, execution falls into the next case
default:
    break;
}
```

To read a single non-space character with `scanf`, put a space before `%c` so whitespace is skipped: `scanf(" %c", &cmd)`.
