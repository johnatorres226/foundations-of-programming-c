# Foundations of Programming: C

A self-study C course. Clone the repo, open HTML lessons in a browser, write real C in
real files. Audience has **minimal programming experience**; prose targets **6th grade**.

## Read these first

| File | What it governs |
|---|---|
| **`.claude/project-specs/PRD.md`** | The executable spec. Curriculum, chapter structure, citation rules, TDD order, definition of done. |
| **`.claude/project-specs/DESIGN-GUIDELINES.md`** | Branding and the component kit. Deliberately short. |
| **`SYLLABUS.md`** | Every chapter's declared learning outcomes. Recaps are written against this file. |
| **`.claude/templates/chapter-template.html`** | Copy for every new `CONTENT.html`. All six sections and every component, verified rendering offline. Change asset paths to `../../../../assets/`. |
| **`.claude/templates/quiz-template.html`** | Copy for every new `QUIZ.html`. Edit only the JSON block. |
| **`.claude/templates/homework-template.html`** | Copy for every new `exercises/HOMEWORK.html` (chapters with real exercises — not Module 0). Bridges chapter concepts to what each exercise asks; see `.claude/project-specs/PRD.md` §9. |
| **`.claude/templates/exam-template.html`** | Copy for every new `module-exam/EXAM.html`. Same schema and engine as the quiz template, longer, with an optional `section` field to group questions by chapter. Correct answers + reasoning also live in `src/back-of-the-book/module-<N>/exam-answers.md`; see `.claude/project-specs/PRD.md` §10. |
| **`CRITICAL-PATH.md`** | What to work on next. Generated from the GitHub issue graph; dispatch only unblocked issues. Gitignored — local orchestration only, never pushed. Regenerate from the issue graph when stale. |

## `.claude/` layout

This file is the only thing you read cold — everything else it points to. Two
directories behind it, split by what a reader does with the file, not by topic:

- **`.claude/project-specs/`** — rules you follow but never copy: `PRD.md`,
  `DESIGN-GUIDELINES.md`. Read-only decisions; changing one changes the rule for
  every chapter, so a change here is a real design change, not routine authoring.
- **`.claude/templates/`** — files you copy then edit: `chapter-template.html`,
  `quiz-template.html`, `exam-template.html`. Each new `CONTENT.html`/`QUIZ.html`/
  `EXAM.html` starts as a copy of one of these with asset paths corrected for its
  real depth, never written blank.

New spec content goes in `project-specs/`; a new copyable skeleton goes in
`templates/`. Don't add a third top-level `.claude/` file — put it in whichever of
these two it is, or ask whether it needs a third category before creating one.

## Coding philosophy

- **Boring over clever.** Someone with three weeks of programming experience reads this
  code. Cleverness is a teaching failure.
- **The laziest thing that works.** No abstraction without a second caller. No config for a
  value that never changes. Deletion beats addition.
- **Stdlib first.** This is a C course — reaching for a dependency to avoid writing ten
  lines of C teaches the wrong lesson.
- **Every example compiles as shown.** No `...` elisions in anything the learner runs.
- **`-std=c17 -Wall -Wextra -Werror`.** Clean, always.

## Non-negotiable

1. **No build step, no CDN, no network.** Pages must render from `file://` with wifi off.
2. **Tests before prose.** `tests/*.c` first, then solution, then exercise stub, then HTML.
   Module 0 is the exception: it is an introduction with no tests, quizzes, project, or exam.
3. **Cite, never mirror.** And never cite Beej's Guide before Module 6 — it assumes prior
   programming experience. Never excerpt *Modern C* — it is CC BY-NC-ND.
4. **No saved state.** No `localStorage`. Progress is the learner's `exercises/` files.

## Exercise shapes (PRD §9)

Two shapes, told apart by what's in `tests/`. A **function exercise** pairs
`exercises/NN_name.c` (no `main`) with `tests/NN_name_test.c` (`main` + `assert`s),
compiled and run together. A **program exercise** pairs a full-program
`exercises/NN_name.c` with `tests/NN_name.expected` (its exact stdout), optionally fed
`tests/NN_name.input` on stdin. Unfinished stubs must compile clean under `-Werror`
(`(void)` your unused parameters) and fail with a `TODO:` message, never a linker dump.
Solutions live at the matching path under `src/back-of-the-book/module-<N>/`; quiz/exam
answers go in that same chapter's `ANSWERS.md`.

Per-exercise overrides sit next to the test: `tests/NN_name.sanitize` (`thread` swaps in
ThreadSanitizer, since it cannot combine with the course-default AddressSanitizer) and
`tests/NN_name.requires` (a header that must compile here, or the harness reports SKIP
instead of a false pass — `<threads.h>` on Apple Clang is the reason this exists).

## Verify

```sh
make check                          # every reference solution against tests/, -Werror
make check-mine                     # your own exercises/ against tests/
make check-mine CHAPTER=<fragment>  # scope either to one chapter — do this while writing one
make selftest                       # regression-tests the harness itself (tools/selftest/)
make lint                           # clang-format check
```

Then open a `CONTENT.html` from `file://` **with wifi off**. That is the delivery promise.
