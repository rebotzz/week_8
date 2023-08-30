#define _CRT_SECURE_NO_WARNINGS
#include"head.h"


//void test1()
//{
//	cout << "common:a:" << &a << " " << a << endl;
//}


////���������,�����Ͷ������
//void PART::print()
//{
//	cout << _year << "-" << _month << "-" << _date << endl;
//}


////��������� ==> ȫ��
////ȫ��	==> ��Ҫ�������Ա����,ȡ�������޶�
//bool operator == (const Date& d1, const Date& d2)
//{
//	return d1._day == d2._day
//		&& d1._month == d2._month
//		&& d1._year == d2._year;
//}


//����==����
bool Date::operator == (const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//����=����
Date& Date::operator=(const Date& d)	//const,���ӽ��ܷ�Χ:������ʱ�ı���,���г�����
{
	cout << "Date& operator=(Date& d)" << endl;
	//�����Լ����Լ���ֵ���
	if (this != &d)
	{
		_day = d._day;
		_month = d._month;
		_year = d._year;
	}

	return *this;
}

//++����
Date& Date::operator++()
{
	if (this != nullptr)
	{
		this->_day++;
	}
	return *this;
}

//����++
Date Date::operator++(int)
{
	Date tmp(*this);
	this->_day++;
	return tmp;
}

//��Ա�����������������
// ����+=����
// d1 += 15;
Date& Date::operator+=(int day)
{
	//�޸�d1,����d1
	this->_day += day;
	CheckValidDay(*this);
	return *this;
}
// ����+����
// d2 = d1 + 200;
//tmp��ʱ����������,���Է���ֵ
Date Date::operator+(int day)
{
	//ԭ����d1����,���ؼ��������d2
	Date tmp(*this);
	tmp._day += day;
	CheckValidDay(tmp);
	return tmp;
}

//����-����
//d2 = d1 - 15
Date Date::operator-(int day)
{
	//d1����,��this����,�����޸ĺ���
	Date tmp(*this);
	tmp._day -= day;
	CheckValidDay(tmp);
	return tmp;
}
// ����-=����
// d1 -=15;
Date& Date::operator-=(int day)
{
	//��d1(thisָ��)���޸�,����d1
	this->_day -= day;
	CheckValidDay(*this);
	return *this;
}

// ����--
//d1--
Date Date::operator--(int)
{
	//this,�����޸�ǰ��ֵ
	Date tmp(*this);
	this->_day--;
	CheckValidDay(*this);
	return tmp;
}

// ǰ��--
//--d1
Date& Date::operator--()
{
	//this,�����޸ĺ��ֵ
	--(this->_day);
	CheckValidDay(*this);
	return *this;
}

// >���������
// d2 > d1
bool Date::operator>(const Date& d)
{
	//this > d
	//�� 
	if (this->_year > d._year)
	{
		return true;
	}
	else if (this->_year < d._year)
	{
		return false;
	}
	else	//�����
	{
		//�� 
		if (this->_month > d._month)
		{
			return true;
		}
		else if (this->_month < d._month)
		{
			return false;
		}
		else	//�����
		{
			//��
			if (this->_day > d._day)
			{
				return true;
			}
			else if (this->_day < d._day)
			{
				return false;
			}
			else  //�����ն����
			{
				return false;
			}
		}
	}
}

// >=���������
// d1 >= d2
bool Date::operator >= (const Date& d)
{
	//this >= d  ==>  this > d �� this == d
	return (*this == d) || (*this > d);
}

// <���������
//d1 < d2
bool Date::operator < (const Date& d)
{
	//this ��>= d
	return !(*this >= d);
}

// <=���������
//d1 <= d2
bool Date::operator <= (const Date& d)
{
	//this <= d	==> this < d �� this == d
	return (*this < d) || (*this == d);
}
// !=���������
//d1 != d2
bool Date::operator != (const Date& d)
{
	//this != d
	return !(*this == d);
}

// ����-���� ��������
// day = d2 - d1	Ĭ��d2����d1
// 15 = 2023-5-30 - 2023-5-15
int Date::operator-(const Date& d)
{
	//this - d
	int day = GetSumDay(*this) - GetSumDay(d);
	return day;
}

//��ȡ��ǰʱ�����0/1/1��Ԫ0������� ==> �Ż�:���2000/1/1
//��ͼ:ʱ����,2�·ֽ�
int Date::GetSumDay(const Date& d)	//bug:������һ��û�м��� ==> ���޸�
{
	Date tmp(d);
	int sumday = 0;

	//1.0	�����ۼ�����+ʣ����ɢ����
	//int sumday += tmp._day;
	//while (tmp._year >= 0)
	//{
	//	//��һ������:ǰ��һ����,���ڸ�ʽ�Ϸ���,�Ӻʹ�������
	//  
	//	tmp._month--;
	//	if (tmp._month <= 0)	//û��0��
	//	{
	//		tmp._year--;
	//		tmp._month = 12;
	//	}
	//	if (tmp._year >= 0)
	//	{
	//		sumday += GetMonthDay(tmp._year, tmp._month);
	//	}
	//}

	//2.0	�����ۼ�����+ʣ���·�����+ʣ����ɢ����
	//���2000/1/1
	while (tmp._year > 2000)
	{
		//��2000�����ǰ
		//�·�С�ڵ���2��:ǰ����ܿ�����	�·ݴ��ڶ���:������ܿ�����
		if (tmp._month <= 2)
		{
			if (((tmp._year - 1) % 4 == 0) && ((tmp._year - 1) % 100 != 0) || ((tmp._year - 1) % 400 == 0))
			{
				sumday += 366;
			}
			else
			{
				sumday += 365;
			}
		}

		if (tmp._month > 2)
		{
			if ((tmp._year % 4 == 0) && (tmp._year % 100 != 0) || (tmp._year % 400 == 0))
			{
				sumday += 366;
			}
			else
			{
				sumday += 365;
			}
		}

		tmp._year--;
	}

	while (tmp._year < 2000)
	{
		//��2000����ǰ��
		//�·�С�ڵ���2��:������ܿ�����	�·ݴ��ڶ���:������ܿ�����
		if (tmp._month <= 2)
		{
			if ((tmp._year % 4 == 0) && (tmp._year % 100 != 0) || (tmp._year % 400 == 0))
			{
				sumday -= 366;
			}
			else
			{
				sumday -= 365;
			}
		}

		if (tmp._month > 2)
		{
			if (((tmp._year + 1) % 4 == 0) && ((tmp._year + 1) % 100 != 0) || ((tmp._year + 1) % 400 == 0))
			{
				sumday -= 366;
			}
			else
			{
				sumday -= 365;
			}
		}

		tmp._year++;
	}

	if (tmp._year == 2000)
	{
		//+ʣ����ɢ����
		sumday += tmp._day;
		tmp._month--;
		//+ʣ���·�����
		while (tmp._month >= 1)
		{
			sumday += GetMonthDay(tmp._year, tmp._month);
			tmp._month--;
		}
	}

	return sumday;
}




//�ж������Ƿ�Ϸ�,�Ƿ���Ҫ��λ:����Ҫ,���λ
//ע������this-> �� d.
void Date::CheckValidDay(Date & d)
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