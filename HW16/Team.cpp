#include <iostream>
#include "Team.h"
#include "Player.h"

Team::Team(const std::string& name, int numMembers) 
    : teamName(name), 
    numberOfMembers(numMembers) 
{}

Team::~Team() {
    for (Player* player : players) {
        delete player;
    }
}

std::string Team::getTeamName() const {
    return teamName;
}

int Team::getNumberOfMembers() const {
    return numberOfMembers;
}

const std::vector<Player*>& Team::getPlayers() const {
    return players;
}

bool Team::AddPlayer(Player* player) {
    if (std::find(players.begin(), players.end(), player) == players.end()) {
        players.push_back(player);
        return true;
    }
    return false;
}

bool Team::RemovePlayer(Player* player) {
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
        return true;
    }
    return false;
}