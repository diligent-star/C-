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
	int top;//栈顶
	int capacity;//容量
};
typedef struct Stack	
		Stack;

//初始化栈
void StackInit(Stack *pst);
//销毁栈
void StackDestory(Stack *pst);
//入栈
void StackPush(Stack *pst, STDataType data);
//出栈
void StackPop(Stack *pst);
//获取栈顶数据
STDataType StackTop(Stack *pst);
//判断空
bool StackEmpty(Stack *pst);
//栈的大小
int StackSize(Stack *pst);




/*
**			// 支持动态增长的栈
**		typedef int STDataType;
**		typedef struct Stack
**		{
**			STDataType* _a;
**			int _top;		// 栈顶
**			int _capacity;  // 容量 
**		}Stack;
**		// 初始化栈 
**		void StackInit(Stack* ps); 
**		// 入栈 
**		void StackPush(Stack* ps, STDataType data); 
**		// 出栈 
**		void StackPop(Stack* ps); 
**		// 获取栈顶元素 
**		STDataType StackTop(Stack* ps); 
**		// 获取栈中有效元素个数 
**		int StackSize(Stack* ps); 
**		// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
**		int StackEmpty(Stack* ps); 
**		// 销毁栈 
**		void StackDestroy(Stack* ps); 
*/