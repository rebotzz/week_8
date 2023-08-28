#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//�鲢����,��������ϰ

//����һ�����������ļ�
void CreatFile()
{
	//���ļ�
	FILE* pf = fopen("BigData", "w");

	//д��
	for (int i = 1005; i >= 0; i--)
	{
		fprintf(pf, "%d\n", i);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//�ļ��鲢�����ӳ���:��fout1,fout2�ļ���ȡ����,һ�߶�ȡһ��˳��д��tmp�ļ�
void _OutMergeSort(char* fout1, char* fout2, char* tmp)
{
	FILE* f1 = fopen(fout1, "r");
	FILE* f2 = fopen(fout2, "r");
	FILE* f3 = fopen(tmp, "w");

	//��Ϊ�ļ�ָ���Զ���ǰ,����ֱ����fscanf()�ķ���ֵ�ж��ļ��Ƿ����
	// (ֱ���ÿ��ܵ����ļ�ָ��ǰ��,���ϴζ�ȡ���ݻ�δʹ�þͱ�����)
	//��fscanf()�ķ���ֵ����ret,����ret�ж�,����Ч�����ļ�ָ���ƶ�
	//���һ���ļ������ݶ�����һ���ļ�С,�ļ�ָ�벻�ÿ�������
	int num1, num2;
	int ret1 = fscanf(f1, "%d\n", &num1);
	int ret2 = fscanf(f2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(f3, "%d\n", num1);
			ret1 = fscanf(f1, "%d\n", &num1);
		}
		else
		{
			fprintf(f3, "%d\n", num2);
			ret2 = fscanf(f2, "%d\n", &num2);
		}
	}

	//��һ���ļ�ʣ�µ�����
	while (ret1 != EOF)
	{
		fprintf(f3, "%d\n", num1);
		ret1 = fscanf(f1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(f3, "%d\n", num2);
		ret2 = fscanf(f2, "%d\n", &num2);
	}

	fclose(f1);
	fclose(f2);
	fclose(f3);
}


//(��)�ļ�����
void OutMergeSort(FILE* pf)
{
	//����ļ�,ֱ���ڴ�������
	//������Ϊ10��
	int arr[100] = { 0 };//��ֺ�����ڴ�
	int i = 0;
	int n = 100; //�ָ���ÿ���ļ��洢n=100������
	char* fname[20];//�ָ���ļ���
	int fileid = 1;	//�ָ���ļ�id���

	while (fscanf(pf, "%d\n", &arr[i]) != EOF)
	{
		if (i < n - 1)//[0 ~ n-2] ��n-1������;������һ�����ݵĴ洢����
		{					//(���һ���ж�fscanf()!= EOF�ִ�����һ����)		
			i++;
		}
		else
		{
			i++;  //i == n
			//���ָ����ļ�����:��������
			QuickSort(arr, 0, n - 1);
			//�����ļ��洢�ָ�������
			sprintf(fname, "%d", fileid++);
			//�����ļ�:��,д��,�ر�
			FILE* fin = fopen(fname, "w");
			for (int j = 0; j < i; j++)
			{
				fprintf(fin, "%d\n", arr[j]);
			}
			fclose(fin);

			//��ʼ��i
			i = 0;
		}
	}

	//��������ݲ���n��ʱ:
	//���ﲻ��i++;���һ�ζ�ȡ�ƺ�������,==EOF�����,Խ��
	sprintf(fname, "%d", fileid++);
	QuickSort(arr, 0, i - 1);
	FILE* fin = fopen(fname, "w");
	for (int j = 0; j < i; j++)
	{
		fprintf(fin, "%d\n", arr[j]);
	}
	fclose(fin);

	//�鲢����
	//��1,2�ļ��鲢Ϊtmp
	//ֱ���鲢�����һ���ļ�
	char* fout1[20];	//�ļ���
	char* fout2[20];
	char* tmp[20];
	sprintf(fout1, "%d", 1);
	sprintf(fout2, "%d", 2);
	sprintf(tmp, "1_%d.tmp", 2);

	FILE* f1 = fopen(fout1, "r");	//�ļ�ָ������
	FILE* f2 = fopen(fout2, "r");
	FILE* f3 = fopen(tmp, "w");		//д
	_OutMergeSort(fout1, fout2, tmp);//�鲢����
	fclose(f1);
	fclose(f2);
	fclose(f3);
	f1 = f2 = f3 = NULL;

	//���ι鲢,ֱ���ָ�����һ���ļ�
	for (int i = 3; i < fileid; i++)
	{
		sprintf(fout1, tmp);	//����һ�ι鲢����ļ���Ϊ��һ�ι鲢�������ļ�֮һ
		sprintf(fout2, "%d", i);
		sprintf(tmp, "1_%d.tmp", i);//�´���һ���ļ�,���ڴ�Ź鲢�������
		_OutMergeSort(fout1, fout2, tmp);//�鲢����
	}
}

int main()
{
	//����һ�����������ļ�
	CreatFile();

	//���ļ�
	FILE* pf = fopen("BigData", "r");

	//�����ļ�
	OutMergeSort(pf);

	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	return 0;
}