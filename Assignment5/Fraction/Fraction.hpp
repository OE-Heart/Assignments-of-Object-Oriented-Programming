/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 17:20:28
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 20:21:10
 * @Description: 
 * @FilePath: /Fraction/Fraction.hpp
 */

#include <iostream>
#include <istream>
#include <cstdio>
#include <string>
#include <cmath>

class Fraction
{
public:
    Fraction();
    Fraction(const int& a, const int& b);
    Fraction(const Fraction& f);
    Fraction(const std::string& dec);
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
    operator std::string();
    friend std::istream& operator>>(std::istream& input, Fraction& F);
    friend std::ostream& operator<<(std::ostream& output, const Fraction& F);
private:
    int Molecular;
    int Denominator;
};

int gcd(int a, int b);