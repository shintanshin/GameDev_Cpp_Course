#include <iostream>
#include "Player.h"


Player::Player(const std::string& playerName, int playerHealth, PlayerClass playerClass)
    : m_Name(playerName), 
    health(playerHealth), 
    playerClass(playerClass), 
    weapon(nullptr),
    team(nullptr){}

Weapon::Weapon()
    : damage (0), range(0){}

std::string Player::getName() const {
    return m_Name;
}

int Player::getHealth() const {
    return health;
}

PlayerClass Player::getPlayerClass() const {
    return playerClass;
}

void Player::setWeapon(Weapon* newWeapon) {
    delete weapon;
    weapon = newWeapon;
}

Weapon* Player::getWeapon() const {
    return weapon;
}
void Player::setTeam(Team* newTeam) {
    team = newTeam;
}

Team* Player::getTeam() const {
    return team;
}

void Player::printPlayerInfo() const {
    std::cout << "Name: " << m_Name << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Player Class: ";

    switch (playerClass) {
    case ASSAULT:
        std::cout << "Assault";
        break;
    case SUPPORT:
        std::cout << "Support";
        break;
    case SNIPER:
        std::cout << "Sniper";
        break;
    case MEDIC:
        std::cout << "Medic";
        break;
    }

    std::cout << std::endl;

    if (weapon != nullptr) {
        std::cout << "Weapon Info: " << weapon->name << ", Damage: " << weapon->damage << ", Range: " << weapon->range << std::endl;
    }

    if (team != nullptr) {
        std::cout << "Team: " << team->getTeamName() << std::endl;
    }
}