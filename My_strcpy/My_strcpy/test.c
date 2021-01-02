#define  _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <assert.h>

char* My_Strcpy(char des[], const char str[])
{
	char* p = des;
	assert(des != NULL);
	assert(str != NULL);

	while (*des++ = *str++)
	{
		;
	}
	return p;
}

int main()
{ 
	//创建2个字符数组
	char arr1[] = "I Love China";
	char arr2[] = "I Love You";
	//复制的实现
	printf("%s\n",arr1);
	printf("%s\n",My_Strcpy(arr1, arr2));
 	return 0;
}