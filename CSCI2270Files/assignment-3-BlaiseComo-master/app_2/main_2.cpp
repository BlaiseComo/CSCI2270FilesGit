#include "../code_2/CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

     // DO NOT MODIFY THIS.
    if(argc>1) 
    {
        freopen(argv[1],"r",stdin);
    }
     // DO NOT MODIFY ABOVE.

    // TODO

    CUSatelliteNetwork SN;

    int option = 0;
    int count = 0;

    while (option != 5) {

        displayMenu();

        if (count > 0) {
            //cin.ignore(100,'\n');
            cin >> option;
        }
        else {
            cin >> option;
        }

        switch (option) {

            case 1:
            {
                SN.loadDefaultSetup();
                SN.printNetwork();
                break;
            }

            case 2:
            {
                SN.printNetwork();
                break;
            }

            case 3:
            {
                string satellite;
                cout << "Enter name of the recipient to receive the message: " << endl;
                cin.ignore(10000,'\n');
                getline(cin, satellite);
                cout << endl;
                SN.transmitInfo(satellite);
                break;
            }

            case 4:
            {
                string newSatellite;
                int distanceFromEarth1;
                string previousSatellite;

                cout << "Enter a new satellite name: ";
                cin.ignore(10000, '\n');
                getline(cin, newSatellite);
                cout << "\nEnter distance of satellite from earth: ";
                //cin.ignore(100, '\n');
                cin >> distanceFromEarth1;
                cout << "\nEnter the previous satellite name (or First): ";
                cin.ignore(10000, '\n');
                getline(cin, previousSatellite);
                cout << "\n";

                while ((SN.searchForSatellite(previousSatellite) == nullptr) && (previousSatellite != "First")) {
                    cout << "INVALID(previous satellite name)...Please enter a VALID satellite name!" << endl;
                    getline(cin, previousSatellite);
                }

                SN.addSatelliteInfo(previousSatellite, newSatellite, distanceFromEarth1);

                SN.printNetwork();

                break;
            }

            case 5:
            {
                cout << "Quitting..." << endl;
                break;
            }
            
        }
        count++;

    }

    cout << "Goodbye!" << endl;
    
    return 0;
}




/************************************************
           Definitions for main_2.cpp
************************************************/
void displayMenu()
{
    // COMPLETE
    cout << "Select a numerical option: " << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Broadcast Info " << endl;
    cout << " 4. Add Satellite " << endl;
    cout << " 5. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
