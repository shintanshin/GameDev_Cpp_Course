#pragma once
#include "Munchkin.h"
#include "DeckBase.h"

class Game
{
public:
	Game() = default;
	void run();

private:
	void generateMunchkinInitialCards();
	Monster* generateMonster();


private:
	Munchkin m_munchkin;
	ItemDeck m_itemsDeck;
	ModifierDeck m_modifiersDeck;
	MonsterDeck m_monstersDeck;
};