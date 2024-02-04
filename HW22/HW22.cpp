#include <iostream>
#include "DynamicArray.h"

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

template<typename T>
T& DynamicArray<T>::operator[](std::size_t index)
{

    return data[index];
}

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
std::size_t DynamicArray<T>::getSize() const
{
    return size;
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
void DynamicArray<T>::pop_back()
{
    if (size > 0)
    {
        --size;
    }
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
std::size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
void DynamicArray<T>::shrinkToFit()
{
    if (size < capacity)
    {
        reserve(size);
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


int main()
{
   
    DynamicArray<int> m_container;
    m_container.reserve(4);
    m_container.push_back(25); //No new heap allocations, using reserved memory
    m_container.push_back(30); //No new heap allocations, using reserved memory
    m_container.push_back(10); //No new heap allocations, using reserved memory
    m_container.push_back(39); //No new heap allocations, using reserved memory

    std::cout << "Size: " << m_container.getSize() << std::endl;
    std::cout << "Capacity: " << m_container.getCapacity() << std::endl;

    m_container.push_back(55);

 
    std::cout << "Size: " << m_container.getSize() << std::endl;
    std::cout << "Capacity: " << m_container.getCapacity() << std::endl;

  
    for (std::size_t i = 0; i < m_container.getSize(); ++i)
    {
        std::cout << m_container[i] << " ";
    }
    std::cout << std::endl;
}
