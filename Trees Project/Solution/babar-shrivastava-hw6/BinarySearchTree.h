#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

class BinarySearchTree
{
public:
	void makeHardcodedTree();
	void print();
	~BinarySearchTree();
	void printInOrder();
	void insert(int value);
	bool contains(int value);
	bool onlyEvens();



private:
	void printSpaces(int numSpaces);
	void printHelper(IntBTNode* curr, int depth, char header);
	void destructorHelper(IntBTNode* curr);
	void insertHelper(IntBTNode* &curr, IntBTNode* add);
	void printInOrderHelper(IntBTNode* curr);
	bool containsHelper(IntBTNode* curr, int value);
	int countEvens(IntBTNode* curr);
	int countFull(IntBTNode* curr);
	IntBTNode* root;
};
