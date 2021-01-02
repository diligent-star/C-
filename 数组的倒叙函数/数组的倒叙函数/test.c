#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* My_StrBack(char arr[], const int size)
{
	assert(arr != NULL);
	int first = 0;
	int end = size - 2;
	while(first < end)
	{
		char temp = 0;
		temp = *(arr + first);
		*(arr + first) = *(arr + end);
		*(arr + end) = temp;
		first++;
		end--;
	}
	return arr;
}

int main()
{
	//创建字符数组
	char arr1[] = "a23456789";
	int size = sizeof(arr1) / sizeof(arr1[0]);
	printf("%s\n",arr1);
	printf("%s\n", My_StrBack(arr1, size));
	return 0;
}