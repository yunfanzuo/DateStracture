#include <iostream>
using namespace std;

#define ElemType int
#define MaxSize 100

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q) {
    if(Q.rear == Q.front) {
        return true;
    }
    else return false;
}

bool isFull(SqQueue Q) {
    if((Q.rear + 1) % MaxSize == Q.front) {
        return true;
    }
    else return false;
}

//循环存储
bool EnQueue(SqQueue &Q, ElemType x) {
    if(isFull(Q)) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if(isEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

int main()
{
    SqQueue Q;
    int x;
    InitQueue(Q);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    DeQueue(Q, x);
    cout << x << endl;
    DeQueue(Q, x);
    cout << x << endl;
    return 0;
}