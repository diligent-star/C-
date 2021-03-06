#include "game.h"


void game(){
	//

}//game


void menu(void){
	//扫雷棋菜单
	printf("******************\n");
	printf("***  扫雷游戏  ***\n"); 
	printf("******************\n");
	printf("***   1.play   ***\n");
	printf("***   0.exit   ***\n");
	printf("******************\n");
}//menu


int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！！！\n");
			break;
		default:
			printf("输入错误！！！\n请重新输入!!!\n");
			break;
		}
	} while (input != 0);

	return 0;
}