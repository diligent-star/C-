#include "game.h"


void game(){
	//

}//game


void menu(void){
	//ɨ����˵�
	printf("******************\n");
	printf("***  ɨ����Ϸ  ***\n"); 
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
		printf("��ѡ��:>");
		scanf("%d",&input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ������\n");
			break;
		default:
			printf("������󣡣���\n����������!!!\n");
			break;
		}
	} while (input != 0);

	return 0;
}