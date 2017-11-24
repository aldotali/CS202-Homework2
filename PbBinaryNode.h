/**
* Title : Binary Search Trees
* Author : Aldo Tali
* ID: 21500097
* Section : 2
* Assignment : 2
* Description : A header file for the BinaryNode of the pointer based implementation
*/

class PbBinaryNode
{
    private :
        int item ; 
        PbBinaryNode * leftChildPtr ; 
        PbBinaryNode * rightChildPtr ;
        
    public :
        PbBinaryNode () ;
        PbBinaryNode ( const int & anItem ) ;
        PbBinaryNode ( const int & anItem ,
                    PbBinaryNode * leftPtr ,
                    PbBinaryNode * rightPtr ) ;
        friend class PbBST;
};
