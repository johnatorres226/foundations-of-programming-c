# Chapter 1.3 — Variables and Types — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**What does `sizeof(char)` report on every C platform, by definition?**
Always exactly 1. The C standard defines a byte as the size of a `char`, so this is fixed
by definition. Every other type's size is only guaranteed relative to this one.

**What does `int result = 7 / 2;` store in `result`?**
3, because int division throws away the fraction. Dividing two `int`s always truncates
toward zero — the fractional part is discarded, not rounded.

**Why does `digit - '0'` convert a digit character to the int it represents?**
`char` is really a small whole number, and ASCII assigns the digit characters
consecutive numbers starting from `'0'`. The distance between any digit character and
`'0'` equals the digit it represents.

**Why should you avoid comparing two `double` values with `==`?**
Most decimal fractions cannot be represented exactly in binary, so two values that
should be mathematically equal can differ by a tiny amount. Comparing with a tolerance
instead of `==` accounts for that gap.

**An `unsigned char` holding `255` has `1` added to it. A plain (signed) `int` holding
its largest possible value also has `1` added to it. What is the difference?**
The unsigned case wraps around to 0, a guarantee the C standard makes. The signed case
is undefined behavior — the compiler is allowed to produce anything.
