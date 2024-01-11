#pragma once
#include <string>
#include "Team.h"

enum PlayerClass {
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Weapon {
public:
    std::string name;
    int damage;
    int range;

    Weapon();
};

class Team;

class Player {
private:
    std::string m_Name;
    int health;

    PlayerClass playerClass;
    Weapon* weapon; 
    Team* team;

public:
    
    Player(const std::string& playerName, int playerHealth, PlayerClass playerClass) ;

    std::string getName() const;
    int getHealth() const;
    PlayerClass getPlayerClass() const;

    void setWeapon(Weapon* newWeapon);
    Weapon* getWeapon() const;

    void setTeam(Team* newTeam);
    Team* getTeam() const;

    void printPlayerInfo() const;
};