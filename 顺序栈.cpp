#include <iostream>
#include <cstdio>
using namespace std;

#define MaxSize 50
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化
void InitStack(SqStack &s) {
    s.top = -1;
}

//判栈空
bool StackEmpty(SqStack s) {
    if(s.top == -1) {
        return true;
    }
    else return false;
}

//进栈
bool Push(SqStack &s, ElemType x) {
    if(s.top == MaxSize - 1) {
        return false;
    }
    else {
        s.data[++s.top] = x;
        return true;
    }
}

//出栈
bool Pop(SqStack &s) {
    if(s.top == -1) {
        return false;
    }
    else {
        s.top--;
        return true;
    }
}

//取栈顶
bool GetTop(SqStack s, ElemType &x) {
    if(s.top == -1) {
        return false;
    }
    else {
        x = s.data[s.top];
        return true;
    }
}

void DestroyStack(SqStack &s) {
    s.top = -1;
}

int main()
{
    SqStack s;
    InitStack(s);
    Push(s, 6);
    Push(s, 7);
    

    return 0;
}