#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    studentData studentArray[5];
    
    if (argc < 5) {

        cout << "Missing command line arguments!\n";

        return -1;

    }

    string inputFile = argv[1];
    string outputFile = argv[2];
    string lowGrade = argv[3];
    string highGrade = argv[4];

    // These variable definitions and elif statements are part of the system I used to check and make sure that the grades of the students
    // meet the conditions of the command line arguments
    double lowBound, highBound;

    if (lowGrade == "A" || lowGrade == "a") {
        lowBound = 4;
    }
    else if (lowGrade == "B" || lowGrade == "b") {
        lowBound = 3;
    }
    else if (lowGrade == "C" || lowGrade == "c") {
        lowBound = 2;
    }
    else if (lowGrade == "D" || lowGrade == "d") {
        lowBound = 1;
    }
    else if (lowGrade == "F" || lowGrade == "f") {
        lowBound = 0;
    }

    if (highGrade == "A" || highGrade == "a") {
        highBound = 4;
    }
    else if (highGrade == "B" || highGrade == "b") {
        highBound = 3;
    }
    else if (highGrade == "C" || highGrade == "c") {
        highBound = 2;
    }
    else if (highGrade == "D" || highGrade == "d") {
        highBound = 1;
    }
    else if (highGrade == "F" || highGrade == "f") {
        highBound = 0;
    }

    ifstream studentInputFile;
    studentInputFile.open(inputFile);

    if (studentInputFile.is_open()) {

        string line;

        int index = 0;

        while (getline(studentInputFile, line)) {

            string studentName;
            string studentHomework;
            string studentRecitation;
            string studentQuiz;
            string studentExam;

            // This is the method I used to gather the data and assign it to seperate variables depending on how many commas have been added to the commacache
            int commacache=0;

            for (long unsigned int i = 0; i < line.length(); i++) {

                if (line[i] == ',') {

                    commacache++;

                    continue;

                }

                if (commacache == 0) {

                    studentName += line[i];

                }

                else if (commacache == 1) {

                    studentHomework += line[i];

                }

                else if (commacache == 2) {

                    studentRecitation += line[i];

                }

                else if (commacache == 3) {

                    studentQuiz += line[i];

                }

                else if (commacache == 4) {

                    studentExam += line[i];
                    
                }

            }

            // I attempted to use stoi(), though the program kept failing when I did that, so I tried the below method instead and it seemed to work
            // I believe it might have to do something with the version of C++
            int studentHomework2 = atoi(studentHomework.c_str());
            int studentRecitation2 = atoi(studentRecitation.c_str());
            int studentQuiz2 = atoi(studentQuiz.c_str());
            int studentExam2 = atoi(studentExam.c_str());

            addStudentData(studentArray, studentName, studentHomework2, studentRecitation2, studentQuiz2, studentExam2, index);

            index++;

        }

    }

     else {

        cout << "Error opening file!\n";

        return -1;

    }

    ofstream studentOutputFile; 
    studentOutputFile.open(outputFile);

    for (int i = 0; i < 5; i++) {

        // This is the next part of the system for determing if the students grade meet the command line arguments criteria
        int grade_comparison;

        if (calcLetterGrade(studentArray[i].average) == 'A') {
            grade_comparison = 4;
        }
        else if (calcLetterGrade(studentArray[i].average) == 'B') {
            grade_comparison = 3;
        }
        else if (calcLetterGrade(studentArray[i].average) == 'C') {
            grade_comparison = 2;
        }
        else if (calcLetterGrade(studentArray[i].average) == 'D') {
            grade_comparison = 1;
        }
        else {
            grade_comparison = 0;
        }

        // The two parts of the system come together and the upper grade and lower grade are compared against the determined student grade
        if ((grade_comparison <= highBound) && (grade_comparison >= lowBound)) {

            studentOutputFile << studentArray[i].studentName << "," << showpoint << fixed << setprecision(2) << studentArray[i].average << "," << calcLetterGrade(studentArray[i].average) << endl;

            cout << studentArray[i].studentName << "," << studentArray[i].average << "," << calcLetterGrade(studentArray[i].average) << endl;

        }

    }

    studentOutputFile.close();
 
    return 0;
}