## Problem Statement

**How deep can recursion go?**

Parsers, directory walkers and JSON/XML readers recurse on their input. If the input controls the depth, an attacker can crash the program with a deeply nested input. In this exercise you find the limit and then protect against it.

Compile everything with `-O0` unless the text says otherwise.

```c
int dive(int depth, int limit);
```

Behavior of `dive`:
- if `limit != 0` and `depth == limit`: return `1` (limit reached, stop recursing).
- otherwise, every time `depth` is a multiple of `10000`, print `depth <depth>` on **stderr** (`fprintf(stderr, ...)`), so the output is visible even if the program crashes.
- then call itself with `depth + 1` and return its result.

`main` reads `limit` from standard input and calls `dive(1, limit)`. If `dive` returns, print `Reached limit <limit> safely`.

**Part 1: crash it.** Run `echo 0 | ./main` (no limit). Note the last `depth` line printed before `Segmentation fault`.

**Part 2: measure.**
1. Read your stack size with `ulimit -s` (in KB).
2. Estimate the bytes used by one frame: `stack_bytes / last_depth`. Compare with what you expect (return address, parameters, saved registers).

**Part 3: predict.**
1. Predict the last depth for a stack of 1024 KB. Check with `(ulimit -s 1024; echo 0 | ./main)`.
2. Add a few local variables to `dive` (for example `volatile long a = depth, b = depth, c = depth;`). Predict, then check how the maximum depth changes.
3. Compile with `-O2` and run `echo 0 | ./main` again. What changes? Explain.

**Part 4: guard it.** Run `echo 5000 | ./main` and `echo 50000000 | ./main`. Add an input check in `main` so a limit above `100000` is rejected with an error message and exit code `3`, before calling `dive`.

**Examples**

```
$ echo 5000 | ./main
Reached limit 5000 safely

$ echo 0 | ./main
depth 10000
depth 20000
...
depth 260000
Segmentation fault        <- about 260000 with an 8 MB stack at -O0; it depends on your system

$ echo 200000 | ./main
Error: limit too large (max 100000)       (exit code 3)
```

**Hints**
- A segmentation fault is the operating system killing the program that wrote outside its stack.
- On a test machine (8 MB stack, `-O0`) the crash came at depth about 260000, so roughly 32 bytes per frame. With `ulimit -s 1024` it came at about 30000. With `-O2` the program did not crash at all and kept counting, because the call became a jump.
- Each call stores the return address, the parameters and saved registers. At `-O0` every local variable also gets a slot.
- At `-O2` the compiler may turn `return dive(depth + 1, limit);` into a jump (a **tail call**) so no new frame is used.
- The subshell `( ... )` keeps the changed `ulimit` from affecting your terminal.

## Questions to verify knowledge
- Why does the program die with a segmentation fault instead of printing a clean error?
- What is stored in one stack frame? Why do extra locals make the maximum depth smaller?
- What is a tail call? Why can `-O2` run for much longer, and why can't you rely on that?
- Name a real situation where outside input controls the recursion depth (parsers, nested data, directory trees with links). What should such code do?
- How do you pick a safe depth limit? Which number would you choose for a 8 MB stack and a 100-byte frame?
