#include <gtest/gtest.h>
#include "test_helpers.hpp"
#include "../code_1/generateSeries.hpp"
#include "../code_2/CUSatelliteNetwork.hpp"

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}


std::string readFileIntoString(std::string fileName){
	std::string line, out;
  	ifstream A;
  	A.open(fileName);
  	if(!A){throw std::runtime_error("could not open file: " + fileName);}
	while(getline(A,line)){
		out = out+line+"\n";
	}
	return out;
}

string test_search(string searchkey, bool build)
{
    CUSatelliteNetwork CUBuildingNet;
    testing::internal::CaptureStdout();
    if (build)
    {
        CUBuildingNet.loadDefaultSetup();
        cout << "** Default network constructed" << endl;
    }
    cout << "** Searching for \""+searchkey+"\"" << endl;
    CUSatellite *tmp = CUBuildingNet.searchForSatellite(searchkey);
    if(tmp) {
      cout << "Name of satellite returned by function: " << tmp->name << endl;
    }
    else {
      cout << "NULL pointer received"<< endl;;
    }
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_addSatelliteinfo(string prev, string name, int distance, CUSatelliteNetwork *netPointer){
    testing::internal::CaptureStdout();    
    netPointer->addSatelliteInfo(prev, name, distance);
    netPointer->printNetwork();
    string output = testing::internal::GetCapturedStdout();
    return output;
}


string test_loadDeafultSetup()
{
    CUSatelliteNetwork CUBuildingNet;
    testing::internal::CaptureStdout();
    CUBuildingNet.loadDefaultSetup();
    CUBuildingNet.printNetwork();
    string output = testing::internal::GetCapturedStdout();
    return output;
}


string test_transmitInfo(string arr[], int len, bool build)
{
    CUSatelliteNetwork CUBuildingNet;
    testing::internal::CaptureStdout();
    if(build)
    {
        CUBuildingNet.loadDefaultSetup();
        cout << "** Default network constructed" << endl;
    }
    CUBuildingNet.printNetwork();
    for(int i=0;i<len;i++)
    {
        CUBuildingNet.transmitInfo(arr[i]);
    }
    string output = testing::internal::GetCapturedStdout();
    
    return output;
}