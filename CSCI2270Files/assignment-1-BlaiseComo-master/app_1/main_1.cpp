#include <iostream>
#include <fstream>
#include <string>
#include "../code_1/fundamentals_1.hpp"


using namespace std;

int main(int argc, char* argv[])
{
    // This conditional statement makes sure there are enough arguments
    if (argc < 2) {

        cout << "Missing file argument" << endl;

        return -1;

    }

    string fileName = argv[1];

    ifstream dataFile;

    dataFile.open(fileName);

    float arrayOfFloats[100];

    string line;

    float fileNum;

    int sizeArray = 0;

    // This conditional statement checks to make sure the file is open
    if (dataFile.is_open()) {

        while (getline(dataFile, line)) {

            sizeArray++;

            fileNum = stof(line);

            addToArrayDesc(arrayOfFloats, sizeArray, fileNum);

            for (int i = 0; i < sizeArray; i++) {

                if (i < sizeArray-1) {
                
                    cout << arrayOfFloats[i] << ",";

                }

                else {

                    cout << arrayOfFloats[i];

                }
            
            }

            cout << "\n";

        }

        return 0;

    }

    else {

        cout << "Failed to open the file." << endl;

        return -1;

    }

    
}