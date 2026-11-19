#include <iostream>
#include <string>
#include <cassert>  //  assert()
#include "MyVector.h"

using std::cout;

int main ()
{
    MyVector<int> vec1;
    for (int i = 0; i != 10; ++i)
    {
        vec1.push_back(i);
    }
    vec1 = vec1;
    std::cout << "vec1 : ";
    for (size_t i = 0; i != vec1.size(); ++i)
    {
        std::cout << vec1[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "=======================" << '\n';
    

    MyVector<int> vec2 (vec1);
    std::cout << "vec2 : ";
    for (size_t i = 0; i != vec2.size(); ++i)
    {
        std::cout << vec2[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "=======================" << '\n';

    vec2[0] = 999;
    assert(vec1[0] == 0);   // 深拷贝的证明

    MyVector<int> vec3 = vec1;
    cout << "vec3 : ";
    for (size_t i = 0; i != vec3.size(); ++i)
    {
        cout << vec3[i] << ' ';
    }
    cout << '\n';
    cout << vec3.size() << " " << vec3.capacity() << '\n';

    vec3.pop_back();
    cout << vec3.size() << " " << vec3.capacity() << '\n';
    cout << "vec3 : ";
    for (size_t i = 0; i != vec3.size(); ++i)
    {
        cout << vec3[i] << ' ';
    }
    cout << '\n';

    vec3.clear();
    cout << vec3.size() << " " << vec3.capacity() << '\n';
    cout << "=======================" << '\n';


    MyVector<int> v;
    for (int i = 1; i <= 5; ++i) v.push_back(i);
    int sum1 = 0;
    for (int x : v) sum1 += x;
    cout << "sum1 = " << sum1 << '\n';

    int sum2 = 0;
    const MyVector<int>& cv = v;
    for (int x : cv) sum2 += x;
    cout << "sum2 = " << sum2 << '\n';


    MyVector<double> dv;
    dv.push_back(3.14);

    MyVector<std::string> sv;
    sv.push_back("hello");

    return 0;
}