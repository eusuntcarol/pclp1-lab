## Problem Statement

**CTF Flag Processor**

In Capture The Flag (CTF) competitions, participants solve challenges (usually security-related) in order to "capture" a hidden string called a **flag**. A flag usually looks like `CTF_IDENTIFIER`. Once a participant finds a flag, they must submit it to the platform, which validates it.

In this exercise we build a simplified flag processor, to practice formatted input with `scanf` descriptors. For simplicity, we only use natural numbers: instead of the string `CTF`, the header is encoded as `101`. A valid flag therefore looks like `101_ID`, where `ID` is a natural number (e.g. `101_48213`).

**Task**

1. Read a non-negative natural number `expectedId`: the identifier the platform expects.
2. Read the submitted flag using **a single `scanf` call**: read the header `101`, match the literal `_` separator, then read the identifier. A flag with another separator, such as `101-48213`, is invalid.
3. If the header is `101` **and** the identifier equals `expectedId`, print `Valid flag!` and return code `0`. Otherwise print `Invalid flag!` and return code `1`.
4. Extend the task in order to accept a bigger integer as identifier.

**Examples**

```
48213
101_48213   -> Valid flag!     (exit code 0)

48213
101_99      -> Invalid flag!   (exit code 1) - wrong identifier

48213
102_48213   -> Invalid flag!   (exit code 1) - wrong header

48213
10148213    -> Invalid flag!   (exit code 1) - missing separator
```

## Questions to verify knowledge
- Which descriptor field lets you read a value without storing it?
- Which descriptor limits how many characters are read for the header?
- Which modifier do you need for large identifiers?
- What does `scanf` return, and why should you check it?
