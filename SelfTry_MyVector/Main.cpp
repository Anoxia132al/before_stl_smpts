#include <iostream>
#include "MyVector.h"

int main ()
{
    MyVector vec1;
    for (int i = 0; i != 10; ++i)
    {
        vec1.push_back(i);
    }
    for (size_t i = 0; i != vec1.size(); ++i)
    {
        std::cout << vec1[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "=======================" << std::endl;
    MyVector vec2 (vec1);
    for (size_t i = 0; i != vec2.size(); ++i)
    {
        std::cout << vec2[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}