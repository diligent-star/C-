#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



void Is_Leap_Year(int year)
{
	if ((year % 4 == 0)&&(year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d is leap year\n",year);
	}
	else
	{
		printf("%d is not leap year\n",year);
	}
}

int main()
{
	int year = 0;
	scanf("%d",&year);
	//ÅĞ¶ÏÈòÄê
	Is_Leap_Year(year);
	return 0;
}