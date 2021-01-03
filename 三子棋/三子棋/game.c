#define  _CRT_SECURE_NO_WARNINGS 1//注意函数的定义格式 返回内型 函数名 （形式参数）{}

#include "game.h"

//实现棋盘初始化
void InitBoard (char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			Board[i][j] = ' ';//注意字符‘’而不是字符串“”
	}

}

//打印棋盘的实现

//void DisplayBoard(char Board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row;i++)
//	{
//		//1.打印一行数据
//			printf(" %c | %c | %c \n", Board[i][0], Board[i][1], Board[i][2]);
//		
//			//2.打印分割行
//			if (i<row-1)
//			printf("---|---|---\n");
//	}
//}   无法满足要求 row 和 col 无法控制棋盘


//打印棋盘的实现（改）
//将每排也分成小的模块分别打印  打印变化元素时应找到相同的元素 多余元素用if筛选掉
void DisplayBoard(char Board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		//打印行数据
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//打印分割行
		if (i < row - 1)//最后一排不打印
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < row - 1)//每排最后一个不打印
					printf("|");
			}
			printf("\n");//每行打印完后换行
		}
	}
}

//玩家走算法实现
void Playermove(char Board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	printf("请玩家输入坐标:>");
	while (1)
	{
		scanf("%d,%d", &x, &y);
		//判断x,y的合法性
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (Board[x - 1][y - 1] == ' ')//注意该位置为字符类型
			{
				Board[x - 1][y - 1] = '*';//注意该位置为字符类型
				break;//下完后退出下棋
			}
			else
				printf("该坐标已被占用，请重新输入:>");
		}
		else
		{
			printf("请重新输入:>");
		}
	}

}

//电脑走实现
void AiMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	
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

//判断输赢算法实现
//玩家赢 ‘*’
//电脑赢 ‘#’
//平局   ‘Q’
//继续   ‘C’
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	//判断横竖三排
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
	//对角线
	if (board[0][0] == board[1][1] && board[2][2] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//平局
	if (1 == IsFull(board, row, col))
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}


//返回0表示棋盘满了
//返回1表示棋盘没满
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