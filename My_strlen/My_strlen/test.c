#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int My_Strlen(const char arr[])
{
	assert(arr !=NULL);
	int i = 0;
	int count = 0;//计数
	for (i = 0;arr[i] != '\0';i++)//不包含\0
	{
		count++;
	}
	return count;
}

int main()
{
	//创建字符数组
	char arr[] = "I Love China";

	//求字符串长度
	printf("%d",My_Strlen(arr));
	return 0;
}