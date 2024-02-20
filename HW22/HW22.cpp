#include <iostream>
#include "DynamicArray.h"

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
