#include "MovieTree.hpp"
#include <iostream>
#include <fstream>



using namespace std;
/* ------------------------Starter Code function---------- */
LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

void preorderTraversalHelper(TreeNode * root) {
	if (root == NULL) 
    {
		return;
	}
    cout << root->titleChar << " ";
    preorderTraversalHelper(root->leftChild);
    preorderTraversalHelper(root->rightChild);
}

void MovieTree::preorderTraversal() {
	preorderTraversalHelper(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* --------------------------Constructor---------------------------- */
MovieTree::MovieTree()
{
    root = NULL;
}

/* --------------------------Destructor---------------------------- */

void MovieTree:: rdelete(TreeNode *node)
{
	//TODO
    if (node == NULL) return;
    else {
        rdelete(node->leftChild); 
        rdelete(node->rightChild); 
        LLMovieNode* importantNode = node->head;
        if (importantNode != NULL) {
            while (importantNode->next != NULL) {
                LLMovieNode* tmp = importantNode;
                importantNode = importantNode->next;
                delete tmp;
            }
            delete importantNode;
        }
        delete node;

    }
}


MovieTree::~MovieTree()
{
	//TODO
    rdelete(root);
    root = NULL;
}

/* -------------------------showMovieCollection----------------------------- */
void MovieTree::printMovieInventoryHelper(TreeNode* node)
{
	//TODO
    if (node == NULL) return;
    else {
        LLMovieNode* m = node->head;
        printMovieInventoryHelper(node->leftChild);
        if (m != NULL) {
            cout << "Movies starting with letter: " << node->titleChar << endl;
            while (m != NULL) {
                cout << " >> " << m->title << " " << m->rating << endl;
                m = m->next;
            }
        }
        printMovieInventoryHelper(node->rightChild);
    }
}

void MovieTree::showMovieCollection()
{
	//TODO
    printMovieInventoryHelper(root);
}

/* --------------------------insertMovie---------------------------- */
TreeNode* MovieTree::addHelper(TreeNode *root, TreeNode* parentpointer, int _ranking, string _title, int _year, float _rating)
{
	//TODO

    if (root == NULL && parentpointer != NULL) {

        TreeNode* newNode = new TreeNode;
        newNode->parent = parentpointer;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->titleChar = _title[0];


        LLMovieNode* importantNode = NULL;


        LLMovieNode* newMovieNode = getLLMovieNode(_ranking, _title, _year, _rating);

            importantNode = newMovieNode;
            newNode->head = importantNode;
            
            return newNode;
    
    }

    else if (root == NULL && parentpointer == NULL) {

        TreeNode* newNode = new TreeNode;
        newNode->parent = parentpointer;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->titleChar = _title[0];

        LLMovieNode* newMovieNode = getLLMovieNode(_ranking, _title, _year, _rating);

        newNode->head = newMovieNode;

        return newNode;

    }

    else if (_title[0] == root->titleChar) {
        
        LLMovieNode* importantNode = root->head;

        LLMovieNode* newMovieNode = getLLMovieNode(_ranking, _title, _year, _rating);

        if (importantNode == NULL) {
            //importantNode = newMovieNode;
            root->head = newMovieNode;
            return root;
        }
        if (importantNode->title > _title) {
            newMovieNode->next = importantNode;
            root->head = newMovieNode;
            return root;
        }
        while (importantNode->next != NULL) {
            if (importantNode->title < _title) {
                break;
            }
            importantNode = importantNode->next;
        }

        if (importantNode->next == NULL) {
            importantNode->next = newMovieNode;
            return root;
        }

        newMovieNode->next = importantNode->next;
        importantNode->next = newMovieNode;
        return root;
    
    }

    else if (_title[0] < root->titleChar) { root->leftChild = addHelper(root->leftChild, root, _ranking, _title, _year, _rating); }

    else if (_title[0] > root->titleChar) { root->rightChild = addHelper(root->rightChild, root, _ranking, _title, _year, _rating); }

    return root;

}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	//TODO
    //cout << "here><" << endl;
    if (root == NULL) {
        root = addHelper(root, root, ranking, title, year, rating);
    }
    else {
        root = addHelper(root, root->parent, ranking, title, year, rating);
    }
}

/* ------------------------removeMovieRecord------------------------------ */
void MovieTree::removeMovieRecord(std::string title)
{
    //TODO
    TreeNode* importantNode = searchCharNode(title[0]);

    if (importantNode != NULL) {
        LLMovieNode* importantMovieNode = importantNode->head;
        if (importantMovieNode != NULL) {
            LLMovieNode* prevNode = NULL;
            while (importantMovieNode->next != NULL && importantMovieNode->title != title) {
                prevNode = importantMovieNode;
                importantMovieNode = importantMovieNode->next;
            }
            if (importantMovieNode->title == title && importantMovieNode->next == NULL && prevNode == NULL) {
                delete importantMovieNode;
                importantNode->head = NULL;
                return;
            }
            else if (importantMovieNode->title == title && prevNode != NULL) {
                prevNode->next = importantMovieNode->next;
                delete importantMovieNode;
                return;
            }
            else if (importantMovieNode->title == title && importantMovieNode->next != NULL) {
                importantNode->head = importantMovieNode->next;
                delete importantMovieNode;
                return;
            }
        }
    }
    cout << "Movie not found." << endl;
    
}

/* ------------------------removeBSTNode------------------------------ */
void MovieTree::removeLLnodes(TreeNode* node){
    //TODO
    LLMovieNode* importantMovieNode = node->head;

    if (importantMovieNode == NULL) return;

    while (importantMovieNode->next != NULL) {
        LLMovieNode* tmp = importantMovieNode;
        importantMovieNode = importantMovieNode->next;
        delete tmp;
    }
    delete importantMovieNode;

    node->head = NULL;

}

TreeNode* MovieTree::getSuccessor(TreeNode* node){
    //TODO
    if (node == NULL) return node;
    while (node->leftChild != NULL) { 
        node = node->leftChild;
    }
    
    return node;
}

TreeNode* MovieTree::removeBSTNodeHelper(TreeNode* node, TreeNode* parent, char titleFirstLetter){
    //TODO
    if (node == NULL) return node;

    if (titleFirstLetter < node->titleChar) {
        node->leftChild = removeBSTNodeHelper(node->leftChild, node->parent, titleFirstLetter);
    }

    else if (titleFirstLetter > node->titleChar) {
        node->rightChild = removeBSTNodeHelper(node->rightChild, node->parent, titleFirstLetter);
    }
    
    else {

        if (node->leftChild == NULL && node->rightChild == NULL) {
            return NULL;
        }

        else if (node->leftChild == NULL) {
            TreeNode* importantRightNode = node->rightChild;
            removeLLnodes(node);
            delete node;
            return importantRightNode;
        }

        else if (node->rightChild == NULL) {
            TreeNode* importantLeftNode = node->leftChild;
            removeLLnodes(node);
            delete node;
            return importantLeftNode;
        }


            TreeNode* importantSuccessorNode = getSuccessor(node);

            node->titleChar = importantSuccessorNode->titleChar;
            removeLLnodes(node);

            node->rightChild = removeBSTNodeHelper(node->rightChild, node->parent, importantSuccessorNode->titleChar);

    }

    return node; 

}

void MovieTree::removeBSTNode(char titleFirstLetter){
    //TODO
    root = removeBSTNodeHelper(root, root->parent, titleFirstLetter);
}


/* --------------------------rightRotation---------------------------- */
void MovieTree::rightRotation(TreeNode* curr)
{
	//TODO
    if (curr->leftChild == NULL) return;
    else if (curr->parent == NULL) {
    
        TreeNode* rightChildOfX = curr->leftChild->rightChild;
        TreeNode* xPointer = curr->leftChild;
        xPointer->rightChild = curr;
        curr->parent = xPointer;
        curr->leftChild = rightChildOfX;
        xPointer->parent = NULL;
        root = xPointer;
    }

    else {

        TreeNode* bigParent = curr->parent;
        TreeNode* rightChildOfX = curr->leftChild->rightChild;
        TreeNode* xPointer = curr->leftChild;
        if (xPointer->titleChar < bigParent->titleChar) bigParent->leftChild = xPointer;
        else if (xPointer->titleChar > bigParent->titleChar) bigParent->rightChild = xPointer;
        xPointer->rightChild = curr;
        curr->parent = xPointer;
        curr->leftChild = rightChildOfX;
        xPointer->parent = bigParent;

    }



}
