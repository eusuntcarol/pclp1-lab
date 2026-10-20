## Problem Statement

**A logger with private internals**

Libraries show a small public interface and hide the rest. Build a tiny logging module with `static` functions and variables, and see what the linker does with them.

Files: `logger.h`, `logger.c`, `main.c`.

Public interface (in `logger.h`, with an include guard):

```c
void log_info(int code);      // prints "[INFO] event <code>"
void log_warn(int code);      // prints "[WARN] event <code>"
void log_error(int code);     // prints "[ERROR] event <code>"
int log_count(void);          // number of messages written so far
```

Private part (only in `logger.c`, **not** in the header):

```c
static int message_count = 0;
static void write_line(int level, int code);   // level: 0 info, 1 warn, 2 error
```

`write_line` prints the line (use `switch (level)` to choose the tag) and increments `message_count`. The three public functions call `write_line`. `log_count` returns `message_count`.

`main` reads pairs `level code` until the end of the input and calls the matching public function (use `switch`). Unknown levels are ignored. At the end print `Total messages: <log_count()>`.

**Examples**

```
$ echo "0 200 1 404 2 500" | ./main
[INFO] event 200
[WARN] event 404
[ERROR] event 500
Total messages: 3

$ echo "0 200 7 1" | ./main
[INFO] event 200
Total messages: 1
```

**Part 2: break the privacy.**
1. In `main.c` declare `void write_line(int level, int code);` yourself and call it. Compile and link. Which stage fails and with what message?
2. In `main.c` declare `extern int message_count;` and print it. What happens now?
3. Create `extra.c` containing its own `static void write_line(void) { }` and add it to the `gcc` command. Does it link? Why?
4. Remove `static` from `write_line` in **both** files and link again. What error do you get?

**Hints**
- A `static` file-level variable keeps its value for the whole run but only code in that file can name it.
- The declaration in step 1 makes the **compiler** happy. The **linker** is the one that cannot find a visible `write_line`.
- Keep the header as small as possible: only what other files need.

## Questions to verify knowledge
- What does `static` mean on a function? And on a variable declared at file level?
- Why is exposing `log_count()` better than exposing `message_count` directly?
- Why can two files each have a `static` function with the same name?
- Why can the linker not find a `static` function from another file, even though the file defines it?
- Why are global variables discouraged even when `static`? What can go wrong when many functions change the same variable?
