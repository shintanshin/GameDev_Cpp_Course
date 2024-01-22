#include "DynamicIntArray.h"

DynamicIntArray::DynamicIntArray() : m_data(nullptr), m_size(0){}

DynamicIntArray::DynamicIntArray(std::size_t initialSize) 
	: m_size(initialSize) 
{
	m_data = new int[m_size];
	for (std::size_t i = 0; i < m_size; ++i) {
		m_data[i] = 0; 
	}
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other)
	: m_size(other.m_size)
{
	m_data = new int[m_size];
	for (std::size_t i = 0; i < m_size; ++i) {
		m_data[i] = other.m_data[i];
	}
}

DynamicIntArray::~DynamicIntArray()
{
	if (m_data != nullptr) delete[] m_data;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other)
{
	if (this != &other) {
		delete[] m_data;

		m_size = other.m_size;
		m_data = new int[m_size];
		for (std::size_t i = 0; i < m_size; ++i) {
			m_data[i] = other.m_data[i];
		}
	}
	return *this;
}

int& DynamicIntArray::operator[](std::size_t index)
{
	return m_data[index];
}

void DynamicIntArray::setSize(std::size_t newSize)
{
	int* newData = new int[newSize];
	std::size_t minSize = (newSize < m_size) ? newSize : m_size;

	for (std::size_t i = 0; i < minSize; ++i) {
		newData[i] = m_data[i];
	}

	delete[] m_data;
	m_data = newData;
	m_size = newSize;
}

std::size_t DynamicIntArray::getSize() const
{
	return m_size;
}

void DynamicIntArray::clear()
{
	if (m_data != nullptr) delete[] m_data;
	m_data = nullptr;
	m_size = 0;
}

void DynamicIntArray::push_back(int element)
{
	std::size_t newSize = m_size + 1;
	int* newData = new int[newSize];

	for (std::size_t i = 0; i < m_size; ++i) {
		newData[i] = m_data[i];
	}

	newData[m_size] = element;

	delete[] m_data;
	m_data = newData;
	m_size = newSize;
}
