#include <string>

#include "Weapon.h"
#include "PlayerClass.h"
#include "Player.h"

int main()
{
	Player player1("OnePunchMan", new SniperRifle, new AttackerClass);
	Player player2("JohnCena", new Axe, new DefenderClass);
	Player player3("Rembo", new AssaultRifle, new LuckyManClass);
	Player player4("Sub Zero", new BareHand, new DefenderClass);

	player1.attack(player2, 1000);
	player1.attack(player1, 350);
	player2.attack(player3, 15);
	player4.attack(player1, 20);
}