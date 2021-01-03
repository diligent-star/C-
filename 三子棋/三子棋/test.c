#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()//游戏过程，算法实现
{
	char ret = 'C';
	//存放棋盘信息
	char board[ROW][COL] = { 0 };//棋盘中全是null即为空格
	//初始化棋盘 使棋盘中的元素即为所要
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	
	//下棋
	while (1)
	{
		//玩家下棋
		Playermove(board,ROW,COL);
		//打印棋盘
		DisplayBoard(board, ROW, COL);
		//判断玩家胜利
		if (ret != IsWin(board, ROW, COL))
		{
			break;
		}
		
		//电脑下棋
		AiMove(board,ROW,COL);
	
		//打印棋盘
		DisplayBoard(board,ROW,COL);

		//判断电脑胜利
		if (ret != IsWin(board, ROW, COL))
		{
			break;
		}
	
		printf("继续\n");
	}
	ret = IsWin(board, ROW, COL);
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
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
		printf("请选择:>");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1: 
			printf("三子棋!!!\n");
			game();//游戏的实现
			break;
		case 0:
			printf("退出游戏!!!\n");
			break;
		default:
			printf("选择错误请重新选择!!!\n");
			break;
		}
	} while(choice);
}

int main()
{
	test();

	return 0;
}