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

int main()
{
	int choice = 0;
	int input1 = 0;//������
	int input2 = 0;//������
	int(*fp[5])(int, int) = {0,Add,Sub,Mul,Div};//���ܱ���

	do
	{
		Menu();
		printf("��ѡ����Ҫʵ�ֵĹ���:>");
		scanf("%d", &choice);
		if (choice >=1 && choice <= 4)
		{
			printf("��ѡ������2��������:>");
			scanf("%d %d", &input1, &input2);
			printf("%d\n",fp[choice](input1,input2));
		}
		else if (choice == 0)
		{
			;
		}
		else
		{
			printf("�������,����������\n");
		}
	} while (choice);
	return 0;
}