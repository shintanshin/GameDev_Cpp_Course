#include <iostream>

void readArray(int numbers[], int size) {
    std::cout << "Enter " << size << " integers:\n";

    for (int i = 0; i < size; i++) {
        std::cin >> numbers[i];
    }
}
void printArray(const int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << " " << numbers[i];
    }
    std::cout << std::endl;
}
void translateArray(int numbers[], int size) {
    
    for (int i = 0; i < size; i++) {
        (numbers[i] > 0) ? numbers[i] *= 2 : numbers[i] = 0;
    }
}

void inputString(char str[]) {
    std::cout << "Input: ";
    std::cin>>str; 
}
void toUppercase(char str[]) {
    const int firstSymbol = 96;
    const int lastSymbol = 123;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > firstSymbol && str[i] < lastSymbol) { str[i] = toupper(str[i]); }
    }
}

bool isPalindrom(const char str[]) {
    int value = 0;
    int length = std::strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (str[i] != str[length - i - 1]) {
            value = 1;
            break;
        }
    }
    if (value) {
        std::cout << "Output: False" << std::endl;
        return false;
    }
    else  {
        std::cout << "Output: True" << std::endl;
        return true;
    }
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) {
    vowelsCount = 0;
    consonantsCount = 0;
    for (int i = 0;  str[i] != '\0'; i++) {
        char currentChar = std::tolower(str[i]);
        if  (std::isalpha(currentChar)) {
            if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u' || currentChar == 'y') {
                ++vowelsCount;
            }
            else {
                ++consonantsCount;
            }
        }
    }
}
bool isEqual(const char str1[], const char str2[]) {
    int i = 0;
    int value = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            value = 1;
            break;
        }
        ++i;
    }
    if (value) {
        std::cout << "strings are not equal";
        return false;
    }
    else {
        std::cout << "strings are equal";
        return true;
    }
    return false;
}