## Problem Statement

**Password strength meter**

Sign-up forms rate the password you type. Write a program that reads one password (one line from standard input) and prints its strength.

Read the line character by character with `getchar` until a newline or the end of the input. Do not use `<ctype.h>`: write the character tests yourself.

```c
int is_lower(int c);       // 'a'..'z'
int is_upper(int c);       // 'A'..'Z'
int is_digit(int c);       // '0'..'9'
int is_symbol(int c);      // any other printable ASCII character, codes 33..126
int score(int length, int has_lower, int has_upper, int has_digit, int has_symbol);
void print_verdict(int points);
```

Scoring rules for `score`:
- if `length < 8` the score is `0` (return immediately)
- otherwise `+1` for each character class present (lower, upper, digit, symbol)
- `+1` more if `length >= 12`

So the score is in [0, 5].

`print_verdict` prints the verdict with a `switch`:

| Score | Verdict |
|---|---|
| 0 | `Rejected` |
| 1, 2 | `Weak` |
| 3 | `Medium` |
| 4, 5 | `Strong` |

Output format:

```
Length: <length>
Score: <score>
Verdict: <verdict>
```

**Examples**

```
$ echo "hunter2" | ./main
Length: 7
Score: 0
Verdict: Rejected

$ echo "password1" | ./main
Length: 9
Score: 2
Verdict: Weak

$ echo "Passw0rd!" | ./main
Length: 9
Score: 4
Verdict: Strong

$ echo "correct-horse-battery" | ./main
Length: 21
Score: 3
Verdict: Medium

$ echo "" | ./main
Length: 0
Score: 0
Verdict: Rejected
```

**Hints**
- The loop:
```c
int c;
while ((c = getchar()) != EOF && c != '\n') {
    /* use c */
}
```
- Keep four flags in `main` (`has_lower`, ...) set to `0`. Set one to `1` when the matching function returns true.
- Character constants compare directly: `c >= 'a' && c <= 'z'`.
- In `score`, the early `return 0;` for short passwords avoids nested `if`s.
- Combine the pieces: `main` counts and sets flags, `score` decides, `print_verdict` shows.

## Questions to verify knowledge
- Why is `c` an `int` and not a `char`?
- What is the numeric value of `'a'`? Why does `c >= 'a' && c <= 'z'` work?
- What does an early `return` buy you compared with nested `if`/`else`?
- Why is a long passphrase like `correct-horse-battery` scored like this, and is it a good password? How do real systems judge passwords (entropy, breached-password lists)?
- Why is a length check done before counting character classes?
