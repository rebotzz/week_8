#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

//�鲢����,��������ϰ

//����һ�����������ļ�
void CreatFile()
{
	//���ļ�
	FILE* pf = fopen("BigData", "w");

	//д��
	for (int i = 100000; i >= 0; i--)
	{
		fprintf(pf, "%d\n", i);
	}
	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//���ļ�����
void OutMergeSort(FILE* pf)
{

}

int main()
{
	//����һ�����������ļ�
	CreatFile();
	//���ļ�
	FILE* pf = fopen("BigData", "r");

	//����ļ�,ֱ���ڴ�������
	//������Ϊ10��
	int arr[10000] = { 0 };
	int i = 0;
	FILE* begin = pf;

	//fseek(pf, 0, SEEK_SET);
	//printf("%d\n", ftell(pf));
	////fseek(pf, 0, SEEK_END);
	//printf("%d\n", ftell(pf));

	while (fscanf(begin,"%d\n",&arr[i]	) != EOF)
	{
		//
		printf("%d\n", ftell(pf));
		system("pause");
		//fseek(pf, -1, SEEK_CUR);
		printf("%d\n", ftell(pf));

	}




	//�鲢����


	//�ر��ļ�
	fclose(pf);
	pf = NULL;

	return 0;
}