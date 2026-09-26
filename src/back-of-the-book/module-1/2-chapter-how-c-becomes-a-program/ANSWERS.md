# Chapter 1.2 — How C Becomes a Program — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**Which stage runs first, and what does it work with?**
The preprocessor, working with plain text. It runs first and only understands lines
starting with `#`. It substitutes text — pasting in headers, swapping macro names for their
value — and never checks a single C rule.

**`#define CRATE_SIDE 4` is used in a program. What is `CRATE_SIDE` by the time the program
is running?**
Nothing — the preprocessor already replaced every `CRATE_SIDE` with the literal digit `4`,
before the compiler even started. By the time the program runs, the name `CRATE_SIDE` never
existed as far as it's concerned.

**`#define SQUARE(x) x * x` (missing parentheses) is used as `SQUARE(3 + 4)`. What goes
wrong?**
It expands to `3 + 4 * 3 + 4`, which evaluates to 19, not the 49 you wanted. The
preprocessor pastes in the raw text `3 + 4` wherever `x` appeared. This is why every
parameter — and the whole expression — needs its own parentheses: `((x) * (x))`.

**You misspell `printf` as `prntf`. Which stage produces the error, and why?**
Compile. By the time compiling starts, the preprocessor has already finished, and `printf`
is genuinely declared in the pasted-in text from `stdio.h`. The compiler reads your call to
`prntf`, checks it against every declared name, and refuses because none of them match.

**A compiled object file lists `printf` as an undefined (`U`) symbol. What does that mean,
and which stage fixes it?**
The object file mentions `printf` but holds no code for it yet. The linker searches the
standard library's own object files for a matching defined (`T`) symbol and copies its
machine code in, turning the `U` into a `T` in the finished program.
