#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    DynamicIntArray array1;
    std::cout << "Size of array1: " << array1.getSize() << std::endl;

    DynamicIntArray array2(5);
    std::cout << "Size of array2: " << array2.getSize() << std::endl;
    std::cout << "Elements of array2: ";
    for (std::size_t i = 0; i < array2.getSize(); ++i) {
        array2[i] = i + 1;
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    DynamicIntArray array3(array2);
    std::cout << "Size of array3: " << array3.getSize() << std::endl;
    std::cout << "Elements of array3: ";
    for (std::size_t i = 0; i < array3.getSize(); ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    array3.setSize(3);
    std::cout << "New size of array3: " << array3.getSize() << std::endl;

    array3.push_back(42);
    std::cout << "New elements of array3: ";
    for (std::size_t i = 0; i < array3.getSize(); ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    array3.clear();
    std::cout << "Size of array3 after clear: " << array3.getSize() << std::endl;
}
