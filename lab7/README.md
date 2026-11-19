# Lab 7 — Strings

Compile (all exercises and demos):

```
gcc -Wall -Wextra main.c -o main
./main
```

While testing, also compile with the address sanitizer. It catches reads and writes past the end of a string:

```
gcc -Wall -Wextra -g -fsanitize=address main.c -o main
```

There is no starting code, except for the bug hunt. For each exercise, create a directory named after it, with a `main.c` inside (e.g. `1-basics/2-progress-bar/main.c`). Write the answers to the questions as comments at the end of the file.

Sections:

1. [1-basics](1-basics/README.md) — characters, the `'\0'` terminator, building a string by hand, bug hunt
2. [2-my-string](2-my-string/README.md) — write your own `strlen`, `strcpy`, `strcmp`, `strstr`, `strtok`
3. [3-applications](3-applications/README.md) — file permissions, IP addresses, a list of usernames

Rules from previous labs still apply: no variable array sizes (`#define NMAX`), initialize pointers when you declare them, check what `malloc` returns, `free` what you allocate.

---

## 1. Characters

A `char` is a small integer (1 byte). The character you see is just how that number is printed. The mapping is the **ASCII** table:

| char | `'0'` | `'9'` | `'A'` | `'Z'` | `'a'` | `'z'` | `' '` | `'\n'` | `'\0'` |
|---|---|---|---|---|---|---|---|---|---|
| code | 48 | 57 | 65 | 90 | 97 | 122 | 32 | 10 | 0 |

Because they are numbers, you can do arithmetic with them:

```c
char c = 'A';
printf("%c %d\n", c, c);      // A 65
printf("%c\n", c + 2);        // C
printf("%d\n", '7' - '0');    // 7   (digit character -> its value)
printf("%c\n", 'a' + ('Q' - 'A'));  // q   (upper -> lower, by hand)
```

`'a'` is one character. `"a"` is a string of two characters: `'a'` and `'\0'`.

`ctype.h` has ready-made tests and conversions. They take and return `int`:

| function | true / result for |
|---|---|
| `isdigit(c)` | `'0'`...`'9'` |
| `isalpha(c)` | letters |
| `isalnum(c)` | letters or digits |
| `isspace(c)` | `' '`, `'\t'`, `'\n'`, ... |
| `isupper(c)`, `islower(c)` | upper / lower case letters |
| `toupper(c)`, `tolower(c)` | the converted letter (other characters are returned unchanged) |

## 2. What a string is

C has no string type. A string is **an array of `char` that ends with `'\0'`** (the byte with value 0). Every string function walks the array until it finds that `'\0'`.

```c
#define NMAX 16
char s[NMAX] = "hello";
```

| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 ... 15 |
|---|---|---|---|---|---|---|---|
| `s[i]` | `'h'` | `'e'` | `'l'` | `'l'` | `'o'` | `'\0'` | `'\0'` |

- `sizeof(s)` is 16: the size of the array.
- `strlen(s)` is 5: the number of characters before the first `'\0'`.
- A string of length `n` needs **`n + 1` bytes**. Forgetting the `+ 1` is the most common string bug.
- If `'\0'` is missing, functions keep reading past the end of the array, into whatever memory follows.

### Array vs. pointer to a literal

```c
char s[] = "hello";          // array of 6 chars, a copy you own: s[0] = 'H' is fine
const char *p = "hello";     // pointer to a string literal, which is read-only
```

String literals live in read-only memory. Writing into one (`p[0] = 'H'` without the `const`) compiles, but crashes or misbehaves at run time. Always point to literals with `const char *`, so the compiler stops you.

## 3. `const char *`

`const` applies to what is on its left, or, if nothing is on its left, to what is on its right. Read the declaration from right to left:

| declaration | read as | `p = q;` | `*p = 'x';` |
|---|---|---|---|
| `const char *p` | pointer to const char | ✅ | ❌ |
| `char * const p` | const pointer to char | ❌ | ✅ |
| `const char * const p` | const pointer to const char | ❌ | ❌ |

All of `string.h` takes input strings as `const char *`. It is a promise: *this function only reads your string*. The compiler checks the promise, and it lets you pass literals. The same goes for `const int *v` in lab6: the function only reads the array.

```c
size_t my_len(const char *s)
{
	const char *p = s;

	while (*p != '\0')
		p++;          // OK: the pointer moves
	// *p = 'x';      // error: the characters are const
	return p - s;
}
```

## 4. Reading and printing strings

```c
char name[NMAX];
char line[NMAX];

printf("%s\n", name);              // prints until '\0'

scanf("%15s", name);               // one word: stops at a space / newline
                                   // no &: name is already an address
                                   // 15 = NMAX - 1, leaves room for '\0'

fgets(line, NMAX, stdin);          // a whole line, spaces included
line[strcspn(line, "\n")] = '\0';  // fgets keeps the '\n': remove it
```

