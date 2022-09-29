/*******************************************************************/
/*                CUSatelliteNetwork Implementation                 */
/*******************************************************************/
/* TODO: Implement the member functions of class CUSatelliteNetwork */
/*       This class uses a linked-list of CUSatellite nodes to      */
/*       represent communication paths between Satellites           */
/*******************************************************************/

#include "CUSatelliteNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
CUSatelliteNetwork::CUSatelliteNetwork() 
{
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUSatelliteNetwork::isEmpty()
{
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new Satellite to the network
 *   between the Satellite previous and the Satellite that follows it in the network.
 * @param previous - name of the Satellite that comes before the new Satellite
 * @param SatelliteName - name of the new Satellite 
 * @param distance - distance of satellite from earth
 * @return none
 */
void CUSatelliteNetwork::addSatelliteInfo(string previous, string satelliteName, int distance) 
{     
    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: populates the network with the predetermined CUSatellites
 * @param none
 * @return none
 */
void CUSatelliteNetwork::loadDefaultSetup()
{
    deleteEntireNetwork();
    // TODO: Copy-paste your solution from Assignment 3
    string arrayOfSatellites[6] = {"MAVEN", "JUNO", "PIONEER", "GALILEO", "KEPLER", "TESS"};
    int arrayOfNums[6] = {9,4,5,6,10,2};

    for (int i = 0; i < 6; i++) {
        this->addSatelliteInfo("First", arrayOfSatellites[i], arrayOfNums[i]);
    }

}

/*
 * Purpose: Search the network for the specified Satellite and return a pointer to that node
 * @param SatelliteName - name of the Satellite to look for in the network
 * @return pointer to node of SatelliteName, or NULL if not found
 *
 */
CUSatellite* CUSatelliteNetwork::searchForSatellite(string satelliteName)
{
    // TODO: Copy-paste your solution from Assignment 3
    
    CUSatellite* satellite1 = head;
    if (head != nullptr) {
        satellite1 = head;
    }
    else {
        return nullptr;
    }
    
    while (satellite1->name != satelliteName && satellite1->next != nullptr) {

        satellite1 = satellite1->next;

    }

    if (satellite1->name == satelliteName) {
        return satellite1;
    }

    return nullptr;
}

/*
 * Purpose: Relay a message through the linked list until the specified Satellite
 * @param string receiver - name of the Satellite 
 * @return none
 */
void CUSatelliteNetwork::transmitInfo(string receiver)
{
    // TODO: Copy-paste your solution from Assignment 3
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

 * Purpose: prints the current list in an organized manner
 * @param none
 * @return none

 */
void CUSatelliteNetwork::printNetwork() 
{
    /* finished. do not touch. */
    cout << "== CURRENT PATH ==" << endl;

    if (head)
    {
        CUSatellite* temp = head;
        
        while (temp)
        {
            cout << temp->name << "(" << temp->distanceFromEarth << ") -> ";
            temp = temp->next;
        }
        cout << "NULL";
    }
    else
    {
        cout << "nothing in path";
    }

    cout << endl << "===" << endl;


}

/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/

/*
 * Purpose: Delete the Satellite in the network with the specified name.
 * @param SatelliteName - name of the Satellite to delete in the network
 * @return none
 */
void CUSatelliteNetwork::deleteCUSatellite(string satelliteName)

{

    CUSatellite* traverser = head;
    CUSatellite* previous = nullptr;

    if (head == NULL) {

        cout << "Satellite does not exist." << endl;
        return;

    }

    if (traverser->name == satelliteName) {
        if (head->next != NULL) {
            head = head->next;
        }
        else {
            head = NULL;
        }
        delete traverser;
        traverser = nullptr;
        return;
    }

    while (traverser->next != NULL) {

        if (traverser->name == satelliteName) {
            break;
        }

        previous = traverser;

        traverser = traverser->next;

    }

    if (traverser->name == satelliteName) {

        previous->next = traverser->next;
        delete traverser;
        return;


    }

    else {

        cout << "Satellite does not exist." << endl;

    }

}

/*
 * Purpose: deletes all Satellites in the network starting from the head Satellite.

 * @param: none
 * @return: none
 */
void CUSatelliteNetwork::deleteEntireNetwork()
{
    // TODO: Complete this function
    if (head == NULL) {
        return;
    }
    else {
        CUSatellite* destructor = head;

        while (destructor != NULL) {

            CUSatellite* tempDestructor = destructor->next;
            delete destructor;
            destructor = tempDestructor;
        }

        head = NULL;

    }

}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool CUSatelliteNetwork::detectLoop() 
{
    // TODO: Complete this function
    if (head == NULL || head->next == NULL) {
        return false;
    }

    CUSatellite* fast = head->next;
    CUSatellite* slow = head;

    while (fast->next->next != NULL && slow->next != NULL) {
        if (fast == slow) {
            return true;
        }

        fast = fast->next->next;
        slow = slow->next;

        if (fast == NULL || slow == NULL || fast->next == NULL) {
            break;
        }

    }

    
    return false;
}

/*
* Purpose: Creates a loop from last node to the Satellite specified.
* @param SatelliteName - name of the Satellite to loop back to
* returns the last node before loop creation (to break the loop)
*/

CUSatellite* CUSatelliteNetwork::createLoop(string satelliteName) 
{ 
    // TODO: Complete this function
    if (head == NULL) {
        return nullptr;
    }

    CUSatellite* intermediateNode = searchForSatellite(satelliteName);

    CUSatellite* lastNode = head;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    if (intermediateNode == nullptr) {
        return lastNode;
    } 

    CUSatellite* temp = lastNode;

    if (lastNode->next == NULL && intermediateNode->name == satelliteName) {
        lastNode->next = intermediateNode;
    }

    return temp;

}

/*
 * Purpose: Take the chunk of nodes from start index to end index and
 *          move that chunk to the end of the List
 * @param: start_index, end_index - indices of start node and the end node
 * @return: none
 */
// Instead of using an array, use a second linked list to store the values
// Traverse through the list to get to the node at the start index, connect it to the node at the end index, figure out the rest
void CUSatelliteNetwork::readjustNetwork(int start, int end)
{
    // TODO: Complete this function

    CUSatellite* startNode = head;

    int count = 0;

    while (count < start && startNode->next != NULL) {
        startNode = startNode->next;
        count++;
    }

    CUSatellite* lastNode = startNode;

    int numOfNodes = 1;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
        numOfNodes++;
    }

    count = 0;

    CUSatellite* endNode = head;
    while (endNode->next != NULL && count < end) {
        endNode = endNode->next;
        count++;
    }

    if (head == NULL) {
        cout << "Linked List is Empty" << endl;
    }
    else if (end > numOfNodes || end < 0) {
        cout << "Invalid end index" << endl;
    }
    else if (start > numOfNodes || start < 0) {
        cout << "Invalid start index" << endl;
    }
    else if (start > end) {
        cout << "Invalid indices" << endl;
    }
    else if (start == end) {
        CUSatellite* previous = head;
        while (previous->next != NULL && previous->next != startNode) {
            previous = previous->next;
        }
        previous->next = startNode->next;
        lastNode->next = startNode;
        startNode->next = NULL;
    }
    else if (start > 0) {
        lastNode->next = startNode;
        head->next = endNode->next;
        endNode->next = NULL;
    }
    else if (start == 0) {
        head = endNode->next;
        lastNode->next = startNode;
        endNode->next = NULL;
    }

}

/*
 * Purpose: Destructor to delete the entire list on program termination
 * @param none
 * @return none
 */
CUSatelliteNetwork::~CUSatelliteNetwork()
{
    // TODO: Complete this function
    deleteEntireNetwork();
    
}