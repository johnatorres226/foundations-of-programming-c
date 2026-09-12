# Foundations of Programming: C
#
# make check       compile + run every reference solution (this is the test suite)
# make check-mine  same, but against YOUR files in exercises/
# make lint        check formatting
# make format      fix formatting
# make clean       remove build output

CC      ?= cc
CSTD    ?= -std=c17
WARN    := -Wall -Wextra -Werror
DEBUG   := -g
SAN     := -fsanitize=address,undefined
CFLAGS  := $(CSTD) $(WARN) $(DEBUG) $(SAN) -pthread
BUILD   := build

SOLUTIONS := $(shell find src/back-of-the-book -name '*.c' 2>/dev/null | sort)
MINE      := $(shell find src/modules -path '*/exercises/*.c' 2>/dev/null | sort)
ALL_C     := $(shell find src -name '*.c' 2>/dev/null | sort)

.PHONY: check check-mine lint format clean help

help:
	@sed -n '3,7p' Makefile | sed 's/^# \{0,1\}//'

# Compile and run each .c as a standalone program. Solutions self-check with assert(),
# so a broken solution fails the build rather than silently passing.
define run_suite
	@mkdir -p $(BUILD)
	@files="$(1)"; \
	if [ -z "$$files" ]; then \
	  echo "No .c files found yet in $(2) - nothing to check."; exit 0; \
	fi; \
	pass=0; fail=0; \
	for f in $$files; do \
	  out="$(BUILD)/$$(echo $$f | tr '/.' '__')"; \
	  if ! $(CC) $(CFLAGS) "$$f" -o "$$out" 2>"$$out.log"; then \
	    echo "  COMPILE FAIL  $$f"; sed 's/^/      /' "$$out.log"; fail=$$((fail+1)); continue; \
	  fi; \
	  if sh -c '"$$0" >/dev/null 2>"$$1"' "$$out" "$$out.run" 2>/dev/null; then \
	    echo "  ok            $$f"; pass=$$((pass+1)); \
	  else \
	    echo "  RUN FAIL      $$f"; sed 's/^/      /' "$$out.run"; fail=$$((fail+1)); \
	  fi; \
	done; \
	echo ""; echo "  $$pass passed, $$fail failed"; \
	[ $$fail -eq 0 ]
endef

check:
	@echo "Checking reference solutions ($(CSTD), -Werror, sanitizers on)"
	$(call run_suite,$(SOLUTIONS),src/back-of-the-book)

check-mine:
	@echo "Checking your work ($(CSTD), -Werror, sanitizers on)"
	$(call run_suite,$(MINE),src/modules/*/exercises)

lint:
	@if [ -z "$(ALL_C)" ]; then echo "No .c files yet."; else \
	  clang-format --dry-run --Werror $(ALL_C) && echo "Formatting OK"; fi

format:
	@if [ -z "$(ALL_C)" ]; then echo "No .c files yet."; else \
	  clang-format -i $(ALL_C) && echo "Formatted $(words $(ALL_C)) files"; fi

clean:
	@rm -rf $(BUILD)
	@echo "Cleaned."
