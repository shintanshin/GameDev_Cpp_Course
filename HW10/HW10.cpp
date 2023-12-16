#include <iostream>

void swapAmp(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "Value a: " << a << std::endl;
	std::cout << "Value b: " << b<< std::endl;
}
void swapDeref(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	std::cout << "Value a: " << *a << std::endl;
	std::cout << "Value b: " << *b << std::endl;
}
bool calculateSum(const double* arr, int arrSize, double& sum) {
	if (arrSize <= 0) {
		std::cout << "Array size is zero or less." << std::endl;
		return false;
	}
	sum = 0;
	for (int i = 0; i < arrSize; i++) {
		sum += arr[i];
	}
	std::cout << "Sum of array elements: " << sum << std::endl;
	return true;
}
bool find(const int* arr, int size, int elem) {
	const int* arrayEnd = arr + size; 
	for (const int* ptr = arr; ptr < arrayEnd; ++ptr) {
		if (*ptr == elem) {
			std::cout << "Element found in the array." << std::endl;
			return true;  
		}
	}
	std::cout << "Element not found in the array." << std::endl;
	return false;  
}
int main()
{
	int a = 10;
	int b = 15;
	
	swapAmp(a, b);
	swapDeref(&a, &b);


	const int sizeOfArray = 5;
	double myArr[sizeOfArray] = { 3.4, 0.7, 7, -1.5, -9.2 };
	double resultSum = 0;

	calculateSum(myArr, sizeOfArray, resultSum);


	const int arraySize = 5;
	int myArr1[arraySize] = { 10, -2, 0, 4, 84 };
	int searchElement = -2;

	find(myArr1, arraySize, searchElement);
}
