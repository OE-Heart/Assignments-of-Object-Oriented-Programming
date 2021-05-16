/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 17:21:20
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 17:21:37
 * @Description: 
 * @FilePath: /Fraction/main.cpp
 */

#include "Fraction.hpp"

int main()
{
    Fraction fa;
    Fraction fb(1, 4);
    Fraction fc = fa+fb;
    fc.print();
    fc = fa-fb;
    fc.print();
    fc = fa*fb;
    fc.print();
    fc = fa/fb;
    fc.print();
    return 0;
}