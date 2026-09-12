# Syllabus — Foundations of Programming: C

**65 chapters · 15 modules · ~1 hour per chapter**

This file is the contract. Every chapter's **Recap** section is written against the
outcomes declared here — never against the previous chapter's actual prose. That is what
lets any chapter be written independently of the ones around it.

Legend: **Ex** = code exercises · **Q** = quiz · difficulty ●○○ intro / ●●○ core / ●●● hard

---

## Module 0 — What Is C? ●○○

*Time: ~4 hours · Tags: orientation, history, setup · No prior knowledge assumed*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 0.1 | What a Program Actually Is | Explain what a CPU does, what source code is, and the difference between compiled and interpreted languages | 0 | — |
| 0.2 | The Story of C | Say where C came from, what problem it solved, and why Unix made it spread | 0 | — |
| 0.3 | The Versions of C | Name C89/C99/C11/C17/C23, describe what changed, and explain why this course pins C17 while C23 is current | 0 | — |
| 0.4 | Set Up Your Machine | Install a working compiler on macOS, Windows, or Linux; compile and run a first program; verify the toolchain | 0 | — |

**Module 0 is an introduction, not an examined module.** It has no tests, quizzes, project, or exam.
0.1–0.3 are reading. 0.4 is a guided setup the learner checks by eye: compile and run a
first program. Tested exercises start in Module 1.

---

## Module 1 — Basics ●○○

*Time: ~5 hours · Tags: syntax, compilation, types, io, debugging*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 1.1 | Your First Program, Line by Line | Explain every token of a hello-world program: `#include`, `main`, `return`, `printf` | 3 | ✓ |
| 1.2 | How C Becomes a Program | Describe preprocess → compile → assemble → link, and what the compiler does at each step | 3 | ✓ |
| 1.3 | Variables and Types | Declare and use `int`, `char`, `float`, `double`; predict `sizeof`; explain why fixed sizes matter | 4 | ✓ |
| 1.4 | Getting Input and Showing Output | Use `printf` format specifiers correctly and read input with `scanf`, knowing its traps | 4 | ✓ |
| 1.5 | When Things Break | Read a compiler error, set a breakpoint in a debugger, and run a program under `-fsanitize=address` | 3 | ✓ |

> **1.5 is the tooling seed.** The debugger and AddressSanitizer are introduced here,
> shallow, so Modules 7–8 can teach memory bugs the learner is able to *see*.
> Module 11 revisits both in depth. Do not deepen 1.5 — that is 11's job.

---

## Module 2 — Control Flow ●○○

*Time: ~4 hours · Tags: conditionals, loops, branching*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 2.1 | Making Decisions | Write `if`/`else if`/`else`, and explain that C has no boolean type historically — zero is false, everything else is true | 4 | ✓ |
| 2.2 | Combining Conditions | Use `&&`, `\|\|`, `!` and explain short-circuit evaluation and why it matters for safety | 4 | ✓ |
| 2.3 | Repeating Work | Choose correctly between `while`, `do`/`while`, and `for`; write loops that terminate | 5 | ✓ |
| 2.4 | Choosing Many Paths | Use `switch` correctly, explain fall-through, and use `break`/`continue` deliberately | 4 | ✓ |

---

## Module 3 — Functions & Scope ●●○

*Time: ~4 hours · Tags: functions, scope, stack, recursion*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 3.1 | Writing Your Own Functions | Define functions with parameters and return values, and explain why C passes arguments by value | 4 | ✓ |
| 3.2 | Declaration vs Definition | Write prototypes, explain why declaration order matters, and fix "implicit declaration" errors | 3 | ✓ |
| 3.3 | Scope and Lifetime | Distinguish local, global, and `static` storage; explain shadowing and why globals are risky | 4 | ✓ |
| 3.4 | Recursion | Write a recursive function with a correct base case and trace its call stack | 4 | ✓ |

---

## Module 4 — Arrays & Strings ●●○

*Time: ~5 hours · Tags: arrays, strings, bounds*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 4.1 | Arrays | Declare and index arrays, and explain that C does **not** check bounds and what that costs | 4 | ✓ |
| 4.2 | Arrays and Loops | Iterate arrays safely, track length separately, and avoid off-by-one errors | 4 | ✓ |
| 4.3 | Strings Are Arrays | Explain the null terminator and why a C string is just a `char` array with a convention | 4 | ✓ |
| 4.4 | The `string.h` Toolkit | Use `strlen`, `strcpy`, `strcmp`, `strncpy`; explain why the `n` variants exist | 5 | ✓ |
| 4.5 | Multi-dimensional Arrays | Declare and traverse 2D arrays and explain how they are laid out in memory | 4 | ✓ |

