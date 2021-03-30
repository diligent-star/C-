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

//β��
void SeqListPushBack(SeqList *seq, SLDataType x);
//ͷ��
void SeqListPushFront(SeqList *seq, SLDataType x);
//βɾ
void SeqListPopBack(SeqList *seq);
//ͷɾ
void SeqListPopFront(SeqList *seq);
//��ʼ��
void SeqListInit(SeqList *seq);
//����
void SeqListDestory(SeqList *seq);
//��ӡ
void SeqListPrint(const SeqList *seq);