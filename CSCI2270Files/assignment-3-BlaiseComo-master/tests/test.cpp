// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "test_helpers.hpp"
#include "../code_1/generateSeries.hpp"

#include "../code_2/CUSatelliteNetwork.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include <sstream>

using namespace std;

class test : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
			std::cout << "Total Grade is : " << (int)std::ceil(100*total_grade/max_grade) << std::endl;
		}
	}

	void add_points_to_grade(double points){
		if(!::testing::Test::HasFailure()){
			total_grade += points;
		}
	}

	// this function runs before every TEST_F function
	void SetUp() override {}

	// this function runs after every TEST_F function
	void TearDown() override {
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)std::ceil(100*total_grade/max_grade);
			outgrade.close();
		}
	}
	
	static double total_grade;
	static double max_grade;
};

double test::total_grade = 0;
double test::max_grade = 100;


/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test, TestGenerateSeries){
	int totalElements;
    int *result;
    int n , m;

	totalElements = 4;
    n = 3;
    m = 4;
    result = new int[totalElements];
    int expected_array_1[] = {3, 12, 48, 192};
    generateSeries(result, n, m, totalElements);
    for(int i = 0; i < totalElements; i++){
	    ASSERT_EQ(expected_array_1[i], result[i]);
    }
	add_points_to_grade(10);
    delete[] result;
    result = nullptr;

	totalElements = 4;
    n = 1;
    m = 3;
    result = new int[totalElements];
    int expected_array_2[] = {1, 3, 9, 27, 81};
    generateSeries(result, n, m, totalElements);
    for(int i = 0; i < totalElements; i++){
	    ASSERT_EQ(expected_array_2[i], result[i]);
    }
	add_points_to_grade(10);
    delete[] result;
    result = nullptr;
}


TEST_F(test, TestAddSatelliteInfo)
{
    //testcase1
    string expected_array, result;
    CUSatelliteNetwork CUBuildingNet;
    CUSatelliteNetwork * netPointer = &CUBuildingNet;
    expected_array = "adding: MARINER (HEAD)\n== CURRENT PATH ==\nMARINER(1) -> NULL\n===\n";
    result = test_addSatelliteinfo("","MARINER", 1, netPointer);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(5);
    
    //testcase2
    expected_array = "Cannot add new node; previous node not found\n\n== CURRENT PATH ==\nMARINER(1) -> NULL\n===\n";
    result = test_addSatelliteinfo("NOTFOUND", "PLANCK", 5, netPointer);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(5);
    
    //testcase3
    expected_array = "adding: PLANCK (prev: MARINER)\n== CURRENT PATH ==\nMARINER(1) -> PLANCK(5) -> NULL\n===\n";
    result = test_addSatelliteinfo("MARINER", "PLANCK", 5, netPointer);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(5);

    //testcase4
    expected_array = "adding: KEPLER (prev: MARINER)\n== CURRENT PATH ==\nMARINER(1) -> KEPLER(5) -> PLANCK(5) -> NULL\n===\n";
    result = test_addSatelliteinfo("MARINER", "KEPLER", 5, netPointer);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(5);
}

TEST_F(test, TestLoadDeafultSetup)
{
    string expected_array, result;
    result = test_loadDeafultSetup();
    expected_array = "adding: MAVEN (HEAD)\nadding: JUNO (HEAD)\nadding: PIONEER (HEAD)\nadding: GALILEO (HEAD)\nadding: KEPLER (HEAD)\nadding: TESS (HEAD)\n== CURRENT PATH ==\nTESS(2) -> KEPLER(10) -> GALILEO(6) -> PIONEER(5) -> JUNO(4) -> MAVEN(9) -> NULL\n===\n";
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(10);
}

