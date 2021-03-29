#include "contact.h"

void 
InitContact(struct Contact *p)
{
	p->sz = 0;
	memset(p->data, 0, sizeof(p->data));
}

void
AddContact(struct Contact *p)
{
	if (DATA_MAX == p->sz)
	{
		printf("通讯录已满！！！\n");
	}
	else
	{
		printf("请输入姓名>:");
		scanf("%s",p->data[p->sz].name);
		printf("请输入年龄>:");
		scanf("%d",&(p->data[p->sz].age));
		printf("请输入性别>:");
		scanf("%s", p->data[p->sz].sex);
		printf("请输入电话>:");
		scanf("%s", p->data[p->sz].tele);
		printf("请输入地址>:");
		scanf("%s", p->data[p->sz].addr);
		p->sz++;
	}
}

void
ShowContact(const struct Contact *p)
{
	int i = 0;
	printf("%-10s\t%-3s\t%-3s\t%-13s\t%-20s\n",
		"姓名","年龄","性别","电话","地址");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-10s\t%-3d\t%-3s\t%-13s\t%-20s\n",
			p->data[i].name,
			p->data[i].age, 
			p->data[i].sex, 
			p->data[i].tele,
			p->data[i].addr);
	}
	if (0 == p->sz)
	{
		printf("通讯录无信息!!!\n");
	}
}

int
SearchContact(const struct Contact *p, char *search_name)
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (0 == strcmp(p->data[i].name, search_name))
		{
			return i;
		}
	}
	//找不到
	return -1;
}


int
DelContact(struct Contact *p, char *del_name)
{
	int ret = SearchContact(p, del_name);
	if (-1 == ret)
	{
		return -1;
	}
	else if (1 == p->sz && ret != -1)
	{
		InitContact(p);
		return 1;
	}
	else
	{
		int i = 0;
		for (i = ret; i < p->sz-1; i++)
		{
			p->data[i] = p->data[i + 1];
		}
		p->sz--;
		return 1;
	}
}

int
ModifyContact(struct Contact *p, char *modify_name)
{
	int ret = SearchContact(p, modify_name);
	if (-1 == ret)
	{
		return -1;
	}
	else
	{
		printf("请输入姓名>:");
		scanf("%s", p->data[ret].name);
		printf("请输入年龄>:");
		scanf("%d", &(p->data[ret].age));
		printf("请输入性别>:");
		scanf("%s", p->data[ret].sex);
		printf("请输入电话>:");
		scanf("%s", p->data[ret].tele);
		printf("请输入地址>:");
		scanf("%s", p->data[ret].addr);
		return 1;
	}
}

static void
ChoiceMune(void)
{
	printf("*****************\n");
	printf("***  1.name  ****\n");
	printf("***  2.age   ****\n");
	printf("***  3.tele  ***\n");
	printf("***  0.eixt  ***\n");
	printf("*****************\n");
}

static int
compare_by_stu_name(const void *x, const void *y)
{
	return strcmp(((struct PeoInfo*)x)->name, ((struct PeoInfo*)y)->name);
}

static int
compare_by_stu_tele(const void *x, const void *y)
{
	return strcmp(((struct PeoInfo*)x)->tele, ((struct PeoInfo*)y)->tele);
}

static int
compare_by_stu_age(const void *x, const void *y)
{
	return ((struct PeoInfo*)x)->age - ((struct PeoInfo*)y)->age;
}


void
SortContact(struct Contact *p)
{
	enum choice
	{
		EIXT,
		NAME,
		AGE,
		TELE,
	};
	int input = 0;
	ChoiceMune();
	printf("请选择排序种类>:");
	scanf("%d", &input);
	switch (input)
	{
	case NAME:
		qsort(p->data, p->sz, sizeof(p->data[0]), compare_by_stu_name);
		break;
	case AGE:
		qsort(p->data, p->sz, sizeof(p->data[0]), compare_by_stu_age);
		break;
	case TELE:
		qsort(p->data, p->sz, sizeof(p->data[0]), compare_by_stu_tele);
		break;
	case EIXT:
		printf("退出排序！！！\n");
		break;
	default:
		printf("无效选项！！！\n");
		break;
	}
	if (input != 0)
	{
		printf("完成排序！！！\n");
	}
}
