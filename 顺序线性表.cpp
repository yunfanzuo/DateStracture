#include <cstdio>
#include <iostream>
using namespace std;

#define InitialSize 100
#define ElemType int

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
    free(tmp);
}

bool ListInsert(SeqList &L, int i, ElemType e) {
    if(i < 1 || i > L.length + 1) {
        return false;
    }
    if(L.length >= L.MaxSize) {
        return false;
    }
    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length + 1) {
        return false;
    }
    e = L.data[i-1];
    for(int j = i; j < L.length; j++) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

ElemType LocateElem(SeqList &L, ElemType e) {
    for(int i = 0; i < L.length; i++) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SeqList L;
    InitialList(L);
    ListInsert(L, 1, 1);
    ListInsert(L, 2, 2);
    ListInsert(L, 3, 3);
    ListInsert(L, 4, 4);
    ListInsert(L, 5, 5);
    int t = 0;
    ListDelete(L, 3, t);
    LocateElem(L, 4);
    return 0;
}













