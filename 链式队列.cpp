#include <iostream>
using namespace std;

#define ElemType int

typedef struct LinkNode{
    ElemType data;
    LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    //建立一个头结点，让首尾指针都指向它
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front -> next = NULL;
}

bool isEmpty(LinkQueue Q) {
    if(Q.front == Q.rear) return true;
    else return false;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    //搞一个新结点，装载好要插入的值
    LinkNode *tmp = (LinkNode *)malloc(sizeof(LinkNode));
    tmp -> data = x;
    tmp -> next = NULL;
    //链尾接上并后移尾指针
    Q.rear -> next = tmp;
    Q.rear = tmp;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if(Q.front == Q.rear) return false;

    //这里是为了把值套出来
    LinkNode *tmp = (LinkNode *)malloc(sizeof(LinkNode));
    tmp = Q.front -> next;
    x = tmp -> data;
    
    Q.front -> next = tmp -> next;
    free(tmp);
    return true;
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    int x;
    DeQueue(Q, x);
    cout << x << endl;
    return 0;
}