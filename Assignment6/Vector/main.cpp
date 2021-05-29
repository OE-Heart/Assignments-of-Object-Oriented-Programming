/*
 * @Author: Ou Yixin
 * @Date: 2021-05-29 13:31:43
 * @LastEditors: Ou Yixin
 * @LastEditTime: 2021-05-29 13:45:51
 * @Description: 
 * @FilePath: /Vector/main.cpp
 */
#include <iostream>
#include "myvector.hpp"

int main()
{
    Vector<int> a;
    Vector<int> t(2);
    for (int i = 0; i < 11; i++)
    {
        t.push_back(i);
    }

    std::cout << "size = " << t.size() << std::endl;

    for (int i = 0; i < 11; i++)
    {
        std::cout << t.at(i) << " ";
        std::cout << t[i] << " ";
    }

    Vector<int> b(t);

    std::cout << "size = " << t.size() << std::endl;

    for (int i = 0; i < 11; i++)
    {
        std::cout << b.at(i) << " ";
        std::cout << b[i] << " ";
    }

    if (t.empty()) std::cout << "empty" << std::endl;
    else std::cout << "not empty" << std::endl;

    t.clear();

    if (t.empty()) std::cout << "empty" << std::endl;
    else std::cout << "not empty" << std::endl;

    return 0;
}