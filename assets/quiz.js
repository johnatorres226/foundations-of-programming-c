/* Foundations of Programming — shared quiz renderer.
 *
 * Quiz content is DATA, not code. Each QUIZ.html carries:
 *
 *   <div id="quiz"></div>
 *   <script type="application/json" id="quiz-data"> { "questions": [ ... ] } </script>
 *   <script src="../../../../assets/quiz.js"></script>
 *
 * Wrap code in `backticks` inside q, text, and why — it renders as <code>.
 * Every option needs a "why" — wrong ones too. Explaining only the right answer
 * teaches half as much. See .claude/project-specs/PRD.md §10.
 *
 * A question may carry an optional "section" (e.g. "Chapter 2: Control Flow").
 * When it differs from the previous question's section, a heading is inserted
 * before that question — exams group by chapter this way. Quizzes never set
 * it, so this is a no-op for them.
 *
 * No localStorage. No network. Nothing is saved. (PRD §2 rule 4)
 */
(function () {
  "use strict";

  // Render `backtick` spans as <code>. Built from text nodes, never innerHTML,
  // so nothing in quiz data can inject markup.
  function withCode(el, text) {
    String(text).split("`").forEach(function (part, i) {
      if (!part) return;
      if (i % 2) {
        var c = document.createElement("code");
        c.textContent = part;
        el.appendChild(c);
      } else {
        el.appendChild(document.createTextNode(part));
      }
    });
    return el;
  }

  var dataEl = document.getElementById("quiz-data");
  var mount = document.getElementById("quiz");
  if (!dataEl || !mount) return;

  var quiz;
  try {
    quiz = JSON.parse(dataEl.textContent);
  } catch (e) {
    mount.textContent = "This quiz could not be loaded: " + e.message;
    return;
  }

  var questions = (quiz && quiz.questions) || [];
  if (!questions.length) {
    mount.textContent = "This quiz has no questions yet.";
    return;
  }

  var form = document.createElement("form");
  form.setAttribute("novalidate", "");

  var lastSection = null;

  questions.forEach(function (q, qi) {
    if (q.section && q.section !== lastSection) {
      var sectionHead = document.createElement("h2");
      sectionHead.className = "quiz-section";
      withCode(sectionHead, q.section);
      form.appendChild(sectionHead);
      lastSection = q.section;
    }

    var box = document.createElement("section");
    box.className = "quiz-q";

    var heading = document.createElement("h3");
    withCode(heading, qi + 1 + ". " + q.q);
    box.appendChild(heading);

    // A fieldset groups the radios so screen readers announce the question with them.
    var set = document.createElement("fieldset");
    set.style.border = "0";
    set.style.margin = "0";
    set.style.padding = "0";

    var legend = document.createElement("legend");
    legend.className = "visually-hidden";
    legend.textContent = String(q.q).replace(/`/g, "");
    legend.style.position = "absolute";
    legend.style.clip = "rect(0 0 0 0)";
    set.appendChild(legend);

    (q.options || []).forEach(function (opt, oi) {
      var label = document.createElement("label");
      label.className = "quiz-opt";
      label.dataset.q = String(qi);
      label.dataset.o = String(oi);

      var radio = document.createElement("input");
      radio.type = "radio";
      radio.name = "q" + qi;
      radio.value = String(oi);

      label.appendChild(radio);
      withCode(label, opt.text);
      set.appendChild(label);
    });

    box.appendChild(set);
    form.appendChild(box);
  });

  var btn = document.createElement("button");
  btn.type = "submit";
  btn.className = "quiz-btn";
  btn.textContent = "Check my answers";
  form.appendChild(btn);

  var score = document.createElement("p");
  score.className = "quiz-score";
  score.setAttribute("role", "status");
  form.appendChild(score);

  form.addEventListener("submit", function (ev) {
    ev.preventDefault();

    var right = 0;

    questions.forEach(function (q, qi) {
      var picked = form.querySelector('input[name="q' + qi + '"]:checked');
      var pickedIndex = picked ? Number(picked.value) : -1;

      (q.options || []).forEach(function (opt, oi) {
        var label = form.querySelector(
          '.quiz-opt[data-q="' + qi + '"][data-o="' + oi + '"]'
        );
        if (!label) return;

        label.querySelector("input").disabled = true;

        if (oi === pickedIndex) {
          label.classList.add(opt.correct ? "is-correct" : "is-wrong");
        } else if (opt.correct) {
          // Show the right answer even when they picked something else.
          label.classList.add("is-missed");
        }

        // Explain every option they engaged with, plus the correct one.
        if (opt.why && (oi === pickedIndex || opt.correct)) {
          var why = document.createElement("p");
          why.className = "quiz-why";
          withCode(why, opt.why);
          label.insertAdjacentElement("afterend", why);
        }
      });

      if (pickedIndex >= 0 && q.options[pickedIndex] && q.options[pickedIndex].correct) {
        right++;
      }
    });

    form.classList.add("quiz-answered");
    btn.disabled = true;
    score.textContent =
      "You got " + right + " of " + questions.length + " right. " +
      (right === questions.length
        ? "Every one. Move on to the next chapter."
        : "Read the explanations above, then revisit the chapter section they point at.");
  });

  mount.appendChild(form);
})();
