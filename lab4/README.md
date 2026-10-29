# Lab 4

Topics: arrays (vectors and matrices), frequency vectors, searching (linear, binary), sorting (selection, bubble), merging, matrix operations.

The goal is to learn the concepts and to practice syntax, not to solve all exercises.

Rules for this lab:
- Static arrays only, with the maximum size given by a `#define` (`NMAX`). No `malloc` and no pointer syntax yet (they come in later labs).
- One operation = one function. Every exercise gives you the prototypes. Implement them and use them from `main`.
- Reuse what you already wrote: copy a working `read_array` / `print_array` from an earlier exercise instead of rewriting it.
- Always check the size read from the input against `NMAX` before using the array.

Please have a separate file open where you write down notes on your progress:
- exercises solved for each section (e.g. 2.03 for exercise 3 of section 2)
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
| [1-arrays](1-arrays/) | 01 | [sensor-readings](1-arrays/01-sensor-readings.md) | Easy | `read_array`, `print_array`, `NMAX` check |
| [1-arrays](1-arrays/) | 02 | [sensor-report](1-arrays/02-sensor-report.md) | Easy | sum, min, position of max, average, reusing functions |
| [1-arrays](1-arrays/) | 03 | [status-histogram](1-arrays/03-status-histogram.md) | Medium | frequency vector, `= {0}` initialization |
| [1-arrays](1-arrays/) | 04 | [ring-buffer](1-arrays/04-ring-buffer.md) | Medium | shifting elements, changing an array inside a function |
| [1-arrays](1-arrays/) | 05 | [spike-detector](1-arrays/05-spike-detector.md) | Hard | sliding window, index ranges, exit codes |
| [1-arrays](1-arrays/) | 06 | [caesar-breaker](1-arrays/06-caesar-breaker.md) | Hard | `char` arrays, letter frequency, `%` wrap-around |
| [2-search-sort](2-search-sort/) | 01 | [port-blocklist](2-search-sort/01-port-blocklist.md) | Easy | linear search, `-1` for not found |
| [2-search-sort](2-search-sort/) | 02 | [leaderboard](2-search-sort/02-leaderboard.md) | Medium | selection sort, swap |
| [2-search-sort](2-search-sort/) | 03 | [user-lookup](2-search-sort/03-user-lookup.md) | Medium | binary search, counting comparisons |
| [2-search-sort](2-search-sort/) | 04 | [merge-logs](2-search-sort/04-merge-logs.md) | Hard | merging two sorted arrays, three indexes |
| [3-matrices](3-matrices/) | 01 | [rotate-image](3-matrices/01-rotate-image.md) | Easy | read/print matrix, transpose |
| [3-matrices](3-matrices/) | 02 | [motion-detector](3-matrices/02-motion-detector.md) | Medium | matrix addition and subtraction |
| [3-matrices](3-matrices/) | 03 | [route-counter](3-matrices/03-route-counter.md) | Medium | matrix multiplication, aliasing |
| [3-matrices](3-matrices/) | 04 | [k-hop-routes](3-matrices/04-k-hop-routes.md) | Hard (bonus) | matrix power, reusing `multiply_matrix` |

## Compiling and running

Each exercise is a written specification.
Create a dedicated directory for each exercise and a `main.c` beside. Compile with:

```sh
gcc -Wall -Wextra main.c -o main
```

Run it and type the input. For exercises that read "until the input ends", finish with `Ctrl+D` (Linux/macOS) or `Ctrl+Z` then Enter (Windows).

`echo $?` prints the exit code of the last command.
