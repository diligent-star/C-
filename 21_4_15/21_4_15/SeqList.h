#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SeqDataType;//�л��洢����

typedef struct SeqList
{
	SeqDataType *a;//��̬���ٿռ�
	int size;
	int capacity;
}SeqList;

//��ʼ��,����
void SeqListInit(SeqList *seq);
void SeqListDestory(SeqList *seq);
//β��,βɾ
void SeqListPushBack(SeqList *seq, SeqDataType x);
void SeqListPopBack(SeqList *seq);
//ͷ�壬ͷɾ
void SeqListPushFront(SeqList *seq, SeqDataType x);
void SeqListPopFront(SeqList *seq);
//����
int SeqListFind(SeqList *seq, SeqDataType find_num);
//����λ�ò���
void SeqListInsert(SeqList *seq, int pos, SeqDataType x);
//����λ�õ�ɾ��
void SeqListErase(SeqList *seq, int pos);
//�޸�
void SeqListModify(SeqList *seq, int pos, SeqDataType x);
//�򵥴�ӡint˳���
void SeqListPrint(SeqList *seq);