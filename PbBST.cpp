/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : This is the cpp file which implements the neccessary functions
* for the assignment given
*/

#include <iostream>
using namespace std;
#include "PbBST.h"
#include <cstdlib>
#include <math.h>

//constructor
PbBST :: PbBST(){
    root = NULL;
}

/*
//destructor
PbBST :: ~PbBST(){
	destroyTree(root);
}
*/
//deletes the tree starting from root
//Note that this code is already available in the textbook
void PbBST :: destroyTree(PbBinaryNode* &ptr){
	if(ptr!=NULL){
		destroyTree(root->leftChildPtr);
		destroyTree(root->rightChildPtr);
		delete ptr;
		ptr = NULL;
	}
}

//takes a value and inserts it to the Binary Search Tree
void PbBST :: insert(int val){
    helperInstert(root, val);
}

//Takes a root and a value and starting from the root finds the 
//correct position where to insert the value nad inserts it to the tree
//Note that this method will insert duplicate values to the right of the node
// for the sake of the assignemnt requirements.
void PbBST :: helperInstert(PbBinaryNode* &root, int value){
    //we found the place to insert
    if (root == NULL){
        root = new PbBinaryNode(value,NULL,NULL);
    } else {
        //check the left subtree if the value is smaller than root value
        //check right otherwise
        if (value < root->item){
            //if the place of insertion is on the left set the left Ptr to a new node
            PbBinaryNode * left = root->leftChildPtr;
            if (left == NULL){
                root->leftChildPtr = new PbBinaryNode(value,NULL,NULL);
            } else
                helperInstert(left, value); // keep searching
        } else {
            //if the place of insertion is on the right set the right Ptr to a new node
            PbBinaryNode * right = root->rightChildPtr;
            if (right == NULL){
                root->rightChildPtr = new PbBinaryNode(value,NULL,NULL);
            }else
                helperInstert(right, value); //keep searching
        }
    }
}

//returns the height of a tree
int PbBST :: getHeight() {
    return helperGetHeight(root);
}

//starts from root and returns the height of that tree from the root
int PbBST :: helperGetHeight(PbBinaryNode *root){
    //a Null value means the tree does not increase anymore
    if (root == NULL)
        return 0;
    else {
        //get the height of the left and right subtrees and add 1 more to that height
        // which is for the height that the root adds up.
        int left = 1 + helperGetHeight(root->leftChildPtr);
        int right = 1 + helperGetHeight(root ->rightChildPtr);
        if (left < right)
            return right;
        else
            return left;
    } 
}

//outputs the elements of the tree in a preorder fashion
//1.Root 2.Left 3.Right
void PbBST :: displayTree(PbBinaryNode* root){
    if (root != NULL){
        cout <<root->item<<endl;
        PbBinaryNode*  left = root->leftChildPtr;
        displayTree(left);
        PbBinaryNode* right = root->rightChildPtr;
        displayTree(right);
    }
}

//checks id the tree is a valid Binary Search Tree
bool PbBST :: isValidBST(){
    checkBST(root);
}

//starts from root and checks if the tree is a Binary Search Tree or not
bool PbBST :: checkBST(PbBinaryNode* root){
    //a Null node is by default a BST so check whatever is not NULL
    if (root != NULL){
        bool isLeftNULL = (root->leftChildPtr == NULL);
        bool isRightNULL = (root->rightChildPtr == NULL);

        //By default a sigle node with no children represents a BST
        if (isLeftNULL && isRightNULL){
            return true;
        } else if (!isLeftNULL && !isRightNULL) {
            //in the case where both children exist check both childrens keys and the root key
            if (root->item < (root->rightChildPtr)->item && 
                root->item > (root->leftChildPtr)->item){
                    return true;
                }
            return false;
        } else if (!isRightNULL){
            //check the case when only the node has only 1 child
            if (root->item < (root->rightChildPtr)->item )
                return true;
            else return false;
        }else {
            if (root->item > (root->leftChildPtr)->item )
                return true;
            else return false;
        }
    } else  return true;
}

//computes the median of a BinarySearchTree
//returns -27 when the tree is empty.
//Note that in the case that there are an even number of nodes the number returned by the median
// will be rounded. Ex: 7.5 returns 8 whereas 7.4 returns 7;
int PbBST :: medianOfBST(){
    //count the number of the nodes
    int nodeCount = countNodes(root);
    int count = 0;
    int item = -27;
    int result = -27;

    //find the median values (in case the nodeConunt is even both the values are meaningful)
    findMedianInOrder(root, count, item,result, nodeCount);
    //even number of nodes returns the average of the middle 2 values otherwise the middle value is enough
    if (nodeCount%2 == 0)
        return (int) round((item+result)/2.0);
    else
    return result;

}

//counts the number of nodes in a tree
int PbBST :: countNodes(PbBinaryNode* root){
    if (root == NULL)
        return 0;
    else {
        return (1 + countNodes(root->leftChildPtr) + countNodes(root->rightChildPtr));
    }
}

//makes an inorder traversal to find the 2 nodes at the count/2 location
//results will be returned on item and item2
void PbBST :: findMedianInOrder(PbBinaryNode* root, int &count, int &item,int &item2, int size){
    //a null root does not return anything
    if (root != NULL){
        //make an inorder traversal
        findMedianInOrder(root->leftChildPtr, count, item,item2, size);
        //an even number of nodes returns 2 values at indexes size/2 -1 and size/2
        if (size % 2 == 0 ){
            if (count == (size/2)-1){
                item = root->item;
            }   
            else {
                if (count == size/2){
                    count++;
                    item2 = root->item;
                }
            }   
        } else {
            //od number of nodes return only 1 values
            if (count == size/2){
                count++;
                item2 = root->item;
            }
        }
        count++;
        findMedianInOrder(root->rightChildPtr, count, item,item2, size);
    }
}
