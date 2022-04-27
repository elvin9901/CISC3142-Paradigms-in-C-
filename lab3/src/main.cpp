#include <iostream>
#include "header.h"
#include "aggregate.cpp"
#include "reading_writing.cpp"
using namespace std;


int main()
{
string file;
    file = "lab3/data/1115.csv";
    file_input(file);
    write_function(1);

    file = "lab3/data/3115.csv";
    file_input(file);
    write_function(2);

    file = "lab3/data/3130.csv";
    file_input(file);
    write_function(3);

    return 0;
}