---

## Module 5 — Pointers ●●●

*Time: ~6 hours · Tags: pointers, memory, indirection · **Diagrams required***

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 5.1 | What a Pointer Is | Explain that a pointer holds an address; use `&` and `*` correctly; read `int *p` out loud | 4 | ✓ |
| 5.2 | Pointers and Functions | Change a caller's variable from inside a function, and explain why that needs a pointer | 4 | ✓ |
| 5.3 | Pointer Arithmetic | Predict what `p + 1` does for different types, and explain why the type matters | 4 | ✓ |
| 5.4 | Pointers and Arrays | Explain array-to-pointer decay and why `sizeof` differs inside a function | 4 | ✓ |
| 5.5 | Pointers to Pointers, and `const` | Use `**` meaningfully and read `const` placement correctly | 4 | ✓ |

> **This is where learners quit.** Diagrams are mandatory here, not optional.

---

## Module 6 — Structs, Enums, Unions ●●○

*Time: ~4 hours · Tags: types, data-modeling*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 6.1 | Structs | Define and use structs to group related data | 4 | ✓ |
| 6.2 | Structs and Pointers | Use `->`, and explain when to pass a struct by pointer instead of by value | 4 | ✓ |
| 6.3 | Enums | Use enums for named constants and explain why they beat bare integers | 3 | ✓ |
| 6.4 | Unions and `typedef` | Explain what a union shares, when it is the right tool, and how `typedef` improves readability | 4 | ✓ |

---

## Module 7 — Dynamic Memory ●●●

*Time: ~5 hours · Tags: heap, malloc, ownership · **Diagrams required***

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 7.1 | Why Dynamic Memory | Explain what the stack cannot do and when a program must allocate at runtime | 3 | ✓ |
| 7.2 | `malloc`, `calloc`, `realloc`, `free` | Allocate, resize, and release memory, and check every allocation for failure | 5 | ✓ |
| 7.3 | Ownership | State who is responsible for freeing a pointer, and design functions with a clear ownership contract | 4 | ✓ |
| 7.4 | Leaks and Use-After-Free | Reproduce a leak and a use-after-free, then find both with AddressSanitizer | 4 | ✓ |

---

## Module 8 — Memory Deep Dive ●●●

*Time: ~5 hours · Tags: memory-layout, alignment, undefined-behavior · **Diagrams required***

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 8.1 | How Memory Is Laid Out | Describe text, static, stack, and heap regions and say where any given variable lives | 3 | ✓ |
| 8.2 | Alignment and Padding | Predict `sizeof` a struct, explain padding, and reorder fields to shrink it | 4 | ✓ |
| 8.3 | Lifetime and Dangling Pointers | Identify when a pointer outlives what it points at, and why returning a local's address is a bug | 4 | ✓ |
| 8.4 | Undefined Behavior Around Memory | Name common memory UB, explain why the compiler may do anything, and detect it with sanitizers | 4 | ✓ |

---

## Module 9 — Files & I/O ●●○

*Time: ~4 hours · Tags: files, streams, error-handling*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 9.1 | Streams | Explain `stdin`, `stdout`, `stderr`, and why error output belongs on `stderr` | 3 | ✓ |
| 9.2 | Reading and Writing Text Files | Open, read, write, and close files with `fopen`/`fgets`/`fprintf`/`fclose` | 5 | ✓ |
| 9.3 | Binary Files | Use `fread`/`fwrite` and explain how binary differs from text | 4 | ✓ |
| 9.4 | Handling I/O Errors | Check every return value, use `errno`, and fail safely | 4 | ✓ |

---

## Module 10 — Multi-File Projects ●●○

