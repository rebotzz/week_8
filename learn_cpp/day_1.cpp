#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

//using std::cout;
//using std::cin;
//using std::endl;
////������
//namespace rebotzz
//{
//	int a = 0;
//	int b = 3;
//	float c = 12.54;
//	struct SeqL
//	{
//		int* _arr;
//		int _size;
//		int _capacity;
//	};
//	void Fun()
//	{
//		cout << "hello, this is in namespace rebotzz" << endl;
//	}
//}
//
//int main()
//{
//	std::cout << "hellow world!" << std::endl;
//	int a = 3;
//	float b = 2.5;
//	cout << a << " " << b << endl;
//	cin >> a >> b;
//	cout << a << " " << b << endl;
//	rebotzz::Fun();
//	cout << rebotzz::a << endl;
//	return 0;
//}

//��������
int add(int a, int b)
{
	return a + b;
}

float add(double a, float b)
{
	return a + b;
}

//���÷���
int& func2()
{
	int* n = (int*)malloc(sizeof(int));
	assert(n);
	*n = 5;
	return *n;
}

int main()
{
	cout << add(4, 8) << endl;
	cout << add(2.2453, 5.6) << endl;

	//����
	int b = 4;
	int& bb = b;
	cout << b++ << endl;
	cout << bb << endl;

	int& nn = func2();
	cout << ++nn << endl;
	free(&nn);
	cout << nn << endl;


	return 0;
}

