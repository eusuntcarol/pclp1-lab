## Problem Statement

**IPv4 network address**

An IPv4 address is a 32-bit number, written as four 8-bit numbers (**octets**) separated by dots: `a.b.c.d`. The **prefix length** `/n` says how many of the leftmost bits identify the network. The remaining bits identify the host inside that network.

To get the **network address**, we keep the first `n` bits of the address and set all other bits to `0`. This is done with a bitwise AND between the address and a **mask** that has `n` leading ones.

Worked example for `192.168.10.77/26`:

```
192.168.10.77  =  11000000.10101000.00001010.01001101   (address)
mask /26       =  11111111.11111111.11111111.11000000   (26 ones, then 6 zeros)
                  ----------------------------------- AND
                  11000000.10101000.00001010.01000000
               =  192.168.10.64                         (network address)
```

Only the last octet changed: `01001101 & 11000000 = 01000000 = 64`.

**Task**

Read an address and a prefix length in the exact format `a.b.c.d/n` (this is called **CIDR notation**). Print the network address in CIDR notation: the computed address, followed by `/n`.

**How to approach it**

1. Read the five integers with a single `scanf`. The `.` and `/` are written literally in the format, so they must match the input exactly.
2. Pack the four octets into **one 32-bit number**. Which data type fits best? Does the sign matter when you shift and negate?
3. Build the mask, apply it, then print the result octet by octet.
4. Some values appear several times in your code (the number of bits in an address). Which one could get a name with `#define`?

No loops, arrays or functions are needed.

**Errors:** return the code as described in the table

| Code | Condition |
|---|---|
| 1 | an octet is not in [0, 255] |
| 2 | prefix not in [1, 32] |

Check the octets first, then the prefix.

**Examples**

```
192.168.10.77/26  -> 192.168.10.64/26
10.0.0.5/8        -> 10.0.0.0/8
1.2.3.4/32        -> 1.2.3.4/32
172.16.99.200/20  -> 172.16.96.0/20
```

**Hints**
- Packing: `ip = (a << 24) | (b << 16) | (c << 8) | d`. Each octet is moved to its position, then the pieces are merged with `|`.
- To extract an octet from a packed number, shift it to the right end and keep the last 8 bits with `& 255`.
- The mask is `~0u << (32 - n)`.

## Questions to verify knowledge
- Why `unsigned` and not `int` for the packed address? (think about `a << 24` and `>>`)
- Why does `~0u << (32 - n)` give exactly `n` leading ones?
- What does `ip & mask` keep, and what does it clear?
- How do you extract the second octet of a packed number?
