#include "SeqList.h"

void
TestSeqList1()
{
	SeqList list;
	SeqListInit(&list);
	SeqListPushBack(&list, 1);
	SeqListPushBack(&list, 1);
	SeqListPushBack(&list, 1);
	SeqListPushBack(&list, 1);
	SeqListPrint(&list);
	SeqListPushBack(&list, 2);
	SeqListPushBack(&list, 2);
	SeqListPrint(&list);

	SeqListPopFront(&list);
	SeqListPrint(&list);
	SeqListPopBack(&list);
	SeqListPrint(&list);

	SeqListDestory(&list);
}

int 
main()
{
	TestSeqList1();
	return 0;
}