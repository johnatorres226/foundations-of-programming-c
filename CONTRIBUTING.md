# Contributing

This course is for people with **minimal programming experience**, and prose targets a
**6th-grade reading level**. Almost every contribution rule below follows from that.

Most valuable contribution: **tell us where an explanation confused you.** An unclear
chapter is a bug, and the person who just struggled through it is the only one who can see
it clearly.

## Ways to help

| | |
|---|---|
| **Report a confusing chapter** | Use the "Something wrong with this chapter?" link at the bottom of any lesson |
| **Fix an error** | Wrong code, broken link, typo — open a PR |
| **Improve an explanation** | Especially pointers and memory (Modules 5–8), where people quit |
| **Propose content** | Open an issue before writing — chapters are sized deliberately |

## Before you open a PR

```sh
make check     # reference solutions compile and pass
make lint      # formatting
```

Then open the chapter's `CONTENT.html` from `file://` **with your wifi off**. If it needs
the network, it is broken — see the rules below.

## Rules that are not negotiable

1. **No build step, no CDN, no network.** A learner clones the repo and opens HTML. Every
   asset is vendored in `assets/`. No npm, no bundler, no external fonts.
2. **`-std=c17 -Wall -Wextra -Werror`.** All code compiles clean.
3. **Cite, never copy.** Link to outside resources; never paste their prose or code here.
   *Modern C* is CC BY-NC-ND — link only, never excerpt.
4. **Six sections, fixed order.** Recap → Big Picture → Core Idea → How It Works → Try It →
   Zoom Out. The structure is the teaching method, not decoration.
5. **Tests first.** New exercises land as `assert`-based tests in `tests/` before the
   solution exists.
6. **No saved state.** No `localStorage`, no accounts. Progress is the learner's own files.

## Writing rules

- Short sentences. One idea each.
- Define every technical term the first time it appears in a chapter — even if an earlier
  chapter defined it.
- Never write "simply", "just", "obviously", "of course", or "as you know". If it were
  obvious, they would not be reading.
- Active voice, second person: "you write", not "one writes".
- Analogies are good. Say where the analogy breaks down.
- A chapter is about **one hour of work total** (~20 min reading). Too big means splitting
  into a continuation chapter, not writing faster.

The full spec is [`.claude/PRD.md`](.claude/PRD.md); visual rules are in
[`.claude/DESIGN-GUIDELINES.md`](.claude/DESIGN-GUIDELINES.md).

## Git workflow

> 📌 **Not yet specified.** Branch naming, PR review rules, and merge strategy are being
> decided. Until then: branch off `main`, one chapter or fix per PR, and describe what you
> changed and why.

## For educators

Course content is **CC BY 4.0** so you can adapt it for your own teaching — please do. Code
is MIT. If you adapt it and find something that works better, we would genuinely like the
PR.
