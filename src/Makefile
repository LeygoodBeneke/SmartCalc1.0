FLAGS=-Wall -Werror -Wextra -std=c11 `pkg-config --cflags gtk4` `pkg-config --libs gtk4`
COVERAGE=
UNAME:=$(shell uname -s)
GTK_FLAGS=-I/usr/include/gtk-4.0 -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/sysprof-4 -I/usr/include/harfbuzz -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/graphene-1.0 -I/usr/lib/graphene-1.0/include -mfpmath=sse -msse -msse2 -pthread
GTK_LIBS=-lgtk-4 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lgdk_pixbuf-2.0 -lcairo-gobject -lcairo -lgraphene-1.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0

FF=pkg-config --cflags gtk4
FL=pkg-config --libs gtk4

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
s21_smart_calc.o: */*.c
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

