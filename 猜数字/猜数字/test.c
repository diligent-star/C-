#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void Menu(){
	//猜数字游戏菜单
	printf("*******************************\n");
	printf("*** Welcome To Guess Number ***\n");
	printf("*******************************\n");
	printf("****** 1. play   0. exit ******\n");
	printf("*******************************\n");
}//Menu


void Print_Range(int correct_answer, int guess_answer){
	//判断游戏进度，打印猜数字的范围
	static int memory_small = 0;
	static int memory_big = 100;

	if (guess_answer > correct_answer)
	{
		printf("大了\n");
		memory_big = guess_answer - 1;
		printf("%d - %d\n", memory_small, memory_big);
	}
	else if (guess_answer < correct_answer)
	{
		printf("小了\n");
		memory_small = guess_answer + 1;
		printf("%d - %d\n", memory_small, memory_big);
	}
	else
	{
		printf("恭喜你！猜对了！\n");
		Sleep(3500);
		system("cls");

		//游戏未关闭，为多次游戏,初始化
		memory_small = 0;
		memory_big = 100;
	}

}//Print_Range


void Guess_Game(){
	//猜数字游戏： 从0 到 100 的数中猜，直到猜中为止

	int guess_answer = 0;
	int correct_answer = 0;

	//1. 形成随机数 包含 0 与 100
	correct_answer = rand() % 101;

	//2.猜数字
	do
	{
		printf("请输入你所猜的数字:>");
		scanf("%d", &guess_answer);
		system("cls");
		Print_Range(correct_answer, guess_answer);
	} while (guess_answer != correct_answer);

}//Guess_game


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		Menu();
		printf("请输入选项:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("游戏开始！\n数字在0 - 100（包括0 与 100）\n");
			Guess_Game();
			break;
		case 0:
			break;
		default:
			printf("输入错误，请重新输入！！！\n");
			Sleep(3500);
			system("cls");
			Sleep(1000);
			break;
		}

	} while (input);

	return 0;
}