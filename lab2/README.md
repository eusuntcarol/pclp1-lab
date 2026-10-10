# Lab 2

The goal is to learn the concepts and to practice syntax, not to solve all exercises.

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

| Section | # | Exercise | Difficulty |
|---|---:|---|---|
| [1-io](1-io/) | 01 | [basic-io](1-io/01-basic-io.md) | Easy |
| [1-io](1-io/) | 02 | [colors](1-io/02-colors.md) | Easy |
| [1-io](1-io/) | 03 | [ctf-flag](1-io/03-ctf-flag.md) | Medium |
| [1-io](1-io/) | 04 | [time-difference](1-io/04-time-difference.md) | Medium |
| [2-types-operators](2-types-operators/) | 01 | [data-sizes](2-types-operators/01-data-sizes.md) | Easy |
| [2-types-operators](2-types-operators/) | 02 | [storage-units](2-types-operators/02-storage-units.md) | Easy |
| [2-types-operators](2-types-operators/) | 03 | [unix-permissions](2-types-operators/03-unix-permissions.md) | Medium |
| [2-types-operators](2-types-operators/) | 04 | [ipv4-network](2-types-operators/04-ipv4-network.md) | Hard |
| [3-control-flow](3-control-flow/) | 01 | [http-status](3-control-flow/01-http-status.md) | Easy |
| [3-control-flow](3-control-flow/) | 02 | [pin-lockout](3-control-flow/02-pin-lockout.md) | Easy |
| [3-control-flow](3-control-flow/) | 03 | [grading-hamming](3-control-flow/03-grading-hamming.md) | Hard |
| [4-math-random-time](4-math-random-time/) | 01 | [cube](4-math-random-time/01-cube.md) | Easy |
| [4-math-random-time](4-math-random-time/) | 02 | [sensor-calibration](4-math-random-time/02-sensor-calibration.md) | Easy |
| [4-math-random-time](4-math-random-time/) | 03 | [pin-generator](4-math-random-time/03-pin-generator.md) | Medium |
| [4-math-random-time](4-math-random-time/) | 04 | [measure-million](4-math-random-time/04-measure-million.md) | Easy |
| [4-math-random-time](4-math-random-time/) | 05 | [pin-brute-force](4-math-random-time/05-pin-brute-force.md) | Medium |
| [5-infrastructure](5-infrastructure/) | 01 | [splitting-files](5-infrastructure/01-splitting-files.md) | Medium |
| [5-infrastructure](5-infrastructure/) | 02 | [makefile](5-infrastructure/02-makefile.md) | Medium |

## Compiling and running

Each exercise is a written specification.
Create a dedicated directory for each exercise and a `main.c` beside. Compile with:

```sh
gcc -Wall -Wextra main.c -o main
```

Add `-lm` for exercises using `math.h`.

Shortcut to not type input every time: `echo 42 | ./main` feeds `42` to standard input.
