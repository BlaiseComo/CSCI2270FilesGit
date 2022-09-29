#include <gtest/gtest.h>
#include "test_helpers.hpp"

#include "../code_1/MovieTree.hpp"


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


traceNode *traceHead = NULL;
bool verbose = false;
int numAllocs = 0;

string test_add(string* name,int* ranking, int* year, float* rating, int len)
{
     MovieTree* tree = new MovieTree();
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        cout << "[GRADER] Adding:(" <<ranking[i]<<", "<<name[i]<<", "<<year[i]<<", "<<rating[i] <<")"<< endl;
        tree->addMovieNode(ranking[i],name[i],year[i],rating[i]);
    }
    cout<<"[GRADER] Printing movie inventory:"<<endl;
    tree->printMovieInventory();
    
     // MEMCHECK!
    delete tree;
    if (traceHead != nullptr){
        cout << endl << "[ERROR] The program leaked memory. The following nodes are still alive:" << endl;
        traceNode *hold = traceHead;
        while (hold != nullptr){
            printNode(hold);
            hold = hold->next;
        }
    }
    else {
        cout << endl << "[GRADER] No leaked memory (Good)." << endl;
    }
     
    string output = testing::internal::GetCapturedStdout();
    return output;
}


string test_find(string* name,int* ranking, int* year, float* rating, int len, string key)
{
     MovieTree* tree = new MovieTree();
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        cout << "[GRADER] Adding:(" <<ranking[i]<<", "<<name[i]<<", "<<year[i]<<", "<<rating[i] <<")"<< endl;
        tree->addMovieNode(ranking[i],name[i],year[i],rating[i]);
    }
    std::cout << "[GRADER] Finding: " <<key<< std::endl;
    tree->findMovie(key);
    
      // MEMCHECK!
    delete tree;
    if (traceHead != nullptr){
        cout << endl << "[ERROR] The program leaked memory. The following nodes are still alive:" << endl;
        traceNode *hold = traceHead;
        while (hold != nullptr){
            printNode(hold);
            hold = hold->next;
        }
    }
    else {
        cout << endl << "[GRADER] No leaked memory (Good)." << endl;
    }
     
    string output = testing::internal::GetCapturedStdout();
    return output;
}

string test_query(string* name,int* ranking, int* year, float* rating, int len, float rt, int yr)
{
     MovieTree* tree = new MovieTree();
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        cout << "[GRADER] Adding:(" <<ranking[i]<<", "<<name[i]<<", "<<year[i]<<", "<<rating[i] <<")"<< endl;
        tree->addMovieNode(ranking[i],name[i],year[i],rating[i]);
    }
    cout << "[GRADER] Querying movies with a min rating and year" << endl;
    tree->queryMovies(rt, yr);
    
      // MEMCHECK!
    delete tree;
    if (traceHead != nullptr){
        cout << endl << "[ERROR] The program leaked memory. The following nodes are still alive:" << endl;
        traceNode *hold = traceHead;
        while (hold != nullptr){
            printNode(hold);
            hold = hold->next;
        }
    }
    else {
        cout << endl << "[GRADER] No leaked memory (Good)." << endl;
    }
    
    string output = testing::internal::GetCapturedStdout();
    return output;
}


string test_avgrating(string* name,int* ranking, int* year, float* rating, int len)
{
     MovieTree* tree = new MovieTree();
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        //cout << "[GRADER] Adding:(" <<ranking[i]<<", "<<name[i]<<", "<<year[i]<<", "<<rating[i] <<")"<< endl;
        tree->addMovieNode(ranking[i],name[i],year[i],rating[i]);
    }
    std::cout << "[GRADER] Average rating of movies: " << std::endl;
    tree->averageRating();
    
     // MEMCHECK!
    delete tree;
    if (traceHead != nullptr){
        cout << endl << "[ERROR] The program leaked memory. The following nodes are still alive:" << endl;
        traceNode *hold = traceHead;
        while (hold != nullptr){
            printNode(hold);
            hold = hold->next;
        }
    }
    else {
        cout << endl << "[GRADER] No leaked memory (Good)." << endl;
    }
    
    string output = testing::internal::GetCapturedStdout();
    return output;
}


string test_printLevelK(string* name,int* ranking, int* year, float* rating, int len)
{
    MovieTree* tree = new MovieTree();
    testing::internal::CaptureStdout();
    
    for(int i=0;i<len;i++)
    {
        //cout << "[GRADER] Adding:(" <<ranking[i]<<", "<<name[i]<<", "<<year[i]<<", "<<rating[i] <<")"<< endl;
        tree->addMovieNode(ranking[i],name[i],year[i],rating[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        cout << "[GRADER] Result of `movies.printLevelNodes("<<i<<")` is:" << endl;
        tree->printLevelNodes(i);
        cout << endl;
    }
    // MEMCHECK!
    delete tree;
    if (traceHead != nullptr){
        cout << endl << "[ERROR] The program leaked memory. The following nodes are still alive:" << endl;
        traceNode *hold = traceHead;
        while (hold != nullptr){
            printNode(hold);
            hold = hold->next;
        }
    }
    else {
        cout << endl << "[GRADER] No leaked memory (Good)." << endl;
    }
    
    string output = testing::internal::GetCapturedStdout();
    return output;
}