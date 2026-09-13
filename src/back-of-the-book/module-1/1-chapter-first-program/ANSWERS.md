# Chapter 1.1 — Your First Program, Line by Line — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**What does `#include <stdio.h>` do?**
It tells the compiler about functions like `printf`, defined elsewhere, before it reads the
rest of your file. `stdio.h` stands for standard input/output. Without this line the
compiler has never heard of `printf` and refuses to compile.

**Why does `main` need to exist in every C program?**
It is the one function the operating system looks for and runs first. Nothing in your code
calls `main` — the operating system does, which is why every C program needs exactly one.

**Inside `printf("Hi\n");`, what does `\n` do?**
It moves output to a new line and does not appear in the printed text itself. `\n` is an
escape sequence — a backslash plus a letter meaning something other than the letter itself.

**A program is missing the closing `"` on one of its string literals, part-way through. What
happens?**
The compiler keeps reading the rest of the file as if it were part of that string. The error
it reports often points somewhere far from the real mistake.

**What does `return 0;` at the end of `main` communicate?**
The program ran successfully — this is the exit status the operating system reads. By
convention, `0` means everything worked; any other number signals something went wrong.
