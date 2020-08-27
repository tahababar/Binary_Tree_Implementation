#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;


void BinarySearchTree::makeHardcodedTree() {
	// ------------------------------------------
	// root
	root = new IntBTNode();
	root->data = 20;
	root->left = NULL;
	root->right = NULL;

	// ------------------------------------------
	// Children of root
	IntBTNode* leftOfRoot = new IntBTNode();
	leftOfRoot->data = 15;
	leftOfRoot->left = NULL;
	leftOfRoot->right = NULL;

	IntBTNode* rightOfRoot = new IntBTNode();
	rightOfRoot->data = 27;
	rightOfRoot->left = NULL;
	rightOfRoot->right = NULL;

	root->left = leftOfRoot;
	root->right = rightOfRoot;

	// ------------------------------------------
	// Children of root's left child
	IntBTNode* leftOfLeft = new IntBTNode();
	leftOfLeft->data = 12;
	leftOfLeft->left = NULL;
	leftOfLeft->right = NULL;

	IntBTNode* rightOfLeft = NULL; // no node here

	leftOfRoot->left = leftOfLeft;
	leftOfRoot->right = rightOfLeft;

	// ------------------------------------------
	// Children of root's right child
	IntBTNode* leftOfRight = new IntBTNode();
	leftOfRight->data = 23;
	leftOfRight->left = NULL;
	leftOfRight->right = NULL;

	IntBTNode* rightOfRight = new IntBTNode();
	rightOfRight->data = 29;
	rightOfRight->left = NULL;
	rightOfRight->right = NULL;

	rightOfRoot->left = leftOfRight;
	rightOfRoot->right = rightOfRight;

	// ------------------------------------------
	// One more child - a great grandchild of the root

	IntBTNode* last = new IntBTNode();
	last->data = 28;
	last->left = NULL;
	last->right = NULL;

	rightOfRight->left = last;
}

void BinarySearchTree::destructorHelper(IntBTNode* curr) {
	if (curr != NULL) {
		IntBTNode* left = curr->left;
		IntBTNode* right = curr->right;
		delete curr;
		destructorHelper(left);
		destructorHelper(right);
	}
}

BinarySearchTree::~BinarySearchTree() {
	cout << "Calling destructor (automatically, on the local BinarySearchTree variables declared in runTest)" << endl;
	destructorHelper(root);
}

void BinarySearchTree::printSpaces(int numSpaces) {
	for (int i = 0; i < numSpaces; i++)
		cout << " ";
}

void BinarySearchTree::printHelper(IntBTNode* curr, int depth, char header) {
	if (curr != NULL) {
		printSpaces(depth * 4);
		if (curr != root)
			cout << header << ": ";

		cout << curr->data << endl;
		printHelper(curr->left, depth + 1, 'L');
		printHelper(curr->right, depth + 1, 'R');
	}
}

void BinarySearchTree::print() {
	cout << "-------------------------------" << endl;
	printHelper(root, 0, ' ');
	cout << "-------------------------------" << endl;
}

/////////////////////////////////////////

void BinarySearchTree::insertHelper(IntBTNode* &curr, IntBTNode* add) {
	if (curr == NULL)
		curr = add;
	else {
		if (add->data < curr->data)
			insertHelper(curr->left, add);
		else
			insertHelper(curr->right, add);
	}
}

void BinarySearchTree::insert(int value) {
	IntBTNode* add = new IntBTNode();
	add->data = value;
	add->left = NULL;
	add->right = NULL;
	
	insertHelper(root, add);
}

void BinarySearchTree::printInOrder()
{   
	printInOrderHelper(root);
	cout << endl;
}

void BinarySearchTree::printInOrderHelper(IntBTNode* curr)
{   
	if (curr != NULL) {
		printInOrderHelper(curr->left);
		cout << curr->data << " ";
		printInOrderHelper(curr->right);
	}
}

bool BinarySearchTree::contains(int value)
{
	
	return containsHelper(root, value);
}

bool BinarySearchTree::containsHelper(IntBTNode* curr, int value)
{
	    if (curr == NULL)
	    {
		    return false;
	    }
		else if (curr->data == value)
		{
			return true;
		}
		else if (curr->data > value)
		{
		    return containsHelper(curr->left, value);
		}
		else 
		{
			return containsHelper(curr->right, value);
		}
}

int BinarySearchTree::countEvens(IntBTNode* curr)
{   
		if (curr == NULL)
		{
			return 0;
		}
		else  if (curr->data % 2 != 0)
		{
			return countEvens(curr->left) + countEvens(curr->right);			
		}
		else
		{
			return 1 + countEvens(curr->left) + countEvens(curr->right);			
		}	
}

int BinarySearchTree::countFull(IntBTNode* curr)
{	
	if (curr == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + countFull(curr->left) + countFull(curr->right);
	}
}


bool BinarySearchTree::onlyEvens()
{
	int ctEvens = countEvens(root);
	int ctFull = countFull(root);
	if (ctEvens == ctFull)
	{
		return true;
	}
	else
	{
		return false;
	}
}







