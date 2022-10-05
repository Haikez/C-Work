#include <iostream>
#include "linklist.h"
using namespace std;

// 1.递归删除所有值为x的结点
void delete_x(LinkList &L, int x)
{
    if (!L)
        return;
    if (L->data == x)
    {
        LNode *p = L;
        L = L->next;
        free(p);
        delete_x(L, x);
    }
    else
    {
        delete_x(L->next, x);
    }
}
// 5.就地逆置,空间复杂度O(1)
void reserveList(LinkList &L)
{
    LNode *p = L->next, *cur, *pre = NULL;
    while (p)
    {
        cur = p;
        p = cur->next;
        cur->next = pre;
        pre = cur;
    }
    L->next = cur;
}
// 6.使带头结点的单链表L递增有序（链表的插入排序）
void sortList(LinkList &L)
{
    LNode *pre, *p, *r;
    p = L->next;
    r = p->next;
    p->next = NULL;
    p = r;
    while (p)
    {
        pre = L;
        r = p->next;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r;
    }
}
// 7.删除表中所有值介于给定两个值之间的元素
void deleteAtoB(LinkList &L, int A, int B)
{
    LNode *p = L->next;
    LNode *pre = L;
    while (p)
    {
        if (p->data >= A && p->data <= B)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
// 8.给定两个单链表，编写算法找出两个链表的公共结点
LNode *searchCommon(LinkList L, LinkList L1)
{
    if(!L||!L1) return L?L:L1;
    LNode *La=L;
    LNode *Lb=L1;
    while (La!=Lb)
    {
        La=La?La->next:L1;
        Lb=Lb?Lb->next:L;
    }
    if (La)
        cout<<La->data;
    else cout<<"无公共结点";
    return La;
}
// 10 将一个单链表拆成一奇一偶链表
LinkList DisCreate(LinkList &A)
{
    LinkList B = new LNode;
    LNode *p = A->next;
    LNode *a = A;
    LNode *b = B;
    a->next = NULL;
    b->next = NULL;
    while (p)
    {
        if (p->data % 2)
        {
            a->next = p;
            a = a->next;
            p = p->next;
            a->next = NULL;
        }
        else
        {
            b->next = p;
            b = b->next;
            p = p->next;
            b->next = NULL;
        }
    }
    return B;
}
// 11
LinkList DisCreate2(LinkList &A)
{
    LinkList B = new LNode;
    LNode *p = A->next, *r;
    LNode *a = A;
    A->next = NULL;
    B->next = NULL;
    while (p)
    {
        a->next = p;
        a=a->next;
        p = p->next;
        if (p)
        {
            r = p;
            p = p->next;
            r->next = B->next;
            B->next = r;
        }
    }
    a->next=NULL;
    return B;
}
int main()
{
    LinkList L, L1;
    int a[] = {1, 9, 3, 3, 6, 5, 3, 5};
    int b[] = {1, 2, 4, 2, 5, 6, 8, 9, 2, 3, 5};
    createList_Tail(L, a, sizeof(a) / sizeof(int));
    createList_Tail(L1, b, sizeof(b) / sizeof(int));
    // 1
    // delete_x(L,3);
    // 5
    // reserveList(L);
    // 6
    // sortList(L);
    // 7
    // deleteAtoB(L,3,5);
    // 8
    LNode *p = L->next->next;
    LNode *q = L1->next->next->next;
    q->next= p;
    searchCommon(L, L1);
    // 10
    // LinkList B = DisCreate(L1);
    // printList(L1);
    // cout<<endl;
    // printList(B);
    // 11
    // LinkList L11,B;
    // int a11[] = {11, 21, 12, 22, 13, 23, 14, 24, 15, 25, 16, 26, 17, 27};
    // createList_Tail(L11, a11, sizeof(a11) / sizeof(int));
    // B = DisCreate2(L11);
    // printList(L11);
    // cout<<endl;
    // printList(B);
    //12
}