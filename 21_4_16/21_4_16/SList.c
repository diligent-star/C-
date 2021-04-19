#include "SList.h"

void
SListPrint(SListNode *plist)
{
	SListNode *cur = plist;
	if (plist == NULL)
	{
		printf("NULL");
	}
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

SListNode*
BuySListNode(SListDataType x)
{
	SListNode *node = (SListNode*)malloc(sizeof(SListNode)*1);
	if (node != NULL)
	{
		node->data = x;
		node->next = NULL;
		return node;
	}
	else//开辟失败
	{
		printf("malloc fail!!!\n");
		exit(EXIT_FAILURE);
	}
}

void
SListPushFront(SListNode **pplist, SListDataType x)
{
	//创建新节点
	SListNode *newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void
SListPushBack(SListNode **pplist, SListDataType x)
{
	//创建新节点
	SListNode *newnode = BuySListNode(x);
	if (*pplist != NULL)
	{
		SListNode *ptail = *pplist;
		//找尾
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//链接
		ptail->next = newnode;
	}
	else
	{
		*pplist = newnode;
	}
}

void 
SListPopFront(SListNode **pplist)
{
	assert(*pplist);
	SListNode *next = (*pplist)->next;
	free(*pplist);
	*pplist = next;
}

void 
SListPopBack(SListNode **pplist)
{
	assert(*pplist != NULL);
	if ((*pplist)->next == NULL)//一个节点
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//多个节点
	{
		SListNode *prev = NULL;
		//找尾
		SListNode *ptail = *pplist;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		free(ptail);
		ptail = NULL;
		prev->next = NULL;
	}
}

SListNode* 
SListFind(SListNode *plist, SListDataType x)
{
	SListNode *cur = plist;
	while (cur != NULL)
	{
		if (plist->data != x)
		{
			plist = plist->next;
		}
		else
		{
			return plist;
		}
	}
	//找不到
	return NULL;
}

void
SListInsertAfter(SListNode* pos, SListDataType x)
{
	assert(pos != NULL);
	SListNode *newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void
SListEraseAfter(SListNode *pos)
{
	assert(pos != NULL);
	assert(pos->next != NULL);
	SListNode *del = pos->next;
	pos->next = del->next;
	free(del);
	del = NULL;
}

void
SListDestory(SListNode *plist)
{
	SListNode *destory = plist;
	while (destory != NULL)
	{
		free(destory);
		destory = plist->next;
		plist = plist->next;
	}
}

