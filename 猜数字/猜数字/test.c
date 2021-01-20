#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void Menu(){
	//��������Ϸ�˵�
	printf("*******************************\n");
	printf("*** Welcome To Guess Number ***\n");
	printf("*******************************\n");
	printf("****** 1. play   0. exit ******\n");
	printf("*******************************\n");
}//Menu


void Print_Range(int correct_answer, int guess_answer){
	//�ж���Ϸ���ȣ���ӡ�����ֵķ�Χ
	static int memory_small = 0;
	static int memory_big = 100;

	if (guess_answer > correct_answer)
	{
		printf("����\n");
		memory_big = guess_answer - 1;
		printf("%d - %d\n", memory_small, memory_big);
	}
	else if (guess_answer < correct_answer)
	{
		printf("С��\n");
		memory_small = guess_answer + 1;
		printf("%d - %d\n", memory_small, memory_big);
	}
	else
	{
		printf("��ϲ�㣡�¶��ˣ�\n");
		Sleep(3500);
		system("cls");

		//��Ϸδ�رգ�Ϊ�����Ϸ,��ʼ��
		memory_small = 0;
		memory_big = 100;
	}

}//Print_Range


void Guess_Game(){
	//��������Ϸ�� ��0 �� 100 �����в£�ֱ������Ϊֹ

	int guess_answer = 0;
	int correct_answer = 0;

	//1. �γ������ ���� 0 �� 100
	correct_answer = rand() % 101;

	//2.������
	do
	{
		printf("�����������µ�����:>");
		scanf("%d", &guess_answer);
		system("cls");
		Print_Range(correct_answer, guess_answer);
	} while (guess_answer != correct_answer);

}//Guess_game


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		Menu();
		printf("������ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("��Ϸ��ʼ��\n������0 - 100������0 �� 100��\n");
			Guess_Game();
			break;
		case 0:
			break;
		default:
			printf("����������������룡����\n");
			Sleep(3500);
			system("cls");
			Sleep(1000);
			break;
		}

	} while (input);

	return 0;
}