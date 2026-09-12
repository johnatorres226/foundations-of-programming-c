# Foundations of Programming: C

**Learn C from the beginning — no prior programming experience needed.**

You read the lessons in your browser. You write the code in real files, and compile it with
a real compiler, the same way working C programmers do. Nothing to install beyond a
compiler. No accounts, no website, no build step.

```sh
git clone https://github.com/johnatorres226/foundations-of-programming-c.git
cd foundations-of-programming-c
open src/modules/0-module-intro/README.md   # start here
```

---

## How this course works

**Start at Module 0.** It explains what C is, why it exists, and how to set up your
machine. Then work through the modules in order.

Each **chapter** is about one hour: roughly 20 minutes of reading, then exercises. One
chapter is one sitting. If you only have an hour this week, that is exactly enough.

Every chapter follows the same six steps, on purpose:

| | | |
|---|---|---|
| **1. Recap** | where you are | two sentences to get your bearings |
| **2. Big Picture** | why this exists | before any detail |
| **3. The Core Idea** | one sentence | the thing to remember |
| **4. How It Works** | the details | code, diagrams, traps |
| **5. Try It** | your turn | real `.c` files you edit |
| **6. Zoom Out** | how it connects | back to the whole language |

This is a **spiral**: you meet the big idea first, go deep, then come back up and see how
it fits. Ideas return in later modules with more depth each time.

---

## What you need

- A text editor
- A C compiler:
  - **macOS** — `xcode-select --install`
  - **Linux** — `sudo apt install build-essential` (or your distro's equivalent)
  - **Windows** — MinGW-w64, or WSL
- `make` (comes with all of the above)

Module 0, Chapter 4 walks through this step by step and helps you check it worked.

---

## Checking your work

```sh
make check-mine   # compile and test the exercises you wrote
make check        # compile and test the reference solutions
make lint         # check formatting
```

Everything compiles with `-std=c17 -Wall -Wextra -Werror` and runs with sanitizers on.
The compiler will be strict with you. That is the point — it catches mistakes now instead
of at 3am later.

---

## What you will be able to do

By the end you can write real C programs: multi-file, managing their own memory, reading
and writing files, tested, and free of leaks. You will be comfortable with **pointers**,
**memory**, and **concurrency** — the three things that make C hard and make C worth
learning.

**15 modules · 65 chapters · 232 exercises.** See **[SYLLABUS.md](SYLLABUS.md)** for the
full map.

| Modules | |
|---|---|
| **0–1** | What C is, and your first programs |
| **2–4** | Control flow, functions, arrays and strings |
| **5–8** | **Pointers and memory** — the heart of C |
| **9–11** | Files, multi-file projects, debugging and tooling |
| **12–14** | **Concurrency**, then advanced C |
| **Capstone** | One substantial program using all of it |

---

## About the answers

Every solution is in this repo, in `src/back-of-the-book/`. We are not hiding them.

They are labelled **"one approach"** rather than "the answer", because in C there are
genuinely several right ways to write almost anything. Compare yours to ours and notice
where they differ — that comparison teaches more than the solution does.

You will only cheat yourself, and you already know that. Try first.

---

## Found a problem?

Every chapter has a **"Something wrong with this chapter?"** link at the bottom that opens
a pre-filled issue. Please use it — unclear explanations are bugs.

Educators: the course content is **CC BY 4.0**, specifically so you can adapt it for your
own teaching. See [CONTRIBUTING.md](CONTRIBUTING.md) and [LICENSE](LICENSE).

---

## Part of a series

**Foundations of Programming** — same structure, same approach, different language:

| | |
|---|---|
| **C** | this repo |
| **C++** | planned |
| **Rust** | planned |
