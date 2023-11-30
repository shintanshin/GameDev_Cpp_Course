#include <iostream>

int factorialRecursion(int count) {
	const int factorial = 1;
	int result = 0;
	if (count < 1) {
		std::cout << "ERROR!!! Integer can't be less than 1!";
		return 1;
	}
	if (count == factorial) { return 1; }
	else {
		result = count * factorialRecursion(count - 1);
		return result;
	}
}
int printNaturalNumbersRecursionAscend(int count) {
	if (count < 0) {
		std::cout << "ERROR!!! It doesn't consist natural numbers!";
		std::cin >> count;
		return 1;
	}
	if (count > 0) {
		printNaturalNumbersRecursionAscend(count - 1);
		std::cout << count << " ";
	}
	return count;
}
int printNaturalNumbersRecursionDesc(int count) {
	if (count < 0) {
		std::cout << "ERROR!!! It doesn't consist natural numbers!";
		std::cin >> count;
		return 1;
	}
	if (count > 0) {
		std::cout << count << " ";
		printNaturalNumbersRecursionDesc(count - 1);
	}
	return count;
}