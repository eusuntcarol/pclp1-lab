## Problem Statement

**Automating the build**

Write a `Makefile` that automates building and running the three-file program from [5-infrastructure/01](01-splitting-files.md).

1. A target that **compiles** `main.c` and `math_ops.c` into an executable (with `-Wall -Wextra`, and `-lm` if needed).
2. A target that **runs** the program.
3. A target that **removes** the generated files.

Running only `make` must build the program.

**Example**

```
$ make          # builds
$ make run      # runs
$ make clean    # deletes the executable
```

**Hints**
- See the section README and its example Makefile.
- A rule has the form `target: dependencies`, followed by a command indented with a **TAB**.

## Questions to verify knowledge
- Why does `make` not recompile if you run it twice without changing the source?
- What is the role of the dependency list (`main: main.c math_ops.c math_ops.h`)?
- Why is `-lm` placed after the source file and not before?
- What does `.PHONY` do, and what goes wrong without it if a file named `clean` exists?
- What happens if you run `make main` with no Makefile?
