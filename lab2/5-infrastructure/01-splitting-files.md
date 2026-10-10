## Problem Statement

**Splitting a program into files**

Until now, everything was in one file. Real programs are split into several files. In this exercise you build a small program with **three files**.

Write a program that reads two integers and prints their sum and their product. The computations must live in a separate file, not in `main.c`.

**Files**

Programs are usually split in:
- `main.c` which is the entrypoint of the program, containing `main()` function
- `.h` header files, which contain declarations of the functions that we want to use
- `.c` source files, which contain the definitions of those functions

In our `#include` directives we use `.h`, then later we will link the objects using gcc.

| File | Content |
|---|---|
| `math_ops.h` | **declarations** of `add` and `mul`, protected by an include guard |
| `math_ops.c` | **definitions** of `add` and `mul` |
| `main.c` | reads the numbers, calls the functions, prints the results |

**Task**

1. Create the three files.
2. In `math_ops.h`, add an include guard so the header can be included more than once safely.
3. In `main.c`, add `#include "math_ops.h"` **twice** (yes, on purpose). The program must still compile.
4. Remove the include guard and compile again. What error do you get? Put the guard back.
5. Compile and run with:
```
gcc -Wall -Wextra main.c math_ops.c -o main
```
6. Exercise the gcc compiling steps:
```
gcc -Wall -Wextra -c main.c     # outputs main.o
gcc -Wall -Wextra -c math_ops.c # outputs math_ops.o
gcc main.o math_ops.o -o main
```
7. Can you explain the differences between points 5 and 6?

**Example**

```
3 4   ->  Sum: 7
          Product: 12
```

**Hints**
- A declaration says *that* a function exists somewhere: `int add(int a, int b);`
- A definition says *what it does*: it has a body `{ ... }`.
- Your own headers use quotes `"..."`, system headers use `<...>`.
- Guard pattern:
```c
#ifndef MATH_OPS_H
#define MATH_OPS_H
/* declarations here */
#endif
```

## Questions to verify knowledge
- What is the difference between a declaration and a definition?
- Why does `#include` twice cause an error without the guard? (what does the preprocessor do with the text?)
- Why is the `.c` file not included in `main.c`, but passed to `gcc`?
- What error do you get if you forget `math_ops.c` in the `gcc` command? Is it a compile or a linker error?
- Why must the guard name be unique per header file?
