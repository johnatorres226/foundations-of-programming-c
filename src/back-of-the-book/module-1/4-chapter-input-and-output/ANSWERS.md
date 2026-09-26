# Chapter 1.4 — Getting Input and Showing Output — Quiz Answers

Correct answers and reasoning only. Wrong-answer explanations live in `QUIZ.html`, where
the learner already agreed to see them by taking the quiz. See PRD.md §10.

**In `printf("%d apples", count)`, what does `%d` tell `printf`?**
Read exactly the right number of bytes from `count` and print them as a whole number. `%d`
is a promise about type: it tells `printf` how many bytes to read starting at that
argument, and how to interpret them — as a plain integer, not a floating-point value or
anything else.

**`printf("%d\n", price);` where `price` is a `double`. What happens?**
Undefined behavior — `%d` and a `double` argument do not match, and the result can be
anything. An `int` and a `double` are different sizes in memory, so `%d` reads the wrong
bytes the wrong way.

**`printf("[%-10s]\n", name);` is given a `name` that is 14 characters long. What prints?**
All 14 characters of `name`, with no extra padding, then `]`. Width only adds padding when
the value is shorter than the field; a 14-character name already exceeds the 10-character
minimum, so nothing gets added or removed.

**Why does `scanf("%d", &age)` need the `&` in front of `age`, when `printf("%d", age)` does
not?**
`scanf` changes the variable, so it needs to know where in memory that variable lives, not
only its current value. `printf` only reads `age`'s value, so the value alone is enough.

**A program calls `scanf("%d", &score)` and then immediately `scanf("%c", &grade)`. The
person types `87` and presses enter, then types `A` and presses enter. What does `grade`
end up holding?**
`'\n'`, the leftover newline from pressing enter after `87`. `%d` stops right after reading
the digits and leaves the following newline in the input; the next character `%c` finds is
that leftover newline, not `'A'`.

**A program reads an age with `scanf("%d", &age)`, then reads a name with
`fgets(name, sizeof(name), stdin)`. `name` comes out empty. What is the most likely
cause?**
The leftover newline from `scanf("%d", ...)` is still in the input, and `fgets` read that
empty line instead of the real name. `fgets`, unlike `%d`, does not skip leading whitespace.
