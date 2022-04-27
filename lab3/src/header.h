#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include <cstdlib>
#include<sstream>
#include<fstream>//we will use this header file to read our csv file.
#include<set>
#include<algorithm>
#include<map>
#include <iomanip>

using namespace std;

struct student{
    string StudentId;
    string CourseNumber;
    string InstructorId,TermId,SectoionId,Grade;
};

struct Instructor{
    string Ins_ID;
    string Ins_Course;
    string Ins_Term;
};

struct Term{
    string T_id,Display_name;
};

struct Course{
    string student_Id,Course_Number,SectionCode,Term;
};
std::ofstream outputfile;


vector<Course> All_Course;
vector<student>AllData;
int cnt=0;
vector<Instructor>All_Instructor;
set<string>INS;
set<string>CRS;
int Fall_size=6;
int Spring_size=6;
string Fall[]={"T04","T08","T12","T16","T20","T23"};
string Spring[]={"T02","T06","T10","T14","T18","T21"};

void write_function(int n);
void file_input(string file);
void Course_summarization();
void Instructor_summarization();
void pass_rate();
void Fall_rate();
void Spring_rate();
void W_rate();
