#define _CRT_SECURE_NO_WARNINGS
#include "head.h"
using namespace std;

void test1()
{
	Date d1(2023, 5, 2);
	Date d2(2023, 5, 2);
	cout << (d1 == d2) << endl;
	Date d3 = d1;
	d3.print();

	//Ĭ�����ɵ�ֻ��ǳ����
	Stack s1;
	s1.Push(1);
	s1.Push(2);

	////ע�⣺�������δ�漰����Դ������ֵ������Ƿ�ʵ�ֶ����ԣ�
	////	һ���漰����Դ���������Ҫʵ�֡�
	Stack s2;
	s2 = s1;	//main��������,��������,��������,�ظ�free

	Stack s3(s1);
}

void test2()
{
	Date d1(2023, 5, 6);
	d1.print();
	++d1;
	d1.print();

	d1++.print();
	d1.print();
	Date d2 = d1;
	cout << (d2 == d1) << endl;
	cout << "d2:";
	d2.print();

	d1 += 31;
	d1.print();

	Date d3 = (d1 + 60);
	cout << "d3:";
	d3.print();
	cout << "d1:";
	d1.print();

	Date d4 = d1 - 365;
	cout << "d4:";
	d4.print();

	//d4 -= 50;
	//cout << "d4:";
	//d4.print();

	//cout << "d4:";
	//d4--.print();
	//d4.print();

	//--d4;
	//cout << "d4:";
	//d4.print();

	Date d5(1000, 1, 1);
	cout << "d5:";
	d5.print();
	//(--d5);
	//d5.print();

	//d2 = d1;
	cout << (d1 != d2) << endl;

	Date d6(2001,1,1);
	Date d7(2000,1,1);
	d7.print();
	int day = d6 - d7;
	cout << "day:" << day << endl;


	Date t1(2000, 3, 1);
	Date t2(2000, 2, 1);
	cout << "day:" << (t1 - t2) << endl;

}

int main()
{
	//test1();
	test2();

	return 0;
}

