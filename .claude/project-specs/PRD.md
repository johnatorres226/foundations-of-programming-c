# PRD — Foundations of Programming: C

**This is an executable spec, not a pitch.** You are writing this course. Follow these
rules literally. When a rule and your judgment disagree, the rule wins — or open an issue
to change the rule.

---

## 1. Product

| Field | Value |
|---|---|
| Name | **Foundations of Programming: C** |
| Repo | `johnatorres226/foundations-of-programming-c` |
| Series | Foundations of Programming — C, then C++, then Rust (separate repos, shared framework) |
| Delivery | Clone the repo. Open HTML in a browser. Write C in real files. |
| Audience | **Minimal programming experience.** Assume no prior language. |
| Readability | **6th grade.** Non-negotiable. See §4. |
| Outcome | Competent C application programmer, comfortable with memory and concurrency. |

### Non-goals

Do not write chapters on these. If a topic below feels necessary, open an issue instead:

- Embedded / freestanding / bare-metal C
- Kernel or driver development
- GUI programming
- C++ (that is repo #2)
- Build systems beyond `make`
- Progress tracking, accounts, or any server-side feature

---

## 2. Hard rules

These break the build or the product if violated.

1. **No build step.** A learner opens `CONTENT.html` from `file://` with no internet and
   everything works. No CDN links. No npm. No bundler. Vendor every asset into `assets/`.
2. **Cite, never mirror.** Link to external sources. Never copy their prose, images, or
   code into this repo. See §7.
3. **`-std=c17`.** All example and solution code compiles clean under
   `-std=c17 -Wall -Wextra -Werror`. See §8.
4. **No `localStorage`, no saved state.** Pages are stateless. The learner's progress is
   the files in their `exercises/` directory.
5. **Tests before prose.** See §9.

---

## 3. Teaching model — spiral / top-down

State the big idea, descend into technical detail, then resurface and re-tie it to the
whole. Every chapter reinforces the global picture, not just its own topic.

### The six sections — fixed order, every chapter, no exceptions

| # | Section | Rule |
|---|---|---|
| 1 | **Recap** | Exactly 2–3 sentences. What the previous chapter established, and where this one sits. Written against the **declared outcomes in `SYLLABUS.md`**, never against the previous chapter's actual prose. |
| 2 | **Big Picture** | The advance organizer. Why this exists in C at all. |
| 3 | **The Core Idea** | **One sentence.** Plain words. If it needs two, the chapter is too big. |
| 4 | **How It Works** | The technical detail. Code, diagrams, gotchas. |
| 5 | **Try It** | Points at real files in `exercises/`. Never inline the work here. |
| 6 | **Zoom Out** | Re-tie to the whole language. Name what comes next. |

> **Why Recap is written against SYLLABUS, not prior prose:** if recaps quote the previous
> chapter's actual text, every chapter serializes and the course cannot be written in
> parallel. `SYLLABUS.md` declares every chapter's outcomes up front precisely so any
> chapter can be authored independently. **Never break this.**

### Headings must name what they connect to

`<h2>The big picture</h2>` and `<h2>Zooming out</h2>` are placeholders, not finished
headings — a reader hitting the same bare label in every chapter has no way to tell what
this chapter's big picture or zoom-out is actually *about* until they read the paragraph
under it. Every chapter's headings carry the connection in the words themselves:

- **Big Picture:** `Big picture: <what this chapter connects to>` — e.g. `Big picture: why
  every C program needs a starting point`.
- **Zoom Out:** `Zooming out: <what this chapter zooms out to>` — e.g. `Zooming out: from
  reading tokens to watching the compiler work`.

Never ship the bare `The big picture` / `Zooming out` text — it is a sign the chapter's own
author has not yet named the connection.

### The chapter table of contents

Every chapter opens with a real table of contents — not a link list — inside
`.chapter-head`, immediately after `<h1>`. It is a nested `<nav class="chapter-toc">`, not
a dot-separated line of links buried inside `.how`: a learner should see the chapter's
whole shape before reading a word of it, not stumble onto an index halfway through:

```html
<header class="chapter-head">
  <p class="crumb">Module 1 · Chapter 1</p>
  <h1>Your First Program, Line by Line</h1>
  <nav class="chapter-toc" aria-label="Chapter contents">
    <p>In this chapter</p>
    <ol>
      <li><a href="#big-picture">Big picture: why every C program states the same pieces up front</a></li>
      <li><a href="#how">How it works</a>
        <ol>
          <li><a href="#include-line">#include &lt;stdio.h&gt;</a></li>
          <li><a href="#main-line">int main(void)</a></li>
        </ol>
      </li>
      <li><a href="#try-it">Try it</a></li>
      <li><a href="#zoom-out">Zooming out: from reading tokens to watching the compiler work</a></li>
      <li><a href="exercises/HOMEWORK.html">Homework →</a></li>
    </ol>
  </nav>
</header>
```

Rules:

- **Four entries always: Big Picture, How It Works, Try It, Zoom Out.** Recap and Core Idea
  are 2–3 sentences and one sentence respectively — framing, not content to navigate to —
  and are left out. Each `<h2>`-bearing section needs a matching `id` (`big-picture`, `how`,
  `try-it`, `zoom-out`) for the anchors to resolve.
- **How It Works nests its `<h3>` subsections** one level deeper, in their own `<ol>`, each
  with a matching `id` — this is the part worth previewing in detail, since it's most of the
  chapter's length. A chapter with only one flat block under `.how` (no natural
  subsections) still gets the four top-level entries; it just has no nested list under "How
  it works."
