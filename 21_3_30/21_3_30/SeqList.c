#include "SeqList.h"

void
SeqListInit(SeqList *seq)
{
	assert(seq != NULL);
	seq->arr = NULL;
	seq->size = 0;
	seq->capacity = 0;
}

void
SeqListDestory(SeqList *seq)
{
	assert(seq != NULL);
	free(seq->arr);
	seq->arr = NULL;
	seq->size = 0;
	seq->capacity = 0;
}

void
SeqListPrint(const SeqList *seq)
{
	assert(seq != NULL);
	size_t i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->arr[i]);
	}
	printf("\n");
}

static void
SeqListCheckCapacity(SeqList *seq)
{
	assert(seq != NULL);
	if (seq->size == seq->capacity)//�ж�����
	{
		int newcapacity = (0 == seq->capacity) ? (4) : (2 * seq->capacity);
		SLDataType *new_arr = realloc(seq->arr, sizeof(SLDataType)* newcapacity);
		if (new_arr == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			seq->arr = new_arr;
			seq->capacity = newcapacity;
		}
	}
}

void
SeqListPushBack(SeqList *seq, SLDataType x)
{
	assert(seq != NULL);
	SeqListCheckCapacity(seq);
	//���ֵ
	seq->arr[seq->size] = x;
	seq->size++;
}

void
SeqListPushFront(SeqList *seq, SLDataType x)
{
	assert(seq != NULL);
	SeqListCheckCapacity(seq);
	int end = seq->size - 1;//���Ԫ���±�
	while (end >= 0)//�Ӻ�ʼ ��Ų��
	{
		seq->arr[end + 1] = seq->arr[end];
		end--;
	}
	seq->arr[0] = x;
	seq->size++;
}

void
SeqListPopBack(SeqList *seq)
{
	assert(seq != NULL);
	assert(seq->size > 0);
	seq->size--;
}

void
SeqListPopFront(SeqList *seq)
{
	assert(seq != NULL);
	assert(seq->size > 0);
	size_t head = 0;//�ʼԪ���±�
	while (head < seq->size - 1)//��ǰ��ʼ ��ǰŲ��
	{
		seq->arr[head] = seq->arr[head + 1];
		head++;
	}
	seq->size--;
}
