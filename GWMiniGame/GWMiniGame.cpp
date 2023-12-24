#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

char* wordInput() {
	const int maxWordLength = 5;
	char buffer[maxWordLength + 1];
	std::cout << "ENTER : ";
	std::cin >> buffer;
	std::cout << std::endl;

	char* result = new char[maxWordLength + 1];
	for (int i = 0; i <= maxWordLength; ++i) {
		result[i] = buffer[i];
	}
	return result;
}

int mainMenu(){
	int value = 0;
	std::cout << "Greetings in Guess Word Game!" << std::endl;
	std::cout << "1 - Random Word" << std::endl;
	std::cout << "2 - Word of the day" << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::cout << "Enter: ";
	std::cin >> value;
	std::cout << std::endl;
	return value;
}

std::string randomWordFromBD(const char* fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in);

	std::string randomWord;

	if (!file) {
		std::cout << "File not found!\n";
	}
	else {
		std::vector<std::string> words;
		std::string word;

		while (file >> word) {
			words.push_back(word);
		}

		if (words.empty()) {
			std::cout << "No words found in the file!\n";
		}
		else {
			std::srand(static_cast<unsigned>(std::time(0)));
			int randomIndex = std::rand() % words.size();
			randomWord = words[randomIndex];
		}
	}
	file.close();
	return randomWord;
}

int getDay(const std::tm * tmObj)
{
	return tmObj->tm_mday;
}

int getMonth(const std::tm * tmObj)
{
	return tmObj->tm_mon + 1;
}

int getYear(const std::tm * tmObj)
{
	return tmObj->tm_year + 1900;
}

std::string getDate() {
	std::string date;
	std::string dash = "-";
	std::time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	date = std::to_string(getDay(now)) + dash + std::to_string(getMonth(now)) + dash + std::to_string(getYear(now));
	return date;
}

void writeDate(const char* fileName) {
	std::fstream file;
	std::string date = getDate();
	file.open(fileName, std::ios::out);
	file << date;
}

bool checkDate(const char* fileName) {
	std::fstream file;
	file.open(fileName, std::ios::in);

	std::string date;

	if (!file) {
		file.open(fileName, std::ios::out);
		file.close();
		return true;
	}
	else {
		std::vector<std::string> dates;
		std::string d;

		while (file >> d) {
			dates.push_back(d);
		}

		if (dates.empty()) {
			file.close();
			return true;
		}
		else {
			for (int i = 0; i < dates.size(); i++) {
				date = dates[i];
				if (date == getDate()) {
					file.close();
					return false;
				}
			}
			file.close();
			return true;
		}
	}
}

int letterCount(const std::string& array, const char currentChar) {
	int count = 0;
	for (int i = 0; i < array.length(); ++i) {
		char lowerCaseDB = std::tolower(array[i]);
		if (lowerCaseDB == currentChar) {
			count++;
		}
	}
	return count;
}

bool findIndex(const std::string& array, const char* arrayInput, const char currentChar) {
	bool result = false;
	const int maxWordLength = 5;
	const int falseValue = 9;
	int indexDB[maxWordLength];
	int indexInput[maxWordLength];
	for (int i = 0; i < maxWordLength; ++i) {
		if (array[i] == currentChar) {
			indexDB[i] = i;
		}
		else {
			indexDB[i] = falseValue;
		}
	}
	for (int i = 0; i < maxWordLength; ++i) {
		if (arrayInput[i] == currentChar) {
			indexInput[i] = i;
		}
		else {
			indexInput[i] = falseValue;
		}
	}
	for (int i = 0; i < maxWordLength; ++i) {
		if (indexDB[i] != falseValue) {
			for (int j = 0; j < maxWordLength; ++j) {
				if (indexDB[i] == indexInput[j]) {
					result = true;
					return result;
				}
			}
		}
	}
	return result;
}

bool isWordGuessed(const std::string& arrayDB, const char* arrayInput) {
	for (int i = 0; i < arrayDB.length() && arrayInput[i] != '\0'; ++i) {
		char lowerCaseDB = std::tolower(arrayDB[i]);
		char lowerCaseInput = std::tolower(arrayInput[i]);
		if (lowerCaseDB != lowerCaseInput) {
			return false;
		}
	}
	return true;
}

char* wordCompare(const std::string& arrayDB, const char* arrayInput) {
	const int maxWordLength = 5;
	char countCheck[maxWordLength + 1];
	char* result = new char[maxWordLength + 1];
	
	for (int i = 0; i < arrayDB.length(); ++i) {
		char lowerCaseDB = std::tolower(arrayDB[i]);
		char lowerCaseInput = std::tolower(arrayInput[i]);

		if (lowerCaseDB == lowerCaseInput) {
			countCheck[i] = lowerCaseInput;
			result[i] = (char)std::toupper(lowerCaseInput);
		}
		else {
			countCheck[i] = lowerCaseInput;
			if (letterCount(countCheck, lowerCaseInput) <= letterCount(arrayDB, lowerCaseInput) && letterCount(arrayDB, lowerCaseInput) == 1) {
				if (findIndex(arrayDB, arrayInput, lowerCaseInput)) {
					result[i] = '*';
				}
				else {
					result[i] = lowerCaseInput;
				}
			}
			else if(letterCount(countCheck, lowerCaseInput)<= letterCount(arrayDB, lowerCaseInput) && letterCount(arrayDB, lowerCaseInput)>1){
				result[i] = lowerCaseInput;
			}
			else {
				result[i] = '*';
			}
		}
	}
	result[5] = '\0';
	return result;
}

int main(){
	while (true) {
		int value = mainMenu();
		if (value == 0) {
			std::cout << "See You next time!" << std::endl;
			break;
		}
		if (value == 1) {
		const std::string& randomWord = randomWordFromBD("WordDB.txt");
		int attemptCount = 0;
			while (true) {
				attemptCount++;
				if (attemptCount == 1) {
					std::cout << "RESULT: *****" << std::endl;
				}
				char* userInput = wordInput();
				
				if (isWordGuessed(randomWord.c_str(), userInput) == true) {
					std::cout<< "That's right!" << std::endl;
					std::cout << "You made " << attemptCount << " tries!" << std::endl;
					std::cout << std::endl;
					delete[] userInput;
					break;
				}
				else {
					std::cout << "RESULT: " << wordCompare(randomWord.c_str(), userInput) << std::endl;
				}
				delete[] userInput;
			}
		}
		if (value == 2) {
			if (checkDate("WordOfDay.txt")) {
				const std::string& randomWord = randomWordFromBD("WordDB.txt");
				int attemptCount = 0;
				while (true) {
					attemptCount++;
					if (attemptCount == 1) {
						std::cout << "RESULT: *****" << std::endl;
					}
					char* userInput = wordInput();

					if (isWordGuessed(randomWord.c_str(), userInput) == true) {
						std::cout << "That's right!" << std::endl;
						std::cout << "You made " << attemptCount << " tries!" << std::endl;
						std::cout << std::endl;
						delete[] userInput;
						break;
					}
					else {
						std::cout << "RESULT: " << wordCompare(randomWord.c_str(), userInput) << std::endl;
					}
					delete[] userInput;
				}
				writeDate("WordOfDay.txt");
			}
			else {
				std:: cout << "Already found! Come back tomorrow." << std::endl;
				std::cout << std::endl;
			}
		}
	}
}