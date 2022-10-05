#include<iostream>
#include<vector>
using namespace std;
typedef struct BTNode{
    int data;
    struct BTNode *lchild=NULL,*rchild=NULL;
} *BTree;
