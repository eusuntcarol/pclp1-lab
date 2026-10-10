## Problem Statement

**HTTP status classifier**

A web server log contains HTTP status codes. Read one status code (an integer) and print what it means.

Known codes get their own message:

| Code | Message |
|---|---|
| 200 | `OK` |
| 301 | `Moved Permanently` |
| 403 | `Forbidden` |
| 404 | `Not Found` |
| 500 | `Internal Server Error` |

Any other code is classified by its first digit:

| Range | Message |
|---|---|
| 2xx | `Success` |
| 3xx | `Redirection` |
| 4xx | `Client error` |
| 5xx | `Server error` |

Anything else (below 200 or above 599): print `Unknown` and return code `1`.

**Constraint:** use `switch` for both steps (no `if`).

**Examples**

```
404  ->  Not Found
200  ->  OK
503  ->  Server error
418  ->  Client error
302  ->  Redirection
99   ->  Unknown      (exit code 1)
```

**Hints**
- A `switch` compares one integer with constants, it can't test a range like `400..499`.
- `code / 100` turns `404` into `4`, so you can `switch` again on the class.
- Several `case` labels can share one block.

## Questions to verify knowledge
- What happens if you forget a `break` at the end of a `case`?
- What does `default` do and where can it be placed?
- What is `404 / 100` in integer arithmetic? What would it be with `double`?
- Why can't a `case` label be a variable?
