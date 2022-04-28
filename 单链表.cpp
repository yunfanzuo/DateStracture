#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) {
    L = NULL;
    return true;
}

//头插法建表
LinkList List_HeadInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L -> next = NULL;
    LNode *s = NULL;
    cin >> x;
    while(x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        s -> next = L -> next;
        L -> next = s;
        cin >> x;
    }
    return L;
}

//尾插法建表
LinkList List_TailInsert(LinkList &L) {
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L; 
    cin >> x;
    while(x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s -> data = x;
        r -> next = s;
        r = s;
        cin >> x;
    }
    r -> next = NULL;
    return L;
}

//按序号查找结点
LNode* GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L -> next;
    if(i == 0) {
        return L;
    }
    if(i < 1) {
        return NULL;
    }
    while(p && j < i) {
        p = p -> next;
        j++;
    }
    return p; 
}

//按值查找结点
LNode* LocateElem(LinkList L, ElemType e) {
    LNode *p = L -> next;
    while(p != NULL && p -> data != e) {
        p = p -> next;
    }
    return p;
}

//插入结点（后插）
void ListInsert(LinkList &L, int i, LNode *s) {
    LNode *p = GetElem(L, i-1);
    s -> next = p -> next;
    p -> next = s;
}

//删除结点
void ListDelete(LinkList &L, int i) {
    LNode *p = GetElem(L, i-1);
    LNode *q = p -> next;
    p -> next = q -> next;
    free(q);
}

int main()
{
    LinkList L;
    InitList(L);

    return 0;
}