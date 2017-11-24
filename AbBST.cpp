/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A cpp file that is used for the implementation of the array based BST
*/

#include <iostream>
#include "AbBST.h"

//constructor
//initially the maximum size is 2
AbBST :: AbBST() {
    setMaxSize(2);
    int max = getMaxSize();
    tree = new AbBinaryNode[max];
    size = 0;
}

//return the maximum size of the array
int AbBST :: getMaxSize(){
    return max_size;
}

//sets the maximum size of the arrayh
void AbBST :: setMaxSize(int size){
    max_size = size;
}

//inserts a new element in the array
void AbBST :: insert(int val) {
    if (size >= getMaxSize()){
        reallocateTree();
    }
    tree[size] = AbBinaryNode(val);
    findInsertPlace(val, size);
    size++;
}

//finds the insert location and update the left child and right child indeces
void AbBST :: findInsertPlace(int val, int index){
    int root = 0;
    int insertIndex;
    while (root < index){
        if (root > size){
            root = -27;         //-27 indicates a non existing value (index lower than 0 is meaningless in the array)
        }
        //traverse the treee
        else if (tree[root].nodeItem > val){
            if (tree[root].leftIndex < 0){
                insertIndex = root;
                tree[root].leftIndex = index;
                root = -27;
            }
            else
                root = tree[root].leftIndex;
        } else /*if (tree[root].nodeItem < val)*/ {
            if (tree[root].rightIndex < 0){
                insertIndex = root;
                tree[root].rightIndex= index;
                root = -27;
            }
            else
                root = tree[root].rightIndex;
        }
    }
}

//reallocates the tree array by doubling the size of the array and deletes the old array
void AbBST :: reallocateTree(){
    setMaxSize(2*getMaxSize());
    int max = getMaxSize();
    AbBinaryNode* temp = new AbBinaryNode[max];
    for (int i = 0; i < max; i++){
        if (i < size){
            temp[i] = tree[i];
        }
    }
    delete []tree;
    tree = NULL;
    tree = temp;
    temp = NULL;
    delete temp;
}

//serves to display the tree
void AbBST :: displayTree(){
    for (int i = 0; i < size; i++){
        cout<<"Element: "<<tree[i].nodeItem<<" LEft: "<<tree[i].leftIndex<<" Right: "<< tree[i].rightIndex<<"\n";
    }
}

//return the height of the tree
int AbBST :: getHeight(){
    if (size == 0)
    return 0;
    else
    return helperGetHeight(0);
}

//helper function for geting the height of the BST
int AbBST :: helperGetHeight(int root){
    if (root < 0)
        return 0;
    else {
        //here left and right hold the potential height of the tree starting at root
        int left = 1 + helperGetHeight(tree[root].leftIndex);   
        int right = 1 + helperGetHeight(tree[root].rightIndex);
        if (left < right)
            return right;
        else
            return left;
    } 
}