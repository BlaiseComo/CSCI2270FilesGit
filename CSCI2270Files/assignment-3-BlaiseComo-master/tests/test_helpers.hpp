#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>
#include "../code_2/CUSatelliteNetwork.hpp"


using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
string test_append(int totalElements, string expected_output);
string test_search(string searchkey, bool build);
string test_addSatelliteinfo(string prev, string name, int distance, CUSatelliteNetwork *netPointer);
string test_loadDeafultSetup();
string test_transmitInfo(string arr[], int len, bool build);


#endif // TEST_H__