- **A fifth entry, "Homework →", links to `exercises/HOMEWORK.html`** for any chapter that
  has one (every chapter with real exercises — see the new Homework section below). It is a
  real page link, not an anchor, and it is fine for it to be the only non-anchor entry in the
  list. Chapters with no real exercises (Module 0, plus the rare reading-and-quiz-only
  chapter elsewhere, like M14.5) omit this entry.
- This is not decoration — it lets a learner see the chapter's shape (how many parts, what
  each covers, and that homework is waiting at the end) before committing to read it start
  to end, and lets them jump back to one part later.

---

## 4. Readability — 6th grade

The audience has minimal programming experience. Jargon is the main way this course fails.

- Short sentences. One idea per sentence.
- **Define every technical term the first time it appears in a chapter**, even if an
  earlier chapter defined it. Use a vocabulary chip (see `DESIGN-GUIDELINES.md`).
- Prefer the concrete word: "memory address" over "referent", "runs" over "executes".
- Analogies are welcome. Analogies that are wrong are not — if the analogy breaks down,
  say where it breaks down.
- Never write "simply", "just", "obviously", "of course", or "as you know". If it were
  obvious the learner would not be reading.
- Active voice. Second person ("you write", not "one writes").

---

## 5. Chapter sizing

**A chapter is one sitting: about one hour total** — roughly 20 minutes reading, the rest
exercises and digestion.

This is a **consistency target, not a hard cap.** The learner commits to one chapter per
session; every chapter should feel like the same size commitment. A topic that will not
fit splits into **continuation chapters** (`5-chapter-pointers-part-1`,
`5-chapter-pointers-part-2`), each a full six-section chapter in its own right.

A module holds roughly 4–5 chapters.

### Depth checklist — a measurable floor, not a vibe

"About 20 minutes" is not checkable by eye once ~65 chapters exist. Before a chapter is
called done, run this from the repo root (a plain `grep -o` undercounts badly — HTML
attributes wrap across lines, so it has to parse the three sections as blocks, not lines):

```sh
python3 - "src/modules/<path>/CONTENT.html" <<'EOF'
import re, sys
html = open(sys.argv[1]).read()
total = 0
for cls in ("big-picture", "how", "zoom-out"):
    m = re.search(rf'<section class="{cls}">(.*?)</section>', html, re.S)
    body = re.sub(r'<svg.*?</svg>', '', m.group(1), flags=re.S)
    words = re.sub(r'<[^>]+>', ' ', body).split()
    total += len(words)
print(total, "words, ~%.1f min @150wpm" % (total / 150))
EOF
```

