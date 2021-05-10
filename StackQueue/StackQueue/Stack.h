#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int
		STDataType;

struct Stack
{
	STDataType *head;
	int top;//ջ��
	int capacity;//����
};
typedef struct Stack	
		Stack;

//��ʼ��ջ
void StackInit(Stack *pst);
//����ջ
void StackDestory(Stack *pst);
//��ջ
void StackPush(Stack *pst, STDataType data);
//��ջ
void StackPop(Stack *pst);
//��ȡջ������
STDataType StackTop(Stack *pst);
//�жϿ�
bool StackEmpty(Stack *pst);
//ջ�Ĵ�С
int StackSize(Stack *pst);




/*
**			// ֧�ֶ�̬������ջ
**		typedef int STDataType;
**		typedef struct Stack
**		{
**			STDataType* _a;
**			int _top;		// ջ��
**			int _capacity;  // ���� 
**		}Stack;
**		// ��ʼ��ջ 
**		void StackInit(Stack* ps); 
**		// ��ջ 
**		void StackPush(Stack* ps, STDataType data); 
**		// ��ջ 
**		void StackPop(Stack* ps); 
**		// ��ȡջ��Ԫ�� 
**		STDataType StackTop(Stack* ps); 
**		// ��ȡջ����ЧԪ�ظ��� 
**		int StackSize(Stack* ps); 
**		// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
**		int StackEmpty(Stack* ps); 
**		// ����ջ 
**		void StackDestroy(Stack* ps); 
*/