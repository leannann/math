WWW = -Werror -Wextra -Wall
G = gcc

all : s21_math.a test gcov_report

clean: 
	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info test test_html

test: 
	$(G) $(WWW) s21_*.c tests.c -lcheck -o test

s21_math.a:
	$(G) $(WWW) -c s21_*.c
	ar r s21_math.a *.o
	rm *.o

gcov_report:
	$(G) $(WWW) -fprofile-arcs -ftest-coverage tests.c s21_*.c -pthread -lcheck -pthread -lm -o test
	./test
	lcov -t "test_html" -o tests.info -c -d .
	genhtml -o test_html tests.info
	open test_html/index.html

rebuild: clean all
