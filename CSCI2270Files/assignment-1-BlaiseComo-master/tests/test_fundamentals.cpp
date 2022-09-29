// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
#include "../code_1/fundamentals_1.hpp"
#include "../code_2/fundamentals_2.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

class test_fundamentals : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
		std::ofstream outgrade("./total_grade.txt");
		if(outgrade.is_open()){
			outgrade.clear();
			outgrade << (int)0;
			outgrade.close();
		}

    // Clean up to ensure old output files are not present
    remove("../out_2_1.csv");
    remove("../out_2_2.csv");
    remove("../out_2_3.csv");
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

double test_fundamentals::total_grade = 0;
double test_fundamentals::max_grade = 100;

/////////////////////////////////////////
// Test Helper Functions
/////////////////////////////////////////

string desired_result("408\n491.7,408\n491.7,408,99\n491.7,479.11,408,99\n491.7,479.11,408,213,99\n491.7,479.11,408,213,105,99\n491.7,479.11,408,213,115,105,99\n");

bool compare_arrays(float a[], float b[], int size){
  bool pass = true;
  for(int i = 0; i<size; ++i){
    if(a[i] != b[i])
      pass = false;
  }
  return pass;
}

bool compare_structs(studentData &a, studentData &b){
  bool pass = false;
  if(a.homework==b.homework && a.recitation==b.recitation && a.quiz==b.quiz && a.exam==b.exam)
    pass = true;
  return pass;
}

bool compare_files(string fileA, string fileB){
  std::string lineA, lineB;
  ifstream A, B;
  A.open(fileA);
  if(!A){throw std::runtime_error("could not open file: " + fileA);}
  B.open(fileB);
  if(!B){throw std::runtime_error("could not open file: " + fileB);}

  bool pass = true;
  while(getline(A,lineA) && getline(B,lineB)){
    if(lineA!=lineB){
      pass = false;
    }
  }
  return pass;
}

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

/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

///////////////////
// Part 1
//////////////////

// Test the addToArrayAsc function [10 POINTS]
TEST_F(test_fundamentals, TestAddToArrayDesc){

  // Create a sample test array
  const int listsize=6;
  float l[listsize] = {29.5, 44.0 ,35.1 ,16.2, 9,200.4};
  float myArray[100];
  int sizeArray = 0;

  // After a single insert, the array size should be 1
  sizeArray = addToArrayDesc(myArray,sizeArray,l[0]);
  ASSERT_EQ(1,sizeArray);
  add_points_to_grade(1.43);

  // Check if after a single insert the correct element is contained within the array
  float array_A[] = {29.5};
  bool same = compare_arrays(myArray, array_A, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);

  // Insert another element, check for correct array orientation
  float array_B[] = {44,29.5};
  sizeArray = addToArrayDesc(myArray,sizeArray,l[1]);
  same = compare_arrays(myArray, array_B, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);

  // Insert another element, check for correct array orientation
  float array_C[] = {44,35.1,29.5};
  sizeArray = addToArrayDesc(myArray,sizeArray,l[2]);
  same = compare_arrays(myArray, array_C, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);

  // Insert another element, check for correct array orientation
  float array_D[] = {44,35.1,29.5,16.2};
  sizeArray = addToArrayDesc(myArray,sizeArray,l[3]);
  same = compare_arrays(myArray, array_D, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);

  // Insert another element, check for correct array orientation
  float array_E[] = {44,35.1,29.5,16.2,9};
  sizeArray = addToArrayDesc(myArray,sizeArray,l[4]);
  same = compare_arrays(myArray, array_E, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);
  
  // Insert another element, check for correct array orientation
  float array_F[] = {200.4,44,35.1,29.5,16.2,9};
  sizeArray = addToArrayDesc(myArray,sizeArray,l[5]);
  same = compare_arrays(myArray, array_F, sizeArray);
  ASSERT_TRUE(same);
  add_points_to_grade(1.43);

}

// Test the entire application program. Test that data file name
// passed in via command line can be read in, and that the
// addToArrayAsc function works within the context of the program.
// [35 POINTS]

TEST_F(test_fundamentals, TestApp_1){
  string resp = exec("./run_app_1 ../numbers.txt");
  ASSERT_EQ(resp,desired_result);
  add_points_to_grade(35);
}

///////////////////
// Part 2
//////////////////

// Test the addStudentData function [10 POINTS]
TEST_F(test_fundamentals, TestAddStudentData){

  // Check if adding a single element correctly writes a 
  // struct within the array of structs
  studentData students[10];
  addStudentData(students,"Tim Thomas",90, 92, 95, 100, 0);
  studentData s0;
  s0.studentName = "Tim Thomas";
  s0.homework = 90;
  s0.recitation = 92;
  s0.quiz = 95;
  s0.exam = 100;
  s0.average = 94.25;
  bool same = compare_structs(students[0],s0);
  ASSERT_TRUE(same);
  add_points_to_grade(4);

  // Write 3 more records to the array of structs
  // Ensure that overall averages are being calculated correctly
  int idx = 0;
  addStudentData(students, "Bob Brown", 80, 90, 88, 81, idx++);
  addStudentData(students, "Jenny Jackson", 69, 79, 90, 73, idx++);
  addStudentData(students, "Samantha Smith", 65, 57, 72, 59, idx++);
  double averages [] = {84.75, 77.75, 63.25};
  same = false;
  for(int i = 0; i<idx; i++){
    ASSERT_EQ(students[i].average,averages[i]);
    add_points_to_grade(2);
  }

}


// Test the calcLetterGrade function [5 POINTS]
TEST_F(test_fundamentals, TestCalcLetterGrade){
  double averages [] = {84.75, 77.75, 63.25};

  ASSERT_EQ('B',calcLetterGrade(averages[0]));
  add_points_to_grade(1.66);

  ASSERT_EQ('C',calcLetterGrade(averages[1]));
  add_points_to_grade(1.66);

  ASSERT_EQ('D',calcLetterGrade(averages[2]));
  add_points_to_grade(1.66);

}


string desired_result_2_1("Tim Thomas,94.25,A\nBob Brown,84.75,B\nJenny Jackson,77.75,C\n");
string desired_result_2_2("");
string desired_result_2_3("Tim Thomas,94.25,A\nBob Brown,84.75,B\nJenny Jackson,77.75,C\nSamantha Smith,63.25,D\nRalph Rogers,56,F\n");


// Test the entire program [40 POINTS]
// The program should print the results to both standard output and to a csv file
// - each case tests for both. 
TEST_F(test_fundamentals, TestApp_2){
  string resp_2_1 = exec("./run_app_2 ../students.csv ../out_2_1.csv C A");
  ASSERT_EQ(resp_2_1,desired_result_2_1);
  add_points_to_grade(6);
  bool same = compare_files("../out_2_1.csv","../tests/expected_2_1.csv");
  ASSERT_TRUE(same);
  add_points_to_grade(8);

  string resp_2_2 = exec("./run_app_2 ../students.csv ../out_2_2.csv A C");
  ASSERT_EQ(resp_2_2,desired_result_2_2);
  add_points_to_grade(6);
  same = compare_files("../out_2_2.csv","../tests/expected_2_2.csv");
  ASSERT_TRUE(same);
  add_points_to_grade(7);

  string resp_2_3 = exec("./run_app_2 ../students.csv ../out_2_3.csv F A");
  ASSERT_EQ(resp_2_3,desired_result_2_3);
  add_points_to_grade(6);
  same = compare_files("../out_2_3.csv","../tests/expected_2_3.csv");
  ASSERT_TRUE(same);
  add_points_to_grade(7);

}