This counts **Big Picture + How It Works + Zoom Out** — prose, code, and terminal text
alike (a beginner reads a code block slowly, not for free), excluding only inline SVG
diagram markup.

**Prototype-phase target: 3,500–5,200 words per chapter (~18–22 minutes at ~240
words/minute).** This is deliberately generous for where the course is right now: build
every chapter out to real depth first — worked examples, gotchas, diagrams, second and
third angles on the idea — and curate/trim once all ~65 chapters exist and can be compared
side by side. Cutting a too-long chapter later is easy; a thin chapter nobody expanded is a
silent gap. Treat this band as the current target for **every** chapter, Module 0 included,
not a ceiling to avoid — a first draft that lands under 3,500 is not done yet.

- **Under ~2,500 words:** not done. Add real coverage — another angle on the idea, a second
  worked example, a diagram, a gotcha the topic actually has — never padding sentences.
- **~3,500–5,200 words:** the prototype target band.
- **Over ~6,000 words:** likely two topics wearing one chapter — split into a continuation
  chapter (§5) instead.

This band will shrink once the whole course exists and curation starts — it is a
build-it-out number for the prototype, not a permanent one. Document in the PR if a chapter
lands outside it.

### Write the heading after the paragraph, against the paragraph

The Big Picture and Zoom Out `<h2>` (§3) must describe what **that section's own prose**
argues — not the module's general topic, and not a later chapter's payoff. Draft the
paragraph first, then write the heading to match what it actually says. A heading that
correctly previews something true two chapters from now, but that this section's own
paragraph never mentions, is still wrong — it's describing the module, not the section a
reader is looking at. (Chapter 0.1 shipped this exact mistake once: title "What a Program
Actually Is," but its Big Picture heading named the compiler — a chapter-0.4 idea the
paragraph beneath it never raised. Fixed to name what the paragraph actually argues: that
this question matters more in C than in most languages.)

Two structural signals correlate with real depth and are easy to check without counting
words:

- **`.how` has at least one `.gotcha` or figure/diagram per `<h3>` subsection** once it has
  subsections — naming a sub-topic without its trap or its picture is a heading with nothing
  under it.
- **The chapter's `.how-index` (if present) has 2+ entries** — a section too thin to name
  more than one part of itself is a section that has not been broken down enough to show its
  own progression.

---

## 6. Module map

Authoritative list. Chapter-level outcomes live in `SYLLABUS.md`.

| # | Module | Covers |
|---|---|---|
| 0 | What Is C? | history, C89→C23, what it solves, pros/cons, learning curve *and why*, real-world uses, **environment setup** |
| 1 | Basics | structure, compiling, variables, types, I/O, **+ debugger & AddressSanitizer intro** |
| 2 | Control Flow | conditionals, loops, `switch` |
| 3 | Functions & Scope | declaration vs definition, parameters, scope, recursion |
| 4 | Arrays & Strings | arrays, C strings, `string.h` |
| 5 | Pointers | addresses, dereferencing, pointer arithmetic, the stack |
| 6 | Structs, Enums, Unions | user-defined types |
| 7 | Dynamic Memory | `malloc`/`free`, ownership, leaks |
| 8 | Memory Deep Dive | layout, alignment, padding, lifetime, memory UB |
| 9 | Files & I/O | streams, reading/writing, error handling |
| 10 | Multi-File Projects | headers, preprocessor, `make`, linking |
| 11 | Debugging & Tooling | `lldb`/`gdb`, sanitizers, valgrind, testing |
| 12 | Concurrency I | **pthreads**, races, mutexes, condition variables |
| 13 | Concurrency II | memory model, atomics, + C11 `threads.h` comparison |
| 14 | Advanced | bit manipulation, function pointers, UB, performance |
| — | Capstone | one substantial program spanning Modules 1–14 |

