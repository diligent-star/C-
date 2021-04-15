#include "SeqList.h"

void
SeqListInit(SeqList *seq)
{
	assert(seq != NULL);
	seq->capacity = 0;
	seq->size = 0;
	seq->a = NULL;
}

void
SeqListDestory(SeqList *seq)
{
	assert(seq != NULL);
	seq->capacity = 0;
	seq->size = 0;
	free(seq->a);
	seq->a = NULL;
}

//����Ƿ�Ҫ����
void
IsFull(SeqList *seq)
{
	assert(seq != NULL);
	if (seq->size == seq->capacity)
	{
		int new_capacity = (seq->capacity == 0) ? 10 : seq->capacity * 2;
		SeqDataType *check = realloc(seq->a, sizeof(SeqDataType) * new_capacity);
		if (check == NULL)
		{
			printf("Realloc Fail������\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			seq->a = check;
			seq->capacity = new_capacity;
		}
	}
}


void 
SeqListPushBack(SeqList *seq, SeqDataType x)
{
	assert(seq != NULL);
	IsFull(seq);
	seq->a[seq->size] = x;
	seq->size++;
}

void 
SeqListPushFront(SeqList *seq, SeqDataType x)
{
	assert(seq != NULL);
	IsFull(seq);
	//�ȴӺ���ǰŲ������ֵ����
	int i = seq->size;
	while (i >= 0)
	{
		seq->a[i + 1] = seq->a[i];
		i--;
	}
	seq->a[0] = x;
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
	//��ǰ����Ų�����ݸ��ǵ�һ������
	int i = 0;
	for (i = 0; i < seq->size - 1; i++)
	{
			seq->a[i] = seq->a[i + 1];
	}
	seq->size--;
}

void
SeqListPrint(SeqList *seq)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->a[i]);
	}
	if (0 == seq->size)
	{
		printf("NULL");
	}
	printf("\n");
}

//�ҵ������±꣬
//������Ԫ�ز�ͬʱ�ȽϷ�ʽ��Ҫ�ı䡣
int
SeqListFind(SeqList *seq, SeqDataType find_num)
{
	int i = 0;
	for (i = 0; i < seq->size; i++)
	{
		if (seq->a[i] == find_num)
		{
			return i;
		}
	}
	//�Ҳ���
	return -1;
}

void
SeqListInsert(SeqList *seq, int pos, SeqDataType x)
{
	assert(seq != NULL);
	assert(pos >= 0 && pos <= seq->size);
	IsFull(seq);
	int i = 0;
	for (i = 0; i < seq->size - pos; i++)
	{
		seq->a[seq->size - i] = seq->a[seq->size - i - 1];
	}
	seq->a[pos] = x;
	seq->size++;
}

void
SeqListErase(SeqList *seq, int pos)
{
	assert(seq != NULL);
	assert(pos >= 0 && pos < seq->size);
	int i = 0;
	for (i = 0; i < seq->size - 1 - pos; i++)
	{
		seq->a[pos + i] = seq->a[pos + 1 + i];
	}
	seq->size--;
}

void
SeqListModify(SeqList *seq, int pos, SeqDataType x)
{
	assert(seq != NULL);
	assert(pos >=0 && pos < seq->size);
	seq->a[pos] = x;
}