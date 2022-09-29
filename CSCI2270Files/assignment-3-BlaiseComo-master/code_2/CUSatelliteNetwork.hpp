/****************************************************************/
/*                  CUSatelliteNetwork Definition               */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

//#pragma once
#ifndef CUSatelliteNetwork_H__
#define CUSatelliteNetwork_H__
#include <iostream>
using namespace std;

// CUSatellite: node struct that will be stored in the CUSatelliteNetwork
struct CUSatellite{
    string name;         // name of the satellite
    string message;      // message this satellite has received
    int numberMessages=0;  // no. of messages passed through this satellite
    CUSatellite *next;   // pointer to the next satellite
    int distanceFromEarth; // distance of satellite from earth in light years
};

// class for storing and manipulating linked-list of satellites
class CUSatelliteNetwork {
    private:
        CUSatellite* head;  // pointer to head of linked list of satellites

    public:
        // You will need to define the below unfinished methods in CUSatelliteNetwork.cpp
        CUSatelliteNetwork();
        void addSatelliteInfo(string previous, string satelliteName, int distance);
        void loadDefaultSetup();
        CUSatellite* searchForSatellite(string satelliteName);
        void transmitInfo(string receiver);
        void printNetwork();
};
#endif
