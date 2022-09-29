#include <iostream>
#include <fstream>
#include "../code_1/generateSeries.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    int arraySize = 4;
    int m = 4;
    int n = 3;
    int seriesArray[arraySize];

    int* arrayPointer = seriesArray;
    // Enter your code to test out your 'generateSeries' function if you wish to.
    // Code written here would not count towards your grade for this assignment.
    generateSeries(arrayPointer, n, m, arraySize);
    for (int i = 0; i < arraySize; i++) {

        cout << seriesArray[i] << " ";

    }

    cout << endl;
    
    return 0;
}