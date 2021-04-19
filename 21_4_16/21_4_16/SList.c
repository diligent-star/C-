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
	else//����ʧ��
	{
		printf("malloc fail!!!\n");
		exit(EXIT_FAILURE);
	}
}

void
SListPushFront(SListNode **pplist, SListDataType x)
{
	//�����½ڵ�
	SListNode *newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

void
SListPushBack(SListNode **pplist, SListDataType x)
{
	//�����½ڵ�
	SListNode *newnode = BuySListNode(x);
	if (*pplist != NULL)
	{
		SListNode *ptail = *pplist;
		//��β
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//����
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
	if ((*pplist)->next == NULL)//һ���ڵ�
	{
		free(*pplist);
		*pplist = NULL;
	}
	else//����ڵ�
	{
		SListNode *prev = NULL;
		//��β
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
	//�Ҳ���
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

