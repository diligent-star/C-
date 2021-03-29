#include "contact.h"

void
menu(void)
{
	printf("******************************\n");
	printf("****        ͨѶ¼        ****\n");
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
		printf("��ѡ�����>:");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			printf("������Ҫɾ��������>:");
			scanf("%s",del_name);
			ret = DelContact(&con, del_name);
			if (-1 == ret)
			{
				printf("ɾ��ʧ�ܣ�����\n");
			}
			else
			{
				printf("ɾ���ɹ�������\n");
			}
			break;
		case SEARCH:
			printf("������Ҫ�����˵�����>:");
			scanf("%s", search_name);
			ret = SearchContact(&con, search_name);
			if (-1 == ret)
			{
				printf("�Ҳ���������\n");
			}
			else
			{
				printf("%-10s\t%-3s\t%-3s\t%-13s\t%-20s\n",
					"����", "����", "�Ա�", "�绰", "��ַ");
				printf("%-10s\t%-3d\t%-3s\t%-13s\t%-20s\n",
					con.data[ret].name,
					con.data[ret].age,
					con.data[ret].sex,
					con.data[ret].tele,
					con.data[ret].addr);
			}
			break;
		case MODIFY:
			printf("������Ҫ�޸��������>:");
			scanf("%s",modify_name);
			ret = ModifyContact(&con, modify_name);
			if (-1 == ret)
			{
				printf("�޸�ʧ�ܣ�����\n");
			}
			else
			{
				printf("�޸óɹ�������\n");
			}
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("�˳�ͨѶ¼������\n");
			break;
		default:
			printf("�޸�ѡ�����\n");
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