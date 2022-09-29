#include <iostream>
#include "WordDecoder.hpp"


using namespace std;


WordDecoder::WordDecoder()
{
    // TODO. Initialize all variables required
    stackHead = nullptr;
}

WordDecoder::~WordDecoder()
{
    //TODO. Free up to avoid memory leaks
    while (stackHead != NULL) {
        pop();
    }
    //pop();

}

bool WordDecoder::isEmpty()
{
    // TODO. Checking if stack is empty
    if (stackHead == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void WordDecoder::push(string letter)
{
    //TODO Perform push operation stack
    Letter* newNode = new Letter; 
    newNode->letter = letter;
    newNode->next = stackHead;
    stackHead = newNode;

}

void WordDecoder::pop()
{
    //TODO Perform pop operation stack
    if (isEmpty()) {
        cout << "Stack empty, cannot pop a letter." << endl;
    }
    else {
        Letter* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }

}

Letter* WordDecoder::peek()
{
    //TODO Perform peek operation stack
    if (stackHead == NULL) {
        cout << "Stack empty, Cannot peek." << endl;
    }
    else {
        return stackHead;
    }
    return nullptr;
}

void WordDecoder::evaluate(string* s, int size)
{
    /* TODO:
    1. Push to stack if letter in string not a ")"
    2. If ")" comes, then pop until "(", store somewhere. Put letters back to the stack in reverse order of pop.
    3. Finally, the elements are stored in reverse, so print in reverse order. */

    for (int i = 0; i < size; i++) {
        
        if (s[i] != ")") {
            push(s[i]);
        }
        else if (s[i] == ")") {
            string storageHolder[size];
            int x = 0;
            while (peek()->letter != "(") {
                storageHolder[x] = peek()->letter;
                pop();
                x++;
            }

            pop();

            for (int y = 0; y < x; y++) {
                push(storageHolder[y]);
            }

        }

    }

    cout << "The decoded word: ";
    
    string necessaryArray[size];

    int count = 0;

    while (!isEmpty()) {
        necessaryArray[count] = peek()->letter;
        pop();
        count++;
    }

    for (count >= 0; count--;) {
        cout << necessaryArray[count];
    }

    cout << endl;

    
}
