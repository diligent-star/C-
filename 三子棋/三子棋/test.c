#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()//��Ϸ���̣��㷨ʵ��
{
	char ret = 'C';
	//���������Ϣ
	char board[ROW][COL] = { 0 };//������ȫ��null��Ϊ�ո�
	//��ʼ������ ʹ�����е�Ԫ�ؼ�Ϊ��Ҫ
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	
	//����
	while (1)
	{
		//�������
		Playermove(board,ROW,COL);
		//��ӡ����
		DisplayBoard(board, ROW, COL);
		//�ж����ʤ��
		if (ret != IsWin(board, ROW, COL))
		{
			break;
		}
		
		//��������
		AiMove(board,ROW,COL);
	
		//��ӡ����
		DisplayBoard(board,ROW,COL);

		//�жϵ���ʤ��
		if (ret != IsWin(board, ROW, COL))
		{
			break;
		}
	
		printf("����\n");
	}
	ret = IsWin(board, ROW, COL);
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}


}

void menu()
{
	printf("*********************\n");
	printf("****1.play 0.exit****\n");
	printf("*********************\n");
}

void test()
{
	srand((unsigned int)time(NULL));
	int choice = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1: 
			printf("������!!!\n");
			game();//��Ϸ��ʵ��
			break;
		case 0:
			printf("�˳���Ϸ!!!\n");
			break;
		default:
			printf("ѡ�����������ѡ��!!!\n");
			break;
		}
	} while(choice);
}

int main()
{
	test();

	return 0;
}