// If you change anything in this file, your changes will be ignored 
// in your homework submission.
// Chekout TEST_F functions bellow to learn what is being tested.
#include <gtest/gtest.h>
// #include "../code_1/<HEADER FILE>.hpp"
#include "../code_1/MovieTree.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <array>
#include <vector>
#include "test_helpers.hpp"

using namespace std;

class test_x : public ::testing::Test {
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

double test_x::total_grade = 0;
double test_x::max_grade = 100;



/////////////////////////////////////////
// Tests start here
/////////////////////////////////////////

TEST_F(test_x, TestAddMovie_PrintMovie){
    string result;
    string expected;
       
    int len = 0;
    int ranking[] ={};
    string name[] = {};
    int year[] = {};
    float rating[] = {};
    
    result = test_add(name,ranking, year, rating, len);
    expected = "[GRADER] Printing movie inventory:\nTree is Empty. Cannot print.\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);
    
    int len1 = 1;
    int ranking1[] ={1};
    string name1[] = {"Tiger"};
    int year1[] = {2006};
    float rating1[] = {5.8};
    
    result = test_add(name1,ranking1, year1, rating1, len1);
    expected = "[GRADER] Adding:(1, Tiger, 2006, 5.8)\n[GRADER] Printing movie inventory:\nMovie: Tiger (5.8)\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);
    
    int len2 = 2;
    int ranking2[] ={2,1};
    string name2[] = { "Elephant", "Argo"};
    int year2[] = {2006, 2012};
    float rating2[] = {6.5, 5.8};
    
    result = test_add(name2,ranking2, year2, rating2, len2);
    expected = "[GRADER] Adding:(2, Elephant, 2006, 6.5)\n[GRADER] Adding:(1, Argo, 2012, 5.8)\n[GRADER] Printing movie inventory:\nMovie: Argo (5.8)\nMovie: Elephant (6.5)\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);
    
    int len4 = 2;
    int ranking4[] ={2,1};
    string name4[] = { "Argo", "Elephant"};
    int year4[] = {2012, 2006};
    float rating4[] = {5.8, 6.5};
    
    result = test_add(name4,ranking4, year4, rating4, len4);
    expected = "[GRADER] Adding:(2, Argo, 2012, 5.8)\n[GRADER] Adding:(1, Elephant, 2006, 6.5)\n[GRADER] Printing movie inventory:\nMovie: Argo (5.8)\nMovie: Elephant (6.5)\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);
    
    
    
    int len3 = 8;
    int ranking3[] ={1,2,3,4,5,6,7,8};
    string name3[] = { "Man on Wire","Hands on a Hardbody","Dogtown and Z-Boys","Dancin' Outlaw", "Jiro Dreams of Sushi","Enron: The Smartest Guys in the Room", "Bowling for Columbine", "Taxi to the Dark Side"};
    int year3[] = {2008, 1997, 2001,1991,2012,2005, 2002, 2007}; 
    float rating3[] = {7.8, 7.7, 7.7, 8.1, 7.9, 7.7, 8, 7.5};
    
    result = test_add(name3,ranking3, year3, rating3, len3);
    expected = "[GRADER] Adding:(1, Man on Wire, 2008, 7.8)\n[GRADER] Adding:(2, Hands on a Hardbody, 1997, 7.7)\n[GRADER] Adding:(3, Dogtown and Z-Boys, 2001, 7.7)\n[GRADER] Adding:(4, Dancin' Outlaw, 1991, 8.1)\n[GRADER] Adding:(5, Jiro Dreams of Sushi, 2012, 7.9)\n[GRADER] Adding:(6, Enron: The Smartest Guys in the Room, 2005, 7.7)\n[GRADER] Adding:(7, Bowling for Columbine, 2002, 8)\n[GRADER] Adding:(8, Taxi to the Dark Side, 2007, 7.5)\n[GRADER] Printing movie inventory:\nMovie: Bowling for Columbine (8)\nMovie: Dancin' Outlaw (8.1)\nMovie: Dogtown and Z-Boys (7.7)\nMovie: Enron: The Smartest Guys in the Room (7.7)\nMovie: Hands on a Hardbody (7.7)\nMovie: Jiro Dreams of Sushi (7.9)\nMovie: Man on Wire (7.8)\nMovie: Taxi to the Dark Side (7.5)\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(6);
}

TEST_F(test_x, TestFindMovie){
    string result;
    string expected;
       
    int len = 7;
    int ranking[] ={6, 55, 1, 50, 11, 49, 4};
    string name[] = {"Pulp Fiction", "Casablanca", "Shawshank Redemption", "Apocalypse Now", "Fight Club","Raiders of the Lost Ark", "The Godfather"};
    int year[] = {1994,1942,1994,1979,1999,1981,1972};
    float rating[] = {8.9,8.5, 9.3,8.5,8.8,8.5, 9.2};
    string key = "Pulp Fiction";
    
    result = test_find(name,ranking, year, rating, len, key);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Finding: Pulp Fiction\nMovie Info:\n==================\nRanking:6\nTitle  :Pulp Fiction\nYear   :1994\nRating :8.9\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    
    key = "Raiders of the Lost Ark";
    result = test_find(name,ranking, year, rating, len, key);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Finding: Raiders of the Lost Ark\nMovie Info:\n==================\nRanking:49\nTitle  :Raiders of the Lost Ark\nYear   :1981\nRating :8.5\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    key = "The Sting";
    result = test_find(name,ranking, year, rating, len, key);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Finding: The Sting\nMovie not found.\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(2);
    
    key = "Fight Club";
    result = test_find(name,ranking, year, rating, len, key);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Finding: Fight Club\nMovie Info:\n==================\nRanking:11\nTitle  :Fight Club\nYear   :1999\nRating :8.8\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(2);
}


TEST_F(test_x, TestQueryMovie){
    string result;
    string expected;
       
    int len = 7;
    int ranking[] ={6, 55, 1, 50, 11, 49, 4};
    string name[] = {"Pulp Fiction", "Casablanca", "Shawshank Redemption", "Apocalypse Now", "Fight Club","Raiders of the Lost Ark", "The Godfather"};
    int year[] = {1994,1942,1994,1979,1999,1981,1972};
    float rating[] = {8.9,8.5, 9.3,8.5,8.8,8.5, 9.2};
    
    
    result = test_query(name,ranking, year, rating, 0, 8.0, 1980);
    expected = "[GRADER] Querying movies with a min rating and year\nTree is Empty. Cannot query Movies.\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(1.25);
    
    result = test_query(name,ranking, year, rating, len, 8.0, 1980);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Querying movies with a min rating and year\nMovies that came out after 1980 with rating at least 8:\nPulp Fiction (1994) 8.9\nFight Club (1999) 8.8\nShawshank Redemption (1994) 9.3\nRaiders of the Lost Ark (1981) 8.5\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(1.25);
    
    
    result = test_query(name,ranking, year, rating, len, 7.0, 1950);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Querying movies with a min rating and year\nMovies that came out after 1950 with rating at least 7:\nPulp Fiction (1994) 8.9\nApocalypse Now (1979) 8.5\nFight Club (1999) 8.8\nShawshank Redemption (1994) 9.3\nRaiders of the Lost Ark (1981) 8.5\nThe Godfather (1972) 9.2\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(2.5);
    
    result = test_query(name,ranking, year, rating, len, 9.5, 1990);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Querying movies with a min rating and year\nMovies that came out after 1990 with rating at least 9.5:\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(2.5);
    
    
     result = test_query(name,ranking, year, rating, len, 8.7, 1980);
    expected = "[GRADER] Adding:(6, Pulp Fiction, 1994, 8.9)\n[GRADER] Adding:(55, Casablanca, 1942, 8.5)\n[GRADER] Adding:(1, Shawshank Redemption, 1994, 9.3)\n[GRADER] Adding:(50, Apocalypse Now, 1979, 8.5)\n[GRADER] Adding:(11, Fight Club, 1999, 8.8)\n[GRADER] Adding:(49, Raiders of the Lost Ark, 1981, 8.5)\n[GRADER] Adding:(4, The Godfather, 1972, 9.2)\n[GRADER] Querying movies with a min rating and year\nMovies that came out after 1980 with rating at least 8.7:\nPulp Fiction (1994) 8.9\nFight Club (1999) 8.8\nShawshank Redemption (1994) 9.3\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(2.5);
    
}


TEST_F(test_x, TestAvgRatingMovie){
    string result;
    string expected;
       
    int len = 7;
    int ranking[] ={6, 55, 1, 50, 11, 49, 4};
    string name[] = {"Pulp Fiction", "Casablanca", "Shawshank Redemption", "Apocalypse Now", "Fight Club","Raiders of the Lost Ark", "The Godfather"};
    int year[] = {1994,1942,1994,1979,1999,1981,1972};
    float rating[] = {8.9,8.5, 9.3,8.5,8.8,8.5, 9.2};
    result = test_avgrating(name,ranking, year, rating, len);
    expected ="[GRADER] Average rating of movies: \nAverage rating:8.81429\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    
    
    result = test_avgrating(name,ranking, year, rating, 1);
    expected ="[GRADER] Average rating of movies: \nAverage rating:8.9\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    
    result = test_avgrating(name,ranking, year, rating, 2);
    expected ="[GRADER] Average rating of movies: \nAverage rating:8.7\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    result = test_avgrating(name,ranking, year, rating, 3);
    expected ="[GRADER] Average rating of movies: \nAverage rating:8.9\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    
    result = test_avgrating(name,ranking, year, rating, 0);
    expected ="[GRADER] Average rating of movies: \nAverage rating:0.0\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
}


TEST_F(test_x, TestPrintLevelNode){
    string result;
    string expected;
       
    int len = 7;
    int ranking[] ={6, 55, 1, 50, 11, 49, 4};
    string name[] = {"Pulp Fiction", "Casablanca", "Shawshank Redemption", "Apocalypse Now", "Fight Club","Raiders of the Lost Ark", "The Godfather"};
    int year[] = {1994,1942,1994,1979,1999,1981,1972};
    float rating[] = {8.9,8.5, 9.3,8.5,8.8,8.5, 9.2};
    result = test_printLevelK(name,ranking, year, rating, len);
    expected ="[GRADER] Result of `movies.printLevelNodes(0)` is:\nMovie: Pulp Fiction (8.9)\n\n[GRADER] Result of `movies.printLevelNodes(1)` is:\nMovie: Casablanca (8.5)\nMovie: Shawshank Redemption (9.3)\n\n[GRADER] Result of `movies.printLevelNodes(2)` is:\nMovie: Apocalypse Now (8.5)\nMovie: Fight Club (8.8)\nMovie: Raiders of the Lost Ark (8.5)\nMovie: The Godfather (9.2)\n\n[GRADER] Result of `movies.printLevelNodes(3)` is:\n\n[GRADER] Result of `movies.printLevelNodes(4)` is:\n\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(3);
    
    
    int len2 = 0;
    int ranking2[] ={};
    string name2[] = {};
    int year2[] = {};
    float rating2[] = {};
    result = test_printLevelK(name2,ranking2, year2, rating2, len2);
    expected = "[GRADER] Result of `movies.printLevelNodes(0)` is:\n\n[GRADER] Result of `movies.printLevelNodes(1)` is:\n\n[GRADER] Result of `movies.printLevelNodes(2)` is:\n\n[GRADER] Result of `movies.printLevelNodes(3)` is:\n\n[GRADER] Result of `movies.printLevelNodes(4)` is:\n\n\n[GRADER] No leaked memory (Good).\n";
    
    ASSERT_EQ(expected, result);
    add_points_to_grade(2);
    
    
    
    int ranking1[] ={50, 55, 11, 6, 49, 1, 4};
     string name1[] = { "Apocalypse Now", "Casablanca", "Fight Club","Pulp Fiction",  "Raiders of the Lost Ark", "Shawshank Redemption", "The Godfather"};
    int year1[] = {1979,1942,1999,1994,1981,1994,1972};
    float rating1[] = {8.5,8.9,8.8, 8.9,8.5,9.3, 9.2};
    result = test_printLevelK(name1,ranking1, year1, rating1, len);
    expected ="[GRADER] Result of `movies.printLevelNodes(0)` is:\nMovie: Apocalypse Now (8.5)\n\n[GRADER] Result of `movies.printLevelNodes(1)` is:\nMovie: Casablanca (8.9)\n\n[GRADER] Result of `movies.printLevelNodes(2)` is:\nMovie: Fight Club (8.8)\n\n[GRADER] Result of `movies.printLevelNodes(3)` is:\nMovie: Pulp Fiction (8.9)\n\n[GRADER] Result of `movies.printLevelNodes(4)` is:\nMovie: Raiders of the Lost Ark (8.5)\n\n\n[GRADER] No leaked memory (Good).\n";
    ASSERT_EQ(expected, result);
    add_points_to_grade(5);
}


TEST_F(test_x, TestMain)
{
    string desired = readFileIntoString("../tests/output/output1.txt");
    string resp = exec("./run_app_1 ../tests/input/movies1.csv ../tests/input/input1.txt");
    ASSERT_EQ(desired, resp);
    add_points_to_grade(6.25);
    
    string desired2 = readFileIntoString("../tests/output/output2.txt");
    string resp2 = exec("./run_app_1 ../tests/input/movies2.csv ../tests/input/input2.txt");
    
    ASSERT_EQ(desired2, resp2);
    add_points_to_grade(6.25);
    
    
    string desired3 = readFileIntoString("../tests/output/output3.txt");
    string resp3 = exec("./run_app_1 ../tests/input/movies3.csv ../tests/input/input3.txt");
    ASSERT_EQ(desired3, resp3);
    add_points_to_grade(6.25);
    
    
    string desired4 = readFileIntoString("../tests/output/output4.txt");
    string resp4 = exec("./run_app_1 ../tests/input/movies4.csv ../tests/input/input4.txt");
    //ofstream out("../tests/output/output4.txt");
    //out<<resp4;
    //out.close();
    
    ASSERT_EQ(desired4, resp4);
    add_points_to_grade(6.25);
}
