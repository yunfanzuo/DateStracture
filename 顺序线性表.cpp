#include <cstdio>
#include <iostream>
using namespace std;

#define InitialSize 100;
#define ElemType int;

typedef struct {
    ElemType *data ;  //动态分配数组的指针
    int MaxSize, length;
} SeqList;

void InitialList(SeqList &L) {
    L.data = (ElemType*)malloc(sizeof(ElemType) * InitialSize);
    L.MaxSize = InitialSize;
    L.length = 0;
}

void IncreaseSize(SeqList &L, int len) {
    ElemType *tmp = L.data;
    L.data = (ElemType*)malloc(sizeof(ElemType) * (L.MaxSize + len));
    L.MaxSize += len;
    for(int i = 0; i < L.length; i++) {
        L.data[i] = tmp[i];
    }
    free(p);
}

bool ListInsert(SeqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length + 1) {
        return false;
    }
    if(L.length >= L.MaxSize) {
        return false;
    }
    for(int j = L.length; j >= i; j--) {
        L.data[i] = L.data[i-1];
    }
    L.data[i] = e;
    L.length++;
    return true;
}

