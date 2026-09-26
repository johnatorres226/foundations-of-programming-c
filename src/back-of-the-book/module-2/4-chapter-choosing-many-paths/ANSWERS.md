# Chapter 2.4 — Choosing Many Paths — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**A `case` in a `switch` has no `break` at the end of it. What happens when execution
reaches the end of that case's code?**
It falls through into the next case's code and keeps running. Fall-through is C's
default behavior — without a `break`, execution does not stop at the end of a case.

**Which of these is the safe, idiomatic use of fall-through, not a bug waiting to
happen?**
Several empty case labels stacked before one shared line of code (`case 1: case 3: case
5: return 31;`). Nothing runs in the gap between the empty labels, so there is nothing to
accidentally execute for the wrong case.

**A `switch` sits inside a `for` loop. Inside one of its cases, you write `break;`. What
does it do?**
Exits the switch only — the for loop keeps running. `break` always exits the single
nearest enclosing loop or switch, never both at once.

**Inside a `for (int i = 0; i < n; i++)` loop, `continue;` runs partway through the loop
body. Does `i++` still happen before the loop checks its condition again?**
Yes. In a for loop, `continue` jumps to the increment expression, not past it — the
increment still runs, then the condition is checked again.

**Why mark a deliberate fall-through with a comment like `/* fallthrough */` instead of
just leaving out the `break`?**
It tells the next reader the missing break was a choice, not a mistake — a case with real
code and no break otherwise looks identical to the classic missing-break bug.
