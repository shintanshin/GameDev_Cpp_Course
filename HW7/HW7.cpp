#include <iostream>
#include <cstdlib>
#include <ctime>

void guessNum() {
    std::cout << "This is the Number Guessing Game!\nThis game generates random number (0 - 50) and you must guess it! \nIf you want to exit just enter -1 \n\n";
    int num = 0;
    int bestRound = 0;
   while(true)
   {
       if (num == -1) {
           std::cout << "Huh! Looser! Come back when you'll be brave enough!\n";
           break;
       }
       int rounds = 1;
       std::srand(std::time(nullptr));
       const int generatingRange = 50;
       const int generatedNum = std::rand() % (generatingRange + 1);
       std::cout << "Make your guess: ";
       std::cin >> num;
       while (true) {
           while (num < -1 || num >50) {
               std::cout << "WOW! It's out of Guessing range! You should use range from 0 to 50!\nTry again: ";
               std::cin >> num;
               rounds++;
           }
           if (num == generatedNum) {
               std::cout << "\n\nHooray!!! You WIN! "<< generatedNum << " was my guess indeed :)"<< std::endl;
               std::cout << "You spent " <<rounds<<" tries!" << std::endl;
               if (bestRound == 0) { bestRound = rounds; }
               if (bestRound > rounds) { bestRound = rounds; }
               std::cout << "Your highscore is " << bestRound << " tries!" << std::endl;
               std::cout << "Go another round!\n\n" << std::endl;
               break;
           }
           if (num == -1) {break;}
           if (num - 20 >= generatedNum) {
               std::cout << "Wow! It's tooooo much! Try less.\nMake your guess: ";
               std::cin >> num;
           }
           else if (num - 10 >= generatedNum) {
               std::cout << "Too much! Try less.\nMake your guess: ";
               std::cin >> num;
           }
           else if (num > generatedNum) {
               std::cout << "Almost here! Try little bit less.\nMake your guess: ";
               std::cin >> num;
           }
           else if (num + 20 <= generatedNum) {
               std::cout << "Wow! It's significantly less! Try more.\nMake your guess: ";
               std::cin >> num;
           }
           else if (num + 10 <= generatedNum) {
               std::cout << "It's less! Try more.\nMake your guess: ";
               std::cin >> num;
           }
           else if (num < generatedNum) {
               std::cout << "Almost here! Try little bit more.\nMake your guess: ";
               std::cin >> num;
           }
           rounds++;
       }
   }

}

int main()
{
    guessNum();
}
