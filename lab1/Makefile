# the compiler: gcc for C program, define as g++ for C++
CC = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall
 
# The build target 
TARGET = lab1
 
all: $(TARGET)

$(TARGET) : clean compile run

compile: file_in.cpp
	$(CC) $(CFLAGS) -o $(TARGET) file_in.cpp
 
clean:
	$(RM) $(TARGET)

run:
	./${TARGET}
