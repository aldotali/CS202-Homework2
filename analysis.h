/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A header file that is used for the implementation of the performanceAnalysis
* and heightAnalysis
*/

//returns the runtime needed to insert an array of values with size size into the pointer
//based implementation of he BST
double getRunTimePBST(int* arr, int size) ;
//returns the runtime needed to insert an array of values with size size into the array
//based implementation of he BST
double getRunTimeABST(int* arr, int size) ;
//returns an array of size size filled with randomly generated integers
int* generateRandom(int size) ;

//outputs the time needed for to insert different number of nodes in the Array and
//pointer Based implementation
void performanceAnalysis() ;

//returns the height of the tree after insertin an array of values into the BST
int getHeightRBST(int* arr, int size) ;
//returns an array of ascending numbers 
int* generateAscending(int size) ;

//outputs the height of trees for different numbers of nodes
//This is for the case when the nodes are in random order and in ascending order
void heightAnalysis() ;

