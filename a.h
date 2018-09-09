#ifndef A_H
#define A_H

#include <string>
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
    const Stock &compare(const Stock &cmp);
};

#endif