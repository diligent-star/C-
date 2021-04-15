#define  _CRT_SECURE_NO_WARNINGS 1
#define NAME_MAX 20
#define SEX_NAME 10
#define TELE_MAX 12
#define ADRR_MAX 30
#define DATA_MAX 1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_NAME];
	char tele[TELE_MAX];
	char addr[ADRR_MAX];
};

struct Contact
{
	struct PeoInfo data[DATA_MAX];
	int sz;
};

void InitContact(struct Contact *p);
void AddContact(struct Contact *p);
void ShowContact(const struct Contact *p);
int SearchContact(const struct Contact *p, char *search_name);//ͨ���������ˣ��ҵ������±꣬�Ҳ�������-1
int DelContact(struct Contact *p, char *del_name);//ͨ������ɾ����ɾ���ɹ�����1��ɾ��ʧ�ܷ���-1
int ModifyContact(struct Contact *p, char *modify_name);//ͨ�������޸ã��޸óɹ�����1���޸�ʧ�ܷ���-1
void SortContact(struct Contact *p);