## Problem Statement

**Why not `#include` a `.c` file, and a Makefile that rebuilds only what changed**

Reuse `main.c`, `netutil.c` and `netutil.h` from `01-port-checker`.

**Part 1: the classic mistake**

1. In `main.c` replace `#include "netutil.h"` with `#include "netutil.c"`.
2. Compile as before: `gcc -Wall -Wextra main.c netutil.c -o main`. Write down the error and say which tool prints it.
3. Now compile with only `gcc -Wall -Wextra main.c -o main`. Does it work? Why?
4. Restore `#include "netutil.h"`.

**Part 2: declare the functions with `extern`**

Now remove the `#include "netutil.c"` mistake without using the header yet.

1. In `main.c`, replace `#include "netutil.c"` with these function
   declarations:

   ```c
   extern int is_valid_port(int port);
   extern int is_well_known_port(int port);
   extern void print_port_class(int port);
   ```

   For functions, `extern` is optional because function declarations have
   external linkage by default. These declarations make the compiler aware of
   the functions, because their definitions are still in `netutil.c`.
2. Compile and link both source files:

   ```sh
   gcc -Wall -Wextra main.c netutil.c -o main
   ```

3. Run the program and check that it works.
4. Replace the manual declarations (what you wrote in step 1) with `#include "netutil.h"` again. Why is
   the header better than repeating the declarations in `main.c`?

**Part 3: Makefile with object files**

Write a `Makefile` with these targets:

| Target | Action |
|---|---|
| `main` (default) | links `main.o` and `netutil.o` into `main` |
| `%.o` (pattern rule) | compiles one `.c` file with `-Wall -Wextra -c` |
| `run` | builds if needed, then runs `./main` |
| `clean` | removes `main` and all `.o` files |

The object files must also depend on `netutil.h`, so a change in the header triggers a rebuild.

**Constraint:** use variables `CC` and `CFLAGS`, and the automatic variables `$<` and `$@` in the pattern rule. Mark `run` and `clean` as `.PHONY`.

**Part 4: check the rebuild logic**

Run these commands and write down what `make` prints each time:
```sh
make                 # builds everything
make                 # nothing to do
touch main.c ; make  # only main.o is rebuilt, then linked
touch netutil.h ; make   # both .o files are rebuilt
make clean ; make
```

**Examples**

```
$ make
gcc -Wall -Wextra -c main.c -o main.o
gcc -Wall -Wextra -c netutil.c -o netutil.o
gcc main.o netutil.o -o main
$ make
make: 'main' is up to date.
$ touch main.c ; make
gcc -Wall -Wextra -c main.c -o main.o
gcc main.o netutil.o -o main
```

**Hints**
- In the pattern rule `$<` is the first dependency (the `.c` file) and `$@` is the target (the `.o` file).
- A rule with only dependencies and no command adds extra dependencies: `main.o netutil.o: netutil.h`.
- Commands in a Makefile begin with a TAB, not spaces.
- `touch file` updates the modification time of a file, which is what `make` compares.

## Questions to verify knowledge
- Why does `#include "netutil.c"` plus compiling `netutil.c` too give `multiple definition`?
- Why does it work if you compile only `main.c` after including `netutil.c`?
  Why is it still a bad habit?
- Why does `extern` make the compiler accept the calls, but not provide the
  function definitions to the linker?
- Why is a shared header better than repeating `extern` declarations?
- Why do `main.o` and `netutil.o` depend on `netutil.h` in the Makefile?
- What would happen to your builds if the header dependency was missing and you changed a prototype?
- Why is `clean` marked `.PHONY`?
