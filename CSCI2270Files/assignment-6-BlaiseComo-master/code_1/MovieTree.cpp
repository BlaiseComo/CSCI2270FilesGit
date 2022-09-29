#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
    //TODO
    root = NULL;
}

void MovieTreeDestructorHelper(MovieNode* Node) {
    if (Node == NULL) return;
    else {
       MovieTreeDestructorHelper(Node->left);
       MovieTreeDestructorHelper(Node->right);
       delete Node; 
    }
}

MovieTree::~MovieTree() {
    //TODO
    MovieTreeDestructorHelper(root);
    root = NULL;
    
}

void printMovieInventoryHelper(MovieNode* Node) {

    if (Node) {
        printMovieInventoryHelper(Node->left);
        cout << "Movie: " << Node->title << " (" << Node->rating << ")" << endl;
        printMovieInventoryHelper(Node->right);
    }
}

void MovieTree::printMovieInventory() {
    //TODO
    if (root == NULL) {
        cout << "Tree is Empty. Cannot print." << endl;
    }
    printMovieInventoryHelper(root);
}

MovieNode* addMovieNodeHelper(MovieNode* Node, MovieNode* root) {
    if (root == NULL) {
        root = Node;
    }
    else if (Node->title <= root->title) {
        root->left = addMovieNodeHelper(Node, root->left);
    }
    else {
        root->right = addMovieNodeHelper(Node, root->right);
    }
    return root;
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
    //TODO
    MovieNode* newNode = new MovieNode;
    newNode->ranking = ranking; newNode->title = title; newNode->year = year; newNode->rating = rating; newNode->left = NULL; newNode ->right = NULL;
    if (root == NULL) {
        root = newNode;
    }
    else {
        root = addMovieNodeHelper(newNode, root);
    }
}

MovieNode* findMovieHelper(string title1, MovieNode* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->title == title1) {
        return root;
    }
    if (root->title > title1) {
        return findMovieHelper(title1, root->left);
    }
    return findMovieHelper(title1, root->right);
}

void MovieTree::findMovie(string title) {
    //TODO
    MovieNode* Node = findMovieHelper(title, root);
    if (Node != NULL) {
        cout << "Movie Info:" << endl;
        cout << "==================" << endl;
        cout << "Ranking:" << Node->ranking << endl;
        cout << "Title  :" << Node->title << endl;
        cout << "Year   :" << Node->year << endl;
        cout << "Rating :" << Node->rating << endl;
    }
    else {
        cout << "Movie not found." << endl;
    }
}

void queryMoviesHelperFunction(MovieNode* currNode, float rating, int year) {
    if (currNode == NULL) {
        return;
    }
    if (currNode->year > year && currNode->rating >= rating) {
        cout << currNode->title << " (" << currNode->year << ") " << currNode->rating << endl;
    }
    queryMoviesHelperFunction(currNode->left, rating, year);
    queryMoviesHelperFunction(currNode->right, rating, year);
}

void MovieTree::queryMovies(float rating, int year) {
    //TODO
   if (root == NULL) {
       cout << "Tree is Empty. Cannot query Movies." << endl;
   }
   else {
       cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
       queryMoviesHelperFunction(root, rating, year);
   }
}

void averageRatingHelper(double &counter, double &averageCounter, MovieNode* Node) {
    if (Node) { 
        averageRatingHelper(counter, averageCounter, Node->left);
        counter++;
        averageCounter += Node->rating;
        averageRatingHelper(counter, averageCounter, Node->right);
    }
}

void MovieTree::averageRating() {
    //TODO
    if (root != NULL) {
        double counter = 0;
        double averageCounter = 0;
        averageRatingHelper(counter, averageCounter, root);
        cout << "Average rating:" << setprecision(6) << (averageCounter / counter) << endl;
    }
    else {
        cout << "Average rating:0.0" << endl;
    }
}

void printLevelNodesHelper(int level, int count, MovieNode* currNode) {
    if (currNode == NULL) {
        return;
    }
    if (count == level) {
        cout << "Movie: " << currNode->title << " (" << currNode->rating << ")" << endl;
        return;
    }

    printLevelNodesHelper(level, count+1, currNode->left);
    printLevelNodesHelper(level, count+1, currNode->right);
    
}

void MovieTree::printLevelNodes(int level) {
    //TODO
    
    int count = 0;
    printLevelNodesHelper(level, count, root);
    
}
