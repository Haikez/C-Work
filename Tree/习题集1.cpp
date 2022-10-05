#include <iostream>
#include "tree.h"
using namespace std;
//先中后遍历序列:
// 1 2 4 7 10 3 5 8 9 6
// 4 7 2 10 1 8 5 9 3 6
// 7 4 10 2 8 9 5 6 3 1

// 1. 求二叉链表树的树高
int getHight(BTree T)
{
    if (!T)
    {
        return 0;
    }
    int l = getHight(T->lchild);
    int r = getHight(T->rchild);
    return l > r ? l + 1 : r + 1;
}
// 2. 根据先序和中序构造二叉链表树
BTree PreInCreate(int A[], int B[], int l1, int r1, int l2, int r2)
{
    BTNode *root = new BTNode;
    root->data = A[l1];
    int i = l2;
    for (; B[i] != root->data; i++)
        ;
    int llen = i - l2;
    int rlen = r2 - i;
    if (llen)
    {
        root->lchild = PreInCreate(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    }
    else
        root->lchild = NULL;
    if (rlen)
    {
        // root->rchild = PreInCreate(A, B, r1 - rlen + 1, r1, r2 - rlen + 1, r2);
        root->rchild = PreInCreate(A, B, r1 - rlen + 1, r1, l2 + llen + 1, r2);

    }
    else
        root->rchild = NULL;
    return root;
}
//先序遍历
void PreOrder(BTree T){
    if (T)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }else return;
    
}
//中序遍历
void InOrder(BTree T)
{
    if (!T)
    {
        return;
    }
    InOrder(T->lchild);
    visit(T);
    InOrder(T->rchild);
}
//后序遍历检查正确性
void PostOrder(BTree T)
{
    if (!T)
    {
        return;
    }
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T);
}
// 3.判断是否为完全二叉树
bool isComplete(BTree T)
{
    BTNode *queue[maxSize];
    //初始化置空!!!
    for (int i = 0; i < maxSize; i++)
        queue[i]=NULL;

    int front = 0, rear = 0;
    if (!T)
        return true;
    queue[rear++] = T;
    BTNode *p;
    while (front != rear)
    {
        p = queue[front++];
        if (!p)
        {
            for (int i = front; i <= rear; i++)
            {
                if (queue[i])
                    return false;
            }
        }
        else
        {
            queue[rear++] = p->lchild;
            queue[rear++] = p->rchild;
        }
    }
    return true;
}

// 4.将指针p指向二叉树中值为key的结点
void search(BTree T, BTNode *&p, int key)
{
    if (T)
    {
        if (T->data == key)
        {
            p = T;
        }
        search(T->lchild, p, key);
        search(T->rchild, p, key);
    }
}

// 5. 输出先序遍历中第k个值
int n = 0;
void print_k(BTree T, int k)
{
    if (T)
    {
        n++;
        if (n == k)
            visit(T);
        else
        {
            print_k(T->lchild, k);
            print_k(T->rchild, k);
        }
    }
}


// 6. 求树的宽度
typedef struct
{
    BTNode *node;
    int level;
} lNode;

