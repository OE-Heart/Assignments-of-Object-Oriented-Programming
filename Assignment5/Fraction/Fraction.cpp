/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 15:51:47
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 20:40:59
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

Fraction::Fraction(const int& a, const int& b)
{
    if (a == 0 || b == 0)
    {
        Molecular = 0;
        Denominator = 0;
        if (b == 0) printf("Denominator cannot be equal to 0!\n");
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

Fraction::Fraction(const std::string& dec)
{
    int n = dec.length();
    int tag = dec.find(".");

    int a = 0, b;
    b = pow(10, n-2);
    for (int i = 0; i < n; i++)
    {
        if (i == tag) continue;
        a = a*10+dec[i]-'0';
    }
    if (a == 0 || b == 0)
    {
        Molecular = 0;
        Denominator = 0;
        if (b == 0) printf("Denominator cannot be equal to 0!\n");
        return;
    }
    int t = gcd(a, b);
    Molecular = a/t;
    Denominator = b/t;
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
    if (this->Molecular == 0 || this->Denominator == 0) return 0;
    return 1.0*this->Molecular/this->Denominator;
}

Fraction::operator std::string()
{
    std::string result;
    if (this->Molecular == 0 || this->Denominator == 0)
    {
        result = "0";
        return result;
    }
    std::string m = std::to_string(this->Molecular);
    std::string d = std::to_string(this->Denominator);
    result = m+"/"+d;
    return result;
}

std::istream& operator>>(std::istream& input, Fraction& F)
{
    int a, b;
    input >> a >> b;
    if (a == 0 || b == 0)
    {
        F.Molecular = 0;
        F.Denominator = 0;
        if (b == 0) printf("Denominator cannot be equal to 0!\n");
        return input;
    }
    int t = gcd(a, b);
    F.Molecular = a/t;
    F.Denominator = b/t;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Fraction& F)
{
    if (F.Molecular == 0)
    {
        output << "0";
        return output;
    }
    output << F.Molecular << "/" << F.Denominator;
    return output;
}