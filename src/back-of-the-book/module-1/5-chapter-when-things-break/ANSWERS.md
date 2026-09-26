# Chapter 1.5 — When Things Break — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**A compiler error reads `rectangle.c:6:17`. What does the `17` mean?**
The problem is at column 17 of line 6 — count characters from the start of that line.
`file:line:column` is the compiler's location format, and the column tells you exactly where
on that line to look.

**A wall of ten compiler errors appears after one small edit. What should you do first?**
Fix only the first error, then recompile before reading the rest. An early mistake — a
missing semicolon, an unclosed brace — throws off everything the compiler reads afterward, so
many of the later errors are not real independent mistakes.

**What does `-Werror` actually do?**
It turns every warning the compiler would otherwise print into a hard error that stops
the build. `-Wall -Wextra` turn on the warnings worth seeing; `-Werror` makes sure you cannot
ignore them and get a program anyway.

**You set a breakpoint on a line inside a loop and run the program under a debugger. What
happens?**
The program pauses each time it reaches that line, and `continue` resumes it until the next
time it gets there. Inside a loop, this means one pause per iteration.

**Why does a debugging session need the program compiled with `-g`?**
`-g` embeds line numbers and variable names so the debugger can connect what is happening back
to your source file. Without it, a debugger can still run the program, but it only sees raw
instructions.

**A program writes one slot past the end of a 5-slot heap array, then runs and prints five
correct-looking numbers with no crash. What does this show?**
Writing one slot past the end is undefined behavior — the program may look fine and still have
written to memory it never should have touched. A buffer overflow does not have to crash to be
a real bug.

**AddressSanitizer reports no errors on a particular run of your program. What can you
conclude?**
No bad memory access happened during that particular run — but a path that was not exercised
could still hide a bug. AddressSanitizer only catches an access that actually happens.
