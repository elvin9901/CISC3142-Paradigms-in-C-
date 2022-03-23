# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target
TARGET = lab2

all: $(TARGET)

$(TARGET) : clean compile run

compile: Calculatornew1.cpp
	$(CC) $(CFLAGS) -o $(TARGET) Calculatornew1.cpp

clean:
	$(RM) $(TARGET)

run:
	./${TARGET}
