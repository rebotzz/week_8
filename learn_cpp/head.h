#pragma once
#include <iostream>
#include <assert.h>

extern int size;	//����
static int a = 2;	//����,����ǰ�ļ��ɼ�,���������ű�,��ͬ�ļ��µ��õ�ַ��ͬ,������һ��


//ȱʡ������������ȱʡ
void func(int a, int b = 3);


void test1();

//������:�ֲ�����,����ֲ�û��,�ٵ�ȫ��Ѱ��
//���������,�����Ͷ������
class PART
{
public:
	void print();

private:
	//���Ƕ���,������,������ȱʡֵ,��Ĭ�Ϲ��캯��ʹ��
	int _year = 2023;
	int _month = 7;
	int _date = 7;

};

//ʱ����
class Time
{
public:
	//Ĭ�Ϲ��캯��(��ʼ��)
	Time()
	{
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	//����,ȱʡֵ(Ĭ��ֵ)
	//int _hour = 0;
	//int _minute = 0;
	//int _second = 0;
	int _hour;
	int _minute;
	int _second;
};

//������
class Date
{
public:
	//��ʼ��	->	ȱ��,��������ʹ�� -> ���:���캯��
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//���캯��,����ʵ����ʱ�Զ�����,��ʼ����Ա
	//���Թ�������
	//Ĭ�Ϲ��캯��:1.������,�������Զ�����;2.�Զ����޲ι��캯��;3.�Զ���ȫȱʡ���캯��;
	//�Զ���ȫȱʡ���캯�� -> ���ӷ���
	Date(int year = 0, int month = 0, int day = 0)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;
	}

	//��������,��������ʱ�Զ�����,�����Դ���ͷ�
	//��������
	//�����Զ���,������������Զ�����:1.��������(��������)��������;2.�Զ������͵�������Ӧ����������
	~Date()
	{
		//������ɲ���
	}

	//�������캯��
	//�ǹ��캯��������
	//���ܴ�ֵ,ֻ�ܴ�����,��Ȼ�ᷢ������ݹ�
	//Date(Date d)	//error
	//�����಻��,δ����ʱ�������Զ����ɵľ͹��� ==> ǳ����
	//�Լ�ʵ�� ==> ��� ����:1.ָ��ָ��ͬһ��ַ 2.�ظ�free
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	//��ӡ����
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;	//�Զ���������Ϊ���Աʱ:���������ɵ�Ĭ�Ϲ��캯����������Ĭ�Ϲ��캯��
};




//��: ջ
typedef int StData;
class Stack
{
public:
	//�ӿں���
	// 
	//���캯����ʼ��
	Stack(int capacity = 3)
	{
		std::cout << "Stack" << std::endl;
		StData* tmp = (StData*)malloc(sizeof(StData) * capacity);
		if (nullptr == tmp)
		{
			perror("malloc error");
			exit(-1);
		}
		_a = tmp;
		_capacity = capacity;
		_top = 0;
	}

	//������������ջ
	~Stack()
	{
		std::cout << "~Stack" << std::endl;
		assert(_a);
		free(_a);
		//������������ٶ�����,���Բ�������
		_a = nullptr;
		_capacity = _top = 0;
	}

	//��ջ
	void Push(StData x)
	{
		//��Ȼ�Ҿ����ƺ�����assertҲ��,ʵ��������ͻᴴ��_a,����û��ʵ����
		assert(_a);
		//���ռ��Ƿ��㹻,����������
		Cheak();
		_a[_top] = x;
		_top++;
	}

	//��ջ
	void Pop()
	{
		assert(_a);
		assert(_top > 0);
		_top--;
	}
	//�п�
	bool IsEmpty()
	{
		assert(_a);
		return _top == 0;
	}

	//��С
	int Size()
	{
		assert(_a);
		return _top;
	}
	//��ȡTop
	StData Top()
	{
		assert(_a);
		assert(_top > 0);
		return _a[_top - 1];
	}

protected:
	//���ռ��Ƿ��㹻,����������
	void Cheak()
	{
		if (_capacity == _top)
		{
			_capacity *= 2;
			StData* tmp = (StData*)realloc(_a, sizeof(StData) * _capacity);//�����˳�sizeof(StData)
			if (nullptr == tmp)
			{
				perror("realloc error");
				exit(-1);
			}
			_a = tmp;
			tmp = nullptr;
		}
	}

private:
	//��̬��ֵʵ��
	StData* _a;
	int _capacity;
	int _top;
};



//��: ����(����ջʵ�ֶ���)
class MyQueue
{
public:
	void print()
	{
		s1.Push(1);
		std::cout << s1.Size() << std::endl;
	}
private:
	Stack s1;
	Stack s2;
};