void getWidth(BTree T)
{
    lNode queue[maxSize];
    int front = 0, rear = 0;
    lNode p;
    if (T)
    {
        queue[rear].node = T;
        queue[rear].level = 1;
        rear++;
    }

    while (front != rear)
    {
        p = queue[front++];
        if (p.node->lchild)
        {
            queue[rear].node = p.node->lchild;
            queue[rear].level = p.level + 1;
            rear++;
        }
        if (p.node->rchild)
        {
            queue[rear].node = p.node->rchild;
            queue[rear].level = p.level + 1;
            rear++;
        }
    }
    int max = 0, n = 0;
    int l = queue[rear].level;
    for (int i = 1; i <= l; i++)
    {
        n = 0;
        for (int j = 0; j < rear; j++)
        {
            if (queue[j].level == i)
                n++;
            if (n > max)
                max = n;
        }
    }
    cout << max;
}
// 7.计算一棵给定二叉树的所有双分支结点个数
int getNum(BTree T)
{
    if (!T)
        return 0;
    else if (T->lchild != NULL && T->rchild != NULL)
    {
        return getNum(T->lchild) + getNum(T->rchild) + 1;
    }
    else
    {
        return getNum(T->lchild) + getNum(T->rchild);
    }
}
// 8.把树中所有结点的左右子树进行交换
void Swap(BTree T)
{
    if (!T)
    {
        return;
    }
    BTNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
    Swap(T->lchild);
    Swap(T->rchild);
}
// 9.删除树中所有值为x的结点，删去以它为根的子树，并释放空间
void del(BTree T)
{
    if (!T)
        return;
    del(T->lchild);
    del(T->rchild);
    delete (T);
}
void sdel(BTree T, int x)
{
    if (!T)
        return;
    if (T->lchild)
    {
        if (T->lchild->data == x)
        {
            T->lchild = NULL;
            del(T->lchild);
        }
    }
    if (T->rchild)
    {
        if (T->rchild->data == x)
        {
            T->rchild = NULL;
            del(T->rchild);
        }
    }
    sdel(T->lchild, x);
    sdel(T->rchild, x);
}
// 10.打印值为x的结点的所有祖先，假设值为x的结点不多于1个
int stack[maxSize] = {0};
int top = -1;
void printParent(BTree T, int x)
{
    if (!T)
        return;
    if (T->data == x)
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
    }
    stack[++top] = T->data;
    printParent(T->lchild, x);
    printParent(T->rchild, x);
    --top;
}
// 11.设一棵二叉树的结点结构为(LLINK,INFO,RLINK),ROOT为指向该二叉树根节点的指针，p和q分别为指向该二叉树中任意两个结点的指针，试编写算法ANCESTOR(ROOT,p,q,r),找到p和q的最近公共祖先结点r
BTNode *S[maxSize];
BTNode *S1[maxSize];
BTNode *r;
void ancestor(BTree T, BTNode *p, BTNode *q)
{
    if (!T)
        return;
    if (T == p)
    {
        for (int i = 0; i <= top; i++)
            S1[i] = S[i];
    }
    if (T == q)
    {
        int i = -1;
        while (S1[i + 1] == S[i + 1] && i + 1 <= top)
            i++;
        r = S[i];
    }
    ++top;
    S[top] = T;
    ancestor(T->lchild, p, q);
    ancestor(T->rchild, p, q);
    --top;
}
// 12.有一棵满二叉树，已知先序，设计一个算法求其后序
void PreToPost(int pre[], int l1, int r1, int post[], int l2, int r2)
{
    if (r1 >= l1)
    {
        post[r2] = pre[l1];
        int half = (r1 - l1) / 2;
        PreToPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        PreToPost(pre, l1 + half + 1, r1, post, r2 - half, r2 - 1);
    }
}
// 13.设计一个非递归方法求二叉树高度
int getHeight2(BTree T)
{
    BTNode *queue[maxSize];
    int front = 0, rear = 0, level = 0, last = 1;
    if (!T)
        return 0;
    queue[rear++] = T;
    BTNode *p;
    while (front != rear)
    {
        p = queue[front++];
        if (p->lchild)
            queue[rear++] = p->lchild;
        if (p->rchild)
        {
            queue[rear++] = p->rchild;
        }
        if (front == last)
        {
            level++;
            last = rear;
        }
    }
    return level;
}
// 14.设计算法，将二叉树叶子结点从左往右穿起来
void Linkleaf(BTree T, BTNode *&head, BTNode *&tail)
{
    if (T)
    {
        if (T->lchild == NULL && T->rchild == NULL)
        {
            if (!head)
            {
                head = tail = T;
            }
            else
            {
                tail->rchild = T;
                tail = tail->rchild;
            }
        }
        Linkleaf(T->lchild, head, tail);
        Linkleaf(T->rchild, head, tail);
    }
}
// 15 判断两个二叉树是否相似
bool isSimilar(BTree T1, BTree T2)
{
    if (T1 == NULL && T2 == NULL)
        return true;
    else if (T1 == NULL || T2 == NULL)
        return false;
    else
    {
        return isSimilar(T1->lchild, T2->lchild) && isSimilar(T1->rchild, T2->rchild);
    }
}
// 16. 设计算法输出二叉树中值为x的层号
int level = 1;
void getlevel(BTree T, int x)
{
    if (T)
    {
        if (T->data == x)
        {
            cout << level;
        }
        ++level;
        getlevel(T->lchild, x);
        getlevel(T->rchild, x);
        --level;
    }
}
// 17.计算二叉树叶子结点的权值和
int leaf_weight = 0;
void getleafWeight(BTree T)
{
    if (!T)
        return;
    if (T->lchild == NULL && T->rchild == NULL)
    {
        leaf_weight += T->data;
    }
    getleafWeight(T->lchild);
    getleafWeight(T->rchild);
}
// 18. 将给定的表达式转化成中缀表达式（用括号反映操作次序）
//(((47)210)1((859)36))
//((47)210)1((859)36)
void BTreeToExp(BTree T, int deep)
{
    if (!T)
    {
        return;
    }
    if (T->lchild == NULL && T->rchild == NULL)
    {
        cout << T->data;
        return;
    }
    if (deep > 1)
        cout << "(";
    BTreeToExp(T->lchild, deep + 1);
    cout << T->data;
    BTreeToExp(T->rchild, deep + 1);
    if (deep > 1)
        cout << ")";
}
int main()
{
    BTree T;
    int A[] = {1, 2, 4, 5, 3, 6, 7};
    int B[] = {4, 2, 5, 1, 6, 3, 7};
    // BTree BT;
    // BT = PreInCreate(A, B, 0, 6, 0, 6);
    createTree(T);
    // PreOrder(BT);
    // cout<<endl;
    // InOrder(BT);
    // cout << getHight(T);
    // Swap(T);
    // InOrder(T);
    // cout<<endl;
    // PostOrder(BT);
    // cout << isComplete(BT);
    // BTNode *p=NULL;
    // search(T,p,10);
    // cout<<p->data;
    // getWidth(T);
    // cout<<getNum(T);
    // sdel(T, 5);
    // InOrder(T);
    // printParent(T,9);
    // 11
    // BTNode *p=T->lchild->lchild->rchild;
    // BTNode *q=T->lchild->rchild;
    // ancestor(T,p,q);
    // cout<<r->data;
    // 12
    // int pre[]={1,2,4,5,3,6,7};
    // int post[7]={0};
    // PreToPost(pre,0,6,post,0,6);
    // for (int i = 0; i < 7; i++)
    // {
    //     cout<<post[i]<<" ";
    // }
    // 13
    // cout<<getHeight2(T);
    // 14
    // BTNode *head=NULL;
    // BTNode *tail=NULL;
    // Linkleaf(T,head,tail);
    // while (head)
    // {
    //     cout<<head->data<<" ";
    //     head=head->rchild;
    // }
    // BTree T1,T2;
    // createTree(T1);
    // createTree(T2);
    // cout<<isSimilar(T,T2);
    // 16
    // getlevel(T,6);
    // 17
    // getleafWeight(T);
    // cout<<leaf_weight;
    // 18
    BTreeToExp(T,1);
}