# Recap and answers

This section summarizes the main points of the previous labs and answers some common questions.

## 0. compile, printf, scanf

**Compile and run.** Save the file first (Ctrl+S). Go to the right folder with `cd`.

```bash
cd lab2
gcc -Wall -Wextra file.c -o file
./file
```

In the terminal, Ctrl+D means "no more input" (EOF - end of file).

**scanf expects exactly the pattern you write.** Any character in the format must also be in the input.

```
scanf("%d,%d", &a, &b);  // input must be 7,2 - with comma (7 2 - with space, fails)
scanf("%d %d", &a, &b);  // input must be 7 2 - without comma
```

**`-` and `+` can be part of a number.** With `scanf("%d%d", ...)`, the input `202-555` reads `202` and `-555`. To read a separator, read it as a character: `scanf("%d%c%d", &a, &sep, &b)`.

**Which format to use.**

| Type | scanf | printf |
| --- | --- | --- |
| `int` | `%d` | `%d` |
| `unsigned int` | `%u` | `%u` |
| `int` as hex | `%x` | `%x` or `%X` |
| `float` | `%f` | `%f` |
| `double` | `%lf` | `%f` or `%lf` |
| `char` | `" %c"` | `%c` |
| `sizeof(...)` |  | `%zu` |

**Width and decimals in printf.**

```javascript
printf("%10.3lf\n", 3.14159);  // "     3.142" (10 wide, 3 decimals)
printf("%05d\n", 42);          // "00042"  (5 wide, with '0' padded)
printf("%.1f%%\n", 50.0);      // "50.0%"  (%% prints one %)
```

If the number is wider than the width, printf uses as much space as it needs.

**Width in scanf limits how many characters it reads.**

```javascript
scanf("#%2x%2x%2x", &r, &g, &b);  // "#FF8000" -> 255 128 0
```

**int / int gives an int.** Convert one side first.

```
128 / 255 * 100         // 0
(float)128 / 255 * 100  // 50.19...
128 / 255.0 * 100       // 50.19...
128.0 / 255.0 * 100.0   // 50.19...
// basically any combination works!
// one side just needs to be float.
// WHY? if both operands are integers, the compiler will use integer division because that is dictated by the types. if one or both are floats, then floating point division will be used.
```

**The format decides how bits are shown.** `-1` stored in an `int` and printed with `%u` shows `4294967295`. Always use the format that matches the type.

**A literal** is a value written directly in the code: `42`, `3.14`, `'a'`, `"hello"`, `0xFF`.

**Several errors at once?** Check them in a fixed order and stop at the first one (see section 5).

## 1. Reading input with scanf

`scanf` returns how many values it read. Always check that number.

**Rule 1: compare with the exact count of values you expect to be read.**

- `1` = it read the value
- `0` = the input was not a number
- `EOF` (-1) end of file = no more input

```javascript
// Bad: misses EOF (-1)
if (scanf("%d", &x) == 0) return 1;

// Good
if (scanf("%d", &x) != 1) return 1;
```

**Rule 2: reading in a loop is fine, but always compare the result.**

Write `while (scanf(...) == 1)`, not just `while (scanf(...))`.

At the end of input scanf returns `EOF` (-1), and -1 counts as true, so the loop never stops.&#32;

Pressing ENTER is expected to not stop the program, because ENTER is `\n`, which will be treated as a character -> converted to int, thus scanf will correctly return 1, because it indeed read one value.

```javascript
// Bad: infinite loop at the end of input
while (scanf("%d", &code)) { ... }

// Good
while (scanf("%d", &code) == 1) { ... }
```

**Rule 3: don't forget `&`.** scanf needs the address of the variable.

```javascript
scanf("%d", x);   // wrong
scanf("%d", &x);  // right
```

**Rule 4: put a space before `%c`.** Without it, `%c` reads the Enter key left from the previous line.

```c
scanf(" %c", &cmd);  // the space skips spaces, tabs and newlines
```

**Rule 5: call scanf once per value.** Calling it twice reads two different inputs.

```javascript
// Bad: the first value is lost
scanf("%d", &x);
if (scanf("%d", &x) != 1) ...

// Good
if (scanf("%d", &x) != 1) ...
```

## 2. Variables

