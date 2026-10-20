## Problem Statement

**Service controller**

Administrators control services with short commands. Write a small controller that reads one-letter commands until `q` and runs them.

| Command | Action |
|---|---|
| `s` | start: print `Starting service...` |
| `t` | stop: print `Stopping service...` |
| `r` | restart: stop, then start |
| `?` | print `Commands: s start, t stop, r restart, q quit` |
| `q` | print `Bye` and stop reading |
| anything else | print `Unknown command: <letter>` |

Functions:

```c
void start_service(void);        // prints "Starting service..."
void stop_service(void);         // prints "Stopping service..."
int run_command(char cmd);       // runs one command, returns 0 if known, 1 if unknown
```

`run_command` decides what to do with a `switch (cmd)`. The restart command must **call** `stop_service` and `start_service`, not repeat their code.

`main` reads commands one by one. If at least one unknown command was seen, `main` returns exit code `2` at the end, otherwise `0`.

**Constraint:** use `switch` inside `run_command`. Every `case` ends with `break` or `return`.

**Part 2:** accept the uppercase letters too (`S`, `T`, `R`, `Q`) by giving two `case` labels to the same block.

**Examples**

```
$ echo "s r t x q" | ./main
Starting service...
Stopping service...
Starting service...
Stopping service...
Unknown command: x
Bye
$ echo $?
2

$ echo "s q" | ./main
Starting service...
Bye
$ echo $?
0
```

**Hints**
- Read a command with `scanf(" %c", &cmd)`. The space before `%c` skips newlines and spaces.
- `switch` on a `char` works because `char` is an integer type. Labels look like `case 's':`.
- `q` is handled by `main` (it stops the loop), but `run_command` can still print `Bye` for it. Decide where it belongs and keep it in one place.
- Several labels can share one block:
```c
case 'x':
case 'X':
    /* ... */
    break;
```

## Questions to verify knowledge
- What happens if you forget a `break` after `case 's':`? Try it.
- Why is the restart implemented by calling the other two functions? What would go wrong in a larger program if you copied their code?
- What does the space in `" %c"` do?
- Who receives the value returned by `main`? How do you read it in the shell?
- Why can a `case` label be `'s'` but not a variable?
