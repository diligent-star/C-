#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QDataType;
struct QListNode
{
	struct QListNode *next;
	QDataType data;
};
typedef struct QListNode
		QListNode;

//��β�����ݣ���ͷ������
struct Queue
{
	QListNode *front;//��ͷ
	QListNode *tail;//��β
};
typedef struct Queue
		Queue;

//��ʼ������
void QueueInit(Queue *q);
//���ٶ���
void QueueDestroy(Queue *q);
//�����
void QueuePush(Queue *q, QDataType data);
//������
void QueuePop(Queue *q);
//��ȡ��ͷ����
QDataType QueueFront(Queue *q); 
//��ȡ��β����
QDataType QueueBack(Queue *q);
//��ȡ����Ч���ݸ���
int QueueSize(Queue *q);
//�������Ƿ�β��
bool QueueEmpty(Queue *q);

/*
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
*/