**Always give counters a start value.** A local variable without a value holds garbage, not 0.

```
// Bad: variables will have random values
int total, client;

// Good
int total = 0, client = 0;
```

**Don't declare the same variable again inside a loop.** The inner one hides the outer one, so the outer one never changes.

```
int cont = scanf("%d", &x);
while (cont != EOF) {
    ...
    int cont = scanf("%d", &x);  // Bad: a NEW variable
}

int cont = scanf("%d", &x);
while (cont != EOF) {
    ...
    cont = scanf("%d", &x); // Good: assign, don't declare
}
```

In the bad version, the `while` checks the outer `cont`, which never changes. The loop never ends, not even with Ctrl+D.

**Use `=` to assign and `==` to compare.**

```c
if (x = 3)   // Bad: sets x to 3, always true
if (x == 3)  // Good
```

## 3. Functions

**Call a function with `()`.** Without them, nothing runs and there is no error.

```c
start_service;    // does nothing
start_service();  // runs it
```

**A non-void function must return on every path.** If one path has no `return`, the result is random.

```c
// Bad: what is returned for code 200?
int is_client_error(int code) {
    if (code >= 400 && code <= 499) return 1;
}

// Good
int is_client_error(int code) {
    return code >= 400 && code <= 499;
}
```

The same goes for recursion. Return the recursive call:

```c
connect_with_retry(attempt + 1, ...);         // Bad: result is lost
return connect_with_retry(attempt + 1, ...);  // Good
```

**`f(void)` vs `f()`.**

- `int init(void)` means: takes no arguments. `init(5)` is an error.
- `int init_any()` in older C (C99, C11, C17) means: arguments not specified. `init_any(5)` compiles without a warning.
- In C23 (the default in new GCC versions), `f()` means the same as `f(void)`. So `init_any(5)` is an error too.

That is why you got different results on different machines. Check with:

```bash
gcc -std=c99 -Wall -Wextra test.c   # init_any(5) compiles
gcc -std=c23 -Wall -Wextra test.c   # init_any(5) is an error
```

Rule: always write `void` when a function takes nothing.

**Pass by value: functions get copies.** Changing `a` and `b` inside `swap` does not change `x` and `y` in `main`. That was the point of the exercise. Pointers (`int *a`) fix it, but come later.

```c
void swap(int a, int b) { int t = a; a = b; b = t; }
swap(x, y);  // x and y are unchanged
```

**Use the return value to send results back.**

```c
int clamp(int value, int lo, int hi) {
    if (value < lo) return lo;
    if (value > hi) return hi;
    return value;
}
```

**Give each function one job.** If `run_command` only checks whether a command exists, `main` ends up with a second `switch` that repeats it. Let `run_command` do the work and return 0 or 1.

## 4. switch

**Several cases can share one block.** Stack them:

```c
switch (cmd) {
    case 's':
    case 'S':
        start_service();
        break;
    case 'q':
    case 'Q':
        printf("Bye\n");
        break;
    default:            // anything not listed above
        printf("Unknown command: %c\n", cmd);
        return 1;
}
```

**End each case with `break` (or `return`).** Without it, the code runs into the next case.

```c
// Bad: option 2 also runs withdraw, exit and "invalid option"
case 2: deposit();
case 3: withdraw();
case 0: printf("Bye\n");
default: printf("Error\n");
```

Compile with `-Wextra` and GCC warns you: `this statement may fall through`.

**`break` leaves the switch, not the loop.** To leave a loop from inside a switch, use a flag or check the value after the switch:

```c
while (scanf(" %c", &cmd) == 1) {
    run_command(cmd);
    if (cmd == 'q' || cmd == 'Q') break;  // this break leaves the loop
}
```

**Use `default`** to handle anything unexpected.

## 5. Errors and exit codes

**An error has two parts: a message and a return code.** Printing the message is not enough. Stop the program too.

```c
// Bad: prints the error, then keeps going
if (percent < 0 || percent > 100)
    printf("Error: percent must be between 0 and 100\n");

// Good
if (percent < 0 || percent > 100) {
    printf("Error: percent must be between 0 and 100\n");
    return 1;
}
```

**`return 0` means success.** Never return 0 from an error branch.

