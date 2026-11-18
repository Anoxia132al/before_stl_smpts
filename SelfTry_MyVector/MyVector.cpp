#include "MyVector.h"

MyVector::MyVector ()
    : data_(nullptr), size_(0), capacity_(0) {}

MyVector::MyVector (size_t initCapacity)
    : data_(nullptr), size_(0), capacity_(0)
{
    if (initCapacity == 0)  return;
    else
    {
        data_ = new int[initCapacity];
        capacity_ = initCapacity;
    }
}

MyVector::~MyVector ()  { delete[] data_; }

MyVector::MyVector (const MyVector& other)
    : data_(nullptr), size_(0), capacity_(0)
{
    if (other.size_ == 0) return;
    else
    {
        data_ = new int[other.capacity_];
        for (int i = 0; i != other.size_; ++i)
        {
            data_[i] = other.data_[i];
        }
        size_ = other.size_;
        capacity_ = other.capacity_;
    }
}

// MyVector& MyVector::operator= (MyVector other)
// {
    
// }

size_t MyVector::size () const { return size_; }

void MyVector::push_back (int value)
{
    if (size_ == capacity_)
    {
        size_t newcapacity = (capacity_ == 0 ? 1 : capacity_ * 2);

        int* newData = new int[newcapacity];
        for (int i = 0; i != size_; ++i)
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

int& MyVector::operator[] (size_t i) { return data_[i]; }
