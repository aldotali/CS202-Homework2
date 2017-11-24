/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A header file that is used for the implementation of the array based BST
*/

#include "AbBinaryNode.h"
#include <iostream>
using namespace std;

class AbBST
{
	  private :
	  	 int max_size;		//the size of the array
      public :
      AbBST();				//constructor
	
	  //inserts a value into the BST
      void insert(int val);
	  //returns the height of the tree
      int getHeight();
	  //helper function to get the height startign from the root
	  int helperGetHeight(int root);
	  //return the overall size of the array (max_size)
	  int getMaxSize();
	  //changes the overall size of the array (max_size)
	  void setMaxSize(int size);

	  //pointer to dynamically allocate the array
	  AbBinaryNode *tree;
	  int size;		//the number of arrays that we have inserted so far
	  //finds the the insert location and update the leftChild and RightChild indeces
	  void findInsertPlace(int val, int index);
	  void reallocateTree();	//allocate a tree with the double the size
      void displayTree();		//outputs the elements of the tree
};
