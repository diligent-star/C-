#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int input_bf1 = 0;//备份input1
	int input_bf2 = 0;//备份input2
	int end = 0;
	int input1 = 0;
	int input2 = 0;
	scanf("%d %d", &input1, &input2);
	input_bf1 = input1;
	input_bf2 = input2;
	if (input1 < input2)
	{
		int temp = 0;
		temp = input1;
		input1 = input2;
		input2 = temp;
	}//input1总是最大的数

	while (
		end = input1 % input2,
	    input1 = input2,
	    input2 = end,
		end)
	{
		;
    }//辗转相除法的实现
	printf("%d\n",input1);

	printf("%d\n", input_bf1 / input1 * input_bf2);
	return 0;
}