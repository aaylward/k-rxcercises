SOURCES = src
TESTS = test
FILES = ex2_5.c util.c
DEPS = $(TESTS)/test_ex2_5.c $(addprefix $(SOURCES)/, $(FILES))
OBJS = test_ex2_5.o ex2_5.o util.o

compile:
	gcc -c $(DEPS)
	gcc -o run_tests $(OBJS)
	rm -f *.o

clean:
	rm -f run_tests