**Check in the right order.** First check that scanf worked, then check the values. If scanf failed, the variables hold garbage.

```c
if (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4) { ... return 1; }  // 1st
if (a < 0 || a > 255 || ...)                   { ... return 1; }  // 2nd
```

**Don't ignore what a function returns.** If it reports failure, pass it on:

```c
if (connect_with_retry(1, max, 1, 0, ok_at) == -1)
    return 2;
```

**Check the exit code** after running:

```bash
./prog
echo $?    # prints the code main returned
```

## 6. Numbers

**Read negatives into `int`, then convert.** An `unsigned` can never be negative, so `x < 0` is always false.

```c
int input;
if (scanf("%d", &input) != 1 || input < 0) return 1;
unsigned int serial = (unsigned int)input;  // safe now
```

**Match the format to the type.**

| Type | printf / scanf |
| --- | --- |
| `int` | `%d` |
| `unsigned int` | `%u` |
| `char` | `%c` (scanf: `" %c"`) |
| `long long` | `%lld` |

**Multiply first, then divide.** Integer division drops the decimals.

```c
33 / 100 * 20   // = 0 * 20 = 0   (wrong)
33 * 20 / 100   // = 660 / 100 = 6 (right)
```

**Never divide by zero.** Check first:

```c
int percent(int part, int whole) {
    if (whole == 0) return 0;
    return part * 100 / whole;
}
```

**Watch the edges (off-by-one).** Test the smallest and largest values.

```c
for (i = 0; i < width; i++)   // width steps
for (i = 0; i <= width; i++)  // width + 1 steps (one too many)
```

- "amount <= balance" is not the same as "amount < balance". Withdrawing the whole balance must work.
- A base case `n <= 10` returns 10 for `n = 10`. The digit sum of 10 is 1. Use `n < 10`.
- Use `%04u` to print a serial with 4 digits: `7` → `0007`.

**Use `>>` and `&` for bits, not `pow()`.** `pow` works with `double` and is slow and inexact.

## 7. Recursion and bits

**Every recursive function has two parts:**

1. A base case: when to stop.
2. A smaller step: call itself on a smaller problem.

```c
unsigned int digit_sum(unsigned int n) {
    if (n < 10) return n;               // 1. stop
    return n % 10 + digit_sum(n / 10);  // 2. smaller problem
}
```

**What `>> 1` and `& 1` do.**

- `value & 1` = the last bit (same as `value % 2`).
- `value >> 1` = drop the last bit (same as `value / 2`).

```c
13 = 1101
13 & 1  = 1      // last bit
13 >> 1 = 110 = 6
```

**Why `print_binary` needs `bits`.** The number alone doesn't say how many digits to print. `1` must print as `00000001`, so the function needs to know "print 8 bits". `bits` counts how many are left. When it reaches 0, stop.

```c
void print_binary(unsigned int value, int bits) {
    if (bits == 0) return;              // nothing left
    print_binary(value >> 1, bits - 1); // first print the higher bits
    printf("%u", value & 1);            // then print the last bit
}
```

**Order matters.** The last bit is known first, but must be printed last. So call first, print after. Trace for `print_binary(5, 3)` (5 = 101):

```text
print_binary(5, 3)
  print_binary(2, 2)
    print_binary(1, 1)
      print_binary(0, 0) -> stop
      prints 1
    prints 0
  prints 1
Output: 101
```

If you print before the call, the bits come out reversed: `6` (110) prints as `011`.

**Recursion or a loop?**

- Use a loop for simple counting or repeating.
- Use recursion when the problem contains a smaller copy of itself (digits, bits, trees, retrying with new values).
- Every recursive call uses stack memory. Very deep recursion crashes the program (the stack-depth exercise shows this).

**Tail recursion.**

(Not subject of our lab, but one question was about this, feel free to skip)

A function is tail recursive when the recursive call is the very last thing it does. Nothing is left to compute after the call returns.

**Why it matters.** Every call gets its own frame on the stack (its parameters and local variables). A normal recursive function must keep each frame alive, because it still has work to do after the call returns. With 100,000 calls, that means 100,000 frames, and the program can crash (this is what the stack-depth exercise shows).

