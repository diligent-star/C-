#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

//size_t
//my_strlen(const char *string)
//{
//	assert(string != NULL);
//	size_t count = 0;//计数器
//	while (*string++ != '\0')
//	{
//		count++;
//	}
//	return count;
//}

//char*
//my_strcpy(char *dest, const char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//char*
//my_strcat(char *dest, const char *src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *ret = dest;
//	//找到dest中的'\0'
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	//字符串拷贝
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}

//int
//my_strcmp(const char *string1, const char *string2)
//{
//	assert(string1 != NULL);
//	assert(string2 != NULL);
//	while (*string1 == *string2)//字符一样时字符串向后移动
//	{
//		if ('\0' == *string1)//当同时遇到结束标志时退出
//		{
//			return 0;
//		}
//		string1++;
//		string2++;
//	}
//	return (int)(*string1 - *string2);
//}

//char*
//my_strncpy(char *dest, const char *src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *ret = dest;
//	size_t sz = strlen(src);
//	size_t i = 0;
//	for (i = 0; i < count; i++)
//	{
//		if (sz <= i)//count大于字符串长度赋值'\0'
//		{
//			*dest++ = '\0';
//		}
//		else
//		{
//			*dest++ = *src++;
//		}
//	}
//	return ret;
//}

//char*
//my_strncat(char *dest, const char *src, size_t count)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char *ret = dest;
//	size_t i = 0;
//	while (*dest != '\0')//找dest结束标志
//	{
//		dest++;
//	}
//	for (i = 0; i < count; i++)//字符串拷贝
//	{
//		*dest++ = *src++;
//	}
//	*dest = '\0';//添加字符串结束标志'\0'
//	return ret;
//}

//int
//my_strncmp(const char *string1, const char *string2, size_t count)
//{
//	assert(string1 != NULL);
//	assert(string2 != NULL);
//	while ((*string1 == *string2) && (count != 0))
//	{
//		string1++;
//		string2++;
//		count--;
//	}
//	if (count != 0)
//	{
//		return (int)(*string1 - *string2);
//	}
//	else
//	{
//		return 0;
//	}
//}

//char*
//my_strstr(const char *string, const char *check_string)
//{
//	assert(string != NULL);
//	assert(check_string != NULL);
//	const char *m_string = string;//记住第一个相同元素的位置
//	const char *m_check_string = check_string;//记住被查找字符串首地址
//	while ((*string != '\0') && (*check_string != '\0'))
//	{
//		while (*string != *check_string)//找第一个相同元素位置
//		{
//			m_string = ++string;
//		}
//
//		while ((*string == *check_string) && ('\0' != *check_string))//找字符串是否全相同
//		{
//			string++;
//			check_string++;
//		}
//
//		if (*check_string != '\0')//如果不全相同，做出调整
//		{
//			check_string = m_check_string;
//			string = ++m_string;
//		}
//	}
//	if ('\0' == *check_string)
//	{
//		return (char*)m_string;
//	}
//	else
//	{
//		return NULL;
//	}
//}
//
//
//int
//main()
//{
//	//char arr[] = "abccdef";
//	//char arr1[] = "cd";
//	//char* ret = my_strstr(arr, arr1);
//	//if (ret != NULL)
//	//{
//	//	printf("%s\n",ret);
//	//}
//	//else
//	//{
//	//	printf("找不到\n");
//	//}
//	//printf("%d\n", my_strncmp(arr, arr1, 5));
//	//char arr[] = "abcd";
//	//printf("%d\n", strlen(arr));
//	//printf("%d\n", my_strlen(arr));
//	//char dest[20] = "**************";
//	//char src[] = "hello world";
//	//printf("%s\n", my_strcpy(dest, src));
//	//char arr[20] = "orld";
//	//char arr1[] = "aorld";
//	//printf("%s\n",my_strcat(arr, arr1));
//	//printf("%d\n", my_strcmp(arr, arr1));
//	//char arr[30] = "hello\0*******************";
//	//char arr1[] = "world";
//	//printf("%s\n",my_strncat(arr, arr1,5));
//	return 0;
//}