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

//队尾入数据，队头出数据
struct Queue
{
	QListNode *front;//队头
	QListNode *tail;//队尾
};
typedef struct Queue
		Queue;

//初始化队列
void QueueInit(Queue *q);
//销毁队列
void QueueDestroy(Queue *q);
//入队列
void QueuePush(Queue *q, QDataType data);
//出队列
void QueuePop(Queue *q);
//获取队头数据
QDataType QueueFront(Queue *q); 
//获取队尾数据
QDataType QueueBack(Queue *q);
//获取队有效数据个数
int QueueSize(Queue *q);
//检查队列是否尾空
bool QueueEmpty(Queue *q);

/*
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);
*/