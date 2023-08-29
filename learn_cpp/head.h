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

	//��ֵ�����=
	Time& operator=(const Time& t)
	{
		if (this != &t)
		{
			_hour = t._hour;
			_minute = t._minute;
			_second = t._second;
		}
		//std::cout << "Time& operator=(Time& t)" << std::endl;

		return *this;
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

	//Date()//����,����ʧ��,��ȫȱʡ��ͻ ==>������Ĭ�Ϲ��캯��
	//{
	//}

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
	// ���÷�������,���󴴽�ʱthisָ����
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

	//==��������� ==>��Ա����
	//��������;�������Ա����˽��,Ҳ���Է���
	//bool operator == (Date* const this, const Date& d)
	bool operator == (const Date& d);

	//��ֵ= ���������
	//��ֵ������������ʽʵ�֣�������������һ��Ĭ�ϵ� ==>ǳ����
	Date& operator=(Date& d);

	//���������	ǰ��++
	//Date& const thisָ��
	//������,�������÷���,���Ч��
	Date& operator++();

	//���������	����++	��(int)����ǰ��++
	//Date& const thisָ��
	//tmp,ջ�Ͼֲ�����,������������,���Դ�ֵ����
	Date operator++(int);

	//��Ա�����������������
	//
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);

	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();

	// >���������
	bool operator>(const Date& d);

	// >=���������
	bool operator >= (const Date& d);

	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);


//protected:
	//��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month)
	{
		//ÿ������,����,static
		static int mday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//�ж�ʱ��������2��:����%4,!%100,%400
		if (month == 2
			&& (year % 4 == 0) && (year % 100 != 0) && (year % 400 == 0))
		{
			return 29;
		}
		else
		{
			return mday[month];
		}
	}

	//�ж������Ƿ�Ϸ�,�Ƿ���Ҫ��λ:����Ҫ,���λ
	//ע������this-> �� d.
	void CheckValidDay(Date& d)
	{
		int day = GetMonthDay(d._year, d._month);
		//�Ϸ�
		if (d._day <= day && d._day > 0)	//��������û��0
		{
			return;
		}
		else
		{
			//����,ֱ�����ںϷ�
			while (d._day > day)//����Ǽ�������,д���ǽ�������
			{
				//��
				d._day -= day;
				d._month++;
				//��
				if (d._month > 12)
				{
					d._month -= 12;
					d._year++;
				}
				day = GetMonthDay(d._year, d._month);
			}

			while (d._day <= 0)
			{
				//��
				d._month--;
				if (d._month <= 0)	//û��0��,����֮������"="�ܱ���ɹ�,
				{					//����Ϊÿ��������������0�¶�Ӧ0��,���Զ�����ûӰ��
					d._year--;
					d._month = 12;
				}
				//��
				day = GetMonthDay(d._year, d._month);
				d._day += day;	// (-15) + 30 = 15
			}
		}
	}

	//��ȡ��ǰʱ�����0/0/0��Ԫ0�������
	int GetSumDay(const Date& d);

private:
	//��������
	int _year;
	int _month;
	int _day;
	//�Զ�������
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

	//�������캯��	==> ���
	Stack(const Stack& s)
	{
		StData* tmp = (StData*)realloc(this->_a, sizeof(StData) * s._capacity);//realloc������ԭ�ռ�
		if (nullptr == tmp)
		{
			perror("Stack(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
	}

	//������������ջ
	~Stack()
	{
		std::cout << "~Stack:" << this << std::endl;
		assert(_a);
		free(_a);
		//������������ٶ�����,���Բ�������
		_a = nullptr;
		_capacity = _top = 0;
	}

	//��ջ
	void Push(const StData& x)	//�Ż�:StData x ==> const StData& x
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

	//����Դ����(������Դmalloc),��Ҫ�Զ��帳ֵ���������
	Stack& operator=(const Stack& s)
	{
		StData* tmp = (StData*)realloc(_a, sizeof(StData) * s._capacity);//realloc������ԭ�ռ�
		if (nullptr == tmp)
		{
			perror("Stack& operator=(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			//std::cout << "_a:" << _a << std::endl;
			//free(_a);//realloc������ԭ�ռ�
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
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


//ȫ��
//bool operator == (const Date& d1, const Date& d2);