#include "Queue.h"

void
QueueInit(Queue *q)
{
	assert(q != NULL);
	q->front = NULL;
	q->tail = NULL;
}

void
QueueDestroy(Queue *q)
{
	assert(q != NULL);
	QListNode * del = q->front;
	while (del != NULL)
	{
		QListNode *next = del->next;
		free(del);
		del = next;
	}
}

void
QueuePush(Queue *q, QDataType data)
{
	assert(q != NULL);
	QListNode *newnode = (QListNode*)malloc(sizeof(QListNode));
	if (NULL == newnode)
	{
		printf("Malloc Fail！！！\n");
		exit(EXIT_FAILURE);
	}
	newnode->next = NULL;
	newnode->data = data;
	if (NULL == q->front)//第一个
	{
		q->front = newnode;
		q->tail = newnode;
	}
	else//多个
	{
		QListNode *tail = q->tail;
		tail->next = newnode;//链接
		tail = tail->next;
		q->tail = tail;
	}
}

void
QueuePop(Queue *q)
{
	assert(q != NULL);
	assert(!QueueEmpty(q));
	QListNode *del = q->front;
	q->front = q->front->next;
	free(del);
	del = NULL;
	if (NULL == q->front)
	{
		q->tail = NULL;
	}
}

QDataType
QueueFront(Queue *q)
{
	assert(q != NULL);
	assert(!QueueEmpty(q));
	return q->front->data;
}

QDataType 
QueueBack(Queue *q)
{
	assert(q != NULL);
	assert(!QueueEmpty(q));
	return q->tail->data;
}

int
QueueSize(Queue *q)
{
	assert(q != NULL);
	int count = 0;
	QListNode *cur = q->front;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

bool
QueueEmpty(Queue *q)
{
	assert(q != NULL);
	return (NULL == q->front);
}