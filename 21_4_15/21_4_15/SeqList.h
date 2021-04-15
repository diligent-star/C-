#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SeqDataType;//切换存储内容

typedef struct SeqList
{
	SeqDataType *a;//动态开辟空间
	int size;
	int capacity;
}SeqList;

//初始化,销毁
void SeqListInit(SeqList *seq);
void SeqListDestory(SeqList *seq);
//尾插,尾删
void SeqListPushBack(SeqList *seq, SeqDataType x);
void SeqListPopBack(SeqList *seq);
//头插，头删
void SeqListPushFront(SeqList *seq, SeqDataType x);
void SeqListPopFront(SeqList *seq);
//查找
int SeqListFind(SeqList *seq, SeqDataType find_num);
//不定位置插入
void SeqListInsert(SeqList *seq, int pos, SeqDataType x);
//不定位置的删除
void SeqListErase(SeqList *seq, int pos);
//修该
void SeqListModify(SeqList *seq, int pos, SeqDataType x);
//简单打印int顺序表
void SeqListPrint(SeqList *seq);