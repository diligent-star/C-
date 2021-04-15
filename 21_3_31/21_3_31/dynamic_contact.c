#include "dynamic_contcat.h"

void
InitContact(Contact *s)
{
	assert(s != NULL);
	s->sz = 0;
	PeoInfo *check = (PeoInfo*)malloc(sizeof(PeoInfo) * INIT_NUM);
	if (check == NULL)
	{
		printf("��ʼ���ڴ���󣡣���\n");
		exit(1);
	}
	else
	{
		s->message = check;
		s->capacity = 4;
		return;
	}
}

void//��ӻ�����Ϣ
AddInfo(Contact *s)
{
	printf("������Ҫ��ӵ�����>:");
	scanf("%s", s->message[s->sz].name);
	printf("������Ҫ��ӵĵ绰>:");
	scanf("%s", s->message[s->sz].tele);
	printf("������Ҫ��ӵ�����>:");
	scanf("%d", &(s->message[s->sz].age));
	s->sz++;
}

void IsFull(Contact *s)//��������
{
	if (s->sz == s->capacity)
	{
		PeoInfo *check = (PeoInfo*)realloc(s->message, sizeof(PeoInfo)*2*(s->capacity));
		if (check == NULL)
		{
			printf("����ʧ�ܣ�����\n");
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

int//ͨ�����ֲ������ݣ������±꣬�Ҳ�������-1
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
	//�Ҳ���
	return -1;
}

void
DeletContact(Contact *s)
{
	char name[NAME_MAX];
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	int check = CheckContact(s, name);
	if (-1 == check)//�Ҳ���
	{
		printf("��ɾ�����ݣ�����\n");
	}
	else if (1 == check)
	{

	}
	else//�ƶ�����ɾ��
	{
		int i = 0;
		for (i = check; i < s->sz; i++)
		{
			s->message[i] = s->message[i + 1];
		}
	}
}
