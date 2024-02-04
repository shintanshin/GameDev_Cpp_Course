#pragma once
#include <cstdlib>

//#TODO: Make it template class
//int type should be replace with smth more general
template<typename T>

class DynamicArray
{
public:
    DynamicArray() : data(nullptr), size(0), capacity(0) {}
    DynamicArray(std::size_t size) : size(size), capacity(size){data = new T[size]();}
    DynamicArray(const DynamicArray& other) : data(nullptr), size(0), capacity(0) { copyData(other);}

    ~DynamicArray() {delete[] data;}

    DynamicArray& operator=(const DynamicArray& other); //assignment operator, #TODO, change signature if needed

    //validate index always or only in _DEBUG configuration
    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(T element);


    //#TODO: HW new methods
    void pop_back();    //remove last element
    T back() const;   //get last element

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;    //returns reserve size. Should be ALWAYS >= then actual size

    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;    //#TODO, change signature if needed
private:
    T* data; 
    std::size_t size; 
    std::size_t capacity;

};
