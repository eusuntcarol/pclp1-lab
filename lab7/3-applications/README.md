# 3. Applications

You may use `string.h` and `ctype.h` from here on.

## 1. File permissions

On Linux, `ls -l` shows file permissions as 9 characters: read, write, execute for the owner, the group and everyone else. `chmod` uses the same permissions written as 3 octal digits, one per group, where `r` = 4, `w` = 2, `x` = 1:

```
rwx r-x ---
 7   5   0      ->  chmod 750 file
```

Write two functions:

```c
int perm_to_octal(const char *perm, char *octal);  /* "rwxr-x---" -> "750" */
int octal_to_perm(const char *octal, char *perm);  /* "644" -> "rw-r--r--" */
```

Both return 1 on success and 0 if the input is invalid:

- a permission string has exactly 9 characters, and position `i` is either `'-'` or the letter `"rwx"[i % 3]`;
- an octal string has exactly 3 characters, each from `'0'` to `'7'`.

In `main`, read words (`scanf("%15s")`) until `end`. A word of length 9 is converted to octal, anything else to a permission string.

```
> rwxr-x---
750
> 644
rw-r--r--
> 755
rwxr-xr-x
> rw-r--r-x
645
> rwz------
invalid
> 812
invalid
> end
```

Questions:

- How many bytes must the `perm` and `octal` arrays have?
- Convert between a digit character and its value without a lookup table or `switch`. What expression do you use in each direction?

## 2. IP addresses

An IPv4 address is 4 numbers from 0 to 255, separated by dots: `192.168.1.10`. Write:

```c
int parse_ip(const char *s, int parts[4]);   /* returns 1 if s is a valid address */
```

`s` is valid only if it has exactly 4 parts, each part is not empty, has only digits, and is at most 255.

If you use `strtok`, remember it modifies the string, but `s` is `const`. Work on a copy.

Then classify the address:

| range | type |
|---|---|
| `127.x.x.x` | loopback (your own machine) |
| `10.x.x.x`, `172.16.x.x` to `172.31.x.x`, `192.168.x.x` | private (home and office networks) |
| anything else | public |

In `main`, read addresses until `end`:

```
> 192.168.1.10
valid, private
> 8.8.8.8
valid, public
> 127.0.0.1
valid, loopback
> 172.20.0.5
valid, private
> 172.32.0.5
valid, public
> 256.1.1.1
invalid
> 1.2.3
invalid
> 1.2.3.a
invalid
> 1..2.3.4
invalid
> 1.2.3.4.
invalid
> end
```

Questions:

- `strtok` alone accepts the last two examples. Why? How did you reject them?
- Why is `strtol` with `end` safer than `atoi` here?

Bonus: computers store the address as one 32-bit number: `a * 256^3 + b * 256^2 + c * 256 + d`. Print it for each valid address (`192.168.1.10` is `3232235786`). Use `unsigned int`, and explain why `int` is not enough.

## 3. Usernames

A sign-up form receives usernames typed by people, with stray spaces and random capitals. Read lines with `fgets` until an empty line, and for each one:

1. Remove the `'\n'` and the spaces at both ends, in place: `void trim(char *s);`
2. Convert it to lower case.
3. If it contains anything other than letters, digits, `.` and `_`, print `rejected` and skip it.
4. If it is already in the list, print `duplicate` and skip it.
5. Otherwise, store a copy on the heap: `char *copy_string(const char *s);` (see theory, section 7). Keep the copies in `char *users[NUSERS];`.

At the end, sort the list with `qsort` and print it. Then free everything.

`qsort` passes your comparator a pointer **to an element**. The elements are `char *`, so you receive `char **`, hidden behind `const void *`:

```c
int cmp_users(const void *a, const void *b)
{
	const char *x = *(const char * const *)a;
	const char *y = *(const char * const *)b;

	return strcmp(x, y);
}
```

```
user:   Ana.Popescu
user: ion_ionescu
user: ANA.POPESCU
  duplicate: ana.popescu
user: bad name!
  rejected: bad name!
user:   mihai99
user:

3 users:
ana.popescu
ion_ionescu
mihai99
```

Questions:

- Instead of `copy_string`, try `users[n] = line;`. What does the list look like at the end, and why?
- Who frees each string, and when?
- Why doesn't the comparator work as `strcmp((const char *)a, (const char *)b)`?
