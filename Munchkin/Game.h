#pragma once
#include "Munchkin.h"
#include "ItemDeck.h"
//#include "MonsterDeck.h"
#include "ModifierDeck.h"
#include "DeckBase.h"

class Game
{
public:
	Game() = default;
	void run();

private:
	//void generateMunchkinInitialCards(); // base code 
	void generateMunchkinInitialCards();
	Monster* generateMonster();


private:
	Munchkin m_munchkin;
	ItemDeck m_itemsDeck;
	ModifierDeck m_modifiersDeck;
	MonsterDeck m_monstersDeck;
};