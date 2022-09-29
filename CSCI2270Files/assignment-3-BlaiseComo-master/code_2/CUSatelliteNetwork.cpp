/********************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/********************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*     This class uses a linked-list of satellite structs to        */
/*     represent communication paths between satellites             */
/********************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Add a new satellite to the network
 *   between the satellite *previous and the satellite that follows it in the network.
 * @param previous - name of the satellite that comes before the new satellite
 * @param satelliteName - name of the new satellite
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) {
    // TODO
    if (previous == "First" || previous == "") {

        cout << "adding: " << satelliteName << " (HEAD)" << endl;

        if (head == NULL || head == nullptr) {

            head = new CUSatellite;
            head->name = satelliteName;
            head->distanceFromEarth = distance;
            head->next = nullptr;

        }

        else {

            CUSatellite* satellite = new CUSatellite;

            satellite->name = satelliteName;
            satellite->distanceFromEarth = distance;

            satellite->next = head;

            head = satellite;

        }

    }


    else {

        /*if (head == NULL) {

            head = new CUSatellite;
            head->name = satelliteName;
            head->distanceFromEarth = distance;

        }*/

        CUSatellite* satellite = new CUSatellite;
        CUSatellite* prevSatellite = new CUSatellite;
        
        prevSatellite = head;

        while ((prevSatellite->name != previous) && (prevSatellite->next != NULL)) {

            prevSatellite = prevSatellite->next;

        }

        if (prevSatellite->name == previous) {

            cout << "adding: " << satelliteName << " (prev: " << prevSatellite->name << ")" << endl;

            satellite->name = satelliteName;
            satellite->distanceFromEarth = distance;

            satellite->next = prevSatellite->next;
            prevSatellite->next = satellite;

        }
        else {
            cout << "Cannot add new node; previous node not found\n" << endl;
        }

    }
}


/*
 * Purpose: populates the network with the predetermined satellites
 * @param none
 * @return none
 */

void CUSatelliteNetwork::loadDefaultSetup(){
    // TODO 

    string arrayOfSatellites[6] = {"MAVEN", "JUNO", "PIONEER", "GALILEO", "KEPLER", "TESS"};
    int arrayOfNums[6] = {9,4,5,6,10,2};

    for (int i = 0; i < 6; i++) {
        this->addSatelliteInfo("First", arrayOfSatellites[i], arrayOfNums[i]);
    }

   /*
   CUSatelliteNetwork::addSatelliteInfo("First", "MAVEN", 9);
   CUSatelliteNetwork::addSatelliteInfo("First", "JUNO", 4);
   CUSatelliteNetwork::addSatelliteInfo("First", "PIONEER", 5);
   CUSatelliteNetwork::addSatelliteInfo("First", "GALILEO", 6);
   CUSatelliteNetwork::addSatelliteInfo("First", "KEPLER", 10);
   CUSatelliteNetwork::addSatelliteInfo("First", "TESS", 2);
   */

}


/*
 * Purpose: Search the network for the specified satellite and return a pointer to that node
 * @param satelliteName - name of the satellite to look for in network
 * @return pointer to node of satelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName){
    // TODO
    CUSatellite* satellite1 = new CUSatellite;
    if (head != nullptr && head != NULL) {
        satellite1 = head;
    }
    else {
        return nullptr;
    }
    
    while (satellite1->name != satelliteName && satellite1->next != nullptr && satellite1->next != NULL) {

        satellite1 = satellite1->next;

    }

    if (satellite1->name == satelliteName) {
        return satellite1;
    }

    return nullptr;
}


/*
 * Purpose:
 * @param string receiver
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver) {

    if (head == NULL) {

        cout << "Empty list" << endl;
        return;

    }

    if (searchForSatellite(receiver) == nullptr) {

        cout << "Satellite not found\n";
        return;

    }
    // TODO

    CUSatellite* satellite = new CUSatellite;
    satellite = head;
    while (satellite != NULL && satellite != nullptr) {
        satellite->message = "distance of " + satellite->name + " from earth is " + to_string(satellite->distanceFromEarth);
        satellite->numberMessages = satellite->numberMessages + 1;
        cout << satellite->name << " [# messages received: " << satellite->numberMessages << "] received: " << satellite->message << endl;

        if (satellite->name == receiver) {
            break;
        }
        satellite = satellite->next;
    }

}

/*
 * Purpose: prints the current list nicely
 * @param none
 * @return none
 */
void CUSatelliteNetwork::printNetwork() {
     /*
    DO NOT MODIFY THIS FUNCTION
    This function is already complete and is used for testing of other functions. 
    */
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUSatellite* ptr = head;
    if (ptr == NULL) {
        cout << "nothing in path" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->distanceFromEarth << ")" <<" -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
