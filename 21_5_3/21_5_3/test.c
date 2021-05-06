#include "List.h"

void test1()
{
	ListNode *head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);
	ListPopBack(head);
	ListPopBack(head);
	ListPopBack(head);
	ListPopFront(head);
	//ListPopBack(head);
	ListPrint(head);
	ListDestory(&head);
}

void test2()
{
	ListNode *head = ListCreate();
	//ListPushFront(head, 1);
	//ListPushFront(head, 2);
	//ListPushFront(head, 3);
	//ListPushFront(head, 4);
	//ListPushFront(head, 5);
	//ListPushFront(head, 6);
	//ListPrint(head);
	//ListPopFront(head);
	//ListPopFront(head);
	//ListPopFront(head);
	//ListPopFront(head);
	//ListPopFront(head);
	//ListPrint(head);
	ListPushBack(head,2);
	ListPushFront(head, 1);
	ListPushBack(head, 3);
	ListPushFront(head, 0);
	ListPrint(head);
	ListPopBack(head);
	ListPrint(head);

	ListPopFront(head);
	ListPrint(head);

	ListPopBack(head);
	ListPrint(head);

	ListPopFront(head);
	ListPrint(head);

	ListDestory(&head);
}

void test3()
{
	ListNode *head = ListCreate();
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPrint(head);
	ListNode *check = ListFind(head,6);
	if (check != NULL)
	{
		printf("找到了 %d\n ",check->data);
	}
	else
	{
		printf("找不到\n");
	}
	ListPrint(head);
	ListDestory(&head);
}

void test4()
{
	ListNode *head = ListCreate();
	ListPushBack(head, 2);
	ListPushFront(head, 0);
	ListPrint(head);
	ListNode *check = ListFind(head, 2);
	if (check != NULL)
	{
		ListInsert(check, 1);
	}
	else
	{
		printf("找不到！\n");
	}
	ListPrint(head);
	ListDestory(&head);
}

int main()
{
	test1();
	return 0;
}