#define  _CRT_SECURE_NO_WARNINGS 1
#define N 20

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void My_Printf(int arr[N])
{
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	srand((unsigned)time(NULL));
	//�γ����������
	int k = 0;
	int arr[N] = {0};
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		arr[i] = rand()%(3 * N);
	}
	//��ӡ����
	My_Printf(arr);

	//��������
	for (i = 1; i < N; i++)//�ӵ�2��Ԫ�ص����һ��Ԫ�ز�������
	{
		if (arr[i] <= arr[0])//��С����
		{
			int temp = arr[i];
			for (j = i; j > 0; j--)//���ƽ��
			{
				arr[j] = arr[j - 1];
			}
			arr[0] = temp;
		}
		else if (arr[i] >= arr[i - 1])
		{
			;
		}
		else
		{
			for (j = 1; j < i - 1; j++)
			{
				if (arr[i] <= arr[j])//��С����
				{
					int temp = arr[i];
					for (k = i; k > j; k--)
					{
						arr[k] = arr[k - 1];
					}
					arr[j] = temp;
					break;
				}
			}
		}
	}
	My_Printf(arr);
	return 0;
}