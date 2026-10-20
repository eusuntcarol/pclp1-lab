# Lab 3

Topics: functions, recursion, storage classes (`extern` / `static`) and linking.

The goal is to learn the concepts and to practice syntax, not to solve all exercises.

Section 1 also revisits what was left from lab 2 (`for`, `while`, `do while`, `switch`): every exercise with one of these constructs forces it inside a small function. If you skipped lab 2 control flow, read its [cheatsheet](../lab2/3-control-flow/README.md) first.

Rules for this lab:
- No arrays and no pointers yet (they come in later labs). Functions give results back **only** through `return`.
- Every exercise gives you the function prototypes. Your job is to implement them and use them from `main`.

Please have a separate file open where you write down notes on your progress:
- exercises solved for each section (e.g. 3.02 for exercise 2 of section 3)
- notes on what you learned
- questions you have
- problems you encountered during the exercises and how you solved them

Flow of solving exercises:
1. Start with the sections in order.
1. Read the README.md for each section containing the cheatsheet.
1. Solve all the easy exercises.
1. Go to next section and repeat (only easy exercises).
1. After all sections are done, go back and solve the medium exercises.
1. Finally, solve the hard exercises.
1. Do not forget to write down your notes and questions.

When you encounter a problem:
1. Write it down in your notes.
1. Try to solve it by yourself.
1. If you cannot solve it, ask your colleagues.
1. If you still cannot solve it, ask the assistant.
1. Write down the solution in your notes.

At the end of the lab, you will be asked to submit your notes and questions.

## Exercises

| Section | # | Exercise | Difficulty | Practices |
|---|---:|---|---|---|
| [1-functions](1-functions/) | 01 | [progress-bar](1-functions/01-progress-bar.md) | Easy | `for`, `scanf`, `printf` width |
| [1-functions](1-functions/) | 02 | [log-error-counter](1-functions/02-log-error-counter.md) | Easy | `while` + `scanf`, formal vs actual parameters |
| [1-functions](1-functions/) | 03 | [pass-by-value](1-functions/03-pass-by-value.md) | Easy | copies of parameters, `f(void)` vs `f()` |
| [1-functions](1-functions/) | 04 | [wallet-menu](1-functions/04-wallet-menu.md) | Medium | `do while`, `void` functions |
| [1-functions](1-functions/) | 05 | [service-controller](1-functions/05-service-controller.md) | Medium | `switch`, exit code of `main` |
| [1-functions](1-functions/) | 06 | [password-strength](1-functions/06-password-strength.md) | Hard | helper functions, multiple `return`, `getchar` |
| [1-functions](1-functions/) | 07 | [animated-progress-bar](1-functions/07-animated-progress-bar.md) | Hard | `\r`, `fflush`, `nanosleep`, terminal output |
| [2-recursion](2-recursion/) | 01 | [serial-checksum](2-recursion/01-serial-checksum.md) | Easy | return value, `printf` zero-padding |
| [2-recursion](2-recursion/) | 02 | [ipv4-binary](2-recursion/02-ipv4-binary.md) | Easy | base case, order of work around the call |
| [2-recursion](2-recursion/) | 03 | [retry-backoff](2-recursion/03-retry-backoff.md) | Medium | several base cases, accumulator parameters |
| [2-recursion](2-recursion/) | 04 | [stack-depth](2-recursion/04-stack-depth.md) | Hard | stack frames, stack overflow, depth limits |
| [3-storage-linking](3-storage-linking/) | 01 | [call-counter](3-storage-linking/01-call-counter.md) | Easy | local `static`, `scanf` field width, zero-padding |
| [3-storage-linking](3-storage-linking/) | 02 | [port-checker](3-storage-linking/02-port-checker.md) | Easy | `.h` / `.c` split, include guard |
| [3-storage-linking](3-storage-linking/) | 03 | [logger](3-storage-linking/03-logger.md) | Medium | `static` functions and variables |
| [3-storage-linking](3-storage-linking/) | 04 | [object-files](3-storage-linking/04-object-files.md) | Medium | `gcc -c`, compiler vs linker |
| [3-storage-linking](3-storage-linking/) | 05 | [include-c-and-make](3-storage-linking/05-include-c-and-make.md) | Medium | why not `#include "x.c"`, Makefile with `.o` rules |

## Compiling and running

Each exercise is a written specification.
Create a dedicated directory for each exercise and a `main.c` beside. Compile with:

```sh
gcc -Wall -Wextra main.c -o main
```

For exercises with several source files list all the `.c` files:

```sh
gcc -Wall -Wextra main.c netutil.c -o main
```

Add `-lm` for exercises using `math.h`.

Shortcuts to not type input every time:
- `echo 42 | ./main` feeds `42` to standard input.
- `echo $?` prints the exit code of the last command.
