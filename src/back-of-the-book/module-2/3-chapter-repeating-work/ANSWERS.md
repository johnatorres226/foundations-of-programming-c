# Chapter 2.3 — Repeating Work — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**A `while` loop's condition is false the very first time it is checked. What happens?**
The body never runs at all — zero iterations. `while` checks its condition before every
iteration, including the first one, so a false starting condition skips the body
completely.

**Why does `count_digits(0)` need a `do`/`while` loop instead of a `while` loop to return
`1` correctly?**
`do`/`while` runs its body first and checks the condition afterward, so it counts at
least one digit even when the starting condition would already be false. Zero has one
digit, but a `while` loop would never enter its body when `n` starts at `0`.

**What are the three parts inside `for (int i = 0; i < 5; i++)`, in the order they are
written?**
Initializer, condition, update. The initializer runs once before the loop starts, the
condition is checked before every iteration, and the update runs after the body at the
end of every iteration.

**A loop is meant to print every whole number from 1 to 10, but it only prints 1 through
9. What is this bug called, and what is the likely fix?**
An off-by-one error; the condition likely uses `i < 10` instead of `i <= 10`. The loop
stops one iteration short of the intended boundary.

**`while (n >= 0) { ... n--; ... }` never stops when `n` is declared as `unsigned int`.
Why?**
When `n` reaches `0` and is decremented again, it wraps around to a large positive number
instead of going negative, so `n >= 0` stays true forever. An unsigned type can never
represent a negative value.
