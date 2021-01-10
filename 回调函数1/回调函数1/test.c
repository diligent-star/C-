#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int Add(int x, int y){
	//�ӷ�����
	return x + y;
}//Add

int Sub(int x, int y){
	//��������
	return x - y;
}//Sub

int Mul(int x, int y){
	//�˷�����
	return x * y;
}//Mul

int Div(int x, int y){
	//��������
	return x / y;
}//Div

void Menu(){
	//��ӡ�˵� 1.Add 2.Sub 3.Mul 4.Div 0.Exit
	printf("**********************\n");
	printf("***  1.Add  2.Sub  ***\n");
	printf("***  3.Mul  4.Div  ***\n");
	printf("***  0.Exit        ***\n");
	printf("**********************\n");
}//Menu

void Calc(int (*fp)(int, int)){
//��������ĺ���ָ�������Ӧ��ֵ
	int x = 0;
	int y = 0;
	printf("��������������������:>");
	scanf("%d %d",&x,&y);
	printf("%d\n",fp(x,y));
}//Calc

int main()
{
	int choice = 0;
	do
	{
		Menu();
		printf("��ѡ����Ҫʵ�ֵĹ���:>");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			printf("�˳�\n");
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
			printf("�����������������\n");
			break;
		}
	} while (choice);
	return 0;
}