**Tooling is deliberately split.** The debugger and `-fsanitize=address` are introduced in
**Module 1** as part of "how you run C code", then revisited in depth in **Module 11**.
Modules 7–8 teach memory bugs; the learner must already be able to *see* them.

### Threading: pthreads, not C11

**Module 12 teaches pthreads.** `<threads.h>` is an optional C11 feature and is **absent
on Apple Clang and MSVC** — verified on the maintainer's machine:
`fatal error: 'threads.h' file not found`. Teaching it first would break the
clone-and-go promise on the most common learner platforms.

Module 13 covers C11 `threads.h` as a **comparison chapter**: here is the standard API,
here is why you rarely see it.

---

## 7. Citations — hard rules

| Source | Tier | Rule |
|---|---|---|
| [learn-c.org](https://www.learn-c.org/) | Beginner | Free, interactive, no install. Safe from Module 1. |
| [CS50x](https://cs50.harvard.edu/x/) | Beginner | **Week 1 is the C week.** Video. Safe from Module 1. |
| [cppreference — C](https://en.cppreference.com/w/c) | Lookup | Safe anywhere as a reference, not as a lesson. |
| [Beej's Guide to C](https://beej.us/guide/bgc/) | Intermediate | **NEVER cite before Module 6.** It states outright that it assumes you already know another language. |
| [Modern C, 3rd ed.](https://gustedt.gitlabpages.inria.fr/modern-c/) | Advanced | **CC BY-NC-ND. Link only. Never excerpt, quote at length, or adapt.** |
| [GCC C status](https://gcc.gnu.org/projects/c-status.html) · [Clang C status](https://clang.llvm.org/c_status.html) | Reference | For version/standard tables. |

**Before adding any new source:** verify the URL is live, free, and that its license permits
linking. Note it in your chapter's PR description for the module README update at module
close — per `CONTRIBUTING.md` § Git workflow, chapter PRs never edit a module `README.md`
directly, so citations don't collide across ~60 parallel PRs the way a per-chapter edit
would. YouTube links must be checked individually — channels vanish.

---

## 8. Code standards

- **`-std=c17 -Wall -Wextra -Werror`.** Every `.c` file in this repo compiles clean.
- C23 is the current standard (ISO/IEC 9899:2024) and Module 0 teaches that. The course
  **pins C17** because Apple Clang's C23 support is partial and this audience cannot debug
  a dialect error. Module 0 explains the pin.
- `clang-format` with the repo `.clang-format`. CI enforces it.
- Example code in HTML must be **copy-pasteable and compile as shown**. No `...` elisions
  in anything the learner is told to run.
- Every exercise and solution file carries a header comment naming its module and chapter.

---

## 9. TDD — test → solution → prose

**This order is mandatory.** Write in this sequence, commit in this sequence:

1. **Test.** `tests/*.c`, `assert`-based. This defines what the learner must achieve and
   **is the chapter's acceptance criteria.** Write it before any solution exists.
2. **Solution.** The reference solution in `src/back-of-the-book/`, written until the tests
   pass.
3. **Exercise.** The learner-facing stub in `exercises/` that the tests run against.
4. **Prose.** `CONTENT.html`, `QUIZ.html`, chapter `README.md`.

Prose written before the code is prose that describes code that does not exist yet.

**Exception — Module 0.** Module 0 is an introduction, not an examined module: no tests,
quizzes, project, or exam. Its chapters are reading; chapter 0.4's first program is a
hands-on setup check the learner verifies by eye.

### Exercise shapes

Every exercise is one of two shapes. `tools/run-tests.sh` (invoked by `make check` and
`make check-mine`) tells them apart by what it finds in `tests/`:

- **Function exercise.** `exercises/NN_name.c` defines functions and has **no `main`**.
  `tests/NN_name_test.c` has `main()` and `assert()`s, forward-declares the function(s) it
  calls, and is compiled together with the exercise (or solution) file and run as one
  program. Use this whenever the point is a function's return value or its effect on
  arguments — most chapters.
- **Program exercise.** `exercises/NN_name.c` is a full program with its own `main`.
  `tests/NN_name.expected` holds the exact stdout it must produce; `tests/NN_name.input`,
  if present, is piped to its stdin. Use this where the output *is* the behavior — early
  chapters especially, before the learner can write a function with a return value worth
  asserting on.

Both shapes share one filename stem (`NN_name`) across `exercises/`, `tests/`, and the
matching file in `src/back-of-the-book/`.

### Unfinished stubs

A stub committed to `exercises/` must **compile clean** under `-std=c17 -Wall -Wextra
-Werror` and then **fail with a message a beginner can read** — never a linker error, never
a silent wrong answer. Cast unused parameters to `(void)` so an unimplemented function's
signature does not trip `-Wunused-parameter`, then report and exit:

```c
int add(int a, int b) {
    (void) a;
    (void) b;
    fprintf(stderr, "TODO: implement add() in exercises/01_add.c\n");
    exit(1);
}
```

A program-exercise stub does the same in `main`: print a `TODO:` line to `stderr`, `return
1`. Its empty stdout will not match `tests/NN_name.expected`, so `make check-mine` reports a
clear `FAIL`, not a crash dump.

### Per-exercise overrides

Two files, named after the exercise, sit next to its test and change how
`tools/run-tests.sh` builds it:

- **`tests/NN_name.sanitize`** — contents `thread` swap in ThreadSanitizer for that one
  exercise instead of the course-default AddressSanitizer + UBSan, which cannot be combined
  with it. Module 12.3 (race conditions) is the first user.
- **`tests/NN_name.requires`** — a header name (for example `threads.h`) that must compile
  on the current platform. When it does not (Apple Clang has no `<threads.h>`), the harness
  reports that exercise **SKIP**, never a false pass or fail. Module 13.4 (C11 `threads.h`)
  is the first user.

### Homework — bridging chapter to exercise

Early chapters shipped with exercises that felt bolted on: `CONTENT.html` taught the ideas,
then `.try-it` dropped a bare file list with no bridge between "here is how this works" and
"here is what your three files are actually asking you to do." **Homework** is the fix.

**`exercises/HOMEWORK.html`** is a required file for every chapter that has real exercises
(anything outside Module 0's reading chapters — see PRD §9's exception). Copy
`.claude/templates/homework-template.html`; never write one blank. It is a page in its own
right (same `assets/style.css`, one directory deeper than `CONTENT.html` — fix asset paths
to `../../../../../assets/`), not a section inside `CONTENT.html`.

What it contains, one part per exercise:

- **What it asks** — restate the exercise's goal in one or two sentences, concretely (not
  "practice what you learned" — name the actual output or behavior expected).
- **Why** — tie it back to the specific `.how` subsection it exercises, linking to that
  subsection's `id` in `CONTENT.html` (e.g. `../CONTENT.html#printf-line`). This is the
  bridge the old `.try-it` bullet list didn't have.
- **A hint, not the solution** — a `.gotcha` naming the trap this exercise is likely to hit,
  or a `<details class="solution">` "one approach" reveal per §10's honor-system rule. The
  canonical answer still lives only in `src/back-of-the-book/`.

What `CONTENT.html`'s own `.try-it` section keeps, once Homework exists: a short bridging
paragraph (what you're about to do and why, in 1–3 sentences) and the `make check-mine`
command — not the per-exercise breakdown or the solution reveal, both of which move to
Homework. Point to it plainly: `<a href="exercises/HOMEWORK.html">Open your homework →</a>`.
The chapter table of contents (above) also links it as a final "Homework →" entry.

Any chapter with no real exercises has no `exercises/HOMEWORK.html` and no Homework link
anywhere — there is nothing to bridge to. That's every Module 0 chapter (PRD §9's exception)
plus the rare reading-and-quiz-only chapter elsewhere (M14.5, for example).

### Checking your work

```sh
make check                              # every reference solution, whole course
make check-mine                         # your exercises/, whole course
make check-mine CHAPTER=1-module-basics/1-chapter-first-program   # one chapter only
make selftest                           # regression-tests the harness itself
```

`CHAPTER` is a substring match against `<module-dir>/<chapter-dir>`, so a shorter unique
fragment (`CHAPTER=first-program`) also works. Whole-course runs are noise while most
exercises are unfinished — always scope to the chapter you are writing.

---

## 10. Answers, quizzes, and `back-of-the-book`

**Honor system.** Everything ships in the repo. Solutions are framed as **"one approach
among many"**, never as "the answer" — in C there are genuinely five ways to write any
loop, and saying so is honest.

- Every inline solution reveal sits behind a `<details>` element. Not to stop anyone —
  so nobody loses the attempt by scrolling.
- **`src/back-of-the-book/`** holds **correct answers plus reasoning only.** It is the
  canonical record: what the right answer is and why. It does not enumerate wrong answers.

### Quiz data schema

Quiz content is **data, not code.** One shared `assets/quiz.js` renders every quiz. Each
`QUIZ.html` carries a `<script type="application/json" id="quiz-data">` block.

**Every option carries its own explanation** — why a wrong answer is wrong and what that
misunderstanding teaches, and why the right answer is right:

```json
{
  "questions": [
    {
      "q": "What does `int *p;` declare?",
      "options": [
        { "text": "An integer named p",
          "correct": false,
          "why": "This is the most common early mix-up. The `*` binds to `p`, not to `int` — it says p holds an address, not a number." },
        { "text": "A pointer to an integer",
          "correct": true,
          "why": "Right. `p` stores the memory address where an int lives. It does not store the int itself." }
      ]
    }
  ]
}
```

`why` is required on **every** option, correct and incorrect alike. Wrap code in
`backticks` in `q`, `text`, or `why` — `quiz.js` renders it as `<code>`. No other markup. A quiz that only
explains the right answer teaches half as much.

**Quiz answers in `back-of-the-book`.** Each chapter's
`src/back-of-the-book/module-<N>/<N>-chapter-<topic>/ANSWERS.md` holds `QUIZ.html`'s correct
answers and their reasoning, one entry per question, in the same format as exam answers
below. Wrong-answer `why` text stays in `QUIZ.html` only.

### Exams — the same schema, longer, grouped by chapter

An **exam** (`module-exam/EXAM.html`) is a longer quiz covering every chapter in a module
(Modules 1–14; Module 0 has no exam, see §9). It is rendered by the **same**
`assets/quiz.js` — copy `.claude/templates/exam-template.html`, never start a second engine.

A question may carry an optional `"section"` field naming the chapter it covers, e.g.
`"Chapter 2: Control Flow"`. `quiz.js` prints a heading whenever `section` changes between
one question and the next, so the exam reads grouped by chapter. Quizzes never set
`section` — the field is a no-op when absent.

**Exam answers in `back-of-the-book`.** `src/back-of-the-book/module-<N>/exam-answers.md`
holds the exam's correct answers and their reasoning — one entry per question, in the same
order as `EXAM.html`. Wrong-answer `why` text is **not** duplicated here; per the honor-system
rule above, that stays in the HTML where the learner already agreed to see it by taking the
exam. Format:

```markdown
## Chapter 2: Control Flow

**What does `int *p;` declare?**
A pointer to an integer. `p` stores the memory address where an int lives.
```

This mirrors how exercise solutions work: `back-of-the-book` is the one place to find every
correct answer and why, without re-deriving it from the interactive page.

---

## 11. Repository layout

```
README.md · SYLLABUS.md · CONTRIBUTING.md · CHANGELOG.md · LICENSE
CRITICAL-PATH.md   # gitignored — local orchestration only, regenerated from the issue graph
Makefile · .clang-format · .gitignore
.claude/project-specs/PRD.md · .claude/project-specs/DESIGN-GUIDELINES.md · .claude/CLAUDE.md
.claude/templates/chapter-template.html · .claude/templates/quiz-template.html · .claude/templates/exam-template.html
.claude/templates/homework-template.html
    # copy these, never start blank
assets/style.css · assets/quiz.js · assets/mermaid.min.js
.github/ISSUE_TEMPLATE/*.yml · .github/workflows/{ci,release}.yml
tools/run-tests.sh · tools/selftest.sh · tools/selftest/    # the TDD harness, see §9
src/modules/<N>-module-<topic>/
    README.md
    <N>-chapter-<topic>/
        README.md · CONTENT.html · QUIZ.html
        exercises/NN_name.c            # learner-facing stub, no solution logic
        exercises/HOMEWORK.html        # bridges chapter to exercises, see §9. Not in Module 0.
        tests/NN_name_test.c           # function exercise: main() + assert()
        tests/NN_name.expected         # program exercise: exact stdout
        tests/NN_name.input            # program exercise: optional stdin
        tests/NN_name.sanitize         # optional: "thread" overrides the default sanitizer
        tests/NN_name.requires         # optional: a header that gates the exercise to SKIP
    module-project/ · module-exam/EXAM.html
src/back-of-the-book/module-<N>/
    exam-answers.md                    # exam's correct answers + reasoning only, see §10
    <N>-chapter-<topic>/NN_name.c      # reference solution, mirrors the exercise filename
    <N>-chapter-<topic>/ANSWERS.md     # that chapter's quiz answers + reasoning, see §10
src/capstone/
```

`ANSWERS.md` lives in the chapter's `src/back-of-the-book/module-<N>/<N>-chapter-<topic>/`
directory alongside its solutions, even for chapters with no code — quiz answers need the
same "correct answer plus reasoning, no wrong-answer walkthrough" treatment as code (see
§10). Module exams use the separate module-level `exam-answers.md` next to it, since one
exam spans every chapter in the module. Either way, wrong-answer explanations stay in the
HTML (`QUIZ.html` / `EXAM.html`), never here.

### Module `README.md` — required metadata

Every module README opens with: estimated time to complete, difficulty, tags, prerequisites,
syllabus coverage (which `SYLLABUS.md` outcomes this module discharges), and references
with live URLs.

---

## 12. Versioning

SemVer, recorded in `CHANGELOG.md`:

- **MAJOR** — curriculum restructure. Modules renumbered; learner bookmarks break.
- **MINOR** — a new chapter or module ships.
- **PATCH** — corrections, typos, fixed links.
- **v1.0.0 = all 15 modules complete.** Everything before is `0.x`.

---

## 13. Definition of done — a chapter

- [ ] `tests/*.c` written first, `assert`-based, and failing before the solution exists (not in Module 0)
- [ ] Reference solution in `back-of-the-book/` passes `make check`
- [ ] `exercises/*.c` stubs present, compile, and fail the tests until completed
- [ ] `exercises/HOMEWORK.html` present (chapters with real exercises only), copied from the template, one part per exercise, each linking back to its `.how` subsection (§9)
- [ ] `CONTENT.html` has all six sections in order
- [ ] Core Idea is one sentence
- [ ] Recap is 2–3 sentences, written against `SYLLABUS.md` outcomes
- [ ] Big Picture and Zoom Out headings name what they connect to — not the bare label (§3)
- [ ] `.chapter-toc` present in `.chapter-head`, right after `<h1>`, with a nested list for `.how`'s subsections and a final "Homework →" entry if the chapter has one (§3)
- [ ] `.try-it` bridges to Homework in 1–3 sentences plus the check command — the per-exercise breakdown and solution reveal live in Homework, not here (§9)
- [ ] Passes the depth checklist (§5) — word count in the target band, or a documented reason if not
- [ ] `QUIZ.html` has a `why` on **every** option (not in Module 0)
- [ ] Every new technical term is defined on first use
- [ ] No "simply", "just", "obviously", "of course", "as you know"
- [ ] Citations respect §7 tiers
- [ ] Opens correctly from `file://` **with wifi off**
- [ ] Chapter README metadata complete
