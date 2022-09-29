#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include "../code_1/WordDecoder.hpp"

using namespace std;



int main(int argc, char* argv[])
{
    // DO NOT MODIFY THIS.
    if(argc>1)
    {
         freopen(argv[1],"r",stdin);
    }

    /* TODO- 
              1. cout #>
              2. get the user input
              3. store them in an array
              4. If the array is empty then print "Nothing to evaluate"
                 else call the evaluate function
    */

    cout << "Enter the encoded word separated by '(' and ')'" << endl << "#>";
    
    string importantLine;
    getline(cin,importantLine);
    const int constInt = importantLine.length();

    if (importantLine == "") {
        cout << "Nothing to evaluate";
    }
    else {
        string betterArray[constInt];
        for (int i = 0; i < constInt; i++) {
            betterArray[i] = importantLine[i];
        }
        WordDecoder object;
        //string* importantPtr = &importantLine;
        object.evaluate(betterArray, constInt);
    }
    
    return 0;
}
