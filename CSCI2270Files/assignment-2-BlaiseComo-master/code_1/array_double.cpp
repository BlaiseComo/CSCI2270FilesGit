#include "array_double.hpp"

void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]){

    ifstream stopWords;

    string ignoreWordsFile = "";

    // This for loop gathers the characters in ignoreWordFileName and inserts them into a usable string

    for (long unsigned int i = 0; i < strlen(ignoreWordFileName); i++) {

        ignoreWordsFile += ignoreWordFileName[i];

    }

    stopWords.open(ignoreWordsFile);

    string line;

    int count = 0;

    if (stopWords.is_open()) {

        while (getline(stopWords, line)) {

            ignoreWords[count] = line;

            count++;

        }

    }

    else {

        cout << "Failed to open " << ignoreWordsFile << endl;

    }

}


bool isIgnoreWord(string word, string ignoreWords[], int length){

    for (int i = 0; i < length; i++) {

        if (ignoreWords[i] == word) {

            return true;

        }
        
    }

    return false;

}


int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length){

    int count1 = 0;

    for (int i = 0; i < length; i++) {

        count1 = count1 + distinctWords[i].count;

    }

    return count1;

}


void sortArray(wordRecord distinctWords[], int length){

    // This for loop sorts the words based by count

   for (int i = 1; i < length; i++) {

       /*

        if (i % 1000 == 0) {

            cout << "Progress " << i << " out of " << length << endl;

       }
       */

       if (distinctWords[i].count > distinctWords[i-1].count) {

           wordRecord temp = distinctWords[i-1];

           distinctWords[i-1] = distinctWords[i];

            distinctWords[i] = temp;

            i = 0;

       }

    }
    

    int checkpoint=1;

    // This for loop sorts the words based on alphabetical order after the previous loop has finished. 

   for (int i = 1; i < length; i++) {
/*
       if (i % 1000 == 0) {

            cout << "Progress " << i << " out of " << length << endl;

       } */
       

       if (distinctWords[i].count == distinctWords[i-1].count) {

           string smallerWord;

           if (distinctWords[i].word.length() < distinctWords[i-1].word.length()) {
               smallerWord = distinctWords[i-1].word;
           }
           else {
               smallerWord = distinctWords[i].word;
           }

           for (long unsigned int x = 0; x < smallerWord.length(); x++) {

                int currentNum = static_cast<int>(distinctWords[i].word[x]);
                int lastNum = static_cast<int>(distinctWords[i-1].word[x]);

                if (currentNum < lastNum) {

                    wordRecord temp = distinctWords[i];

                    distinctWords[i] = distinctWords[i-1];

                    distinctWords[i-1] = temp;

                    i = checkpoint-1;

                    break;

                }

                else if (currentNum == lastNum) {

                    continue;

                }

                else {

                    break;

                }

           }

       }

       else {

           checkpoint = i;

       } 
   }
   
   

}


void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords){

    for (int i = 0; i < 10; i++) {

        cout << fixed << showpoint << setprecision(5);

        cout << static_cast<float>(distinctWords[N+i].count) / static_cast<float>(totalNumWords) << " - " << distinctWords[N+i].word << endl;

    }


}

