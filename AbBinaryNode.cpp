/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A cpp file that is used for the implementation of the array based BinaryNode
*/

#include "AbBinaryNode.h"
#include <iostream>
using namespace std;

AbBinaryNode :: AbBinaryNode () {
        leftIndex = -27;
        rightIndex = -27;
}

AbBinaryNode :: AbBinaryNode (const int &item){
        nodeItem = item;
        leftIndex = -27;
        rightIndex = -27;
}
AbBinaryNode :: AbBinaryNode(const int &item, int left, int right){
        nodeItem = item;
        leftIndex = left;
        rightIndex = right;
}