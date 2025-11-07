#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
#include <cmath>
using namespace std;

class RationalNumber { 
private:
    int numerator;
    int denominator;
public:
    RationalNumber(int n, int d);
	~RationalNumber();
	RationalNumber operator +(const RationalNumber& ) const;//加法

    RationalNumber operator -(const RationalNumber& ) const;//减法

    RationalNumber operator *(const RationalNumber& ) const;//乘法

    RationalNumber operator /(const RationalNumber& ) const;//除法

    RationalNumber& operator =(const RationalNumber& );//赋值

    void Simplify();//化简

    void Display() const;//显示

    friend ostream& operator<<(ostream& os, const RationalNumber& r);//输出

    friend istream& operator>>(istream& is, RationalNumber& r);//输入
};
#endif