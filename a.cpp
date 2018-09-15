/*************************************************************************
    > File Name: a.cpp
    > Author: Lee
    > Mail: 825526448@qq.com
    > Created Time: Thu 06 Sep 2018 10:47:31 PM CST
 ************************************************************************/

#include <stdio.h>
#include <iostream>
#include "a.h"

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
	std::cout << "Bye, " << company << "\n";
}

void Stock::set_tot()
{
	total_val = share_val;
}

void Stock::show()
{
	std::cout << "company: " << company << "\n";
	std::cout << "shares : " << shares << "\n";
	std::cout << "share_val: " << share_val << "\n";
	std::cout << "total_val: " << total_val << "\n";

	return;
}

const Stock & Stock::compare(const Stock &cmp) const
{
	if(cmp.total_val > total_val)
	{
		std::cout << "max value is " << company << "\n";
		return cmp;
	}
	else
	{
		std::cout << "max value is " << company << "\n";
		return *this;
	}
}

std::ostream & operator<<(std::ostream & os, const Stock & st)
{
	os << "--------------------------\n";
	os << "Company: " << st.company << "\nTotal Value: " << st.total_val << "\n";	
	os << "--------------------------\n";

	return os;
}

int main()
{
	std::cout << "Enter Code\n";
	Stock stock1("LEE", 3, 3.14);
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
	std::cout << "Exit Code\n";
	return 0;
}

