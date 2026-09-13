# Design Guidelines — Foundations of Programming

**Scope: branding and structure only.** This document exists so the C, C++, and Rust repos
look like one family. It is deliberately short. It does **not** govern chapter content —
content goes all-in on diagrams, SVG, and rich elements (see `PRD.md` §3).

**Reproducing this for a new language:** copy `assets/`, change `--accent`. That is the
whole procedure.

---

## 1. Series identity

| Product | Repo | `--accent` |
|---|---|---|
| Foundations of Programming: **C** | `foundations-of-programming-c` | `#2563eb` blue |
| Foundations of Programming: **C++** | `foundations-of-programming-cpp` | `#7c3aed` purple |
| Foundations of Programming: **Rust** | `foundations-of-programming-rust` | `#ea580c` orange |

Everything else — layout, typography, spacing, components — is **identical across all
three**. One variable is the entire per-language identity.

---

## 2. Tokens

Defined once in `assets/style.css`. Never hardcode a color, size, or spacing value in a
chapter file.

```css
:root {
  /* the ONE per-language swap */
  --accent:        #2563eb;
  --accent-soft:   #dbeafe;

  --bg:            #fdfdfc;
  --surface:       #ffffff;
  --border:        #e4e4e0;
  --text:          #1c1c1a;
  --text-muted:    #6b6b66;

  --warn:          #b45309;
  --warn-soft:     #fef3c7;
  --ok:            #15803d;
  --ok-soft:       #dcfce7;
  --err:           #b91c1c;
  --err-soft:      #fee2e2;

  --font-sans: ui-sans-serif, system-ui, -apple-system, "Segoe UI", sans-serif;
  --font-mono: ui-monospace, SFMono-Regular, "SF Mono", Menlo, Consolas, monospace;

  /* type scale */
  --t-xs: .8125rem;  --t-sm: .9375rem;  --t-base: 1.0625rem;
  --t-lg: 1.375rem;  --t-xl: 1.75rem;   --t-2xl: 2.25rem;

  /* spacing scale — use these, not arbitrary px */
  --s-1: .25rem; --s-2: .5rem; --s-3: .75rem; --s-4: 1rem;
  --s-6: 1.5rem; --s-8: 2rem;  --s-12: 3rem;

  --radius: 8px;
  --measure: 68ch;   /* max line length for body text */
}
```

### Dark mode — required

Respect `prefers-color-scheme`. Redefine **only** the color tokens; never redefine a color
inside a component rule.

```css
@media (prefers-color-scheme: dark) {
  :root {
    --accent: #60a5fa;  --accent-soft: #1e3a5f;
    --bg: #16161a;      --surface: #1e1e23;   --border: #33333a;
    --text: #ececee;    --text-muted: #9a9aa3;
    --warn: #fbbf24;    --warn-soft: #3a2f14;
    --ok:   #4ade80;    --ok-soft:   #14321f;
    --err:  #f87171;    --err-soft:  #3a1a1a;
  }
}
```

People read at night. A white page at 11pm is why they close the tab.

---

## 3. Page structure

Every `CONTENT.html`:

```html
<link rel="stylesheet" href="../../../../assets/style.css">
<article class="chapter">
  <header class="chapter-head">
    <p class="crumb">Module 5 · Chapter 2</p>
    <h1>Pointer Arithmetic</h1>
  </header>

  <section class="recap">…</section>        <!-- 1 -->
  <section class="big-picture">…</section>  <!-- 2 -->
  <section class="core-idea">…</section>    <!-- 3 -->
  <section class="how">…</section>          <!-- 4 -->
  <section class="try-it">…</section>       <!-- 5 -->
  <section class="zoom-out">…</section>     <!-- 6 -->

  <nav class="chapter-nav">…</nav>
  <footer class="chapter-foot">…</footer>
</article>
```

Working reference: **`.claude/templates/chapter-template.html`** — copy it rather than writing a page
from scratch. Section order is fixed by `PRD.md` §3. Body text is capped at `--measure`; code and
diagrams may exceed it.

---

## 4. Component kit

Eleven blocks. Everything in a chapter is built from these — do not invent new ones
without adding them here first.

| Class | Use |
|---|---|
| `.recap` | Muted, small. 2–3 sentences of orientation. |
| `.big-picture` | Accent left-border callout. The advance organizer. Its `<h2>` names what the chapter connects to, not the bare label — see `PRD.md` §3. |
| `.core-idea` | Boxed, accent background, larger type. **One sentence.** |
| `.how-index` | Muted, small, dot-separated links. Only when `.how` has 2+ `<h3>` subsections — see `PRD.md` §3. |
| `.code` | Code sample. Requires a `data-file` attribute showing the filename. |
| `.terminal` | Command + output. Visually distinct from `.code` — dark ground, `$` prompt. |
| `.try-it` | Accent box linking to `exercises/*.c`. |
| `.gotcha` | Warning colors. Undefined behavior and common beginner traps. |
| `.vocab` | Inline chip defining a term on first use. |
| `.zoom-out` | Closing recap, mirrors `.big-picture` styling. Its `<h2>` names what the chapter zooms out **to** — see `PRD.md` §3. |
| `.chapter-nav` | Prev / next links. |

### Required footer

Every chapter ends with a feedback link that pre-fills the issue:

```html
<footer class="chapter-foot">
  <a href="https://github.com/johnatorres226/foundations-of-programming-c/issues/new?template=chapter-feedback.yml&title=%5BM5C2%5D+">
    Something wrong with this chapter?
  </a>
</footer>
```

Feedback that requires navigating to GitHub and picking a template does not happen.

---

## 5. Diagrams

**No restraint here** — this is learning content, not branding. Modules 5–8 (pointers and
memory) are close to unteachable without pictures.

- **Inline SVG is the default.** No dependency, offline-safe, full control. Use
  `currentColor` and the tokens so diagrams work in dark mode.
- **Mermaid** where authoring speed wins (flowcharts, state). `assets/mermaid.min.js` is
  **vendored locally** — never load it from a CDN. Offline must work.
- Never put text meaning in color alone. Label it.

---

## 6. Non-negotiables

1. No CDN. No web fonts. No external requests. **It must render with wifi off.**
2. No hardcoded colors or sizes in chapter files — tokens only.
3. Readable at 400px wide. Tables and diagrams get `overflow-x: auto`; the page never
   scrolls sideways.
4. Real heading hierarchy (`h1` → `h2` → `h3`), alt text on every image, visible focus
   states. Some learners use screen readers.
5. `assets/style.css` stays one file. If it needs splitting, that is an issue, not a
   spontaneous refactor.
