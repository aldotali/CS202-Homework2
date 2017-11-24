/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A cpp file for the BinaryNode of the pointer based implementation
*/

#include "PbBinaryNode.h"
#include <iostream>
using namespace std;

// constructor 
PbBinaryNode :: PbBinaryNode (){
           leftChildPtr = NULL;
           rightChildPtr = NULL;
} 

// constructor 
PbBinaryNode :: PbBinaryNode ( const int & anItem ) {
           item = anItem;
           leftChildPtr = NULL;
           rightChildPtr = NULL;

}
// constructor 
PbBinaryNode :: PbBinaryNode ( const int & anItem , PbBinaryNode * leftPtr, PbBinaryNode * rightPtr ){
           item = anItem;
           leftChildPtr = leftPtr;
           rightChildPtr = rightPtr;
}