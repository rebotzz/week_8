#define _CRT_SECURE_NO_WARNINGS
#include "MySort.h"
#include "stack.h"

//ֱ�Ӳ�������	ʱ�临�Ӷ�O(N^2);�ռ临�Ӷ�O(1)
//void InsertSort(int* arr, int n)
//{
//	assert(arr);
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		int end = i;
//		//�ƺ�����,��Ȼ��������,���ⲻ�ǲ���������
//		while (arr[end] > arr[end + 1] && end >= 0)
//		{
//			swap(&arr[end], &arr[end + 1]);
//			end--;
//		}
//	}
//}

//2.0
//ֱ�Ӳ�������	ʱ�临�Ӷ�O(N^2);�ռ临�Ӷ�O(1)
void InsertSort(int* arr, int n)
{
	assert(arr);//��ָ�����
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int key = arr[end + 1];
		//�ҵ���keyС��λ��
		while (arr[end] > key && end >= 0)
		{
			//��key��,һ�κ���,Ϊ����key����λ��
			arr[end + 1] = arr[end];
			end--;
		}
		//��key���뵽end��һλ
		arr[end + 1] = key;
	}
}

//ϣ������	ֱ�Ӳ������� + Ԥ����
//���Ϊgap�ķ�������,���鲢��;
//ֱ�Ӳ�������ȼ���gap = 1��ϣ������;
//1.0
//void ShellSort(int* arr, int n)
//{
//	int gap = n;
//
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;//+1Ϊ�˱�֤���һ��gap = 1,���һ�εȼ���ֱ�Ӳ�������;
//		for (int i = 0; i < n - gap; i++)
//		{
//			int end = i;
//			while (arr[end] > arr[end + gap] && end >= 0)
//			{
//				swap(&arr[end], &arr[end + gap]);//��������Ż�,���ý������񽻻�����,�����������
//				end -= gap;
//			}
//		}
//	}
//}

//2.0	ʱ�临�Ӷ�O(N^1.3) ~ O(N^2);�ռ临�Ӷ�O(1)
void ShellSort(int* arr, int n)
{
	assert(arr);
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1Ϊ�˱�֤���һ��gap = 1,���һ�εȼ���ֱ�Ӳ�������;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int key = arr[end + gap];//����arr[end + gap],����arr[end + gap]�Ϳ��Ա�����,�����ڿӷ�
			while (end >= 0)
			{
				if (arr[end] > key)//ֻҪ��key��,���������Ų��
				{
					arr[end + gap] = arr[end];//���Ų��,����arr[end + gap]
					end -= gap;
				}
				else
				{
					break;
				}
			}
			//��ʱarr[end]С�ڵ���key,key��ֵ���Է���end����һλ
			arr[end + gap] = key;
		}
	}
}



//ѡ������
//ֱ��ѡ������	ʱ�临�Ӷ�O(N^2)	�ռ临�Ӷ�O(1)
//1.0
//void SelectSort(int* arr, int n)
//{
//	//����һ������,�ҵ���Сֵ,����ֵǰ�˽���
//	for (int i = 0; i < n; i++)
//	{
//		int begin = i;
//		int end = n - 1;
//		int mini = begin;//��Сֵ���±�
//		while (begin <= end)
//		{
//			if (arr[begin] < arr[mini])
//			{
//				mini = begin;
//			}
//			begin++;
//		}
//		//������Сֵ����ֵǰ��
//		swap(&arr[i], &arr[mini]);
//	}
//}

//2.0	ʱ�临�Ӷ� O(N^2)	�ռ临�Ӷ�O(1)
void SelectSort(int* arr, int n)
{
	assert(arr);
	//����һ������,�ҵ���Сֵ,���ֵ,����ֵǰ��,��˽���
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int left = begin, right = end;//�ƶ�left��right,���ı�begin,end�±�
		int mini = begin, maxi = begin;//��Сֵ���±�,���ֵ���±�
		//������ֵ,�ҵ����ֵ����Сֵ
		while (left < right)
		{
			if (arr[left] < arr[mini])
			{
				mini = left;
			}
			if (arr[left] > arr[maxi])
			{
				maxi = left;
			}
			left++;
		}   
		//������Сֵ
		swap(&arr[begin], &arr[mini]);
		if (begin == maxi)//��maxi��begin�ص�ʱ,maxiλ�ñ�������miniλ��
		{
			maxi = mini;
		}
		//�������ֵ
		swap(&arr[end], &arr[maxi]);

		//���˵��±�ı�
		begin++;
		end--;
	}
}