**Not tail recursive:** after `digit_sum(n / 10)` returns, the function still has to add `n % 10`. So every frame must wait.

```c
unsigned int digit_sum(unsigned int n) {
    if (n < 10) return n;
    return n % 10 + digit_sum(n / 10);  // adds AFTER the call
}
```

**Tail recursive:** pass the partial result down as an extra parameter (often called an accumulator). The call is the last step, so nothing waits.

```c
unsigned int digit_sum_acc(unsigned int n, unsigned int sum) {
    if (n == 0) return sum;
    return digit_sum_acc(n / 10, sum + n % 10);  // nothing after the call
}

digit_sum_acc(1234, 0);  // 10
```

Trace for `digit_sum_acc(123, 0)`: the answer is built on the way down, so the last call already holds it.

```text
digit_sum_acc(123, 0)
digit_sum_acc(12, 3)
digit_sum_acc(1, 5)
digit_sum_acc(0, 6) -> returns 6
```

`connect_with_retry` from the lab is already tail recursive: `waited` and `delay` are its accumulators, and `return connect_with_retry(...)` is its last step.

**What the compiler does with it.** The old frame is no longer needed, so the compiler reuses it: it overwrites the parameters in the current frame and jumps back to the start of the function instead of making a new call. **The stack does not grow.** GCC does this with optimizations on (`-O2`).

GCC can go further. If the only work left after the call is a simple `+` or `*`, it adds the accumulator by itself. So with `-O2`, even the first `digit_sum` above runs without growing the stack. It cannot do this when the work after the call is something like a `printf` that uses the result.

C does not promise it, though. Without `-O2`, or with another compiler, a tail-recursive function can still run out of stack. If a loop needs to run millions of times, write a loop.

## 8. Storage and linking

**A `static` local variable keeps its value between calls.** It is set to 0 only once, not on every call. No global variable needed.

```c
int count_call(void) {
    static int count = 0;  // runs once
    return ++count;        // 1, 2, 3, ...
}
```

Without `static`, `count` starts at 0 every time and the function always returns 1.

**Split a program into three files.**

| File | What goes in it |
| --- | --- |
| `netutil.h` | Declarations only (the function headers ending in `;`) |
| `netutil.c` | The function bodies. Starts with `#include "netutil.h"` |
| `main.c` | `main`. Starts with `#include "netutil.h"` |

Each `.c` file needs its own `#include <stdio.h>` if it uses `printf`.

**Protect the header with an include guard.** The name must be one word: letters, digits and `_` only (no `-` or `.`).

```c
#ifndef NETUTIL_H
#define NETUTIL_H

int is_valid_port(int port);
int is_well_known_port(int port);
void print_port_class(int port);

#endif
```

**Compile all `.c` files together.** Never `#include` a `.c` file.

```bash
gcc -Wall -Wextra main.c netutil.c -o port_checker
```

## 9. Output and code habits

**Print exactly what the exercise shows.** No extra prompts like ` percent =  ` or `How much?`. Same words, same spaces, a `\n` at the end.

```c
printf("percent = ");               // Bad: not in the expected output
printf("Serial %04u: OK\n", s);    // Good: matches the example
```

**Compile with warnings on, every time.** Most bugs in this document show up as warnings.

```bash
gcc -Wall -Wextra -std=c11 file.c -o file
```

**Avoid magic numbers.** A return value like `67` means nothing to a reader. Use what the exercise asks for (0 = known, 1 = unknown).

**Avoid global variables** when a local one or a return value works.

**Hand in only source files** (`.c`, `.h`). Leave out `a.out`, `.exe` and other compiled files.

## 10. Quick checklist

Before handing in, check each point:

- [ ] Every `scanf` is checked with `!= 1` (or the exact count)
- [ ] There is a space in `" %c"`
- [ ] Every counter starts at 0
- [ ] Every error prints a message AND returns a non-zero code
- [ ] Every non-void function returns on every path (recursive calls too)
- [ ] Every `case` ends with `break` or `return`
- [ ] No division by zero
- [ ] Edge values tested: 0, the maximum, a negative number, a letter
- [ ] Output matches the examples exactly, with no extra prompts
- [ ] Compiled with `-Wall -Wextra` and no warnings left
- [ ] Only `.c` and `.h` files in the archive
