#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//inline ������������꺯��
//auto �Զ�ʶ������,��Χfor
//struct class public private protected ��/��װ ��Ա����,��Ա����

#define ADD(x,y) ((x)+(y))


inline int add(int x, int y)
{
	return x + y;
}



//int main()
//{
//	int arr[100];
//	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		arr[i] = i;
//	}
//	
//	for (auto& e : arr)
//	{
//		e++;
//	}
//
//	//��Χfor
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//typedef char* pstring;
//int main()
//{
//	const pstring p1 ;    // ����ɹ�����ʧ�ܣ�
//	const pstring* p2;   // ����ɹ�����ʧ�ܣ�
//	return 0;
//}


//int main()
//{
//	cout << NULL << endl;
//	printf("%p\n", nullptr);
//	int a = 0;
//	cout << &a << endl;
//	return 0;
//}