#ifndef READFILE_H__
#define READFILE_H__

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct wordRecord {
	string word;
	int count;
};

// TODO add detailed explanation on what the function should do
// getIgnoreWords takes the ignorewords file name and array as an argument, and then reads the words from the file into the array
void getIgnoreWords(const char *ignoreWordFileName, string ignoreWords[]);
// isIgnoreWord takes a word and array and checks every word in the array to see if it matches the word that was passed in the function
bool isIgnoreWord(string word, string ignoreWords[], int length);
// getTotalNumberNonIgnoreWords gets the total number of non ignore words in the document by adding up all the counts associated with the words in the given array
int getTotalNumberNonIgnoreWords(wordRecord distinctWords[], int length);
// sortArray sorts the given array in descending order, first by the count of each word, and then, if the the counts of words are the same
// then the words will be sorted in alphabeitical order using the ascii value of the characters of the words
void sortArray(wordRecord distinctWords[], int length);
// printTenFromN takes an integer N and prints the probability of a word occuring and the word itself from an integer N in the array of words that has been sorted. 
void printTenFromN(wordRecord distinctWords[], int N, int totalNumWords);

#endif // READFILE_H__