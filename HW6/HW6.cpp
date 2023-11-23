#include <iostream>
#include<iomanip>
#include<limits> 

#include <cctype>
void arithmeticProgression() {
    int a1 = 0;
    int d = 0;
    int n = 0;
    int an = 0;
    std::cout << "Enter first element: ";
    std::cin >> a1;
    std::cout << "Enter difference: ";
    std::cin >> d;
    std::cout << "Enter last element: ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        an = a1 + d * (i - 1);
        std::cout << an << " ";
    }
}

//Рекурсивна функція для виводу значення елемента послідовності Фібоначчі
  int FibonacciSequence1(int n) {          
    int r;
    if (n == 1) { return 0; }
    else if (n == 2) { return 1; }
    else {
        r = FibonacciSequence1(n - 1) + FibonacciSequence1(n - 2);
        return r;
    }
}
int getNumber() {
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    return n;
}
// цикл для виводу значення елемента послідовності Фібоначчі
void FibonacciSequence() {
    int n = 0;
    int a = 0;
    int b = 1;
    int c = 0;
    std::cout << "Enter element number: ";
    std::cin >> n;

    while (n < 1) {
            std::cout << "Element number can't be less than 1!\n" << "Enter element number again : ";
            std::cin >> n;
        }

    if (n == 1) { std::cout << a;}
    else if (n==2){ std::cout << b; }
    else {
        for (int i = n; i >= 3; i--) {
            c = a + b;
            a = b;
            b = c;
            }
        std::cout << b;
    }
    }
void factorial() {
    int n = 0;
    int factorial = 1;

    std::cout << "Enter positive integer: ";
    std::cin >> n;
    while (n < 0) {
        std::cout << "Entered integer isn't positive!\n" << "Enter positive integer again : ";
        std::cin >> n;
    }

    for (int i = 1; i <= n; i++) {
        factorial *= i;  
    }
    std::cout << "Factorial of " << n << " is " << factorial;
   }
void geometricFigures() {
    int n = 0;
    std::cout << "Enter positive value: ";
    std::cin >> n;
    while (n < 1) {
        std::cout << "Entered value isn't positive!\n" << "Enter positive value again : ";
        std::cin >> n;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    int m = 0;
    std::cout << "Enter positive value: ";
    std::cin >> m;
    while (m < 1) {
        std::cout << "Entered value isn't positive!\n" << "Enter positive value again : ";
        std::cin >> m;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    int width = 0;
    std::cout << "Enter width: ";
    std::cin >> width;
    int height = 0;
    std::cout << "Enter height: ";
    std::cin >> height;
    if (width <= 0 && height <=0) {
        std::cout << "Sorry, but we can't build figure without positive value!";
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    int l = 0;
    std::cout << "Enter positive value: ";
    std::cin >> l;
    while (l < 1) {
        std::cout << "Entered value isn't positive!\n" << "Enter positive value again : ";
        std::cin >> l;
    }
    for (int i = 0; i <l; i++) {
       
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }
        for (int k = 0; k <l; k++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
    int t = 0;
    std::cout << "Enter positive value: ";
    std::cin >> t;
    while (t < 1) {
        std::cout << "Entered value isn't positive!\n" << "Enter positive value again : ";
        std::cin >> t;
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j <= i; j++) {
            if (i % 2 == 0) {
                if (j % 2 == 0) { std::cout << 1 << " "; }
                else { std::cout << 0 << " "; }
            }
            else{
                if (j % 2 == 0) { std::cout << 0 << " "; }
                else { std::cout << 1 << " "; }
            }
        }
        std::cout << std::endl;

    }
}
void charManip() {
    char value = 0;
    int totalSum = 0;

    while (true) {
        std::cout << "Enter value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (value > 96 && value < 123) {
            value = toupper(value);
            std::cout << value << std::endl;
        }
        else if (value > 47 && value < 58) {
            value = value - '0';
            totalSum += value;
            std::cout << totalSum << std::endl;
        }
        else if (value == 46) {
            break;
        }
        else {
            std::cout << "This symbol isn't processed by the program!" << std::endl;

        }
    }
    
}
int main()
{
    //arithmeticProgression();
    //std::cout << FibonacciSequence1(getNumber()); // вивід рекурсивної функції 
    //FibonacciSequence();
    //factorial();
    //geometricFigures();
    charManip();
}
