/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A cpp file that is used for the implementation of the performanceAnalysis
* and heightAnalysis
*/

#include <iostream>
#include <ctime>
#include <stdlib.h> 
#include <iomanip>
#include "PbBST.h"
#include "AbBST.h"
#include "analysis.h"
using namespace std;

//returns the runtime needed to insert an array of values with size size into the pointer
//based implementation of he BST
double getRunTimePBST(int* arr, int size){
    PbBST aldo = PbBST();
    double begin = clock();
    for (int i = 0; i < size; i++){
        aldo.insert(arr[i]);
    }
    double end = clock();
    //aldo->displayTree(aldo->root);
    return (end-begin)*1000.0/double(CLOCKS_PER_SEC);
}

//returns the runtime needed to insert an array of values with size size into the array
//based implementation of he BST
double getRunTimeABST(int* arr, int size){
    AbBST aldo = AbBST();
    double begin = clock();
    for (int i = 0; i < size; i++){
        aldo.insert(arr[i]);
    }
    double end = clock();
    //aldo->displayTree(aldo->root);
    return (end-begin)*1000.0/double(CLOCKS_PER_SEC);
}

//returns an array of size size filled with randomly generated integers
int* generateRandom(int size){
    int* results = new int[size];
    for (int i = 0; i < size; i++){
        results[i] = rand();
    }
    return results;
}

//outputs the time needed for to insert different number of nodes in the Array and
//pointer Based implementation
void performanceAnalysis(){
    int sizes[] = {2000,4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};
    int size = 10;
    int *results;
    double timeP;
    double timeA;
   AbBST aldo;
    cout<< "Part e - Analysis of BST height"<<endl;
    cout<< "----------------------------------------------------------"<<endl;
    cout<< "Array Size"<<setw(20)<<"Array Based"<<setw(20)<<"Pointer Based"<<endl;
    cout<< "----------------------------------------------------------"<<endl;
    for (int i = 0; i < size; i++){
            results = generateRandom(sizes[i]);
            timeP = getRunTimePBST(results, sizes[i]);
            if (i < 3) //reason for this given in the readME
                timeA = getRunTimeABST(results, sizes[i]);
            delete [] results;
            cout<<sizes[i]<<setw(20)<<timeA<<setw(20)<<timeP<<endl;
            AbBST temp;
            aldo = temp;
    }

    cout<<endl<<endl;
}

//returns the height of the tree after insertin an array of values into the BST
int getHeightRBST(int* arr, int size){
    PbBST aldo = PbBST();
    for (int i = 0; i < size; i++){
        aldo.insert(arr[i]);
    }
    //aldo->displayTree(aldo->root);
    int height = aldo.getHeight();
    return height;
}

//returns an array of ascending numbers 
int* generateAscending(int size){
    int* results = new int[size];
    for (int i = 0; i < size; i++){
        results[i] = i;
    }
    return results;
}

//outputs the height of trees for different numbers of nodes
//This is for the case when the nodes are in random order and in ascending order
void heightAnalysis(){
    int sizes[] = {2000,4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};
    int size = 10;
    int *results;
    int *resultsA;
    int heightR;
    int heightA;

    cout<< "Part f - Performance analysis of BST implementations"<<endl;
    cout<< "----------------------------------------------------------"<<endl;
    cout<< "Array Size"<<setw(20)<<"Random Number"<<setw(20)<<"Ascending Numbers"<<endl;
    cout<< "----------------------------------------------------------"<<endl;
    for (int i = 0; i < size; i++){
            results = generateRandom(sizes[i]);
            resultsA = generateAscending(sizes[i]);
            heightR = getHeightRBST(results, sizes[i]);
            heightA = getHeightRBST(resultsA, sizes[i]);
            delete [] results;
            cout<<sizes[i]<<setw(20)<<heightR<<setw(20)<<heightA<<endl;
    }
    cout<<endl<<endl;
}

