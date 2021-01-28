#include "game.h"


void InitBoard(char board[ROW][COL], int row, int col){
	//初始化棋盘，使棋盘初始化为 全空格
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
	//打印棋盘所有内容
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		//打印 * | * | *  
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j != col - 1 )
				printf("|");
		}
		printf("\n");

		//打印---|---|---
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
	//玩家下棋 玩家输入坐标 坐标合法性后将‘*’输入坐标
	int x = 0;
	int y = 0;
	
	printf("请输入落子坐标:>");
	while (1)
	{
		scanf("%d,%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("坐标已被占用！！！\n请重新输入:>");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("坐标非法！！！\n请重新输入:>");
		}
	}
}//PlayerMove


void ComputerMove(char board[ROW][COL], int row, int col){
	//电脑下棋 随机的落子在棋盘中
	
	while(1)
	{
		int x = rand() % row;
		int y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '&';
			printf("电脑落在 %d,%d\n", x + 1, y + 1);
			break;
		}
	}

}//ComputerMove


char IsWin(char board[ROW][COL], int row, int col){
	//判断一方胜利 若玩家胜利返回‘*’ 若电脑胜利返回‘&’ 
	//若平局返回‘0’  游戏继续返回‘1’ 
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