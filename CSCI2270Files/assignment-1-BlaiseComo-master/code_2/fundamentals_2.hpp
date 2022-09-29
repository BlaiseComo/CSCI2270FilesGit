#ifndef READFILE2_H__
#define READFILE2_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct studentData {
    string studentName;
    int homework;
    int recitation;
    int quiz;
    int exam;
    double average;
};

// TODO add detailed explanation on what the function should do
// The addStudentData function should take the given data, inside the function a struct object is defined, the given data is then added to that struct object, the struct object is then
// added to the array that was also passed into the function
void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int length);
// The calcLetterGrade function is simple, it simply takes a double value as an argument and passses the value through a series of elif statments and a letter grade is returned 
char calcLetterGrade(double avg);


#endif // READFILE2_H__