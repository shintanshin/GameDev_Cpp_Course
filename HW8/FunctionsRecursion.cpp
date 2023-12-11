#include <iostream>

int factorialRecursion(int count) {
	const int factorial = 1;
	if (count < 1) {
		std::cout << "ERROR!!! Integer can't be less than 1!";
		return 1;
	}
	if (count == factorial) { return 1; }
	else {
		return count * factorialRecursion(count - 1);
	}
}
void printNaturalNumbersRecursionAscend(int count) {
	if (count < 0) {
		std::cout << "ERROR!!! It doesn't consist natural numbers!";
		std::cin >> count;
	}
	if (count > 0) {
		printNaturalNumbersRecursionAscend(count - 1);
		std::cout << count << " ";
	}
}
void printNaturalNumbersRecursionDesc(int count) {
	if (count < 0) {
		std::cout << "ERROR!!! It doesn't consist natural numbers!";
		std::cin >> count;
	}
	if (count > 0) {
		std::cout << count << " ";
		printNaturalNumbersRecursionDesc(count - 1);
	}
}