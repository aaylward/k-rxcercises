SOURCE_DIR = src
TEST_DIR = test
SOURCES = ex2_5.c util.c
DEPS = $(TEST_DIR)/test_runner.c $(addprefix $(SOURCE_DIR)/, $(SOURCES))
OBJS = test_runner.o ex2_5.o util.o

all:
	gcc -c $(DEPS)
	gcc -o run_tests $(OBJS)
	rm -f *.o

