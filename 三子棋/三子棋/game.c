#define  _CRT_SECURE_NO_WARNINGS 1//ע�⺯���Ķ����ʽ �������� ������ ����ʽ������{}

#include "game.h"

//ʵ�����̳�ʼ��
void InitBoard (char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			Board[i][j] = ' ';//ע���ַ������������ַ�������
	}

}

//��ӡ���̵�ʵ��

//void DisplayBoard(char Board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row;i++)
//	{
//		//1.��ӡһ������
//			printf(" %c | %c | %c \n", Board[i][0], Board[i][1], Board[i][2]);
//		
//			//2.��ӡ�ָ���
//			if (i<row-1)
//			printf("---|---|---\n");
//	}
//}   �޷�����Ҫ�� row �� col �޷���������


//��ӡ���̵�ʵ�֣��ģ�
//��ÿ��Ҳ�ֳ�С��ģ��ֱ��ӡ  ��ӡ�仯Ԫ��ʱӦ�ҵ���ͬ��Ԫ�� ����Ԫ����ifɸѡ��
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		//��ӡ������
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//��ӡ�ָ���
		if (i < row - 1)//���һ�Ų���ӡ
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)//ÿ�����һ������ӡ
					printf("|");
			}
			printf("\n");//ÿ�д�ӡ�����
		}
	}
}

//������㷨ʵ��
void Playermove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	printf("�������������:>");
	while (1)
	{
		scanf("%d,%d", &x, &y);
		//�ж�x,y�ĺϷ���
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (Board[x - 1][y - 1] == ' ')//ע���λ��Ϊ�ַ�����
			{
				Board[x - 1][y - 1] = '*';//ע���λ��Ϊ�ַ�����
				break;//������˳�����
			}
			else
				printf("�������ѱ�ռ�ã�����������:>");
		}
		else
		{
			printf("����������:>");
		}
	}

}

//������ʵ��
void AiMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");
	
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
     	if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//�ж���Ӯ�㷨ʵ��
//���Ӯ ��*��
//����Ӯ ��#��
//ƽ��   ��Q��
//����   ��C��
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	//�жϺ�������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}

	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//ƽ��
	if (1 == IsFull(board, row, col))
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}


//����0��ʾ��������
//����1��ʾ����û��
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row;i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 0;
}