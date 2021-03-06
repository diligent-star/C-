#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcat(char *dest,const char *sorc)
{
	assert(dest != NULL);
	assert(sorc != NULL);
	char * ret = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *sorc++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr[50] = "I am a ";
	char arr1[] = "handsome boy hehe";
	//printf("%s\n", strcat(arr, arr1));
	printf("%s\n", my_strcat(arr, arr1));
	return 0;
}
//char* my_strstr(const char *e1, const char *e2)
//{
//	assert(e1 != NULL);
//	assert(e2 != NULL);
//	const char *p1 = e1;
//	const char *p2 = e2;
//	while ('\0' != e1)
//	{
//		while (*e2 == *e1 && *e2 != '\0' && *e1 != '\0')
//		{
//			e2++;
//			e1++;
//		}
//		if ('\0' == *e2)
//		{
//			return (char*)p1;
//		}
//		if ('\0' == *e1)
//		{
//			return NULL;
//		}
//		e1 = p1;
//		e2 = p2;
//		e1++;
//		p1++;
//	}
//	return NULL;//找不到
//}
//
//int main()
//{
//	char arr1[] = "abbcddef";
//	char arr2[] = "deff";
//	char *ret = strstr(arr1, arr2);
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("找不到！\n");
//	}
//	ret = my_strstr(arr1, arr2);
//	if (ret != NULL)
//	{
//		printf("%s\n", ret);
//	}
//	else
//	{
//		printf("找不到！\n");
//	}
// 	return 0;
//}
//int my_strlen(const char *s)
//{
//	assert(s != NULL);
//	int count = 0;
//	while (*s != '\0')
//	{;
//		count++;
//		s++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[20] = "i am a student";
//	printf("%d\n", strlen(arr));
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}
//char* my_strcpy(char *dest,const char *sorc)
//{
//	assert(dest != NULL);
//	assert(sorc != NULL);
//	char *ret = dest;
//	while (*dest++ = *sorc++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[20] = "i am a student";
//	char arr1[] = "Hello World";
//	char arr2[] = "I am handsome";
//	printf("%s\n", strcpy(arr, arr1));
//	printf("%s\n", my_strcpy(arr, arr2));
//	return 0;
//}

//int my_strcmp(const char *x, const char *y)
//{
//	assert(x != NULL);
//	assert(y != NULL);	
//	while (*x == *y)
//	{
//		if ('\0' == *x)
//		{
//			return 0;
//		}
//		x++;
//		y++;
//	}
//
//	// *x != *y
//	if (*x > *y)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	char arr1[] = "qwer";
//	char arr2[] = "qwer";
//	char arr3[] = "asdf";
//	printf("%d\n", strcmp(arr1, arr2));
//	printf("%d\n", my_strcmp(arr1,arr2));
//	return 0;
//}