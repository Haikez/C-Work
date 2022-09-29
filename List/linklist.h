#include <iostream>
using namespace std;
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

void createList_Head(LinkList &L, int nums[], int len)
{
    L = new LNode;
    L->next = NULL;
    LNode *node;
    for (int i = 0; i < len; i++)
    {
        node = new LNode;
        node->data = nums[i];
        node->next = L->next;
        L->next = node;
    }
}
void createList_Tail(LinkList &L, int nums[], int len)
{
    L = new LNode;
    L->next = NULL;
    LNode *node, *s = L;
    for (int i = 0; i < len; i++)
    {
        node = new LNode;
        node->data = nums[i];
        s->next = node;
        s = node;
    }
}
void printList(LinkList L){
    LNode *p = L->next;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}