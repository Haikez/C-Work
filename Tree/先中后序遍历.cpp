#include<iostream>
#include"tree.h"
using namespace std;
void preOrder(BTree T){
    if (!T)
        return;
    visit(T);
    preOrder(T->lchild);
    preOrder(T->rchild);
}
void InOrder(BTree T){
    if (!T)
    {
        return;
    }
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}
void PostOrder(BTree T){
    if (!T)
    {
        return;
    }
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}
int main(){
    BTree T;
    createTree(T);
    preOrder(T);
    cout<<endl;
    InOrder(T);
    cout<<endl;
    PostOrder(T);
}