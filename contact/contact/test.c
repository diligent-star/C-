#include "contact.h"

void
menu(void)
{
	printf("******************************\n");
	printf("****        通讯录        ****\n");
	printf("******************************\n");
	printf("****  1.Add      2.Del    ****\n");
	printf("****  3.Search   4.Modify ****\n");
	printf("****  5.show     6.Sort   ****\n");
	printf("****  0.Exit              ****\n");
	printf("******************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void
test(void)
{
	char search_name[NAME_MAX];
	char del_name[NAME_MAX];
	char modify_name[NAME_MAX];
	int ret = 0;
	struct Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择操作>:");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			printf("请输入要删除的姓名>:");
			scanf("%s",del_name);
			ret = DelContact(&con, del_name);
			if (-1 == ret)
			{
				printf("删除失败！！！\n");
			}
			else
			{
				printf("删除成功！！！\n");
			}
			break;
		case SEARCH:
			printf("请输入要查找人的姓名>:");
			scanf("%s", search_name);
			ret = SearchContact(&con, search_name);
			if (-1 == ret)
			{
				printf("找不到！！！\n");
			}
			else
			{
				printf("%-10s\t%-3s\t%-3s\t%-13s\t%-20s\n",
					"姓名", "年龄", "性别", "电话", "地址");
				printf("%-10s\t%-3d\t%-3s\t%-13s\t%-20s\n",
					con.data[ret].name,
					con.data[ret].age,
					con.data[ret].sex,
					con.data[ret].tele,
					con.data[ret].addr);
			}
			break;
		case MODIFY:
			printf("请输入要修改项的姓名>:");
			scanf("%s",modify_name);
			ret = ModifyContact(&con, modify_name);
			if (-1 == ret)
			{
				printf("修该失败！！！\n");
			}
			else
			{
				printf("修该成功！！！\n");
			}
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("退出通讯录！！！\n");
			break;
		default:
			printf("无该选项！！！\n");
			break;
		}
	} while (input);
}

int
main()
{
	test();
	return 0;
}