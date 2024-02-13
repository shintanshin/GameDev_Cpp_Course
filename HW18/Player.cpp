#include "Player.h"
#include <iostream>

Player::~Player()
{
	delete m_class;
	delete m_weapon;
}

void Player::setWeapon(Weapon* weapon)
{
	delete m_weapon;
	m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass)
{
	delete m_class;
	m_class = playerClass;
}

void Player::attack(Player& other, int distance)
{
	if (&other == this)
	{
		std::cout << "\n-------FRIENDLY FIRE!-------\n";
	}

	if (other.isEliminated())
	{
		std::cout << "Player " << other.getName() << " has been already eliminated!\n";
		return;
	}
	float missChance = m_class->getMissChance();
	float randomValue = static_cast<float>(rand()) / RAND_MAX;

	if (randomValue < missChance)
	{
		std::cout << "Player " << getName() << " missed the attack on Player " << other.getName() << "!\n";
		std::cout << "Health left for Player " << other.getName() << ": " << other.m_health << std::endl;
		return;
	}

	const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
	other.m_health -= damage;

	std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
		" with weapon " << typeid(*m_weapon).name() << " with damage " << damage << std::endl;

	std::cout << "Health left for Player " << other.getName() << ": " << other.m_health << std::endl;

	if (other.m_health <= 0)
	{
		other.m_health = 0;	

		std::cout << "Player " << other.getName() << " was eliminated!\n";
	}
}