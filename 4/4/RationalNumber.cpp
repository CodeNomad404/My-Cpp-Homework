#include"RationalNumber.h"
RationalNumber::RationalNumber(int n, int d)
{
    while (d == 0) {
        cout << "错误，分母不能为零！请重新输入" << endl;
        cin >> d;
    }
    numerator = n;
    denominator = d;
    cout << "创建有理数：";
    Simplify();
    Display();
}

RationalNumber::~RationalNumber()
{
    cout << "销毁有理数：";
    Display();
}

void RationalNumber::Display() const
{
    if (numerator == 0) {
        cout << "0" << endl;
        return;
    }
    if (denominator == 1)
    {
        cout << numerator << endl;
        return;
    }
    cout << numerator << "/" << denominator << endl;
    return;
}

RationalNumber RationalNumber::operator +(const RationalNumber& num)const
{
    RationalNumber temp(0, 1);
    temp.numerator = denominator * num.numerator + numerator * num.denominator;
    temp.denominator = denominator * num.denominator;
    temp.Simplify();
    return temp;
}

RationalNumber RationalNumber::operator -(const RationalNumber& num)const
{
    RationalNumber temp(0, 1);
    temp.numerator = numerator * num.denominator - denominator * num.numerator;
    temp.denominator = denominator * num.denominator;
    temp.Simplify();
    return temp;
}

RationalNumber RationalNumber::operator *(const RationalNumber& num) const
{
    RationalNumber temp(numerator * num.numerator, denominator * num.denominator);
    temp.Simplify();
    return temp;
}

RationalNumber RationalNumber::operator /(const RationalNumber& num)const
{
    RationalNumber temp(numerator * num.denominator, denominator * num.numerator);
    temp.Simplify();
    return temp;
}

RationalNumber& RationalNumber::operator =(const RationalNumber& num)
{
	if (this != &num)
	{
		numerator = num.numerator;
		denominator = num.denominator;
	}
	return *this;
}

void RationalNumber::Simplify()
{
    if (numerator == denominator) {
        numerator = 1;
        denominator = 1;
        return ;
    }
    if (numerator > denominator) {
        int bigger =abs(numerator);
        int smaller =abs(denominator);
        while (smaller != 0) {
            int a = bigger % smaller;
            bigger = smaller;
            smaller = a;
        }
        numerator = numerator / bigger;
        denominator = denominator / bigger;
        return;
    }
    else {
        int bigger = abs(denominator);
        int smaller = abs(numerator);
        while (smaller != 0) {
            int a = bigger % smaller;
            bigger = smaller;
            smaller = a;
        }
        numerator = numerator / bigger;
        denominator = denominator / bigger;
        return;
    }
}

ostream& operator<<(ostream& os, const RationalNumber& r)
{
    if (r.denominator == 1) {
        os << r.numerator;
        return os;
    }
    else if (r.numerator == 0) {
        os << '0';
        return os;
    }
    os << r.numerator << "/" << r.denominator;
    return os;
}

istream& operator>>(istream& is, RationalNumber& r)
{
    cout << "请输入一个有理数："<<endl;
    cout << "分子为：";
    is >> r.numerator;
    cout << "分母为：";
    is >> r.denominator;
    while (r.denominator == 0) {
        cout << "错误！分母不能为0！请重新输入分母：";
        is >> r.denominator;
    }
    return is;
}