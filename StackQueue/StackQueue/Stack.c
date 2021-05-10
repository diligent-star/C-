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
	//判断是否栈满了
	if (pst->capacity == pst->top)
	{
		STDataType *tmp = 
	    (STDataType*)realloc(pst->head, 2 * (pst->capacity) * sizeof(STDataType));
		if (NULL == tmp)//增容失败
		{
			StackDestory(pst);
			printf("Realloc Fail!!!\n");
			exit(EXIT_FAILURE);
		}
		//增容成功
		pst->head = tmp;
		pst->capacity *= 2;
	}
	//入栈
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



