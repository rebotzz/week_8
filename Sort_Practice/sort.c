#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//����
void swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//��ӡ����
void arrayPrintf(int* arr, int n)
{
	assert(arr);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}