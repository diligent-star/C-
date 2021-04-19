#pragma once

#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int
		SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode *next;
}SListNode;


//头插，尾插
void SListPushFront(SListNode **pplist, SListDataType x);
void SListPushBack(SListNode **pplist,SListDataType x);
//头删，尾删
void SListPopFront(SListNode **pplist);
void SListPopBack(SListNode **pplist);
//查找返回地址
SListNode* SListFind(SListNode *plist, SListDataType x);
//后插入
void SListInsertAfter(SListNode* pos, SListDataType x);
//后删除
void SListEraseAfter(SListNode *pos);
//销毁链表
void SListDestory(SListNode *plist);
//简单的链表打印
void SListPrint(SListNode *plist);
