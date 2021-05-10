#include "Stack.h"

void 
StackInit(Stack *pst)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
	assert(pst != NULL);
	pst->head = (STDataType*)malloc(4 * sizeof(STDataType));
	pst->capacity = 4;
	pst->top = 0;
}

void
StackDestory(Stack *pst)
{
	assert(pst != NULL);
	pst->capacity = 0;
	pst->top = 0;
	free(pst->head);
	pst->head = NULL;
}

void 
StackPush(Stack *pst, STDataType data)
{
	assert(pst != NULL);
	//�ж��Ƿ�ջ����
	if (pst->capacity == pst->top)
	{
		STDataType *tmp = 
	    (STDataType*)realloc(pst->head, 2 * (pst->capacity) * sizeof(STDataType));
		if (NULL == tmp)//����ʧ��
		{
			StackDestory(pst);
			printf("Realloc Fail!!!\n");
			exit(EXIT_FAILURE);
		}
		//���ݳɹ�
		pst->head = tmp;
		pst->capacity *= 2;
	}
	//��ջ
	pst->head[pst->top] = data;
	pst->top++;
}

void
StackPop(Stack *pst)
{
	assert(pst != NULL);
	assert(!StackEmpty(pst));
	pst->top--;
}

STDataType
StackTop(Stack *pst)
{
	assert(pst != NULL);
	assert(!StackEmpty(pst));
	return pst->head[pst->top - 1];
}


bool
StackEmpty(Stack *pst)
{
	assert(pst != NULL);
	return (0 == pst->top);
}

int
StackSize(Stack *pst)
{
	assert(pst != NULL);
	return pst->top;
}



