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


//ͷ�壬β��
void SListPushFront(SListNode **pplist, SListDataType x);
void SListPushBack(SListNode **pplist,SListDataType x);
//ͷɾ��βɾ
void SListPopFront(SListNode **pplist);
void SListPopBack(SListNode **pplist);
//���ҷ��ص�ַ
SListNode* SListFind(SListNode *plist, SListDataType x);
//�����
void SListInsertAfter(SListNode* pos, SListDataType x);
//��ɾ��
void SListEraseAfter(SListNode *pos);
//��������
void SListDestory(SListNode *plist);
//�򵥵������ӡ
void SListPrint(SListNode *plist);