TEST_F(test, TestSearchForSatellite)
{
    //testcase1
    string expected_array, result;
    expected_array = "adding: MAVEN (HEAD)\nadding: JUNO (HEAD)\nadding: PIONEER (HEAD)\nadding: GALILEO (HEAD)\nadding: KEPLER (HEAD)\nadding: TESS (HEAD)\n** Default network constructed\n** Searching for \"MAVEN\"\nName of satellite returned by function: MAVEN\n";
    result = test_search("MAVEN", true);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(3.75);
    
    //testcase2
    //string expected_array, result;
    expected_array = "adding: MAVEN (HEAD)\nadding: JUNO (HEAD)\nadding: PIONEER (HEAD)\nadding: GALILEO (HEAD)\nadding: KEPLER (HEAD)\nadding: TESS (HEAD)\n** Default network constructed\n** Searching for \"TESS\"\nName of satellite returned by function: TESS\n";
    result = test_search("TESS", true);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(3.75);
       
    //testcase3
    
    //string expected_array, result;
    expected_array = "adding: MAVEN (HEAD)\nadding: JUNO (HEAD)\nadding: PIONEER (HEAD)\nadding: GALILEO (HEAD)\nadding: KEPLER (HEAD)\nadding: TESS (HEAD)\n** Default network constructed\n** Searching for \"ATLS\"\nNULL pointer received\n";
    result = test_search("ATLS", true);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(3.75);
    
    //testcase4
    expected_array = "** Searching for \"TESS\"\nNULL pointer received\n";
    result = test_search("TESS", false);
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(3.75);
}


TEST_F(test, TestTransmitInfo)
{
    //test case1
    string expected_array, result;
    bool build = true;
    string arr[1] = {"TESS"};
    int len = 1;
    result = test_transmitInfo(arr, len, build);
    expected_array = readFileIntoString("../tests/test_transmitInfo/test_transmitInfo1.txt");
    ASSERT_EQ(expected_array, result);
    add_points_to_grade(3);
    
    //test case2
    string expected_array2, result2;
    bool build2 = true;
    string arr2[1] = {"MAVEN"};
    int len2 = 1;
    result2 = test_transmitInfo(arr2, len2, build2);
    expected_array2 = readFileIntoString("../tests/test_transmitInfo/test_transmitInfo2.txt");
    ASSERT_EQ(expected_array2, result2);
    add_points_to_grade(3);
    
    
    string expected_array3, result3;
    bool build3 = true;
    string arr3[1] = {"KKKK"};
    int len3 = 1;
    result3 = test_transmitInfo(arr3, len3, build3);
    expected_array3 = readFileIntoString("../tests/test_transmitInfo/test_transmitInfo3.txt");
    ASSERT_EQ(expected_array3, result3);
    add_points_to_grade(3);
    
    string expected_array4, result4;
    bool build4 = true;
    string arr4[2] = {"TESS", "JUNO"};
    int len4 = 2;
    result4 = test_transmitInfo(arr4, len4, build4);
    expected_array4 = readFileIntoString("../tests/test_transmitInfo/test_transmitInfo4.txt");
    ASSERT_EQ(expected_array4, result4);
    add_points_to_grade(3);
     
    string expected_array5, result5;
    bool build5 = false;
    string arr5[1] = {"TESS"};
    int len5 = 1;
    result5 = test_transmitInfo(arr5, len5, build5);
    expected_array5 = readFileIntoString("../tests/test_transmitInfo/test_transmitInfo5.txt");
    ASSERT_EQ(expected_array5, result5);
    add_points_to_grade(3);

}


TEST_F(test, TestMain)
{
    string desired = readFileIntoString("../tests/main_test/output1.txt");
    string resp = exec("./run_app_2 ../tests/main_test/input1.txt");
    ASSERT_EQ(desired, resp);
    add_points_to_grade(5);
    
    string desired2 = readFileIntoString("../tests/main_test/output2.txt");
    string resp2 = exec("./run_app_2 ../tests/main_test/input2.txt");
    ASSERT_EQ(desired2, resp2);
    add_points_to_grade(5);
    
    
    string desired3 = readFileIntoString("../tests/main_test/output3.txt");
    string resp3 = exec("./run_app_2 ../tests/main_test/input3.txt");
    ASSERT_EQ(desired3, resp3);
    add_points_to_grade(5);
        
    string desired4 = readFileIntoString("../tests/main_test/output4.txt");
    string resp4 = exec("./run_app_2 ../tests/main_test/input4.txt");
    ASSERT_EQ(desired4, resp4);
    add_points_to_grade(5);
}
