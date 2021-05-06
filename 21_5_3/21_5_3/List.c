#include "List.h"

ListNode*
BuyNode(int x)
{
	ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->data = x;
	return new_node;
}

ListNode*
ListCreate(void)
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->prev = head;
	head->next = head;
	return head;
}

void
ListDestory(ListNode** ppHead)
{
	assert(ppHead != NULL);
	assert(*ppHead != NULL);
	ListNode *del = (*ppHead)->next;
	while (del != *ppHead)
	{
		ListNode *next = del->next;
		free(del);
		del = next;
	}
	free(*ppHead);
	*ppHead = NULL;
}

void
ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	//ListNode *new_node = BuyNode(x);
	//ListNode *tail = pHead->prev;
	//tail->next = new_node;
	//new_node->prev = tail;
	//new_node->next = pHead;
	//pHead->prev = new_node;
	ListInsert(pHead, x);
}

void
ListPrint(ListNode* pHead)
{
	ListNode *p = pHead->next;
	while (p != pHead)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void
ListPopBack(ListNode* pHead)
{
	//assert(pHead != NULL);
	//ListNode *tail = pHead->prev;
	//ListNode *prev = tail->prev;
	//prev->next = pHead;
	//pHead->prev = prev;
	//free(tail);
	//tail = NULL;
	ListErase(pHead->prev);
}

void
ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	//ListNode *new_node = BuyNode(x);
	//ListNode *head = pHead->next;
	//pHead->next = new_node;
	//new_node->prev = pHead;
	//new_node->next = head;
	//head->prev = new_node;
	ListInsert(pHead->next, x);
}

void
ListPopFront(ListNode* pHead)
{
	//assert(pHead != NULL);
	//assert(pHead->next != pHead);
	//ListNode *del = pHead->next;
	//ListNode *next = del->next;
	//pHead->next = next;
	//next->prev = pHead;
	//free(del);
	//del = NULL;
	ListErase(pHead->next);
}

ListNode* 
ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead != NULL);
	assert(pHead->next != pHead);
	ListNode *check = pHead->next;
	while (check != pHead)
	{
		if (check->data != x)
		{
			check = check->next;
		}
		else
		{
			return check;
		}
	}
	return NULL;
}

void
ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos != NULL);
	ListNode *cur = BuyNode(x);
	ListNode *prev = pos->prev;
	prev->next = cur;
	cur->prev = prev;
	cur->next = pos;
	pos->prev = cur;
}

void
ListErase(ListNode* pos)
{
	assert(pos != NULL);
	assert(pos->next != pos);
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}




