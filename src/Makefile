CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
CHECK_FLAGS = -lcheck -lm -lpthread -ftest-coverage -fprofile-arcs
GCOV_FLAGS = -ftest-coverage -fprofile-arcs -fPIC
SRC = $(wildcard s21_*.c)
OBJ = $(SRC:%.c=%.o)
TEST_FILES = tests/*.c
SRC_FILES := $(filter-out $(wildcard tests/*.c), $(wildcard *.c))
VALGRIND_FLAGS = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=high

UNAME := $(shell uname -s)
ifeq ($(UNAME), Linux)
	CFLAGS += -lsubunit
	TEST_FLAGS = -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	ifneq ("$(wildcard /proc/version)", "")
		OPENER = wslview
	endif
else
	OPENER = xdg_open
endif
ifeq ($(UNAME), Darwin)
	TEST_FLAGS = $(shell pkg-config --cflags --libs check)
	OPENER = open
endif

all: s21_matrix.a

s21_matrix.a: $(OBJ) *.h
	ar rcs s21_matrix.a $(OBJ)
	ranlib s21_matrix.a
	rm -rf ./*/*.o

test: s21_matrix.a $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) s21_matrix.a -o test.out $(TEST_FLAGS)
	./test.out

gcov_report: s21_matrix.a
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_FILES) $(SRC_FILES) -o report.out $(TEST_FLAGS)
	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	$(OPENER) ./report/index-sort-f.html

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov tests/*.log tests/*.gcno tests/*.gcda *.txt
	rm -rf ./report

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c */*.c *.h
	rm -fr ./.clang-format

format_check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h

valgrind: s21_matrix.a $(TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_FILES) s21_matrix.a -o test.out $(TEST_FLAGS)
	valgrind $(VALGRIND_FLAGS) ./test.out
