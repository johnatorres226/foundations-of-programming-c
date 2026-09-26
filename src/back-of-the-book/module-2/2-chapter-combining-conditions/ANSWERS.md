# Chapter 2.2 — Combining Conditions — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**What does `a && b` require to be true?**
Both `a` and `b` are true. `&&` is only true when neither side is false.

**`int result = !7;` — what does `result` hold, and why?**
0. Any nonzero value counts as true, so `!7` flips a true value to false, which C
represents as `0`.

**Given `count = 0`, does `count != 0 && total / count > 5` divide by zero?**
No. `&&` checks `count != 0` first, sees it is false, and short-circuits — it never
evaluates `total / count` at all.

**Why does short-circuit evaluation matter for safety, not only speed?**
It lets you write a safe guard on the left of `&&` that must pass before a risky
operation on the right ever runs. C guarantees the right side is skipped once the left
side has already decided the answer, so the guard's protection is real, not only likely.

**`is_member && has_coupon || is_vip`, with `is_member = 0`, `has_coupon = 0`, `is_vip = 1`
— what does this evaluate to, and why?**
1. `&&` binds tighter than `||`, so this groups as `(is_member && has_coupon) || is_vip`.
A true `is_vip` on the right of `||` is enough on its own, with no membership requirement
in that grouping.

**A test proves that `expensive_check()` was called zero times after calling
`safe_to_proceed(0, 999)`. What does that prove?**
That short-circuit evaluation genuinely skipped the right side of `&&`, not only that the
final answer happened to come out false. A call counter is observable proof a specific
line of code did not run.
