#include "game.h"

void menu(){
	/*菜单打印*/
	printf("*****************\n");
	printf("***  1. play  ***\n");
	printf("***  0. exit  ***\n");
	printf("*****************\n");
}

void game(){
	/*扫雷游戏的实现*/
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '?');
	SetMine(mine , ROW, COL, EASY_SET);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

int main()
{
	srand((unsigned)time(NULL));
	int choice = 0;
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！！！\n");
			break;
		default:
			printf("输入错误！！！请重新输入！！！\n");
			break;
		}
	} while (choice);
	return 0;
}