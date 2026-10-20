# Storage classes and linking cheatsheet

## From source to executable

Each `.c` file is compiled **separately** into an object file (`.o`). The **linker** then joins the object files and the libraries into one executable.

```sh
gcc -Wall -Wextra -c main.c -o main.o        # compile only, no linking
gcc -Wall -Wextra -c netutil.c -o netutil.o
gcc main.o netutil.o -o main                 # link
```

When compiling `main.c`, the compiler needs only the **declaration** (the prototype) of the functions it calls. The **definition** (the code) is looked up by the linker.

| Problem | Reported by | Typical message |
|---|---|---|
| call to a function that was never declared | compiler | `implicit declaration of function` |
| function declared but its definition is missing | linker | `undefined reference to 'f'` |
| same function defined in two files | linker | `multiple definition of 'f'` |

## Header files

A header (`.h`) contains **declarations**. A source file (`.c`) contains **definitions**. Your own headers are included with quotes. Add an **include guard** so a header included twice does not redeclare things:

```c
/* netutil.h */
#ifndef NETUTIL_H
#define NETUTIL_H

int is_valid_port(int port);

#endif
```

```c
/* main.c */
#include <stdio.h>
#include "netutil.h"
```

Do not `#include` a `.c` file. Both files would then contain the same definitions and the linker reports `multiple definition`.

## `extern` and `static`

The storage class says who can see a function (or a global variable) at link time.

```c
/* util.c */
static int helper(int x) {         // internal linkage: visible only in util.c
    return x * 2;
}

int api(int x) {                   // external linkage (the default, same as 'extern')
    return helper(x);
}

static int call_count = 0;         // file-level variable, private to util.c
```

- `extern` (default for functions): the name is visible to other object files.
- `static`: the name is **private** to the file. Another file can have its own function or variable with the same name without a conflict.
- `extern int x;` on a variable is a declaration that says "defined in another file". Global variables are discouraged: expose them through functions instead.

## Make with object files

```make
CC = gcc
CFLAGS = -Wall -Wextra

main: main.o netutil.o
	$(CC) main.o netutil.o -o main

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.o netutil.o: netutil.h

clean:
	rm -f main *.o

.PHONY: clean
```

`%.o: %.c` is a pattern rule: `$<` is the source file and `$@` is the target. Only the files that changed are recompiled. Commands begin with a TAB.
