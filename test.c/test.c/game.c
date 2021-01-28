#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col){
	//��ʼ�����̣�ʹ���̳�ʼ��Ϊ ȫ�ո�
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}

}//InitBoard


void DisplayBoard(char board[ROW][COL], int row, int col){
	//��ӡ������������
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		//��ӡ * | * | *  
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j != col - 1 )
				printf("|");
		}
		printf("\n");

		//��ӡ---|---|---
		if (i != row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j != col - 1)
					printf("|");
			}
			printf("\n");
		}

	}

}//DisplayBoard


void PlayerMove(char board[ROW][COL], int row, int col){
	//������� ����������� ����Ϸ��Ժ󽫡�*����������
	int x = 0;
	int y = 0;
	
	printf("��������������:>");
	while (1)
	{
		scanf("%d,%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("�����ѱ�ռ�ã�����\n����������:>");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("����Ƿ�������\n����������:>");
		}
	}
}//PlayerMove


void ComputerMove(char board[ROW][COL], int row, int col){
	//�������� �����������������
	
	while(1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '&';
			printf("�������� %d,%d\n", x + 1, y + 1);
			break;
		}
	}

}//ComputerMove


char IsWin(char board[ROW][COL], int row, int col){
	//�ж�һ��ʤ�� �����ʤ�����ء�*�� ������ʤ�����ء�&�� 
	//��ƽ�ַ��ء�0��  ��Ϸ�������ء�1�� 
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{

		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}
		if (board[1][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		{
			return board[1][1];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return '1';
		}
	}
	return '0';
}//IsWin