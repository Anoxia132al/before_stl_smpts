#include "MyVector.h"

template <typename T>
MyVector<T>::MyVector ()
    : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
MyVector<T>::MyVector (size_t initCapacity)
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
        data_ = new T[other.capacity_];
        for (T i = 0; i != other.size_; ++i)
        {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
}

// MyVector& MyVector::operator= (MyVector other)
// {
//     T* newData = new T[other.capacity_];
//     for (T i = 0; i != other.size_; ++i)
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
T& MyVector<T>::operator[] (size_t i) { return data_[i]; }

template <typename T>
size_t MyVector<T>::size () const { return size_; }
template <typename T>
size_t MyVector<T>::capacity () const { return capacity_; }
template <typename T>
bool MyVector<T>::empty () const { return size_ == 0; }

template <typename T>
void MyVector<T>::push_back (T value)
{
    if (size_ == capacity_)
    {
        size_t newcapacity = (capacity_ == 0 ? 1 : capacity_ * 2);

        T* newData = new T[newcapacity];
        for (T i = 0; i != size_; ++i)
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
T* MyVector<T>::begin () const { return data_; }
template <typename T>
T* MyVector<T>::end () { return data_ + size_; }
template <typename T>
T* MyVector<T>::end () const { return data_ + size_; }