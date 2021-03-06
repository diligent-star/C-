#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col){
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col, int set_count){
	int count = set_count;
	while (set_count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			set_count--;
		}
	}
}

int FindMineCount(char mine[ROWS][COLS], int x, int y){
	/* ����������Χ�׵ĸ���*/
	return 	mine[x + 1][y] +
			mine[x + 1][y + 1] +
			mine[x + 1][y - 1] +
			mine[x][y + 1] +
			mine[x][y - 1] +
			mine[x - 1][y + 1] +
			mine[x - 1][y] +
			mine[x - 1][y - 1] -
			'0' * 8;
}

int ExpendMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* p_end){
	/* �Ų�ɹ�����1 �Ų�ʧ�ܷ���0 �Ų�Խ�緵��-1 */
	if (show[x][y] != '?')
	{
		return 0;
	}
	else if (x < 1 || x> ROW || y < 1 || y > COL)
	{
		return -1;
	}
	else
	{
		int count = FindMineCount(mine, x, y);
		show[x][y] = '0' + count;
		(*p_end)--;
		if (0 == count)
		{
			ExpendMine(mine, show, x + 1, y + 1, p_end);
			ExpendMine(mine, show, x + 1, y, p_end);
			ExpendMine(mine, show, x + 1, y - 1, p_end);
			ExpendMine(mine, show, x, y + 1, p_end);
			ExpendMine(mine, show, x, y - 1, p_end);
			ExpendMine(mine, show, x - 1, y + 1, p_end);
			ExpendMine(mine, show, x - 1, y, p_end);
			ExpendMine(mine, show, x - 1, y - 1, p_end);
		} 
		return 1;
	}
}

FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col){
	int end = ROW * COL - EASY_SET;
	int x = 0;
	int y = 0;
	while (end)
	{
		printf("�������Ų�����>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '?')
		{
			if (mine[x][y] == '1')
			{
				printf("�����ˣ���Ϸ������\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				ExpendMine(mine, show, x, y, &end);
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("����Ƿ�������\n");
		}
	}
	if (0 == end)
	{
		printf("��ϲ��ɨ�׳ɹ���\n");
		DisplayBoard(mine, ROW, COL);
	}
}

