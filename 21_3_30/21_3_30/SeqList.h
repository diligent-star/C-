#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *arr;
	size_t size;
	size_t capacity;
}SeqList;

//尾插
void SeqListPushBack(SeqList *seq, SLDataType x);
//头插
void SeqListPushFront(SeqList *seq, SLDataType x);
//尾删
void SeqListPopBack(SeqList *seq);
//头删
void SeqListPopFront(SeqList *seq);
//初始化
void SeqListInit(SeqList *seq);
//销毁
void SeqListDestory(SeqList *seq);
//打印
void SeqListPrint(const SeqList *seq);