# Chapter 2.1 — Making Decisions — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**`int flag = 0; if (flag) { printf("yes\n"); } else { printf("no\n"); }` — what does this
print?**
`no`. C has no dedicated boolean type built into the language the way many newer languages
do — an `if` tests any `int`, and `0` is the one and only value C treats as false.

**Which of these values does C's `if` treat as true: `1`, `-1`, `42`, `-100`?**
All four. C's rule is not "positive number" — it is "nonzero number." Any value other than
`0`, including every negative number, counts as true in a condition.

**An `if`/`else if`/`else` chain has three branches, and two of their conditions are both
true for the value being tested. How many of those branches run?**
Exactly one — the first one, top to bottom, whose condition is true. Once a branch runs,
the chain stops checking the rest, even if a later condition would also have been true.

**A chain checks `score >= 60` before it checks `score >= 90`. For `score` equal to `95`,
which branch runs?**
The `score >= 60` branch — not the `score >= 90` one, even though `95` also satisfies it.
The chain stops at the first true condition it reaches, so branches that test a broader
range have to come after the branches that test a narrower one, never before.

**`if (x = 5) { ... }` — what is wrong with this line, and what should it be?**
`=` assigns; `==` compares. This line sets `x` to `5` and then tests the *result of that
assignment* — `5`, a nonzero value — so the branch always runs, regardless of what `x` held
before. The fix is `==`: `if (x == 5)`.
