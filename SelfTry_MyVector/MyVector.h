#pragma once

#include <cstddef>
#include <utility>

template <typename T>
class MyVector
{
public:
    //  构造函数
    MyVector ();
    //  explicit 防止隐式类型转换
    explicit MyVector (std::size_t initCapacity);
    MyVector (const MyVector& other);   //  用已有容器创建一份独立副本
    MyVector& operator= (MyVector other);
    //  析构函数
    ~MyVector ();   //  释放堆内存

    std::size_t size () const;   // 功能：返回有效元素个数
    std::size_t capacity () const;   //  功能：返回当前已分配能装多少个
    bool empty () const;
    void clear ();

    //  C++ 内置运算符默认只认 int 等基本类型
    //  operator 重载 [] 运算符，让 vec[0] 能访问元素
    T& operator[] (std::size_t i);
    const T& operator[] (std::size_t i) const;

    void push_back (const T& value); // 功能：尾部追加；满了先扩容再放
    void pop_back ();   // 功能：删除尾部元素

    T* begin ();
    const T* begin() const;
    T* end ();
    const T* end() const;

private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;    //  已分配总空间
};


template <typename T>
MyVector<T>::MyVector ()
    : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
MyVector<T>::MyVector (std::size_t initCapacity)
    : data_(nullptr), size_(0), capacity_(0)
{
    if (initCapacity == 0)  return;
    else
    {
        data_ = new T[initCapacity];
        capacity_ = initCapacity;
    }
}

template <typename T>
MyVector<T>::~MyVector ()  { delete[] data_; }

template <typename T>
MyVector<T>::MyVector (const MyVector& other)
    : data_(nullptr), size_(0), capacity_(0)
{
    if (other.size_ == 0) return;
    else
    {
        data_ = new T[other.size_];
        for (std::size_t i = 0; i != other.size_; ++i)
        {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
        capacity_ = other.size_;
    }
}

// MyVector<T>& MyVector<T>::operator= (MyVector other)
// {
//     T* newData = new T[other.capacity_];
//     for (std::size_t i = 0; i != other.size_; ++i)
//     {
//         newData[i] = other.data_[i];
//     }
//     delete[] data_;
//     data_ = newData;
//     size_ = other.size_;
//     capacity_ = other.capacity_;
//     return *this;
// }

template <typename T>
MyVector<T>& MyVector<T>::operator= (MyVector other)
{
    std::swap (data_, other.data_);
    std::swap (size_, other.size_);
    std::swap (capacity_, other.capacity_);
    return *this;
}

template <typename T>
T& MyVector<T>::operator[] (std::size_t i) { return data_[i]; }
template <typename T>
const T& MyVector<T>::operator[] (std::size_t i) const { return data_[i]; }

template <typename T>
std::size_t MyVector<T>::size () const { return size_; }
template <typename T>
std::size_t MyVector<T>::capacity () const { return capacity_; }
template <typename T>
bool MyVector<T>::empty () const { return size_ == 0; }

template <typename T>
void MyVector<T>::push_back (const T& value)
{
    if (size_ == capacity_)
    {
        std::size_t newcapacity = (capacity_ == 0 ? 1 : capacity_ * 2);

        T* newData = new T[newcapacity];
        for (std::size_t i = 0; i != size_; ++i)
        {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newcapacity;
    }
    data_[size_] = value;
    ++size_;
}
template <typename T>
void MyVector<T>::pop_back ()  { if ( !empty() ) --size_; }
template <typename T>
void MyVector<T>::clear () { size_ = 0; }

template <typename T>
T* MyVector<T>::begin () { return data_; }
template <typename T>
const T* MyVector<T>::begin () const { return data_; }
template <typename T>
T* MyVector<T>::end () { return data_ + size_; }
template <typename T>
const T* MyVector<T>::end () const { return data_ + size_; }

