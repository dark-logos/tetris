CC = gcc-14
CFLAGS = -Wall -Wextra -Werror -std=c11 -fprofile-arcs -ftest-coverage
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

PREFIX = /usr/local
BINDIR = $(PREFIX)/bin

EXEC = s21_brick_game
NAME = s21_brick_game.a
TEST_BIN = test.out

SRC = s21_brickGame.c \
      tetris/s21_rotation.c \
      tetris/s21_main_cycle.c \
      tetris/s21_possibility_of_move.c \
      tetris/s21_random_figure.c \
      tetris/s21_getchar.c \
      tetris/s21_count_points.c \
      gui/cli/s21_graphics.c

OBJ = $(SRC:.c=.o)

HEAD = s21_brick_game.h

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(EXEC)
	mkdir -p $(BINDIR)
	cp $(EXEC) $(BINDIR)

uninstall:
	rm -f $(BINDIR)/$(EXEC)

clean:
	find . -type f \( -name "*.o" -o -name "*.gcno" -o -name "*.gcda" -o -name "*.info" -o -name "$(EXEC)" -o -name "$(NAME)" -o -name "$(TEST_BIN)" -o -name "*.gcov" \) -delete
	rm -rf report dist

dvi:
	@echo "No DVI documentation to build."

dist:
	mkdir -p dist
	tar -czvf dist/$(EXEC).tar.gz $(SRC) $(HEAD) Makefile

test: CFLAGS += $(GCOV_FLAGS)
test:
	$(CC) $(CFLAGS) -I/opt/homebrew/include $(filter-out s21_brickGame.c, $(SRC)) tests/s21_tests.c -o $(TEST_BIN) -L/opt/homebrew/lib -lcheck -pthread -lm -lncurses
	./$(TEST_BIN)

gcov_report: test
	lcov --gcov-tool gcov-14 -t "test" -o coverage.info -c -d .
	lcov -r coverage.info "/opt/homebrew/*" "*/tests/*" --ignore-errors unused -o coverage.info
	genhtml coverage.info -o report
	open report/index.html

.PHONY: all install uninstall clean dvi dist test gcov_report
