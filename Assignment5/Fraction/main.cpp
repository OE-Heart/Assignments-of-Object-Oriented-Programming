/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 17:21:20
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 19:14:45
 * @Description: 
 * @FilePath: /Fraction/main.cpp
 */

#include "Fraction.hpp"

int main()
{
    Fraction fa(6, 24);
    Fraction fb(-4, 24);
    fa.print();
    fb.print();
    Fraction fc = fa+fb;
    fc.print();
    fc = fa-fb;
    fc.print();
    fc = fa*fb;
    fc.print();
    fc = fa/fb;
    fc.print();

    if (fa == fb) printf("==\n");
    if (fa != fb) printf("!=\n");
    if (fa > fb) printf(">\n");
    if (fa >= fb) printf(">=\n");
    if (fa < fb) printf("<\n");
    if (fa <= fb) printf("<=\n");

    double x = fb;
    printf("%lf\n", x);
    
    return 0;
}