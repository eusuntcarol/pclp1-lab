## Problem Statement

**Compile and link in separate steps**

There is no new program here. Reuse the three files from `01-port-checker` (`main.c`, `netutil.c`, `netutil.h`). The goal is to see that compiling and linking are two different steps, and to see which one fails when something is missing. Put your observations in your notes.

**Tasks**

1. Build in two steps, then link:
```sh
gcc -Wall -Wextra -c main.c -o main.o
gcc -Wall -Wextra -c netutil.c -o netutil.o
gcc main.o netutil.o -o main
```
Run `./main` to check it works.

2. Rebuild only what changed:
   - Change a message in `main.c`, recompile **only** `main.o` and link again. Check with `ls -l --time-style=full-iso *.o` that `netutil.o` kept its old time.
   - Now change `netutil.h` (for example add a new prototype). Which `.c` files must be recompiled? Why?

3. Delete `netutil.o` and run only:
```sh
gcc main.o -o main
```
Write down the error and say if it comes from the compiler or from the linker.

4. Put `netutil.o` back. In `main.c` call a function that is **declared** in `netutil.h` but that you never define anywhere. Compile with `-c` (does it work?), then link (does it work?).

**Example** (task 3, the exact text depends on your system)

```
$ gcc main.o -o main
/usr/bin/ld: main.o: in function `main':
main.c:(.text+0x2a): undefined reference to `is_valid_port'
collect2: error: ld returned 1 exit status
```

**Hints**
- `gcc -c` stops before linking, so it never complains about missing definitions.
- A file that includes a header must be recompiled when the header changes.
- The word `ld` in the error is the linker.

## Questions to verify knowledge
- What does the compiler need to know about `is_valid_port` to compile `main.c`? What does the linker need?
- Why is the error in task 3 a linker error and not a compiler error?
- Why does a change in `main.c` not require recompiling `netutil.c`, and why does a change in `netutil.h` require recompiling both?
- Why are big projects built from many object files instead of one huge `.c` file?
