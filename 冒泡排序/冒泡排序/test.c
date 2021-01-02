#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>


void My_printf(const int arr[])
{
	assert(arr != NULL);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Bubble_Sort(int arr[],int n)
{
	int i = 0;
	int j = 0;
	for(i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])//把大的放在前面
			{
				int temp = 0;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int i = 0;
	//创建随机数组值并打印
	int arr[10] = {0};
	for (i = 0; i < 10; i++)
	{
		arr[i] = rand()%50;
	}
	My_printf(arr);
	
	//冒泡排序并打印
	Bubble_Sort(arr,10);
	My_printf(arr);
	return 0;
}