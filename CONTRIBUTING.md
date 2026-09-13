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

The full spec is [`.claude/project-specs/PRD.md`](.claude/project-specs/PRD.md); visual rules are in
[`.claude/project-specs/DESIGN-GUIDELINES.md`](.claude/project-specs/DESIGN-GUIDELINES.md).

## Git workflow

This is a solo dev-space repo with no release branch to protect, so the workflow stays
lightweight — the minimum that keeps ~60 parallel chapters from colliding.

- **One branch per issue**, named after the issue's chapter or infra code:
  `m5.3-pointer-arithmetic`, `f1-tdd-harness`. Each subagent works in its own `git worktree`
  so parallel work never shares a checkout.
- **One PR per issue**, closed with `Closes #N` in the PR body.
- **Review:** the orchestrator (Opus) reads the diff against the issue's acceptance
  criteria and `make check` / `make lint` before merging. No second human reviewer required
  in this repo's current single-maintainer phase.
- **Merge commits, never squash.** PRD §9 requires tests committed before the solution;
  squash-merging erases that order from history. `git merge --no-ff`.
- **Commit messages:** plain, present tense, one line — `Add chapter 5.3: Pointer
  Arithmetic`. No trailers, no attribution.
- **CI:** `ci.yml` (ubuntu + macos `make check`, plus lint) must be green before merge.
  Branch protection isn't configured — enforced by review discipline instead, until
  collaborators beyond the maintainer join.
- **Shared-file collisions:** chapter work never edits its module's `README.md` or the
  root `CHANGELOG.md` — only its own chapter directory. Module `README.md` status and the
  changelog are updated once, when a module's chapters all close, not per-chapter. This is
  what makes ~60 parallel PRs conflict-free by construction instead of by locking.

## For educators

Course content is **CC BY 4.0** so you can adapt it for your own teaching — please do. Code
is MIT. If you adapt it and find something that works better, we would genuinely like the
PR.
