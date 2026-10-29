## Problem Statement

**Port blocklist**

A simple firewall keeps a list of blocked ports. For every incoming connection it checks whether the destination port is in the list.

Read the blocklist with `read_array` (from section 1): `n`, then `n` ports. Then read the ports of incoming connections until the input ends. For each one print whether it is blocked, and by which rule (its index in the blocklist).

```c
int find_array(int n, int v[], int x);   // index of the first x in v, or -1 if x is not in v
```

Print `<port>: blocked (rule #<index>)` or `<port>: allowed`. At the end print `Blocked: <count>`.

**Errors** (print a message on the screen and return the code):

| Code | Condition |
|---|---|
| 1 | the blocklist is invalid (same rules as `read_array`) |

**Constraint:** linear search, from left to right, stopping at the first match.

**Examples**

```
$ ./main
5
23 445 3389 21 135
443 22 3389 80 23
<Ctrl+D>
443: allowed
22: allowed
3389: blocked (rule #2)
80: allowed
23: blocked (rule #0)
Blocked: 2
```

Test `find_array` on its own too, with `v = {10, 30, -1, 4, 5}`, `n = 5`:

```c
find_array(n, v, 30);   // 1
find_array(n, v, 4);    // 3
find_array(n, v, 13);   // -1
```

**Hints**
- `return i;` inside the loop stops the search at the first match.
- `return -1;` goes **after** the loop: only when every element was checked.
- `-1` is used for "not found" because it can never be a valid index.

## Questions to verify knowledge
- Why is `-1` a good "not found" value? Would `0` work?
- How many comparisons does `find_array` make for a port that is not in a list of 1000 rules?
- What changes if the same port appears twice in the blocklist?
- If the blocklist were sorted, which faster search could you use? (See exercise 03.)
- Ports 23, 445, 3389, 21, 135 are often blocked. Which services use them?
