#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    bool flag = false;

    Blockchain buffCUoin;

    int blockNumber = 1;

    bool whileFlag = false;

    while (flag == false) {

        string option;
        
        cout << "Input the number corresponding to the procedure" << endl;
        cout << "==================Main Menu===================" << endl;
        cout << "1. Add a transaction" << endl;
        cout << "2. Verify Blockchain" << endl;
        cout << "3. Mine Pending Transactions" << endl;
        cout << "4. Print the Chain" << endl;
        cout << "5. Get Balance" << endl;
        cout << "6. Quit" << endl;

        getline(cin, option);

        cout << endl;
 
        if (option == "1") 
        {
            string source;
            cout << "Enter the name of the sender" << endl;
            getline(cin, source);

            string destination;
            cout << "Enter the name of the destination" << endl;
            getline(cin, destination);

            int amount;
            string stringAmount;
            cout << "Enter the amount" << endl;
            getline(cin, stringAmount);

            amount = stoi(stringAmount);
            buffCUoin.addTransaction(source, destination, amount);

            cout << endl;
        }

        else if (option == "2")
        {
            if (buffCUoin.isChainValid() == true)
            {
                cout << "Chain is valid" << endl;
            }

            else
            {
                cout << "Chain is invalid" << endl;
            }

            cout << endl;
        }

        else if (option == "3")
        {
            string name;
            cout << "Enter the name of the person who wants to mine a block" << endl;
            getline(cin, name);

            cout << name << " mining block " << blockNumber << " ..." << endl;
            buffCUoin.minePendingTransactions(name);

            blockNumber++;

            cout << endl;
        }

        else if (option == "4")
        {
            buffCUoin.prettyPrint();
        }

        else if (option == "5")
        {
            string name;
            cout << "Enter a name" << endl;
            getline(cin, name);

            cout << "Balance of " << name << ": " << buffCUoin.getBalanceOfAddress(name) << endl;

            cout << endl;

        }

        else if (option == "6")
        {
            flag = true;
        }

        else {

            cout << "Invalid Input. Please Try Again" << endl << endl;;

        }
    
    }

}