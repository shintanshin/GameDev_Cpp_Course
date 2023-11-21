#include <iostream>
#include <iomanip>

void gameDuration()
{
    int timeInGame = 0;
    std::cout << "How many tame you spend?: ";
    std::cin >> timeInGame;
    int h = static_cast<int>(timeInGame) / 60 / 60;
    int m = static_cast<int> (timeInGame) / 60 % 60;
    int s = static_cast<int>(timeInGame) % 60;
    std::cout << "Your tome in game: " << h << " hours, " << m << " minutes, " << s << " seconds." << std::endl;
}
void arithmeticSimple()
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
    std::cout << a + b + c << std::endl << a * b * c << std::endl << (a + b + c) / static_cast<double>(3) << std::endl;
    bool compare1 = a < b;
    bool compare2 = c < b;
    bool compare3 = a > c;
    std::cout << "Compare: a < b \n" << std::boolalpha << compare1 << std::endl;
    std::cout << "Compare: c < b \n" << std::boolalpha << compare2 << std::endl;
    std::cout << "Compare: a > c \n" << std::boolalpha << compare3 << std::endl;
}
void comparingValue()
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
void recArea()
{
    int a = 0;
    int b = 0;
    std::cout << "Width:";
    std::cin >> a;
    std::cout << "Height";
    std::cin >> b;
    std::cout << "rectangle area = " << a * b << " m2\n" << "rectangle perimeter = " << 2 * a + 2 * b << " m " << std::endl;
}
void areaAndLength()
{
    const double Pi = 3.14;
    int a = 0;
    std::cout << "Radius:";
    std::cin >> a;
    std::cout << "circle area = " << (a * a) * Pi << " m2\n" << "circle length = " << 2 * Pi * a << " m ";
}
int main()
{
    gameDuration();
    arithmeticSimple();
    comparingValue();
    recArea();
    areaAndLength();
}