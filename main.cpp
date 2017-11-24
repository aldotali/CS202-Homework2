/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description :main file to test the implementation
*/

#include <iostream>
#include "analysis.h"
#include "PbBST.h"
using namespace std;

void executePartG(){
    cout <<"Inserting the testers\n\n"<<endl;
    //PbBST *tester = new PbBST();
    PbBST *tester = new PbBST();
    tester->insert(40);
    tester->insert(50);
    tester->insert(45);
    tester->insert(30);
    tester->insert(60);
    tester->insert(55);
    tester->insert(20);
    tester->insert(35);
    tester->insert(10);
    tester->insert(25);

    //10 20 25 30 35 40 45 50 55 60
    //tester->displayTree(tester->root);
    
    bool isValidBST = tester->isValidBST();
    cout<<"The tree is valid? -> "<<isValidBST<<endl;

    int medianOfBST = tester->medianOfBST();
    cout<<"The median value of this BST is : "<<medianOfBST<<endl<<endl<<endl;
}

void executePartF(){
    heightAnalysis();
}

void executePartE(){
    performanceAnalysis();
}


int main (){
    executePartG();
    executePartF();
    executePartE();


/*
    PbBST aldo = PbBST(); 
    aldo->insert(3);
    aldo->insert(5);
    aldo->insert(2);
    aldo->insert(0);

    int height = aldo->getHeight();
    cout <<"the height is: "<<height<<endl;

    bool valid = aldo->isValidBST();
    cout<<"Is valid:: "<<valid<<endl;
    aldo->displayTree(aldo->root);

    PbBinaryNode* tester = new PbBinaryNode(5,NULL,NULL);
    tester->setLeftChildPtr(new PbBinaryNode(6,NULL,NULL));
    tester->setRightChildPtr(NULL);
    valid = aldo->checkBST(tester);
    cout<<"Is valid:: "<<valid<<endl;*/


    /*int no = aldo->countNodes(aldo->root);
    cout<<"Number of nodes : "<<no<<endl;*/

   // int median = aldo->medianOfBST();
    //cout<<"The median is : "<<median<<endl;
    return 0;

}