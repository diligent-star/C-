#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

void My_Printf(const int arr[],const int size)
{
	assert(arr != NULL);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Selection_Sort(int arr[],const int size)
{
	assert(arr != NULL);
	int i = 0;
	int j = 0;
	int max = 0;//记录最大元素下标
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			int temp = 0;
			max = i;
			if (arr[i] < arr[j])//把大的放在前面
			{
				max = j;
			}
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	//创建一个随机数组
	int i = 0;
	int arr[10] = {0};
	int size = sizeof(arr)/sizeof(arr[0]);//计算数组大小
	for (i = 0; i < 10; i++)
	{
		arr[i] = rand()%50;
	}
	My_Printf(arr,size);
	//选择法排序
	Selection_Sort(arr,size);
	My_Printf(arr,size);
	return 0; 
}