#ifndef A_H
#define A_H

#include <string>
#include <iostream>

// 基础类
class Stock
{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot();
public:
// 构造和析构函数 
    Stock();
    Stock(const std::string &co, long n, double pr);
    ~Stock();
// 功能函数 
    void acquire(const std::string &co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
    const Stock &compare(const Stock &cmp) const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);
};

// 运算符重载
class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m);
    ~Time();
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

// 动态内存分配
class String
{
private:
    char * str;
    int len;
    static int num_strings;
public:
    String(const char * s);
    String();
    String(const String & st);
    String & operator=(const String &st);
    ~String();
    friend std::ostream & operator<<(std::ostream & os, const String & st);
};

class Op
{
private:
    int a;
    int c;
public:
    Op(int b = 0){a = b; std::cout << "        a = " << a << std::endl;}
};

#endif