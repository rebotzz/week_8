#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"


//���µ����㷨
//С��
//void AdjustDown(Heap* php, int size,HPDataType root)
//{
//	int parent = root;
//	//�ҵ����������еĽ�Сֵ
//	int chird = 2 * parent + 1;
//	while (chird < size)
//	{
//		if (chird + 1 <size && php->_a[chird + 1] < php->_a[chird])
//		{
//			chird++;
//		}
//		if (php->_a[chird] < php->_a[parent])
//		{
//			//���½���
//			swap(&php->_a[parent], &php->_a[chird]);
//			parent = chird;
//			chird = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}

//2.0	���µ����㷨	С��
//void AdjustDown(Heap* php, int n, int root)
//{
//	//���������������������˳��,��������ʱ
//	//���������,��ײ������� AdjustDown �㷨ʹ������
//	int parent = root;
//	//�ҵ����������еĽ�Сֵ
//	int chird = 2 * parent + 1;
//	while (chird < n)
//	{
//		if (chird + 1 < n && php->_a[chird + 1] < php->_a[chird])
//		{
//			chird++;
//		}
//		if (php->_a[chird] < php->_a[parent])
//		{
//			//���½���
//			swap(&php->_a[parent], &php->_a[chird]);
//			parent = chird;
//			chird = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//3.0���µ����㷨	���
void AdjustDown(Heap* php, int n, int root)
{
	//���������������������˳��,��������ʱ
	//���������,��ײ������� AdjustDown �㷨ʹ������
	int parent = root;
	//�ҵ����������еĽ�Сֵ
	int chird = 2 * parent + 1;
	while (chird < n)
	{
		if (chird + 1 < n && php->_a[chird + 1] > php->_a[chird])
		{
			chird++;
		}
		if (php->_a[chird] > php->_a[parent])
		{
			//���½���
			swap(&php->_a[parent], &php->_a[chird]);
			parent = chird;
			chird = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//���ϵ����㷨	С��
//void AdjustUp(Heap* php, int n, int chird)
//{
//	assert(php);
//	//���һ������λ�ò���,��Ķ���
//	//����������ϵ���
//	int parent = (chird - 1) / 2;
//	while (chird > 0)
//	{
//		if (php->_a[chird] < php->_a[parent])//С��,��С���ϸ�
//		{
//			swap(&php->_a[chird], &php->_a[parent]);
//			chird = parent;
//			parent = (chird - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//���ϵ����㷨	���
void AdjustUp(Heap* php, int n, int chird)
{
	assert(php);
	//���һ������λ�ò���,��Ķ���
	//����������ϵ���
	int parent = (chird - 1) / 2;
	while (chird > 0)
	{
		if (php->_a[chird] > php->_a[parent])//���,�������ϸ�
		{
			swap(&php->_a[chird], &php->_a[parent]);
			chird = parent;
			parent = (chird - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//����
void swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//��ʼ��
void HeapInit(Heap* php, HPDataType* a, int n)
{
	//��̬���鴴��
	php->_a = (HPDataType*)malloc(n * sizeof(HPDataType));
	if (php->_a == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	//�������ݵ���
	memcpy(php->_a, a, n * sizeof(HPDataType));
	php->_capacity = php->_size = n;
	//������
	//�������������������С��
	//�ӵײ㿪ʼ
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		AdjustDown(php, n, root);
		root--;
	}
}
//����
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//�����Ƿ���Ҫ����
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a,php->_capacity * sizeof(HPDataType));
		if (NULL == tmp)
		{
			perror("realloc");
			exit(-1);
		}
		php->_a = tmp;
		tmp = NULL;
	}
	//���뵽��ĩβ,Ȼ�����һ�����ϵ����㷨,�淶��˳��
	//�����²������ֵ,���Ԫ�ط��϶�˳��,����ֻ�ð����Ԫ�����ϵ���
	php->_a[php->_size] = x;
	php->_size++;
	AdjustUp(php, php->_size,php->_size - 1);
}
//����
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	//memmove(php->_a, php->_a + 1, php->_size - 1);
	//php->_size--;
	//����,����ֱ���ƶ�,��ı�ѵ�˳��,���ܵ����ֵܱ丸��

	//����:�����Ѷ������һ��Ԫ��,size--,
	//��һ�����µ����㷨,������˳��
	swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php, php->_size, 0);
}
//��ȡ
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}
//����
void HeapDestroy(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
}


//������
void HeapSort(Heap* php)
{
	assert(php);
	//����,��Сֵ�ڶѶ�,����ֵ��ĩβ����
	//�������һ��ֵ,�ٴ�����,��ѡ���ĶѶ��ǵڶ�С��ֵ,
	//�ظ��������,ֱ���������.

	for (int i = 1; i < php->_size; i++)
	{
		swap(&php->_a[0], &php->_a[php->_size - i]);
		AdjustDown(php, php->_size - i, 0);
	}
}



//����
void print_hello()
{
	printf("hello world\n");
}


