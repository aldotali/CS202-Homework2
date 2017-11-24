/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A header file that is used for the implementation of the array based BinaryNode
*/

class AbBinaryNode {
    private :
        int nodeItem;
        int leftIndex;
        int rightIndex;
    public :
        AbBinaryNode();
        AbBinaryNode(const int &item);
        AbBinaryNode(const int &item, int left, int right);
        friend class AbBST;
};
