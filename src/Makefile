FLAGS=-Wall -Werror -Wextra -std=c11 `pkg-config --cflags gtk4` `pkg-config --libs gtk4` -lm
COVERAGE=
UNAME:=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lm -lrt -lpthread -lsubunit
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

all: clean s21_smart_calc.a
deafult: all
s21_smart_calc.o: */*.c backend/*/*.c
	gcc $(FLAGS) -c $^
s21_smart_calc.a: s21_smart_calc.o
	gcc $(FLAGS) -o SmartCalc *.o
clean:
	rm -rf *.a *.o *.out *.html *.gcno *.gcov *.gcda s21_test report SmartCalc
test: clean s21_smart_calc.a
	gcc $(FLAGS) $(COVERAGE) -o s21_test tests/s21_test.c tests/source/*.c s21_smart_calc.a $(LDFLAGS)
	./s21_test
add_coverage:
	$(eval FLAGS += --coverage)
gcov_report: add_coverage test
	./s21_test
	gcov -b -l -p -c s21_*.gcno
	gcovr -o gcov_report.html --html --html-details -g -k -r . --html --html-details --filter s21_smart_calc.c
	$(OPEN_CM) gcov_report.html

haha:
	$(FF)