//������
//���µ����㷨
void AdjustDown(int* arr,int root,int n)
{
	assert(arr);
	//������,���������Ǵ��,���ڵ㲻�ǵ����;
	while (root < n)
	{
		//�ҳ����Һ����еĸ�����,����ڵ㽻��
		int chird = 2 * root + 1;
		if (chird + 1 < n && arr[chird + 1] > arr[chird])
		{
			chird++;
		}
		//�������ϸ�
		if (chird < n && arr[chird] > arr[root])
		{
			swap(&arr[chird], &arr[root]);
			root = chird;
		}
		//û�бȸ��ڵ�����,���ڵ��³���ֹ
		else
		{
			break;
		}
	}
}

//������	ʱ�临�Ӷ� O(N*logN)	�ռ临�Ӷ�O(1)
void HeapSort(int* arr, int n)
{
	assert(arr);
	//�����¿��ٿռ�,ֱ����ԭ��ֵ�Ͻ���
	
	//���¶��Ͻ���;����,�������;
	int chird = n - 1;
	int root = (chird - 1) / 2;
	while (root >= 0)
	{
		//���µ����㷨
		AdjustDown(arr, root, n);
		root--;
	}
	//����:���Ѷ����ֵ��ĩβ����,�ų����ֵ���ڵ�ĩβ,���µ�����,ɸѡ�������,ѭ��
	for (int i = 0; i < n - 1; i++)
	{
		swap(&arr[0], &arr[n - 1 - i]);
		AdjustDown(arr, 0, n - 1 - i);//�ų����ֵ���ڵ�ĩβ
	}
}




//��������
// 
//ð������
void BubbleSort(int* arr, int n)
{
	assert(arr);

	//forѭ���汾
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i -1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}
//void BubbleSort(int* arr, int n)
//{
//	//whileѭ���汾
//	int i = 0;
//	while (i < n - 1)
//	{
//		int j = 0;
//		while (j < n - 1 - i)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//			}
//			j++;
//		}
//		i++;
//	}
//}
 


