## Problem Statement

**Pass by value**

This exercise is about observing what happens to arguments, not about building a program.

**Part 1: the failed swap**

Read two integers `x` and `y` and a sensor reading `r` from standard input. Write:

```c
void swap(int a, int b);
```

The function swaps its two parameters using a temporary variable, and prints the values **inside** the function after swapping. In `main`, print `x` and `y` before and after calling `swap(x, y)`.

The swap is **expected not to work** in `main`: that is the point of this part. Your job is to find out why.

Before running the program, **write down your prediction** of the output. Then run it and compare.

```
$ echo "3 7 150" | ./main
Before: x=3 y=7
Inside swap: a=7 b=3
After swap(x, y): x=3 y=7
Clamped reading: 100
```

**Part 2: what works**

A function gives back a value with `return`. Write:

```c
int clamp(int value, int lo, int hi);   // value limited to the range [lo, hi]
```

A sensor reports a value that must stay in [0, 100]. In `main` print `Clamped reading: <clamp(r, 0, 100)>`.

Examples of `clamp`: `clamp(150, 0, 100)` is `100`, `clamp(-5, 0, 100)` is `0`, `clamp(42, 0, 100)` is `42`.

**Part 3: `f()` versus `f(void)`**

Put these in one file and call each from `main`:

```c
int init(void) { return 1; }
int init_any() { return 1; }
```

1. Call `init(5)` and compile. Write down the error message.
2. Call `init_any(5)` and compile with `gcc -std=c99 -Wall -Wextra`. Does it compile?
3. Compile the same code with the default flags of your GCC version. Does `init_any(5)` still compile? (recent GCC versions use C23 by default, where `()` means `(void)`)

**Hints**
- A parameter is a variable that lives only during the call. Changing it does not touch the caller's variable.
- `swap` works inside the function: that is what the `Inside swap` line proves.
- You cannot return two values from one function. Later labs show how to give back several values using pointers.
- The message for part 3.1 contains `too many arguments to function`.

## Questions to verify knowledge
- Why does `x` still have its old value after `swap(x, y)`?
- Where do `a` and `b` live while `swap` runs? What happens to them when it ends?
- How does `clamp` get a changed value back to the caller although parameters are copies?
- Why do `printf` and `scanf` differ here? Why does `scanf` need `&x`? (just guess, the answer comes in the pointers lab)
- Which version, `f()` or `f(void)`, lets the compiler catch a call with a wrong number of arguments?
