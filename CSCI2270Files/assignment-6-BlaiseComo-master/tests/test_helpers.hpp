#ifndef TEST_H__
#define TEST_H__
#include <string>
#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// TODO add detailed explanation on what the function should do
std::string exec(const char* cmd);
std::string readFileIntoString(std::string fileName);
string test_add(string* name,int* ranking, int* year, float* rating, int len);
string test_find(string* name,int* ranking, int* year, float* rating, int len, string key);
string test_query(string* name,int* ranking, int* year, float* rating, int len, float rtg, int yr);
string test_avgrating(string* name,int* ranking, int* year, float* rating, int len);
string test_printLevelK(string* name,int* ranking, int* year, float* rating, int len);

#endif // TEST_H__