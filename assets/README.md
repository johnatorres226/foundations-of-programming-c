# Shared assets

Referenced from every chapter by **relative path**, never a CDN. A chapter lives four
levels down (`src/modules/<M>/<C>/CONTENT.html`), so it links back as `../../../../assets/…`.

| File | What it is |
|---|---|
| `style.css` | The whole design system. Reproducing for another language: change `--accent` and `--accent-soft` at the top. |
| `quiz.js` | Renders and grades quizzes from a JSON data block. Quiz content is data, not code. |
| `mermaid.min.js` | Mermaid v11, vendored. |

## Why mermaid is committed and not linked

The course must open from `file://` with no network (PRD §2). A CDN link breaks that, so
the bundle lives here — 3.4 MB, the single largest file in the repo.

> `ponytail:` 3.4 MB of runtime JS to draw diagrams that could be pre-rendered. If repo
> size or page weight starts to matter, render Mermaid to static SVG at authoring time
> with `mermaid-cli` and drop this file — authors keep the Mermaid syntax, learners
> download nothing. Not worth the extra authoring step yet.

Inline SVG remains the **default** for diagrams (see `.claude/project-specs/DESIGN-GUIDELINES.md` §5).
Mermaid is for flowcharts and state diagrams where hand-authoring SVG is not worth it.
