//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include "head.h"
//using namespace std;
//
//
//
////����С����
////���ƽṹ���С,�ж������
////���Ա�����������С����,����ڹ��������
////����Ĵ�СΪ1�ֽ�,Ŀ��:������ַ
//// 
////���:��������ջ֡ҲҪ�����С.������ռ�ռ��С
////����ܾ���arr[]�ڿ��ٵĺ���������sizeof�����С(int(*p)[count]����ָ��),
////���Ǵ��ݸ���ĺ���ȴֻ��int*ָ��,���㲻�˴�С,һ������
////��ȻҲ����������ָ����int*��ԭ��
//
//class S1
//{
//public:
//	void print(const char* str = "hello world.")
//	{
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//		cout << str << endl;
//
//	}
//
//private:
//	int b;
//	char a;
//	char c;
//
//};
//
//class S2
//{
//public:
//	void func()
//	{
//		cout << "S2:func" << endl;
//	}
//};
//
//class S3
//{
//
//};
//
////��Ĵ�С����
//void Test1()
//{
//	cout << sizeof(S1) << endl;
//	cout << sizeof(S2) << endl;
//	cout << sizeof(S3) << endl;
//}
//
////��ʵ��������
//void Test2()
//{
//	S1 a;
//	S1 b;
//	//a.print("1231");
//	//b.print();
//
//	S1* ps;
//	ps = nullptr;
//	ps->print();
//
//	//��С�˲���
//	//��ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĸߵ�ַ�У������ݵĸ�λ���������ڴ�ĵ͵�ַ�У�
//	//С�ˣ��洢��ģʽ����ָ���ݵĵ�λ�������ڴ�ĵ͵�ַ�У������ݵĸ�λ, ���������ڴ�ĸߵ�ַ�С�
//	int n = 1;
//	char* pn = (char*)&n;
//	printf("%d\n", *pn);
//	if (*pn == 1)
//	{
//		cout << "С��" << endl;
//	}
//
//}
//
//
////���������,�����Ͷ������
//void Test3()
//{
//	PART p;
//	p.print();
//}
//
//
//
////��� thisָ��
////�������ֲ�ͬ��ʵ��������
//void Test4()
//{
//	class S
//	{
//	public:
//		//���캯��,��ʼ��
//		S(int a = 0, int b = 0, int c = 0)
//		{
//			_a = a;
//			_b = b;
//			this->_c = c;
//		}
//
//		//��������,��������ʱ�ͷ���Դ
//		~S()
//		{
//			//Ŀǰ:��malloc,fopen,����
//			cout << this<<"->"<<"~S" << endl;
//		}
//
//		//�������캯��
//		S(const S& src)
//		{
//			this->_a = src._a;
//			this->_b = src._b;
//			//thisָ�����ʡ�Բ�д,�Ͼ���thisָ�������
//			_c = src._c;
//		}
//
//		//this
//		void printThis()
//		{
//			//this = nullptr; //thisָ�����const����,���ܸ���
//			cout << this << endl;
//			cout << this->_a << endl;
//			cout << (*this)._b << endl;
//			cout << _c << endl << endl;
//		}
//
//
//	private:
//		int _a;
//		int _b;
//		int _c;
//	};
//
//
//	S n1(1,2,3);
//	S n2;
//	S n3(1, 2);
//	S n4(n1);
//
//	n1.printThis();
//	n2.printThis();
//	n3.printThis();
//	n4.printThis();
//}
//
//void get(Date d)
//{
//	d.print();
//}
//
//void Test5()
//{
//	Date d1;
//	Date d2(2023, 8, 26);
//	Date d3 = d2;
//	d1.print();
//	d1.Init(2000, 2, 5);
//	cout << endl;
//	d1.print();
//	d2.print();
//	d3.print();
//
//	Date d(d1);
//	cout << "d:";
//	d.print();
//	get(d);
//
//}
//
//
//void TestStack()
//{
//	Stack s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	while (!s.IsEmpty())
//	{
//		cout << s.Top() << " ";
//		s.Pop();
//		//cout << s.Size() << endl;
//	}
//}
//
//
//void TestMyqueue()
//{
//	MyQueue q;
//	q.print();
//}
//
////int main()
////{
////	//Test1();
////	//Test2();
////	//Test3();
////	//Test4();
////	Test5();
////	//TestStack();
////	//TestMyqueue();
////
////	return 0;
////}