- `scanf("%s")` without a width writes past the end of the array if the word is too long. Always give the width.
- `fgets` reads at most `NMAX - 1` characters, always adds `'\0'`, and returns `NULL` when there is no more input.
- Do not mix them. `scanf("%d")` leaves the `'\n'` in the input, and the next `fgets` reads it as an empty line. Pick one style per program.
- Never use `gets`. It was removed from the language because it cannot be used safely.

## 5. `string.h`

| function | what it does | watch out |
|---|---|---|
| `strlen(s)` | number of chars before `'\0'` | it walks the whole string every call: don't put it in a loop condition |
| `strcpy(dst, src)` | copies `src` (with `'\0'`) into `dst` | `dst` must be big enough; nobody checks |
| `strncpy(dst, src, n)` | copies at most `n` chars | if `src` is longer, **no `'\0'`** is added |
| `strcat(dst, src)` | appends `src` at the end of `dst` | `dst` must have room for both |
| `strcmp(a, b)` | `< 0`, `0`, `> 0` (alphabetical order) | only the **sign** is guaranteed, not -1 / 1; `a == b` compares addresses, not text |
| `strncmp(a, b, n)` | compares the first `n` chars | |
| `strchr(s, c)` | pointer to the first `c` in `s`, or `NULL` | |
| `strrchr(s, c)` | pointer to the last `c` in `s`, or `NULL` | |
| `strstr(s, t)` | pointer to the first occurrence of `t` in `s`, or `NULL` | |
| `strcspn(s, set)` | length of the prefix of `s` with no char from `set` | |
| `strtok(s, delim)` | splits `s` into tokens | **modifies `s`**; see below |

Functions that search return a pointer **into the same string**. The position is a pointer difference:

```c
const char *s = "banana";
const char *p = strstr(s, "nan");
if (p != NULL)
	printf("found at %d\n", (int)(p - s));   // found at 2
```

### `strtok`

```c
char s[] = "red,green,,blue";
char *tok = strtok(s, ",");       // first call: the string
while (tok != NULL) {
	printf("[%s]\n", tok);        // [red] [green] [blue]
	tok = strtok(NULL, ",");      // next calls: NULL = "continue where you stopped"
}
```

- It writes `'\0'` over each delimiter, so the original string is destroyed. Never call it on a literal.
- Several delimiters in a row count as one: empty fields are skipped.
- It remembers where it stopped in a hidden `static` variable. That is why the next calls take `NULL`, and why you cannot split two strings at the same time. You will write it yourself in [2-my-string](2-my-string/README.md).

## 6. Converting between strings and numbers

```c
int x = atoi("42");                 // 42 (stdlib.h)
int y = atoi("abc");                // 0: atoi does not report errors
                                    // check with isdigit that the string has only digits first

int a, b;
int n = sscanf("12:34", "%d:%d", &a, &b);   // scanf from a string; n = fields read (2)

char buf[NMAX];
snprintf(buf, sizeof(buf), "%d%%", 75);     // printf into a string: "75%"
                                            // never writes more than sizeof(buf)
```

## 7. Strings on the heap

A copy that must outlive the function that creates it goes on the heap:

```c
char *copy_string(const char *s)
{
	char *c = malloc(strlen(s) + 1);   // + 1 for '\0'

	if (c == NULL)
		return NULL;
	strcpy(c, s);
	return c;
}
```

Memory from `malloc` is **not** freed when the function returns. Whoever receives the pointer owns the block and must call `free` on it, exactly once. Here, that is the caller of `copy_string`.

## 8. Common mistakes

- Missing `'\0'`: building a string by hand and forgetting to terminate it, or `strncpy` on a long source.
- No room for `'\0'`: `char s[5] = "hello";` compiles, but `s` is not a string.
- `malloc(strlen(s))` instead of `malloc(strlen(s) + 1)`.
- `if (s == "yes")` compares addresses. Use `strcmp(s, "yes") == 0`.
- Writing into a string literal.
- `sizeof(p)` on a `char *` is the size of the pointer (8), not the length of the string.
- `scanf("%s")` without a width.

## Demos

Complete programs in [demos/](demos/). Compile and run them, then change them.

| demo | shows |
|---|---|
| `1-terminator.c` | `sizeof` vs `strlen`; cutting a string with `'\0'` |
| `2-reading.c` | `fgets` keeps the `'\n'`; removing it |
| `3-string-h.c` | `strcpy`, `strcat`, `strlen`, `strcmp` |
| `4-strtok.c` | splitting a string into tokens |
| `5-payload.c` | a message hidden in an `int` array: chars are 1-byte numbers |
