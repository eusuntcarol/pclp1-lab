## Problem Statement

**Grading system**

We want to build a grading system based on the **Hamming distance**. The Hamming distance between two numbers is the number of bit positions where their binary representations differ.

We suppose we have a multiple-answer quiz with 3 possible choices, resulting in 7 possible combinations. The student might select any sub-set of answers. We will use the following combinations:
| Choice | Encoding | Binary |
| --- | --- | --- |
| a | 1 | `0b001` |
| b | 2 | `0b010` |
| c | 4 | `0b100` |
| a, b | calculate :) | `a\|b` |
| a, c | calculate :) | `a\|c` |
| b, c | calculate :) | `b\|c` |
| a, b, c | calculate :) | `a\|b\|c` |

Tasks:
1. Complete the above table with the correct encodings.
1. Write a C program that calculates the score using the formula: `score = 3 - hamming_distance(answer)`. The score should be printed on screen.
1. Extend this to use a variable number of answers (not limited to only 3).

**Examples**

```
1 1    -> score 3/3     (001 vs 001, given answer a, expected answer a, hamming distance 0)
1 2    -> score 1/3     (001 vs 010, given answer a, expected answer b, hamming distance 2)
2 5    -> score 0/3     (010 vs 101, given answer b, expected answer a,c, hamming distance 3)
```

**Hints**
- Which operator marks the differing bits? See the `^` entry in the operator table.
- Once you have a number whose `1` bits are the differences, inspect its least significant bit with `& 1`.
- Repeatedly shift the difference value right in a `while` loop until it becomes zero, counting every set bit.
- For the extension, read an unsigned `number_of_answers` first, followed by `answer` and `expected_answer`. The score is `number_of_answers - hamming_distance`.

## Questions to verify knowledge
- What does `n >> 1` do to the binary representation of `n`?
- Why does the loop terminate? What is `n` after enough shifts?
- Why use `unsigned` here, and what could go wrong with a negative `n` and `>>`?
- Why is the score based on the number of answers?
