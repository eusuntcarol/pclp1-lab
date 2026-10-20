## Problem Statement

**Retry with exponential backoff**

Clients that cannot reach a server retry, waiting longer after every failure (1 s, 2 s, 4 s, ...), so they do not hammer a server that is struggling. Simulate this with recursion. Do not really wait: just print and add up the delays.

Read two integers from standard input: `max_attempts` and `succeeds_at`. The simulated server answers successfully starting with attempt number `succeeds_at` (earlier attempts fail). `max_attempts` must be at least `1`.

```c
int try_connect(int attempt, int succeeds_at);       // 1 if attempt >= succeeds_at, otherwise 0
int connect_with_retry(int attempt, int max_attempts, int delay, int waited, int succeeds_at);
```

`connect_with_retry` is **recursive**:
- `attempt` is the current attempt (starts at `1`), `delay` is the wait after a failure (starts at `1`), `waited` is the total seconds waited so far (starts at `0`).
- on success: print `Attempt <n>: connected (waited <waited> s in total)` and return `attempt`.
- on failure with attempts left: print `Attempt <n>: failed, retrying in <delay> s`, then retry with the delay doubled (but never more than `30`) and `waited` increased by the delay.
- on failure at the last attempt: print `Attempt <n>: failed, giving up (waited <waited> s in total)` and return `-1`.

`main` returns `0` if connected, `2` if the function gave up, `1` if the input is invalid.

**Constraint:** no loops anywhere. `try_connect` is the only place where the success test is written.

**Examples**

```
$ echo "5 4" | ./main
Attempt 1: failed, retrying in 1 s
Attempt 2: failed, retrying in 2 s
Attempt 3: failed, retrying in 4 s
Attempt 4: connected (waited 7 s in total)
(exit code 0)

$ echo "5 10" | ./main
Attempt 1: failed, retrying in 1 s
Attempt 2: failed, retrying in 2 s
Attempt 3: failed, retrying in 4 s
Attempt 4: failed, retrying in 8 s
Attempt 5: failed, giving up (waited 15 s in total)
(exit code 2)

$ echo "8 100" | ./main
Attempt 1: failed, retrying in 1 s
Attempt 2: failed, retrying in 2 s
Attempt 3: failed, retrying in 4 s
Attempt 4: failed, retrying in 8 s
Attempt 5: failed, retrying in 16 s
Attempt 6: failed, retrying in 30 s
Attempt 7: failed, retrying in 30 s
Attempt 8: failed, giving up (waited 91 s in total)
(exit code 2)

$ echo "0 1" | ./main
Error: max_attempts must be at least 1
(exit code 1)
```

**Hints**
- There are **two** base cases: the connection works, or there are no attempts left.
- The recursive call changes three arguments: `attempt + 1`, a doubled `delay` (capped), and `waited + delay`.
- Cap with a small `if`: `next_delay = delay * 2; if (next_delay > 30) next_delay = 30;`.
- The `waited` value printed at the end is the total of the delays of the failed attempts before.

## Questions to verify knowledge
- Which two conditions stop the recursion? Which one is checked first and why?
- What is the purpose of the `waited` accumulator? How would you do it without it and without global variables?
- How deep can the recursion get? Is stack overflow a risk here?
- Why do real clients add **jitter** (a random part) to the delay?
- Why is capping the delay useful?
