#include <iostream>
#include <cstdio>
using namespace std;

#define ElemType int

typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
}LinkNode, *LiStack;

void InitList(LiStack &S) {
    S = NULL;
}

bool StackEmpty(LiStack S) {
    if(S == NULL) {
        return true;
    }
    else return false;
}

void Push(LiStack &S, ElemType x) {
    LiStack tmp = (LiStack)malloc(sizeof(LinkNode));
    tmp -> data = x;
    if(S == NULL) {
        tmp -> next = NULL;
        S = tmp;
    }
    else {
        tmp -> next = S;
        S = tmp;
    }
}

bool Pop(LiStack &S) {
    if(S != NULL) {
        S = S -> next;
        return true;
    }
    else return false;
}

ElemType GetTop(LiStack S) {
    return S -> data;
}

void DestroyStack(LiStack &S) {
    if(S) {
        S = S -> next;
    }
}

int main()
{
    LiStack S;
    InitList(S);
    Push(S, 4);
    Push(S, 5);
    Push(S, 6);
    Pop(S);
    cout << GetTop(S) << endl;

    return 0;
}