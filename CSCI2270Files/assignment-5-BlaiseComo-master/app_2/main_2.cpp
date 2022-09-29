#include "../code_2/WaitlistQueue.hpp"
#include <iostream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
    cout << "*----------------------------------------*" << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Resize" << endl;
    cout << "5. Quit" << endl;
    cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 2)
    {
        freopen(argv[2],"r",stdin);
    }
    
    /* TODO */

    WaitlistQueue object(stoi(argv[1]));

    bool quitOption = false;

    while (quitOption == false) {

        int option;

        menu();

        cin >> option;

        switch (option) {

            case 1:
            {
                string enqueueString;
                cout << "Enter the value to add into queue:" << endl;
                cin.ignore(1000, '\n');
                getline(cin, enqueueString);
                object.enqueue(enqueueString);
                break;
            }
            case 2:
            {
                object.dequeue();
                break;
            }
            case 3:
            {
                cout << object.peek() << endl;
                break;
            }
            case 4:
            {
                int newSize;
                cout << "Enter the new capacity:" << endl;
                cin >> newSize;
                cout << "Resizing from " << stoi(argv[1]) <<  " to " << newSize << endl;
                object.resize(newSize); 
                break;
            }
            case 5:
            {
                cout << "Quitting..." << endl;
                cout << "Contents of the queue:" << endl;
                for (int i = object.getQueueFront(); i < object.getQueueEnd()+1; i++) {
                    if (object.getQueue()[i] != "") {
                        cout << object.getQueue()[i] << endl;
                    }
                }
                cout << "Goodbye!" << endl;
                quitOption = true;
                break;
            }
            default:
            {
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                cin >> option;
                break;
            }
        }

    }
    
    return 0;
}