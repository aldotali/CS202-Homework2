/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : This is a header file for a 
* pointer based implementation of a Binary Search Tree
*/

#include "PbBinaryNode.h"
#include <iostream>
using namespace std;


class PbBST
{
      public :
            PbBST();                //constructor
           // ~PbBST();               //destructor
            
            //takes a pointer to the root and deletes the whole tree recursevly
            void destroyTree(PbBinaryNode *& root);

            //inserts a new node containing a value of val
            void insert(int val);
            //returns the height of the tree
            int getHeight();
            //checks if the given tree is a valid BST
            bool isValidBST();

            //helper function which takes a root pointer and checks for the validity of BST tree
            bool checkBST(PbBinaryNode* root);
            //helper function used for inserting a new node in the tree
            void helperInstert(PbBinaryNode* &root, int value);
            //helper function used for getting the height of the tree
            int helperGetHeight(PbBinaryNode *root);

            //keeps the rrot pointer to the tree
            PbBinaryNode* root;

            //auxillary function to display the elements of the tree in PreOrder traversal
            void displayTree(PbBinaryNode* root);
            //returns the number of nodes in a given tree
            //auxillary for calculating the median
            int countNodes(PbBinaryNode* root);
            //finds the item at location count and returns it 
            void findMedianInOrder(PbBinaryNode* root, int &count, int &item,int &item2, int location);
            //returns the median of the tree
            int medianOfBST();
};
