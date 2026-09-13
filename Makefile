# Foundations of Programming: C
#
# make check       run every tests/ file against the reference solutions
# make check-mine  same, but against YOUR files in exercises/
#                  both accept CHAPTER=<substring> to check one chapter,
#                  e.g. make check-mine CHAPTER=1-module-basics/1-chapter-first-program
# make selftest    regression-test the harness itself (tools/selftest/)
# make lint        check formatting
# make format      fix formatting
# make clean       remove build output

CC      ?= cc
CSTD    ?= -std=c17
WARN    := -Wall -Wextra -Werror
DEBUG   := -g
SAN     := -fsanitize=address,undefined
BUILD   := build
CHAPTER ?=

export CC CSTD WARN DEBUG SAN BUILD

ALL_C := $(shell find src tools -name '*.c' 2>/dev/null | sort)

.PHONY: check check-mine selftest lint format clean help

help:
	@sed -n '3,9p' Makefile | sed 's/^# \{0,1\}//'

check:
	@echo "Checking reference solutions ($(CSTD), -Werror, sanitizers on)"
	@tools/run-tests.sh solution "$(CHAPTER)"

check-mine:
	@echo "Checking your work ($(CSTD), -Werror, sanitizers on)"
	@tools/run-tests.sh mine "$(CHAPTER)"

# Proves the harness itself works: both exercise shapes, the per-exercise
# sanitizer override, and the platform-skip mechanism. See tools/selftest/
# and tools/selftest.sh.
selftest:
	@tools/selftest.sh

lint:
	@if [ -z "$(ALL_C)" ]; then echo "No .c files yet."; else \
	  clang-format --dry-run --Werror $(ALL_C) && echo "Formatting OK"; fi

format:
	@if [ -z "$(ALL_C)" ]; then echo "No .c files yet."; else \
	  clang-format -i $(ALL_C) && echo "Formatted $(words $(ALL_C)) files"; fi

clean:
	@rm -rf $(BUILD)
	@echo "Cleaned."
