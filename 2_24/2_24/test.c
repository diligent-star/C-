#include "game.h"

void menu(){
	/*�˵���ӡ*/
	printf("*****************\n");
	printf("***  1. play  ***\n");
	printf("***  0. exit  ***\n");
	printf("*****************\n");
}

void game(){
	/*ɨ����Ϸ��ʵ��*/
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
		printf("��ѡ��>:");
		scanf("%d", &choice);
		switch (choice){
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ������\n");
			break;
		default:
			printf("������󣡣������������룡����\n");
			break;
		}
	} while (choice);
	return 0;
}