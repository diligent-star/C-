#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//棋盘的初始化
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols;j++)
		{
			board[i][j] = set;
		}
	}

}

//棋盘的打印
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//打印列号
	for (i = 0; i <= row;i++)
	{
		printf("%d ",i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)//行打印
	{
		printf("%d ",i);//打印行号
		for (j = 1; j <= col;j++)//列打印
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

//随机放雷
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_Count;
	while (count)
	{
		int x = 0;
		int y = 0;
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//查看坐标周围雷的个数
int Get_Count_Mine(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x-1][y+1] + mine[x][y-1] + mine[x][y+1] + mine[x+1][y-1]
		+ mine[x+1][y] + mine[x+1][y+1] - 8 * '0';
}

//展开一片
//前后元素有变化，要不再判断已经判断过的元素只需要if筛选掉改变的元素即可
void Start_Expend(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (Get_Count_Mine(mine, x, y) == 0)
	{
		show[x][y] = ' ';
		    if ((x - 1 > 0) && (y - 1 > 0))
			if (show[x - 1][y - 1] != ' ')
				Start_Expend(mine, show, x - 1, y - 1);
			if (x - 1 > 0)
			if (show[x - 1][y] != ' ')
				Start_Expend(mine, show, x - 1, y);
			if ((x - 1 > 0) && (y + 1 < 10))
			if (show[x - 1][y + 1] != ' ')
				Start_Expend(mine, show, x - 1, y + 1);
			if (y - 1 > 0)
			if (show[x][y - 1] != ' ')
				Start_Expend(mine, show, x, y - 1);
			if (y + 1 < 10)
			if (show[x][y + 1] != ' ')
				Start_Expend(mine, show, x, y + 1);
			if ((x + 1<10) && (y - 1 > 0))
			if (show[x + 1][y - 1] != ' ')
				Start_Expend(mine, show, x + 1, y - 1);
			if (x + 1 < 10)
			if (show[x + 1][y] != ' ')
				Start_Expend(mine, show, x + 1, y);
			if ((x + 1 < 10) && (y + 1 < 10))
			if (show[x + 1][y + 1] != ' ')
				Start_Expend(mine, show, x + 1, y + 1);
		
	}
	else
	{
		show[x][y] = Get_Count_Mine(mine, x, y) + '0';
	}
}


//排雷
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	printf("请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col )
		{
			if (mine[x][y] == '1')//踩雷
			{
				printf("游戏结束！你踩雷了！你输了！\n");
				DisplayBoard(mine,ROW,COL);
				break;
			}
			else//没踩雷
			{
				//计算坐标周围有几个雷
                   // Get_Count_Mine(mine,x,y);
					//进行递归
					Start_Expend(mine,show,x,y);
					DisplayBoard(show, row, col);
				win++;//统计雷的个数
			}
		}
		else
		{
			printf("请重新输入:>");
		}
		if (win == row*col -  Easy_Count )
		{
			printf("排雷成功!!!\n");
			DisplayBoard(mine,row,col);
			break;
		}
	}
}