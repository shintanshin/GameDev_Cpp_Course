#include <iostream>
#include <iomanip>

enum class WeekDay {
    Zero,

    Monday,

    Tuesday,

    Wednesday,

    Thoursday,

    Friday,

    Saturday,

    Sunday
};
void swapVariables()
{
    int a = 0;
    int b = 0;
    std::cout << "Enter first value: ";
    std::cin >> a;
    std::cout << "Enter second value: ";
    std::cin >> b;
    int tempValue = a;
    a = b;
    b = tempValue;
    std::cout << "First value: " << a << "\n";
    std::cout << "Second value: " << b << "\n";
}
void doubleToInt()
{
    double numDouble = 2548.85;
    std::cout << numDouble << std::endl;
    int numInt = int(numDouble);
    std::cout << numInt << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << numDouble << std::endl;
}
void difNotation()
{
    double num = 25.4885;
    std::cout << num << std::endl;
    std::cout << std::scientific << num << std::endl;
    std::cout << std::fixed << std::setprecision(2) << num << std::endl;
    std::cout << std::fixed << std::setprecision(5) << num << std::endl;
    std::cout << std::fixed << std::setprecision(10) << num << std::endl;
}
void hw2_weekDays()
{
    std::cout << static_cast<int>(WeekDay::Monday) << "\n" << static_cast<int>(WeekDay::Tuesday) << "\n" << static_cast<int>(WeekDay::Wednesday) << "\n" << static_cast<int>(WeekDay::Thoursday)
        << "\n" << static_cast<int>(WeekDay::Friday) << "\n" << static_cast<int>(WeekDay::Saturday) << "\n" << static_cast<int>(WeekDay::Sunday) << std::endl;
}
void checkBool()
{
    int a = 0;
    std::cin >> a;
    bool b = bool(a);
    std::cout << std::boolalpha << b << std::endl;
}

int main()
{
    swapVariables();
    doubleToInt();
    difNotation();
    hw2_weekDays();
    checkBool();
}
