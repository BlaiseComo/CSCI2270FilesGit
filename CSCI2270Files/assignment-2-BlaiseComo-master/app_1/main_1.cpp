#include <iostream>
#include <fstream>
#include "../code_1/array_double.hpp"

using namespace std;

int main(int argc, char* argv[])
{

    int arraySize = 100;

    int usedWordsSize = 100;

    int doubleCount = 0;

    int N = stoi(argv[1]);

    string importantText = argv[2];
    const char* ignoreWordsFileName = argv[3];

    int ignoreWordsLength = 51;

    string ignoreWords[ignoreWordsLength];

    getIgnoreWords(ignoreWordsFileName, ignoreWords);

    ifstream importantFile;

    importantFile.open(importantText);

    wordRecord* distinctWords = new wordRecord[arraySize];

    string word1;

    int fileCount = 0;

    int importantArraySize = 0;

    string* usedWordsArray = new string[usedWordsSize];

    // This loop gathers all of the words from the main file

    while (importantFile >> word1) {

        string currentWord = word1;

        // This conditional statement makes sure that the current word is not a stopword

        if (isIgnoreWord(currentWord, ignoreWords, ignoreWordsLength) == true) {

            continue;

        }

        bool redFlag;

        // The below for loop prevents the same word from being added to the distinctWords array

        for (int x = 0; x < fileCount; x++) {

            if (usedWordsArray[x] == currentWord) {

                redFlag = true;
                break;

            }

            else {

                redFlag = false;

            }

        }

        if (redFlag == false) {

            distinctWords[importantArraySize].word = word1;
            importantArraySize++;

        }

        // This is the array doubling algorithm that uses temporary arrays to double the main arrays in the heap

        if (importantArraySize == arraySize-1) {

            arraySize = arraySize * 2;

            wordRecord tempArray[arraySize];

            for (int i = 0; i < importantArraySize; i++) {
                tempArray[i] = distinctWords[i];
            }

            distinctWords = new wordRecord[arraySize];

            for (int i = 0; i < importantArraySize; i++) {
                distinctWords[i] = tempArray[i];
            }

            doubleCount++;
            
        }

        if (fileCount == usedWordsSize-1) {

            usedWordsSize = usedWordsSize * 2;

            string tempArray[usedWordsSize];

            for (int i = 0; i < fileCount; i++) {
                tempArray[i] = usedWordsArray[i];
            }

            usedWordsArray = new string[usedWordsSize];

            for (int i = 0; i < fileCount; i++) {
                usedWordsArray[i] = tempArray[i];
            }
        }

        usedWordsArray[fileCount] = word1;

        fileCount++;

    }

    // This for loop adds up the count for each word in the document and adds it to the count aspect of the struct for that word
    for (int i = 0; i < importantArraySize+1; i++) {

        int currentWordCount = 0;

        string currentWord = distinctWords[i].word;

        for (int x = 0; x < fileCount; x++) {

            if (usedWordsArray[x] == currentWord) {

                currentWordCount++;

            }

        }

        distinctWords[i].count = currentWordCount;

    }

    sortArray(distinctWords, importantArraySize);

    cout << "Array doubled: " << doubleCount << endl;
    cout << "Distinct non-common words: " << importantArraySize << endl;
    cout << "Total non-common words: " << getTotalNumberNonIgnoreWords(distinctWords, importantArraySize) << endl;
    cout << "Probability of next 10 words from rank " << N << endl;
    cout << "---------------------------------------" << endl;

    int totalWords = getTotalNumberNonIgnoreWords(distinctWords, importantArraySize);
    printTenFromN(distinctWords, N, totalWords);


    delete [] distinctWords;
    delete [] usedWordsArray;

    
    return 0;

}