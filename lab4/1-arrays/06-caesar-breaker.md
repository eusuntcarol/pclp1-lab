## Problem Statement

**Caesar cipher breaker**

The Caesar cipher shifts every letter of a message by the same number of positions in the alphabet. With shift `3`: `a -> d`, `b -> e`, ..., `x -> a`, `y -> b`, `z -> c`. There are only 26 possible shifts, and there is an even faster attack: in English text the most frequent letter is almost always `e`. Count the letters of the encrypted message, find the most frequent one, and you know which letter `e` became, so you know the shift.

Write a program that breaks a Caesar-encrypted message this way.

The message has lowercase letters and spaces and **ends with a `.`** (the `.` is not part of the message). It has at most `MAXLEN` characters (`#define MAXLEN 1000`).

```c
int read_message(char msg[]);                          // reads characters until '.', returns how many, or -1 if more than MAXLEN
void count_letters(int len, char msg[], int count[]);  // count[0] = number of 'a', ..., count[25] = number of 'z'
int most_frequent(int count[]);                        // index 0..25 of the largest count (the first, on a tie)
char decrypt_letter(char c, int shift);                // shifts a letter back; anything else is returned unchanged
```

Print:

```
Most frequent letter: <letter> (<count> times)
Shift: <shift>
Decrypted: <message>
```

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the message has no letters, or it is longer than `MAXLEN` |

**Constraint:** one frequency vector `int count[26] = {0};`. No `if` or `switch` per letter.

**Examples**

```
$ ./main
phhw wkh uhg whdp qhdu wkh vhuyhu urrp dw hohyhq.
Most frequent letter: h (12 times)
Shift: 3
Decrypted: meet the red team near the server room at eleven

$ ./main
aol ihjrbw rlfz hyl opkklu bukly aol klzr.
Most frequent letter: l (7 times)
Shift: 7
Decrypted: the backup keys are hidden under the desk

$ ./main
123 !!.
Error: no letters
(exit code 1)
```

The method can fail on short messages, where `e` is not the most frequent letter:

```
$ ./main
xytu fy stts.
Most frequent letter: t (3 times)
Shift: 15
Decrypted: ijef qj deed
```

**Hints**
- A `char` is a small number: `'a'` is 97, `'b'` is 98, ... So `c - 'a'` is the position of a letter (0 to 25), and `count[c - 'a']++` counts it.
- Read with `scanf("%c", &c)` **without** a space before `%c`, to keep the spaces of the message. Stop at `'.'`.
- The shift is how far `e` moved: `(top - ('e' - 'a') + 26) % 26`, where `top` is the index of the most frequent letter.
- Decrypting one letter: `(c - 'a' - shift + 26) % 26 + 'a'`. The `+ 26` keeps the value positive before `%`.
- Skip the `'\n'` characters when printing the message.

## Questions to verify knowledge
- What is `count['h' - 'a']`? Which element of the array is it?
- Why is `+ 26` needed before `% 26`? What is `-3 % 26` in C?
- Why does `" %c"` (with a space) not work here?
- Why did the attack fail on `xytu fy stts`? How could you make it more reliable (hint: compare the whole frequency vector with the usual English frequencies)?
- How many shifts would a brute-force attack try? Why is the Caesar cipher useless for real security?
