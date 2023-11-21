#include <iostream>
#include <iomanip>
#include "EnumClasses.cpp"


void hw_1() 
{
    std::cout << "\n I love C++!\n\n";
    std::cout << " *\n **\n ***\n";
}
void hw2_1() 
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
void hw2_2()
{
    double numDouble = 2548.85;
    std::cout << numDouble << std::endl;
    int numInt = int(numDouble);
    std::cout << numInt << std::endl;
    std::cout << std::setw(20) << std::right << std::setfill('$') << numDouble << std::endl;
}
void hw2_3()
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
void hw2_5()
{
    int a = 0;
    std::cin >> a;
    bool b = bool(a);
    std::cout << std::boolalpha << b << std::endl;
}
void hw3_1()
{
    int timeInGame = 0;
    std::cout << "How many tame you spend?: ";
    std::cin >> timeInGame;
    int h = static_cast<int>(timeInGame) / 60 / 60;
    int m = static_cast<int> (timeInGame) / 60 % 60;
    int s = static_cast<int>(timeInGame) % 60;
    std::cout << "Your tome in game: " << h << " hours, " << m << " minutes, " << s << " seconds." << std::endl;
}
void hw3_2()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cout << "first value:";
    std::cin >> a;
    std::cout << "second value:";
    std::cin >> b;
    std::cout << "third value:";
    std::cin >> c;
    std::cout << a + b + c << std::endl << a * b * c << std::endl << (a + b + c) / float(3) << std::endl;
    bool compare1 = a < b;
    bool compare2 = c < b;
    bool compare3 = a > c;
    std::cout << "Compare: a < b \n" << std::boolalpha << compare1 << std::endl;
    std::cout << "Compare: c < b \n" << std::boolalpha << compare2 << std::endl;
    std::cout << "Compare: a > c \n" << std::boolalpha << compare3 << std::endl;
}
void hw3_3()
{
    int a = 0;
    int b = 0;
    std::cout << "first value:";
    std::cin >> a;
    std::cout << "second value:";
    std::cin >> b;
    bool lessThan = a < b;
    bool equal = a == b;
    bool moreThan = a > b;
    bool lessOrEqual = a <= b;
    std::cout << "first value less than second: " << std::boolalpha << lessThan << std::endl;
    std::cout << "first value equal second: " << std::boolalpha << equal << std::endl;
    std::cout << "first value more than second: " << std::boolalpha << moreThan << std::endl;
    std::cout << "first value less or equal second: " << std::boolalpha << lessOrEqual << std::endl;

}
void hw3_4()
{
    int a = 0;
    int b = 0;
    std::cout << "Width:";
    std::cin >> a;
    std::cout << "Height";
    std::cin >> b;
    std::cout << "rectangle area = " << a * b << " m2\n" << "rectangle perimeter = " << 2 * a + 2 * b << " m " << std::endl;
}
void hw3_5()
{
    const double p = 3.14;
    int a = 0;
    std::cout << "Radius:";
    std::cin >> a;
    std::cout << "circle area = " << (a * a) * p << " m2\n" << "circle length = " << 2 * p * a << " m ";
}
void hw4_1()
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
    else if (b > a && b > c)
    {
        std::cout << "Biggest number is " << b;
    }
    else
    {
        std::cout << "Biggest number is " << c;
    }
}
void hw4_2()
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
void hw4_3()
{
    int a = 0;
    std::cout << "Enter the number: ";
    std::cin >> a;
    if (a % 5 == 0 && a % 11 == 0)
    {
        //if (a % 11 == 0)
        //{
            std::cout << "Number is divisible by 5 and 11";
        //}
        //else
        //{
            //std::cout << "Number isn't divisible by 5 and 11";
        //}
    }
    else
    {
        std::cout << "Number isn't divisible by 5 and 11";
    }
}
void hw4_4()
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
void hw4_5()
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
void hw4_6()
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
    //hw_1();           // first homework
   // hw2_1();          // swap variables
   // hw2_2();          // double to int
    //hw2_3();          // double in notations
    //hw2_weekDays();   // enum class with sequence number
    //hw2_5();          // bool
    //hw3_1();          // time in game
    //hw3_2();          // sum, product, arithmetic average
    //hw3_3();          // 
    //hw3_4();
    //hw3_5();
    //hw4_1();
    //hw4_2();
    hw4_3();
    //hw4_4();
    //hw4_5();
   // hw4_6();
}
