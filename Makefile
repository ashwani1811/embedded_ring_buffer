CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Isrc -Itests/unity

SRC = src/ring_buffer.c
TEST_SRC = tests/test_ring_buffer.c tests/unity/unity.c

# Detect Operating System & Set Executable Extension + Commands
ifeq ($(OS),Windows_NT)
    TARGET = test_runner.exe
    RM = del /Q /F
    RUN_TARGET = .\$(TARGET)
    CPPCHECK = "cppcheck.exe"
else
    TARGET = test_runner
    RM = rm -f
    RUN_TARGET = ./$(TARGET)
    CPPCHECK = cppcheck
endif

.PHONY: all test misra clean

all: test

test: $(SRC) $(TEST_SRC)
	$(CC) $(CFLAGS) $(SRC) $(TEST_SRC) -o $(TARGET)
	$(RUN_TARGET)

misra:
	$(CPPCHECK) --enable=all --addon=misra --suppress=missingIncludeSystem --suppress=unusedFunction --suppress=staticFunction --suppress=misra-c2012-8.7 --error-exitcode=1 src/

clean:
	$(RM) $(TARGET)