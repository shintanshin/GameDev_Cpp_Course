#include <iostream>

void countingInteger(int input) {
	int positiveNum = 0;
	int negativeNum = 0;
	int zero = 0;
	int num = 0;
	std::cout << "Please, enter your integers " << input << " times: ";
	for (int i = 0; i < input; i++) {
		std::cin >> num;
		if (num == 0) {zero++;}
		else if (num > 0) { positiveNum++; }
		else { negativeNum++; }
	}
	std::cout << "Positive: " << positiveNum << ", Negative: " << negativeNum << ", Zeroes: " << zero;
	std::cout << std::endl;
}
int factorialLoop(int count) {
	int factorial = 1;

	if (count < 0) {
		std::cout << "ERROR!!! Integer can't be less than 0!";
		return 1;
	}

	for (int i = 1; i <= count; i++) {
		factorial *= i;
	}
	return factorial;
}
void printNaturalNumbersLoop(int count) {

	for (int i = 1; i <= count; i++)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (int i = count; i >= 1; i--)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}