/*
 * @Author: Ou Yixin
 * @Date: 2021-05-16 17:21:20
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-16 20:57:57
 * @Description: 
 * @FilePath: /Fraction/main.cpp
 */

#include "Fraction.hpp"

int main()
{
    printf("Please input two integers a and b and fa will be a/b: ");
    Fraction fa;
    std::cin >> fa;
    std::cout << "fa = " << fa << std::endl;
    std::string s = fa;
    std::cout << "fa(string) = " << s << std::endl;
    double x = fa;
    std::cout << "fa(double) = " << x << std::endl;
    std::string q;
    printf("Please input a finite decimal string as fb: ");
    std::cin >> q;
    Fraction fb(q);
    std::cout << "fb = " << fb << std::endl;
    std::cout << "fb = " << q << std::endl;
    printf("The calculation results are as follows:\n");    
    Fraction fc = fa+fb;
    std::cout << "fa+fb = " << fc << std::endl;
    fc = fa-fb;
    std::cout << "fa-fb = " << fc << std::endl;
    fc = fa*fb;
    std::cout << "fa*fb = " << fc << std::endl;
    fc = fa/fb;
    std::cout << "fa/fb = " << fc << std::endl;
    if (fa == fb) printf("fa == fb\n");
    if (fa != fb) printf("fa != fb\n");
    if (fa > fb) printf("fa > fb\n");
    if (fa >= fb) printf("fa >= fb\n");
    if (fa < fb) printf("fa < fb\n");
    if (fa <= fb) printf("fa <= fb\n");
    
    return 0;
}