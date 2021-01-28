#include "game.h"


void game(){
	//��������Ϸ 
	//��Ϸ�����ھŹ����ڣ��������������д��*����
	//          ���������д��&����ͼ��ֻ�ܱ���д��
	//          δ����д�������ڣ�����һ����3��ͼ��
	//          ����һ�ߣ�����ʤ����������������
	//          δ����3��ͼ��һ����ƽ�֡�
	//          �������ʱ���������������� ��ʽΪ��x,y

	char board[ROW][COL] = { '0' };
	
	//�ж���Ϸ���ȱ�ʶ
	char check = 0;

	InitBoard(board, ROW, COL);
	printf("�������\n");
	DisplayBoard(board, ROW, COL);
	//����Ļ���
	while (1)
	{
		//�����������
		PlayerMove(board, ROW, COL);
		check = IsWin(board, ROW, COL);
		if (check != '1')
		{
			break;
		}

		//�����������
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
		printf("���ʤ��������\n");
	else if (check == '&')
		printf("����ʤ��������\n");
	else if (check == '0')
		printf("ƽ�֣�! !\n");
	Sleep(5000);
	system("cls");
}


void rule(void){
	//������Ϸ����
	printf("��Ϸ����\n�ھŹ����ڣ��������������д��*�������������д��&��\nͼ��ֻ�ܱ���д��δ����д��������\n����һ��������ͼ�� ����һ�ߣ�����ʤ��\n������������δ��������ͼ������һ����ƽ��\n�������ʱ���������������� ��ʽΪ��x,y\n");
}//rule


void menu(void ){
	//������ļ��ײ˵� ѡ��1.��ʼ��Ϸ ѡ��2.��ӡ��Ϸ���� ѡ��0.�˳���Ϸ 

	printf("****************\n");	
	printf("***  ������  ***\n");
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
		printf("��ѡ��:>");
		scanf("%d",&input);

		system("cls");
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("�˳���Ϸ������\n");
			break;
		case 2:
			rule();
			break;
		default:
			printf("������󣡣���\n���������룡����\n");
			break;
		}
	} while (input != 0);

	return 0;
}