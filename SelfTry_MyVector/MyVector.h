#pragma once

#include <cstddef>

class MyVector
{
public :
    //  构造函数
    MyVector ();
    //  explicit 防止隐式类型转换
    explicit MyVector (size_t initCapacity);
    MyVector (const MyVector& other);   //  用已有容器创建一份独立副本
//    MyVector& operator= (MyVector other);
    //  析构函数
    ~MyVector ();   //  释放堆内存

    size_t size () const;   // 功能：返回有效元素个数
    size_t capacity () const;   //  功能：返回当前已分配能装多少个
    bool empty () const;
    void clear ();

    //  C++ 内置运算符默认只认 int 等基本类型
    //  operator 重载 [] 运算符，让 vec[0] 能访问元素
    int& operator[] (size_t i);

    void push_back (int value); // 功能：尾部追加；满了先扩容再放

    int* begin ();
    int* end ();

private :
    int* data_;
    size_t size_;
    size_t capacity_;    //  已分配总空间
};

