#include <iostream>
#include "Player.h"
#include "Team.h"
#include "Rectangle.h"


int main()
{
    Rectangle rectangle1;
    Rectangle rectangle2 (6.5, 5.0);

    std::cout << "Rectangle 1 - Area: " << rectangle1.getArea() << ", Perimeter: " << rectangle1.getPerimeter() << std::endl;
    std::cout << "Rectangle 2 - Area: " << rectangle2.getArea() << ", Perimeter: " << rectangle2.getPerimeter() << std::endl;

    std::cout << std::endl;

    Player player("Rita", 100, SUPPORT);
    Weapon weapon;
    weapon.name = "Glock 23";
    weapon.damage = 17;
    weapon.range = 130;
    player.setWeapon(&weapon);

    Team team("PotatoTeam", 5);
    player.setTeam(&team);

    player.printPlayerInfo();

}