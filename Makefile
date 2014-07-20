SOURCE_DIR = src
TEST_DIR = test
SOURCES = section_2_8.c util.c
DEPS = $(TEST_DIR)/test_runner.c $(addprefix $(SOURCE_DIR)/, $(SOURCES))
OBJS = test_runner.o section_2_8.o util.o

all:
	gcc -c $(DEPS)
	gcc -o run_tests $(OBJS)
	rm -f *.o

