## Problem Statement

**Port checker (three files)**

Firewall rules and port scanners classify TCP/UDP ports. Write a program that reads port numbers and says what kind of port each one is. The classification code lives in its own file, not in `main.c`.

| File | Content |
|---|---|
| `netutil.h` | **declarations** of the functions below, protected by an include guard |
| `netutil.c` | **definitions** of the functions |
| `main.c` | reads the ports, calls the functions, sets the exit code |

```c
int is_valid_port(int port);          // 1 if port is in [1, 65535], otherwise 0
int is_well_known_port(int port);     // 1 if port is in [1, 1023], otherwise 0
void print_port_class(int port);      // prints "<port>: <class>"
```

Port classes (printed by `print_port_class`):

| Range | Class |
|---|---|
| 1 to 1023 | `well-known port` |
| 1024 to 49151 | `registered port` |
| 49152 to 65535 | `dynamic port` |
| anything else | `invalid port` |

`main` reads integers until the end of the input and calls `print_port_class` for each. If at least one port was invalid, `main` returns `1`, otherwise `0`.

**Constraint:** `main.c` contains no definition of these functions and does not include a `.c` file. Compile with:

```sh
gcc -Wall -Wextra main.c netutil.c -o main
```

**Part 2:** break things on purpose and write down the messages:
1. Compile with only `gcc -Wall -Wextra main.c -o main` (forget `netutil.c`).
2. Put `netutil.c` back, then delete the prototype of `print_port_class` from the header.
3. Restore the header, then remove the include guard and include the header twice in `main.c`.

**Examples**

```
$ echo "22 8080 50000 70000" | ./main
22: well-known port
8080: registered port
50000: dynamic port
70000: invalid port
$ echo $?
1

$ echo "443 3306" | ./main
443: well-known port
3306: registered port
$ echo $?
0
```

**Hints**
- A declaration says *that* a function exists: `int is_valid_port(int port);`. A definition has a body.
- `print_port_class` should use `is_valid_port` and `is_well_known_port` instead of repeating the numbers.
- Guard pattern: `#ifndef NETUTIL_H`, `#define NETUTIL_H`, declarations, `#endif`.
- `netutil.c` includes `netutil.h` too, so the compiler checks that the definitions match the declarations.
- Your own headers use quotes, system headers use `<...>`.

## Questions to verify knowledge
- What is the difference between a declaration and a definition?
- Which of the three errors from Part 2 comes from the **compiler** and which from the **linker**?
- Why is `netutil.c` passed to `gcc` and not `#include`d in `main.c`?
- Why must `netutil.c` include its own header?
- Why must the guard name be unique per header?
