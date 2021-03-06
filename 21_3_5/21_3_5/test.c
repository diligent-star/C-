#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

struct Stu
{
	char name[20];
	int age;
};

int cmp_int(const void *x, const void *y)
{
	return *(int*)x - *(int*)y;
}

int cmp_Stu_by_age(const void *x, const void *y)
{
	return ((struct Stu*)x)->age - ((struct Stu*)y)->age;
}

int cmp_Stu_by_name(const void *x, const void *y)
{
	return strcmp(((struct Stu*)x)->name, ((struct Stu*)y)->name);
}

void exchange(char *x, char *y, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *x;
		*x = *y;
		*y = tmp;
		x++;
		y++;
	}
}

void bubble_sort(void *arr, int number, int width, int (*cmp)(const void *x, const void *y))
{
	int i = 0;
	for (i = 0; i < number - 1; i++)
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < number - 1 - i; j++)
		{
			if (cmp((char*)arr+j*width, (char*)arr+(j+1)*width) > 0)
			{
				exchange( (char*)arr + j*width, (char*)arr+(j+1)*width, width);
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

void bubble(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz - 1; i++) //趟数
	{
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) //相邻比较
		{
			if (arr[j] < arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 1, 4, 5, 6, 7, 12, 55, 23 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	//bubble(arr , sz);
	return 0;
}
//int main()
//{
//	int arr[] = { 2, 3, 1, 4, 5, 6, 7, 12, 55, 23 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	struct Stu s[] = { { "zhangsan", 18 }, { "lisi", 20 }, { "wangwu", 17 } };
//	sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_Stu_by_age);
//	qsort(s, sz, sizeof(s[0]), cmp_Stu_by_name);
//	return 0;
//}