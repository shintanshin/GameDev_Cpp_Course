#pragma once
#include <vector>
#include <string>
#include "Player.h"

class Player;
class Team {
private:
    std::string teamName;
    int numberOfMembers;
    std::vector<Player*> players; 

public:
    Team(const std::string& name, int numMembers);
    ~Team();

    std::string getTeamName() const;
    int getNumberOfMembers() const;

    bool AddPlayer(Player* player);
    bool RemovePlayer(Player* player);

    const std::vector<Player*>& getPlayers() const;
};
