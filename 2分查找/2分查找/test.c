#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

void My_Printf(const int arr[])
{
	assert(arr != NULL);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void Binary_Chop(const int arr[],const int input, int end)
{
	assert(arr != NULL);
	int first = 0;
	int mid = (first + end) / 2;
	
	while (first <= end)
	{
		if (arr[mid] > input)
		{
			end = mid - 1;
			mid = (first + end) / 2;
		}
		else if (arr[mid] < input)
		{
			first = mid + 1;
			mid = (first + end) / 2;
		}
		else
		{
			printf("想要查找的数是第%d个\n", mid + 1);
			break;
		}
	}
	if (first > end)
	{
		printf("没有你要的数字\n");
	}
}

int main()
{
	int input = 0;
	int i = 0;
	//创建一个有序数组
	int arr[10] = { 0 };
	int end = 0;
	//要查找的量
	scanf("%d",&input);
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	My_Printf(arr);

	//二分查找
	end = sizeof(arr) / sizeof(arr[0]) - 1;
	Binary_Chop(arr,input,end);
	return 0;
}