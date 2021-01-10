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

int main()
{
	int choice = 0;
	int input1 = 0;//操作数
	int input2 = 0;//操作数
	int(*fp[5])(int, int) = {0,Add,Sub,Mul,Div};//功能表列

	do
	{
		Menu();
		printf("请选择您要实现的功能:>");
		scanf("%d", &choice);
		if (choice >=1 && choice <= 4)
		{
			printf("请选择您的2个操作数:>");
			scanf("%d %d", &input1, &input2);
			printf("%d\n",fp[choice](input1,input2));
		}
		else if (choice == 0)
		{
			;
		}
		else
		{
			printf("输入错误,请重新输入\n");
		}
	} while (choice);
	return 0;
}