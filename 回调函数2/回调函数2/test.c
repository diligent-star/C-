#define  _CRT_SECURE_NO_WARNINGS 1
#define FALSE 0
#define TURE 1

#include <stdio.h>
#include <string.h>

typedef struct stu
{
	char name[20];
	int age;
}student;
//void Bubble(int arr[],int n){
//	//冒泡排序，int型排序，使数组从大到小排序
//	int i = 0;
//	int j = 0;
//	int change = 1;
//	for (i = 0; (i < n - 1) && change ; i ++)
//	{
//		change = FALSE;
//		for (j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int temp = 0;
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				change = TURE;
//			}
//		}
//	}
//}//Bubble

//void Print(int arr[], int n){
////打印排列的元素
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//}//Print

//int main()
//{
//	int arr[] = {0,1,2,3,4,5,6,7,8,9};
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	//Bubble(arr,sz);
//	//Print(arr,sz);
//	return 0;
//}

int Cmp_int(void* e1,void* e2){
//整形数据比较
	return *(int*)e1 - *(int*)e2;
}//Cmp_int

int Cmp_student_by_age(void* e1, void* e2){
//结构体student年龄比较
	return ((student*)e1)->age - ((student*)e2)->age;
}//Cmp_student_by_age

int Cmp_student_by_name(void* e1, void* e2){
//结构体student名字比较
	return strcmp(((student*)e1)-> name, ((student*)e2)-> name);
}//Cmp_student_by_name

void Swap(char* e1, char* e2, int width){
//交换元素
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = 0;
		temp = *e1;
		*e1 = *e2;
		*e2 = temp;
		e1++;
		e2++;
	}
}//Swap

void Bubble_sort( void* base, int sz, int width, int (*cmp)(void*e1, void*e2) ){
//冒泡排序，排序所有类型,从小到大
	int i = 0;
	int j = 0;
	int change = TURE;
	for (i = 0; (i < sz - 1) && change; i++)//确定趟数
	{
		change = FALSE;
		for (j = 0; j < sz - 1 - i; j++)//相邻元素比较
		{
			if (cmp((char*)base+j*width ,(char*)base+(j+1)*width) > 0)
			{
				Swap((char*)base + j*width, (char*)base + (j + 1)*width, width);
				change = TURE;
			}
		}
	}
}//Bubble_sort

int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1,0};
	int sz_arr = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr, sz_arr, sizeof(arr[0]), Cmp_int);
	student s[] = { { "zhangsan", 20 }, { "lisi", 19 }, { "wangwu", 18 } };
	int sz_s = sizeof(s) / sizeof(s[0]);
	Bubble_sort(s, sz_s, sizeof(s[0]), Cmp_student_by_age);
	Bubble_sort(s, sz_s, sizeof(s[0]), Cmp_student_by_name);
	return 0;
}