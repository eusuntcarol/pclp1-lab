## Problem Statement

**PIN lockout**

Read a secret PIN, then read up to three guesses. For each wrong guess print `Attempt k of 3 failed`. Stop immediately on a correct guess and print `Access granted`. If all three guesses are wrong, print `Account locked`.

The secret PIN and every guess are unsigned integers. If any required `scanf` call fails, print `Error: invalid input` and return code `1`.

Use a `for` loop, store and check the return value of `scanf`, and use `break` after a successful guess.

**Examples**

Input lines are marked with `>` below; the other lines are program output.

```text
$ ./main
> 4821
> 1234
Attempt 1 of 3 failed
> 4821
Access granted
```

```text
$ ./main
> 4821
> 1111
Attempt 1 of 3 failed
> 2222
Attempt 2 of 3 failed
> 3333
Attempt 3 of 3 failed
Account locked
```

**Hints**

- Check the secret PIN before entering the loop.
- The loop index can produce attempt numbers `1`, `2`, and `3`.
- Use `break` so a correct guess does not consume another attempt.

## Questions to verify knowledge

- Why does the loop stop after a correct guess?
- What should happen if the input ends before all guesses are read?
- What is the difference between `break` and `continue`?
