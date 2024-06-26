CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SF = -fsanitize=leak,address

ifeq ($(shell uname), Linux)
    all: s21_matrix.a test gcov_report

    s21_matrix.a: *.c functions/*.c s21_matrix.h
		$(CC) $(CFLAGS) -c *.c functions/*.c
		ar rcs $@ *.o
		ranlib s21_matrix.a

    test: s21_matrix.a
		$(CC) -g $(CFLAGS) -fprofile-arcs -ftest-coverage -o ./s21_test/s21test s21_test/*.c *.c functions/*.c s21_matrix.h -lcheck -lm -lsubunit

    gcov_report: test
		chmod +x ./s21_test/s21test && ./s21_test/s21test
		mkdir -p gcov-report
		gcovr -r . --html --html-details -o gcov-report/index.html
		open ./gcov-report/index.html

else ifeq ($(shell uname), Darwin)
    SOURCES=$(wildcard s21_test/*.c functions/*.c)
    OBJECTS=$(SOURCES:.c=.o)
    all: s21_matrix.a test gcov_report
    
    s21_matrix.a: *.c functions/*.c
		$(CC) $(CFLAGS)  -c *.c functions/*.c
		ar rc s21_matrix.a *.o
		ranlib s21_matrix.a

    $(OBJECTS): %.o: %.c
		$(CC) -c $(CFLAGS) $< -o $@

    test: $(OBJECTS) s21_matrix.a
		$(CC) -g $(CFLAGS) -fprofile-arcs -ftest-coverage -o ./s21test $^ -lcheck -lm

    gcov_report: test
		$(CC) --coverage $(CFLAGS) -o s21test *.c  ./functions/*.c ./s21_test/*.c -lcheck
		chmod +x ./s21test && ./s21test
		lcov -t "s21test" -o s21test.info -c -d .
		genhtml -o gcov-report s21test.info
		open ./gcov-report/index.html

    lib:
		brew install check
		brew install lcov
endif

clean:
	rm -rf *.o *.a s21_test/*.gcno s21_test/*.gcda functions/*.gcda functions/*.gcno s21_test/s21test
	rm -r gcov-report *.info functions/*.o s21_test/*.o

rebuild: clean all
