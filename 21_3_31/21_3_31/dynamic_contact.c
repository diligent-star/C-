#include "dynamic_contcat.h"

void
InitContact(Contact *s)
{
	assert(s != NULL);
	s->sz = 0;
	PeoInfo *check = (PeoInfo*)malloc(sizeof(PeoInfo) * INIT_NUM);
	if (check == NULL)
	{
		printf("初始化内存错误！！！\n");
		exit(1);
	}
	else
	{
		s->message = check;
		s->capacity = 4;
		return;
	}
}

void//添加基本信息
AddInfo(Contact *s)
{
	printf("请输入要添加的姓名>:");
	scanf("%s", s->message[s->sz].name);
	printf("请输入要添加的电话>:");
	scanf("%s", s->message[s->sz].tele);
	printf("请输入要添加的年龄>:");
	scanf("%d", &(s->message[s->sz].age));
	s->sz++;
}

void IsFull(Contact *s)//处理扩容
{
	if (s->sz == s->capacity)
	{
		PeoInfo *check = (PeoInfo*)realloc(s->message, sizeof(PeoInfo)*2*(s->capacity));
		if (check == NULL)
		{
			printf("扩容失败！！！\n");
			exit(1);
		}
		else
		{
			s->message = check;
			s->capacity *= 2;
		}
	}
}

void
AddContact(Contact *s)
{
	IsFull(s);
	AddInfo(s);
}

void
PrintContact(Contact *s)
{
	int i = 0;
	for (i = 0; i < s->sz; i++)
	{
		printf("%s %s %d\n", 
			s->message[i].name,
			s->message[i].tele, 
			s->message[i].age);
	}
}

int//通过名字查找内容，返回下标，找不到返回-1
CheckContact(Contact *s, char *name)
{
	int i = 0;
	for (i = 0; i < s->sz; i++)
	{
		if (0 == strcmp(name, s->message[i].name))
		{
			return i;
		}
	}
	//找不到
	return -1;
}

void
DeletContact(Contact *s)
{
	char name[NAME_MAX];
	printf("请输入要删除人的姓名:>");
	scanf("%s", name);
	int check = CheckContact(s, name);
	if (-1 == check)//找不到
	{
		printf("无删除内容！！！\n");
	}
	else if (1 == check)
	{

	}
	else//移动覆盖删除
	{
		int i = 0;
		for (i = check; i < s->sz; i++)
		{
			s->message[i] = s->message[i + 1];
		}
	}
}
