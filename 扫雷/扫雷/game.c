#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//���̵ĳ�ʼ��
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

//���̵Ĵ�ӡ
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;

	//��ӡ�к�
	for (i = 0; i <= row;i++)
	{
		printf("%d ",i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)//�д�ӡ
	{
		printf("%d ",i);//��ӡ�к�
		for (j = 1; j <= col;j++)//�д�ӡ
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

//�������
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

//�鿴������Χ�׵ĸ���
int Get_Count_Mine(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x-1][y+1] + mine[x][y-1] + mine[x][y+1] + mine[x+1][y-1]
		+ mine[x+1][y] + mine[x+1][y+1] - 8 * '0';
}

//չ��һƬ
//ǰ��Ԫ���б仯��Ҫ�����ж��Ѿ��жϹ���Ԫ��ֻ��Ҫifɸѡ���ı��Ԫ�ؼ���
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


//����
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	printf("����������:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		//����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col )
		{
			if (mine[x][y] == '1')//����
			{
				printf("��Ϸ������������ˣ������ˣ�\n");
				DisplayBoard(mine,ROW,COL);
				break;
			}
			else//û����
			{
				//����������Χ�м�����
                   // Get_Count_Mine(mine,x,y);
					//���еݹ�
					Start_Expend(mine,show,x,y);
					DisplayBoard(show, row, col);
				win++;//ͳ���׵ĸ���
			}
		}
		else
		{
			printf("����������:>");
		}
		if (win == row*col -  Easy_Count )
		{
			printf("���׳ɹ�!!!\n");
			DisplayBoard(mine,row,col);
			break;
		}
	}
}