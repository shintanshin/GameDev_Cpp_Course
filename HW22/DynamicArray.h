#pragma once
#include <cstdlib>

template<typename T>
class DynamicArray
{
public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    DynamicArray(std::size_t size) : size(size), capacity(size) { data = new T[size](); }
    DynamicArray(const DynamicArray& other) : data(nullptr), size(0), capacity(0) { copyData(other); }

    ~DynamicArray() { delete[] data; }

    DynamicArray& operator=(const DynamicArray& other); 

    T& operator[](std::size_t index) {return data[index];}

    void setSize(std::size_t newSize);
    std::size_t getSize() const {return size;}

    void clear();

    void push_back(T element);

    void pop_back() { if (size > 0) { --size; } }
    T back() const;  

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const { return capacity; }

    void shrinkToFit() { if (size < capacity) { reserve(size); } }

    bool operator==(const DynamicArray& other) const;  
private:
    T* data;
    std::size_t size;
    std::size_t capacity;

};

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] data;
        copyData(other);
    }
    return *this;
}

//template<typename T>
//T& DynamicArray<T>::operator[](std::size_t index)
//{
//    return data[index];
//}

template<typename T>
void DynamicArray<T>::setSize(std::size_t newSize)
{
    if (newSize <= capacity)
    {
        size = newSize;
    }
    else
    {
        reserve(newSize);
        size = newSize;
    }
}

template<typename T>
void DynamicArray<T>::clear()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void DynamicArray<T>::push_back(T element)
{
    if (size == capacity)
    {
        reserve(capacity * 2 + 1);
    }
    data[size++] = element;
}

template<typename T>
T DynamicArray<T>::back() const
{
    if (size > 0)
    {
        return data[size - 1];
    }


    throw std::out_of_range("Cannot get back element from an empty array");
}

template<typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace)
{
    if (reservedSpace > capacity)
    {
        T* newData = new T[reservedSpace];
        for (std::size_t i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = reservedSpace;
    }
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const
{
    if (size != other.size)
    {
        return false;
    }

    for (std::size_t i = 0; i < size; ++i)
    {
        if (data[i] != other.data[i])
        {
            return false;
        }
    }

    return true;
}