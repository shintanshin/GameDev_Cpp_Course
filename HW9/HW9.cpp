#include <iostream>
#include "Arrays.h"
int main()
{
	//const int size = 10;
	//int myArr[size];
	
	//translateArray( myArr, size);
	

	//char myStr[100];
	
   // toUppercase(myStr);


	char myValue[] = "lol";

	isPalindrom(myValue);


	const char word[] = "Mamaaa! Uuuuuu!";
	int vowels = 0, consonants = 0;

	parseStringLetters(word, vowels, consonants);

	std::cout << "Number of vowels: " << vowels << std::endl;
	std::cout << "Number of consonants: " << consonants << std::endl;


	const char str1[] = "A-a-a-a";
	const char str2[] = "Stay alive!";
	const char str3[] = "Stay alive!";
	
	bool result = isEqual(str1, str2);
	std::cout << std::endl;
	result = isEqual(str2, str3);
	std::cout << std::endl;
}