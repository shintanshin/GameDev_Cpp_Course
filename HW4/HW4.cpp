#include <iostream>
#include <iomanip>

enum class Month {

    Begin,

    January,

    February,

    March,

    April,

    May,

    Jun,

    July,

    August,

    September,

    October,

    November,

    December,

    Count = 13,

};

void biggestValue()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cout << "First number:";
    std::cin >> a;
    std::cout << "Second number:";
    std::cin >> b;
    std::cout << "Third number:";
    std::cin >> c;
    if (a > b && a > c)
    {
        std::cout << "Biggest number is " << a;
    }
    else if (b > c)
    {
        std::cout << "Biggest number is " << b;
    }
    else
    {
        std::cout << "Biggest number is " << c;
    }
}

void lessNumber()
{
    int a = 0;
    int b = 0;
    std::cout << "First number:";
    std::cin >> a;
    std::cout << "Second number:";
    std::cin >> b;
    int lessNumber = (a < b) ? a : b;
    std::cout << lessNumber;
}

void divisionNum()
{
    int a = 0;
    std::cout << "Enter the number: ";
    std::cin >> a;
    if (a % 5 == 0 && a % 11 == 0)
    {
        std::cout << "Number is divisible by 5 and 11";

        }
    else
    {
        std::cout << "Number isn't divisible by 5 and 11";
    }
}

void sumOfAngle()
{
    int a = 0;
    std::cout << "Enter first angle: ";
    std::cin >> a;
    int b = 0;
    std::cout << "Enter second angle: ";
    std::cin >> b;
    int c = 0;
    std::cout << "Enter third angle: ";
    std::cin >> c;
    if (a + b + c == 180 && a > 0 && b > 0 && c > 0)
    {
        std::cout << "Congratulations! You've got triangle!";
    }
    else
    {
        std::cout << "No, it's not triangle :(";
    }
}

void monthCount()
{
    int month = 0;
    std::cin >> month;
    if (month<1 || month>static_cast<int>(Month::Count)) {
        std::cout << "Error - ";
    }
    Month readMonth = static_cast<Month>(month);
    switch (readMonth)
    {
    case Month::January:
        std::cout << "January";
        break;
    case Month::February:
        std::cout << "February";
        break;
    case Month::March:
        std::cout << "March";
        break;
    case Month::April:
        std::cout << "April";
        break;
    case Month::May:
        std::cout << "May";
        break;
    case Month::Jun:
        std::cout << "Jun";
        break;
    case Month::July:
        std::cout << "July";
        break;
    case Month::August:
        std::cout << "August";
        break;
    case Month::September:
        std::cout << "September";
        break;
    case Month::October:
        std::cout << "October";
        break;
    case Month::November:
        std::cout << "November";
        break;
    case Month::December:
        std::cout << "December";
        break;
    default:
        std::cout << "Month Invalid";
    }
}

void monthToSeason()
{
    int a = 0;
    std::cin >> a;
    if (a == 12 || a > 0 && a <= 2) {
        std::cout << "Winter";
    }
    else if (a >= 3 && a <= 5) {
        std::cout << "Spring";
    }
    else if (a >= 6 && a <= 8) {
        std::cout << "Summer";
    }
    else if (a >= 9 && a <= 11) {
        std::cout << "Autumn";
    }
    else {
        std::cout << "This month doesn't exist";
    }
}

int main()
{
    biggestValue();
    lessNumber();
    divisionNum();
    sumOfAngle();
    monthCount();
    monthToSeason();
}