#include "SeqList.h"

void
test1(void)
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushFront(&s, 4);
	SeqListPushFront(&s, 5);
	SeqListPushFront(&s, 6);
	SeqListPushBack(&s, 7);

	SeqListPrint(&s);
	SeqListDestory(&s);//销毁顺序表
}

//测试头删
void
test2(void)
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	SeqListDestory(&s);//销毁顺序表
}

//测试尾删
void
test3(void)
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	SeqListDestory(&s);//销毁顺序表
}

//测试不定位置插入
void
test4(void)
{
	SeqList s;
	SeqListInit(&s);
	SeqListInsert(&s, 0, 1);
	SeqListInsert(&s, 0, 2);
	SeqListInsert(&s, 2, 66);
	SeqListPrint(&s);
	SeqListDestory(&s);//销毁顺序表
}

//测试不定位置删除
void
test5(void)
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushFront(&s,1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);
	SeqListErase(&s,0);
	SeqListPrint(&s);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	SeqListErase(&s, 1);
	SeqListPrint(&s);
	SeqListErase(&s, 0);
	SeqListPrint(&s);
}

int
main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}
