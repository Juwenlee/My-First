/*************************************************************************
    > File Name: a.cpp
    > Author: Lee
    > Mail: 825526448@qq.com
    > Created Time: Thu 06 Sep 2018 10:47:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include "a.h"

// 基础类
Stock::Stock()
{
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	company = co;

	if(n < 0)
	{
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout << "----Bye, " << company << "\n";
}

void Stock::set_tot()
{
	total_val = share_val;
}

void Stock::show()
{
	std::cout << "	company: " << company << "\n";
	std::cout << "	shares : " << shares << "\n";
	std::cout << "	share_val: " << share_val << "\n";
	std::cout << "	total_val: " << total_val << "\n";

	return;
}

const Stock & Stock::compare(const Stock &cmp) const
{
	if(cmp.total_val > total_val)
	{
		std::cout << "	max value is " << company << "\n";
		return cmp;
	}
	else
	{
		std::cout << "	max value is " << company << "\n";
		return *this;
	}
}

std::ostream & operator<<(std::ostream & os, const Stock & st)
{
	os << "	--------------------------\n";
	os << "	Company: " << st.company << "\n	Total Value: " << st.total_val << "\n";	
	os << "	--------------------------\n";

	return os;
}

void Dbg_Stock()
{
	std::cout << "Enter Stock\n";
	Stock stock1("Lee", 3, 3.14);
	stock1.show();

	Stock stock2 = stock1;
	stock2.show();

	stock2 = Stock("Zhang", 4,233);
	stock2.show();

	Stock maxStock = stock1.compare(stock2);
	maxStock.show();

	Stock stocks[4];
	
	const Stock *ps = &stocks[0];
	for(int i = 1; i < 4; i++)
		ps = &ps->compare(stocks[i]);

	std::cout << stock1 << stock2 << *ps;
	std::cout << "Exit Stock\n";
}

// 运算符重载
Time::Time()
{
	hours   = 0;
	minutes = 0;
}

Time::Time(int h, int m):hours(h),minutes(m)
{

}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << "	Hour: " << t.hours << "\n	Miniute: " << t.minutes << "\n";
	return os;
}

Time::~Time()
{
}

void Dbg_Time()
{
	std::cout << "Enter Time\n";
	Time time1;
	Time time2(3,59);
	std::cout << time1 << time2;
	std::cout << "Exit Time\n";
}

// 动态内存分配
// 类中的静态变量应该在外部初始化
int String::num_strings = 0;

String::String()
{
	len = 0;
	str = new char [1];
	str[0] = '\0';
	num_strings++;
	std::cout << "	Num = " << num_strings << std::endl;
}

String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::~String()
{
	--num_strings;
	std::cout << "----" << str << " has been deleted\n";
	std::cout << "----Num: " << num_strings << std::endl;
	delete [] str;
}

String::String(const String & st)
{
	num_strings++;
	len = st.len;
	str = new char [len + 1];
	std::strcpy(str, st.str);
}

String & String::operator=(const String &st)
{
	if(this != &st)
	{
		delete [] str;
		len = st.len;
		str = new char[len + 1];
		std::strcpy(str, st.str);
	}

	return *this;
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << "	Name: " << st.str << "\n	Number: " << st.num_strings << "\n	Length: "<< st.len << std::endl;
	return os;
}

void String::HowMany()
{
	std::cout << "	Number: " << num_strings << std::endl;
}

// 没有问题
void callme1(String & s)
{
	std::cout << "	Name1:" << s << std::endl;
}

// 错误的使用方法，会导致析构函数被调用
void callme2(String s)
{
	std::cout << "	Name2:" << s << std::endl;
}

void Dbg_String()
{
	std::cout << "Enter String\n";
	String str1;
	str1.HowMany();
	String str2("Juwenlee");
	str2.HowMany();
	std::cout << str1 << str2;


	callme1(str1);
	callme2(str2);
	std::cout << "Exit String\n";
}

// Klunk(int n = 0){} && Klunk(int n){}
// 带参数的构造函数也可以是默认构造函数，只要所有参数都有默认值
void Dbg_Op()
{
	std::cout << "Enter Op\n";
	Op op1(10);
	Op op2;	
	std::cout << "Exit Op\n";
}

int main()
{
// Stock
	Dbg_Stock();
// Time
	Dbg_Time();
// String
	Dbg_String();
// Op
	Dbg_Op();

	return 0;
}

