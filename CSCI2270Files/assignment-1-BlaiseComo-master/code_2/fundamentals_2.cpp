#include "fundamentals_2.hpp"

char calcLetterGrade(double avg)
{

    // A series of elif statements if used to check the value and a letter grade is returned depending on the value

    if (avg >= 90) {

        return 'A';

    }

    else if (80 <= avg && avg <= 89.9) {

        return 'B';

    }

    else if (70 <= avg && avg <= 79.9) {

        return 'C';

    }

    else if (60 <= avg && avg <= 69.9) {

        return 'D';

    }

    else {

        return 'F';
        
    }

}

void addStudentData(studentData students[], string studentName, int homework, int recitation, int quiz, int exam, int index)
{

    struct studentData student;

    student.studentName = studentName;
    student.homework = homework;
    student.recitation = recitation;
    student.quiz = quiz;
    student.exam = exam;
    student.average = (homework + recitation + exam + quiz) / 4.00;

    students[index] = student;
 
}