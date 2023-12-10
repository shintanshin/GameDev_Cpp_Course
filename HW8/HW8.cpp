#include <iostream>
#include "FunctionsLoop.h"
#include "FunctionRecursion.h"

int main()
{
	countingInteger(3);
	std::cout << factorialLoop(4) << std::endl;
	std::cout << factorialRecursion(4)<< std::endl;
	printNaturalNumbersLoop(10);
	printNaturalNumbersRecursionDesc(9);
	std::cout << std::endl;
	printNaturalNumbersRecursionAscend(9);
}