//��������
//����ȡ��
int GetMidNumber(int* arr, int begin, int end)
{
	int left = begin;
	int mid = (begin + end) / 2;
	int right = end;

	if (arr[left] > arr[mid])
	{
		if (arr[mid] > arr[right])
		{
			return mid;
		}
		else if(arr[right] > arr[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}

	else // mid => left
	{
		if (arr[right] > arr[mid])
		{
			return mid;
		}
		else if (arr[left] > arr[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//��������
//����ѭ��,�ڿӷ�
int SortPart1(int* arr, int begin, int end)
{
	//����ȡ��,������м��С�����������ұ�,��keyȡΪ��׼
	int mid = GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);

	assert(arr);
	//ѡ���ұ�Ϊkey
	int key = arr[end];
	int tmp = end;	//�ڿ�,��ʼ��

	while (begin < end)
	{
		//ѡ�ұ�Ϊ��ʼ��,����߿�ʼ��
		//����߿�ʼ,�ҵ����ڵ���key��ֵ
		while (arr[begin] <= key && begin < end)
		{
			begin++;
		}
		if (arr[begin] > key && begin < tmp)//&& begin < tmp
		{
			arr[tmp] = arr[begin];//���
			tmp = begin;		  //���ڵĿ�
			begin++;
		}

		while (arr[end] >= key && begin < end)
		{
			end--;
		}
		if (arr[end] < key && tmp < end)//&& tmp < end; ���begin��endͬʱָ�����С��key,���Խ��������
		{
			arr[tmp] = arr[end];
			tmp = end;
			end--;
		}
	}

	//key����Ŀ�
	arr[tmp] = key;
	return tmp;
}


//��������
//����ѭ��,ǰ��ָ�뷨
int SortPart2(int* arr, int begin, int end)
{
	//����ȡ��,������м��С�����������ұ�,��keyȡΪ��׼
	int mid = GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);

	int key = arr[end];
	int cur = begin;
	int prev = begin - 1;
	while (cur <= end)
	{
		//curָ���ұ�keyС,�ҵ���keyС,prev++,��С�����ֵ������prev
		//����������ͷ,cur�Ǳ�key������Ļ�ͷ;prev��С�ڵ���key���ֵĻ�ͷ
		//����ѡ�ұ�Ϊkey,����cur��prev����߿�ʼ
		while (arr[cur] > key && cur <= end)//����ǽ���������,д���Ǽ���������
		{
			cur++;
		}
		if (arr[cur] <= key && cur <= end)
		{
			swap(&arr[++prev], &arr[cur]);
			cur++;//����֮��cur��Ҫ++
		}
	}

	return prev;
}

//��������
//����ѭ��,����ָ�뷨
int SortPart3(int* arr, int begin, int end)
{
	//��׼�����ұ�
	//��ָ���ҵ���key���ʱ��ͣ��,��ָ���ұ�keyС��ʱ��ͣ��
	//Ȼ�󽻻�����ָ��ָ����ֵ
	//��ָ������,�������ָ������λ�õ���ֵ��key��,���ÿ�����key����

	//����ȡ��,��������,����
	int mid =  GetMidNumber(arr, begin, end);
	swap(&arr[mid], &arr[end]);
	int key = arr[end];
	int left = begin;
	int right = end - 1;
	// left ... right key

	while (left < right)//left < right;��д��,����left < end
	{
		//��ָ���Ҵ�
		while (arr[left] <= key && left < right)//����key��������ù�,֮������ϸ�ֵ�ʱ����ڵľͱ����ֵ,������
		{
			left++;
		}
		//��ָ����С
		while (arr[right] >= key && left < right)
		{
			right--;
		}
		//����
		if (arr[left] > key && arr[right] < key)
		{
			swap(&arr[left], &arr[right]);
			//left++;
			//right--;
		}
	}
	//����key������ָ��������
	swap(&arr[left], &arr[end]);

	return left;
}

//��������
//ѡ��һ����׼ֵkey,��keyС�ķ������,��key��ķ����ұ�
//Ȼ��������ߺ��ұ�,���������
//ֱ�������ٷָ�
// 1.0	ʱ�临�Ӷ�O(N*logN)		�ռ临�Ӷ�O(logN),�ݹ�����
void QuickSort(int* arr, int begin, int end)
{
	assert(arr);
	//�ݹ��������,���䲻���ٷ�
	if (begin >= end)
	{
		return;
	}

	//С�����Ż�,���ٵݹ����
	//����[arr + begin ,arr + end]���������
	if (end - begin + 1 < 10)
	{
		//ֱ�Ӳ�������
		InsertSort(arr + begin, end - begin + 1);//ע��:����������Ǵ�arr + begin��ʼ,������arr,arrһֱ����
		//arrayPrintf(arr + begin, end - begin + 1);
		//printf("Insert\n");
		return;
	}

	//�ݹ�,����;�������ߺ��Ұ��
	int div = SortPart3(arr, begin, end);
	//arrayPrintf(arr + begin, end - begin + 1);
	//printf("%d\n", div);
	QuickSort(arr, begin, div - 1);
	QuickSort(arr, div + 1, end);
}


////2.0	��������,�����Ӻ����汾
//void QuickSort(int* arr, int begin, int end)
//{
//	assert(arr);
//	//�ݹ��������,���䲻���ٷ�
//	if (begin >= end)
//	{
//		return;
//	}
//
//	//�ݹ�,����;�������ߺ��Ұ��
//	int mid = GetMidNumber(arr, begin, end);
//	swap(&arr[mid], &arr[end]);
//	//ѡ���ұ�Ϊkey
//	int key = arr[end];
//	int tmp = end;	//�ڿ�,��ʼ��
//	int left = begin, right = end;
//
//	while (left < right)
//	{
//		//ѡ�ұ�Ϊ��ʼ��,����߿�ʼ��
//		//����߿�ʼ,�ҵ����ڵ���key��ֵ
//		while (arr[left] <= key && left < right)
//		{
//			left++;
//		}
//		if (arr[left] > key)
//		{
//			arr[tmp] = arr[left];//���
//			tmp = left;		  //���ڵĿ�
//			left++;
//		}
//
//		while (arr[right] >= key && left < right)
//		{
//			right--;
//		}
//		if (arr[right] < key)
//		{
//			arr[tmp] = arr[right];
//			tmp = right;
//			right--;
//		}
//	}
//	arr[tmp] = key;
//
//	int div = tmp;
//	QuickSort(arr, begin, div - 1);
//	QuickSort(arr, div + 1, end);
//}



//3.0 ��������(�ǵݹ�) 1.0
//void QuickSortNonR(int* arr, int begin, int end)
//{
//	assert(arr);
//	assert(begin <= end);
//
//	stack s;
//	StackInit(&s);
//
//	//����ջģ��ݹ�,����;�������ߺ��Ұ��
//	int div = SortPart1(arr, begin, end);
//
//	//���ֻ����������ջ
//	StackPush(&s, div + 1);
//	StackPush(&s, end);
//	StackPush(&s, begin);
//	StackPush(&s, div - 1);
//	
//	while (!StackEmpty(&s))
//	{
//
//		int end1 = StackTop(&s);
//		StackPop(&s);
//		int begin1 = StackTop(&s);
//		StackPop(&s);
//
//		//������仹�ֻܷ�,�����ֻ�,����,����ջ;
//		//���ܾͲ�����ջ,��ջΪ��,�������
//		if (begin1 < end1)
//		{
//			div = SortPart1(arr, begin1, end1);
//			StackPush(&s, div + 1);
//			StackPush(&s, end1);
//			StackPush(&s, begin1);
//			StackPush(&s, div - 1);
//		}
//	}
//
//	//������freeջ
//	StackDestroy(&s);
//}


//3.0 ��������(�ǵݹ�)	2.0
void QuickSortNonR(int* arr, int begin, int end)
{
	assert(arr);
	//assert(begin < end);

	stack s;
	StackInit(&s);
	//[begin,end]
	StackPush(&s, end);
	StackPush(&s, begin);
	
	while (!StackEmpty(&s))
	{
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);

		//�������ݿ�ջģ��ݹ�,����;�������ߺ��Ұ��
		int div = SortPart1(arr, left, right);
		//[left , div - 1] div [div + 1,right]
		if (div + 1 < right)
		{
			StackPush(&s, right);
			StackPush(&s, div + 1);
		}
		if (left < div - 1)
		{
			StackPush(&s, div - 1);
			StackPush(&s, left);
		}
	}

	//������freeջ
	StackDestroy(&s);
}




//�鲢����,�ӳ���
void _MergeSort(int* arr, int* tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	//����:[begin,  mid]   [mid + 1 ,end] 
	//	   [begin1,end1]   [begin2,end2]	
	int mid = (begin + end) / 2;
	int begin1 = begin, end1 = mid;//��mid����mid - 1,��Ϊ�˱���mid - 1С��begin;
	int begin2 = mid + 1, end2 = end;//mid + 1 <= end
	_MergeSort(arr, tmp, begin1, end1);
	_MergeSort(arr, tmp, begin2, end2);

	int index = begin1;
	int cpyIndex = begin1;
	//��������������ѡ��С�����δ���tmp
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}

	//����һ���������,����һ��������ܻ�������
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}

	//��tmp�����������ݿ�����ԭ����
	for (int i = cpyIndex; i <= end2; i++)
	{
		arr[i] = tmp[i];
	}

	//arrayPrintf(arr, 6);
}

//�鲢����	������(Ҳ����������),���������,����Ӳ��
void MergeSort(int* arr, int n)
{
	assert(arr);
	//���ٿռ�,������ʱ�洢�鲢������
	int* tmp = (int*)malloc(n * sizeof(int));
	//�����������˼��
	_MergeSort(arr, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

















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