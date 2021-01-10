#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int Add(int x, int y){
	//加法运算
	return x + y;
}//Add

int Sub(int x, int y){
	//减法运算
	return x - y;
}//Sub

int Mul(int x, int y){
	//乘法运算
	return x * y;
}//Mul

int Div(int x, int y){
	//除法运算
	return x / y;
}//Div

void Menu(){
	//打印菜单 1.Add 2.Sub 3.Mul 4.Div 0.Exit
	printf("**********************\n");
	printf("***  1.Add  2.Sub  ***\n");
	printf("***  3.Mul  4.Div  ***\n");
	printf("***  0.Exit        ***\n");
	printf("**********************\n");
}//Menu

void Calc(int (*fp)(int, int)){
//根据输入的函数指针计算相应的值
	int x = 0;
	int y = 0;
	printf("请输入您的两个操作数:>");
	scanf("%d %d",&x,&y);
	printf("%d\n",fp(x,y));
}//Calc

int main()
{
	int choice = 0;
	do
	{
		Menu();
		printf("请选择您要实现的功能:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("退出\n");
			break;
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (choice);
	return 0;
}