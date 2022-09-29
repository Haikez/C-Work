#include<iostream>
using namespace std;

//通过一个升序序列创建平衡二叉树
typedef struct BTNode{
    BTNode *lchild;
    BTNode *rchild;
    int data;
}BTNode,*BTree;
BTree helper(int nums[],int left,int right){
    if (left>right) return NULL;
    int mid=(left+right)/2;
    BTNode *root=new BTNode;
    root->data=nums[mid];
    root->lchild=helper(nums,left,mid-1);
    root->rchild=helper(nums,mid+1,right);
    return root;
}
void preOrder(BTree T){
    if(T){
        preOrder(T->lchild);
        cout<<T->data<<" ";
        preOrder(T->rchild);
    }
}
int main(){
    int nums[]={1,2,3,4,5,6,7,8,9,10};
    BTree T=helper(nums,0,9);
    preOrder(T);
}