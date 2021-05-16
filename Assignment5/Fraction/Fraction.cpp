/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 15:51:47
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 19:13:47
 * @Description: 
 * @FilePath: /Fraction/Fraction.cpp
 */

#include "Fraction.hpp"

int gcd(int a, int b)
{
    int x = abs(a);
    int y = abs(b);
    int r = x % y;
    while(r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}

Fraction::Fraction()
{
    Molecular = 0;
    Denominator = 0;
}

Fraction::Fraction(int a, int b)
{
    if (a == 0 || b == 0)
    {
        Molecular = 0;
        Denominator = 0;
        if (b == 0) printf("Denominator cannot be equal to 0!");
        return;
    }
    int t = gcd(a, b);
    Molecular = a/t;
    Denominator = b/t;
}

Fraction::Fraction(const Fraction& f)
{
    Molecular = f.Molecular;
    Denominator = f.Denominator;
}

Fraction Fraction::operator+(const Fraction& that)
{
    Fraction result;
    if (this->Molecular == 0)
    {
        result.Molecular = that.Molecular;
        result.Denominator = that.Denominator;;
        return result;
    }
    if (that.Molecular == 0)
    {
        result.Molecular = this->Molecular;
        result.Denominator = this->Denominator;
        return result;
    }
    int m = this->Molecular*that.Denominator+that.Molecular*this->Denominator;
    int d = this->Denominator*that.Denominator;
    int t = gcd(m, d);
    result.Molecular = m/t;
    result.Denominator = d/t;
    return result;
}

Fraction Fraction::operator-(const Fraction& that)
{
    Fraction result;
    if (this->Molecular == 0)
    {
        result.Molecular = -that.Molecular;
        result.Denominator = that.Denominator;;
        return result;
    }
    if (that.Molecular == 0)
    {
        result.Molecular = this->Molecular;
        result.Denominator = this->Denominator;
        return result;
    }
    int m = this->Molecular*that.Denominator-that.Molecular*this->Denominator;
    int d = this->Denominator*that.Denominator;
    int t = gcd(m, d);
    result.Molecular = m/t;
    result.Denominator = d/t;
    return result;
}

Fraction Fraction::operator*(const Fraction& that)
{
    Fraction result;
    int m = this->Molecular*that.Molecular;
    int d = this->Denominator*that.Denominator;
    if (m == 0 || d == 0)
    {
        result.Molecular = 0;
        result.Denominator = 0;
        return result;
    }
    int t = gcd(m, d);
    result.Molecular = m/t;
    result.Denominator = d/t;
    return result;
}

Fraction Fraction::operator/(const Fraction& that)
{
    if (that.Molecular == 0)
    {
        printf("Divisor cannot be equal to 0!\n");
        return *this;
    }
    Fraction result;
    int m = this->Molecular*that.Denominator;
    int d = this->Denominator*that.Molecular;
    if (m == 0 || d == 0)
    {
        result.Molecular = 0;
        result.Denominator = 0;
        return result;
    }
    if (that.Molecular < 0)
    {
        m = -m;
        d = -d;
    }
    int t = gcd(m, d);
    result.Molecular = m/t;
    result.Denominator = d/t;
    return result;
}

bool Fraction::operator==(const Fraction& that)
{
    if (this->Molecular == that.Molecular)
    {
        if (this->Molecular == 0) return true;
        else if (this->Denominator == that.Denominator) return true;
        else return false;
    }
    else return false;
}

bool Fraction::operator!=(const Fraction& that)
{
    return !(*this == that);
}

bool Fraction::operator>(const Fraction& that)
{
    Fraction a = (*this)-that;
    if (a.Molecular > 0) return true;
    else return false;
}

bool Fraction::operator>=(const Fraction& that)
{
    return (*this == that || *this > that);
}

bool Fraction::operator<(const Fraction& that)
{
    return !(*this >= that);
}

bool Fraction::operator<=(const Fraction& that)
{
    return !(*this >that);
}

Fraction::operator double()
{
    return 1.0*Molecular/Denominator;
}

void Fraction::print()
{
    if (Molecular == 0)
    {
        printf("0\n");
        return;
    }
    printf("%d/%d\n", Molecular, Denominator);
}