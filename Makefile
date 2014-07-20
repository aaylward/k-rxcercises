SOURCES = src
TEST = test
FILES = ex2_5.c util.c
DEPS = $(TEST)/test_ex2_5.c $(addprefix $(SOURCES)/, $(FILES))
OBJS = test_ex2_5.o ex2_5.o util.o

all:
	gcc -c $(DEPS)
	gcc -o run_tests $(OBJS)
	rm -f *.o

