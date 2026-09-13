# Foundations of Programming: C

A self-study C course. Clone the repo, open HTML lessons in a browser, write real C in
real files. Audience has **minimal programming experience**; prose targets **6th grade**.

## Read these first

| File | What it governs |
|---|---|
| **`.claude/PRD.md`** | The executable spec. Curriculum, chapter structure, citation rules, TDD order, definition of done. |
| **`.claude/DESIGN-GUIDELINES.md`** | Branding and the component kit. Deliberately short. |
| **`SYLLABUS.md`** | Every chapter's declared learning outcomes. Recaps are written against this file. |
| **`.claude/chapter-template.html`** | Copy for every new `CONTENT.html`. All six sections and every component, verified rendering offline. Change asset paths to `../../../../assets/`. |
| **`.claude/quiz-template.html`** | Copy for every new `QUIZ.html`. Edit only the JSON block. |
| **`.claude/exam-template.html`** | Copy for every new `module-exam/EXAM.html`. Same schema and engine as the quiz template, longer, with an optional `section` field to group questions by chapter. Correct answers + reasoning also live in `src/back-of-the-book/module-<N>/exam-answers.md`; see `.claude/PRD.md` §10. |
| **`CRITICAL-PATH.md`** | What to work on next. Generated from the GitHub issue graph; dispatch only unblocked issues. Gitignored — local orchestration only, never pushed. Regenerate from the issue graph when stale. |

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

## Verify

```sh
make check    # compile + run every reference solution, -Werror
make lint     # clang-format check
```

Then open a `CONTENT.html` from `file://` **with wifi off**. That is the delivery promise.
