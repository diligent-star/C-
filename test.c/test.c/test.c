#include "game.h"


void game(){
	//三子棋游戏 
	//游戏规则：在九宫格内，玩家输入坐标填写‘*’，
	//          电脑随机填写‘&’，图案只能被填写在
	//          未被填写的坐标内，若有一方有3个图案
	//          连成一线，则获得胜利，若坐标填满，
	//          未能有3个图案一线则平局。
	//          玩家输入时先输入行再输入列 格式为：x,y

	char board[ROW][COL] = { '0' };
	
	//判断游戏进度标识
	char check = 0;

	InitBoard(board, ROW, COL);
	printf("玩家先行\n");
	DisplayBoard(board, ROW, COL);
	//下棋的互动
	while (1)
	{
		//玩家输入下子
		PlayerMove(board, ROW, COL);
		check = IsWin(board, ROW, COL);
		if (check != '1')
		{
			break;
		}

		//电脑随机下子
		system("cls");
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		check = IsWin(board, ROW, COL);
		if (check != '1')
		{
			break;
		}
	}
	system("cls");
	DisplayBoard(board, ROW, COL);
	if (check == '*')
		printf("玩家胜利！！！\n");
	else if (check == '&')
		printf("电脑胜利！！！\n");
	else if (check == '0')
		printf("平局！! !\n");
	Sleep(5000);
	system("cls");
}


void rule(void){
	//介绍游戏规则
	printf("游戏规则：\n在九宫格内，玩家输入坐标填写‘*’，电脑随机填写‘&’\n图案只能被填写在未被填写的坐标内\n若有一方有三个图案 连成一线，则获得胜利\n若坐标填满，未能有三个图案连成一线则平局\n玩家输入时先输入行再输入列 格式为：x,y\n");
}//rule


void menu(void ){
	//三子棋的简易菜单 选择1.开始游戏 选择2.打印游戏规则 选择0.退出游戏 

	printf("****************\n");	
	printf("***  三子棋  ***\n");
	printf("****************\n");
	printf("***  1.play  ***\n");
	printf("***  2.rule  ***\n");
	printf("***  0.exit  ***\n");
	printf("****************\n");

}//menu


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);

		system("cls");
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("退出游戏！！！\n");
			break;
		case 2:
			rule();
			break;
		default:
			printf("输入错误！！！\n请重新输入！！！\n");
			break;
		}
	} while (input != 0);

	return 0;
}