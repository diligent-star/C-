#include "dynamic_contcat.h"

void 
test(void)
{
	Contact s;
	InitContact(&s);
	AddContact(&s);
	PrintContact(&s);
	AddContact(&s);
	PrintContact(&s);
}

void 
test1(void)
{
	Contact s;
	InitContact(&s);
	AddContact(&s);
	char name[NAME_MAX];
	scanf("%s", name);
	int check = CheckContact(&s, name);
	if (check == -1)//�Ҳ�������-1
	{
		printf("�Ҳ���������\n");
	}
	else
	{
		printf("�ҵ��ˣ�����\n");
	}
}

void test2(void)
{
	Contact s;
	InitContact(&s);
	AddContact(&s);
	AddContact(&s);
	AddContact(&s);
	AddContact(&s);
	AddContact(&s);
	AddContact(&s);
	AddContact(&s);
	PrintContact(&s);
}

int
main()
{
	test2();
	return 0;
}