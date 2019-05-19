#ifndef __BINARYTREESORT_H__
#define  __BINARYTREESORT_H__

/*About: binary tree sort to ordered double linked list.
*
* Author:baluoteliz@gmail.com
*/
#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct eTagTreeNode {
    int nValue;
    eTagTreeNode* pLeft;
    eTagTreeNode* pRight; 
    eTagTreeNode():
    nValue(0),
    pLeft(NULL),
    pRight(NULL)
    {;}

    eTagTreeNode(int value): nValue(value){;}
    bool operator<(const eTagTreeNode &NodeObject) {
        return nValue < NodeObject.nValue;
    }

}TREENODE,*PTREENODE,*LPTREENODE;

void convertTreeNode(LPTREENODE pNodeRoot,LPTREENODE pPre) {
    //line left node
    if(NULL == pNodeRoot->pLeft)
        return;
    
    convertTreeNode(pNodeRoot->pLeft,pPre);
    pNodeRoot->pLeft = pPre;

    if(pPre) 
        pPre->pRight = pNodeRoot;
    
    pPre = pNodeRoot;
    convertTreeNode(pNodeRoot->pRight,pPre);
}

LPTREENODE convertTreeToBin(TREENODE& treeNode) {
    //line left node
    LPTREENODE pTempHead = &treeNode;
    while(pTempHead) {
        pTempHead = pTempHead->pLeft;
    }

    LPTREENODE pPrev = NULL;
    convertTreeNode(&treeNode,pPrev);

    return pTempHead;
}

void printfOrderedNode(LPTREENODE pNodeRoot) {
    LPTREENODE pNodeTemp = pNodeRoot;
    while(pNodeTemp->pRight)
        cout<<"Node: "<<pNodeTemp->nValue<<endl;
}

int main() {
    //Create BinaryTree (native logic code ingore..)

    TREENODE treeNode;
    LPTREENODE pNodeRoot =  convertTreeToBin(treeNode);
    printfOrderedNode(pNodeRoot);

    return 0;
}

#endif