*Time: ~5 hours · Tags: headers, preprocessor, make, linking*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 10.1 | Splitting Code Into Files | Decide what belongs in its own file and why one big file stops scaling | 3 | ✓ |
| 10.2 | Header Files | Write headers with include guards and explain what belongs in `.h` vs `.c` | 4 | ✓ |
| 10.3 | The Preprocessor | Use `#define`, `#ifdef`, and macros; explain why macros are sharp tools | 4 | ✓ |
| 10.4 | Compiling and Linking Many Files | Compile multiple translation units and read linker errors | 4 | ✓ |
| 10.5 | Writing a Makefile | Write a Makefile with targets, prerequisites, and variables that rebuilds only what changed | 3 | ✓ |

---

## Module 11 — Debugging & Tooling ●●●

*Time: ~4 hours · Tags: debugging, sanitizers, valgrind, testing*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 11.1 | Using a Debugger Properly | Set breakpoints and watchpoints, step, inspect memory, and read a backtrace | 4 | ✓ |
| 11.2 | Sanitizers in Depth | Use AddressSanitizer and UndefinedBehaviorSanitizer and interpret their reports | 4 | ✓ |
| 11.3 | Valgrind and Memory Profiling | Run a program under valgrind and act on what it reports | 3 | ✓ |
| 11.4 | Writing Tests for C | Write `assert`-based tests and build a small test harness with no framework | 4 | ✓ |

---

## Module 12 — Concurrency I ●●●

*Time: ~5 hours · Tags: threads, pthreads, races · **Diagrams required***

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 12.1 | Why Concurrency | Distinguish processes from threads and say when concurrency actually helps | 3 | ✓ |
| 12.2 | Creating Threads with pthreads | Create and join threads with `pthread_create`/`pthread_join` and pass data in safely | 4 | ✓ |
| 12.3 | Race Conditions | **Write a program that produces a wrong answer**, explain why, and detect it with ThreadSanitizer | 4 | ✓ |
| 12.4 | Mutexes and Condition Variables | Protect shared state with a mutex and coordinate threads with a condition variable | 5 | ✓ |

> **pthreads, not C11 `threads.h`.** `<threads.h>` is optional in C11 and is **absent on
> Apple Clang and MSVC** — verified: `fatal error: 'threads.h' file not found`. pthreads
> works on macOS, Linux, and WSL with no setup. The standard API is covered in 13.4.

---

## Module 13 — Concurrency II ●●●

*Time: ~4 hours · Tags: memory-model, atomics, deadlock*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 13.1 | The Memory Model | Explain visibility and reordering, and why "it worked on my machine" is not evidence | 3 | ✓ |
| 13.2 | Atomics | Use atomic operations for simple shared counters and explain what they guarantee | 4 | ✓ |
| 13.3 | Deadlock and Lock Ordering | Produce a deadlock on purpose, then prevent it with a lock ordering rule | 4 | ✓ |
| 13.4 | C11 `threads.h` | Translate a pthreads program to the C11 API and explain why it is rarely available | 3 | ✓ |

---

## Module 14 — Advanced ●●●

*Time: ~5 hours · Tags: bits, function-pointers, ub, performance*

| # | Chapter | On finishing, the learner can… | Ex | Q |
|---|---|---|---|---|
| 14.1 | Bit Manipulation | Use `&`, `\|`, `^`, `~`, `<<`, `>>`; pack flags into an integer and read them back | 5 | ✓ |
| 14.2 | Function Pointers | Store and call functions through pointers, and use them for callbacks and dispatch tables | 4 | ✓ |
| 14.3 | Undefined Behavior in Depth | Recognise the major UB classes and explain why the compiler is allowed to surprise you | 4 | ✓ |
| 14.4 | Performance | Explain cache locality, measure before optimising, and read a profiler's output | 4 | ✓ |
| 14.5 | Where to Go Next | Choose a next step — systems, embedded, C++, Rust — with a clear sense of the tradeoffs | 0 | ✓ |

---

## Projects and exams

Modules 1–14 each ship a **project** (build something using only that module's material and
everything before it) and an **exam** (mixed questions across the whole module, with
per-option feedback). Module 0 has neither — it is an introduction.

## Capstone

One substantial program spanning Modules 1–14: multi-file, dynamically allocated, file-backed,
tested, with a Makefile, and free of leaks under AddressSanitizer.

---

## Coverage totals

| | Count |
|---|---|
| Modules | 15 |
| Chapters | 65 |
| Code exercises | 232 |
| Quizzes | 61 |
| Module projects | 14 |
| Module exams | 14 |
| Capstone | 1 |
