/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 17:20:28
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 19:11:52
 * @Description: 
 * @FilePath: /Fraction/Fraction.hpp
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

class Fraction
{
public:
    Fraction();
    Fraction(int a, int b);
    Fraction(const Fraction& f);
    void print();
    Fraction operator+(const Fraction& that);
    Fraction operator-(const Fraction& that);
    Fraction operator*(const Fraction& that);
    Fraction operator/(const Fraction& that);
    bool operator==(const Fraction& that);
    bool operator!=(const Fraction& that);
    bool operator>(const Fraction& that);
    bool operator>=(const Fraction& that);
    bool operator<(const Fraction& that);
    bool operator<=(const Fraction& that);
    operator double();
private:
    int Molecular;
    int Denominator;
};

int gcd(int a, int b);