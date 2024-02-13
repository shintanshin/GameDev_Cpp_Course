#include <iostream>
#include <vector>
#include <algorithm>

class LengthComparator {
public:
    bool operator()(const std::string& str1, const std::string& str2) const {
        return str1.length() < str2.length();
    }
};

bool compareByLength(const std::string& str1, const std::string& str2) {
    return str1.length() < str2.length();
}

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) {

    return std::count_if(vec.begin(), vec.end(), [number](int element) {
        return element % number == 0;
        });
}


int main()
{
    std::vector<std::string> stringContainer = { "apple", "banana", "watermelon", "kiwi" };
    std::vector<std::string> stringContainer2 = { "apple", "banana", "watermelon", "kiwi" };
    std::vector<std::string> stringContainer3 = { "apple", "banana", "watermelon", "kiwi" };

    std::sort(stringContainer.begin(), stringContainer.end(), compareByLength);

    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    LengthComparator lengthComparator;
    std::sort(stringContainer2.begin(), stringContainer2.end(), lengthComparator);

    for (const auto& str : stringContainer2) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::sort(stringContainer3.begin(), stringContainer3.end(), [](const std::string& str1, const std::string& str2) {
        return str1.length() < str2.length();
        });

    for (const auto& str : stringContainer) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::vector<int> myVectorOfNum = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int divisor = 5;

    unsigned int result = countDivisibleBy(myVectorOfNum, divisor);

    std::cout << "Number of elements that are divided by " << divisor << " integers: " << result << std::endl;
}
