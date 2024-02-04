#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "DeckBase.h"

class Munchkin;


class Victory {
public:
	virtual void apply(Munchkin* munchkin)= 0;
	virtual std::string getFullInfo() { return ""; }
};

class Victory_LvlUp : public Victory {
public:
	Victory_LvlUp(int lvl = 1) : m_lvlToUp(lvl) {};
	void apply(Munchkin* munchkin)override;
	std::string getFullInfo() override { return "Your lvl will increase by " + std::to_string(m_lvlToUp); }
private:
	int m_lvlToUp;
};


class Victory_GetItem : public Victory {
public:
	Victory_GetItem(int item ) : m_getItem(item) {}// base code

	void apply(Munchkin* munchkin)override;
	
	std::string getFullInfo() override { return "Get " + std::to_string(m_getItem) + " random Items"; }

private:
	int m_getItem;
	ItemDeck* m_itemDeck;
};

class Victory_GetModifier : public Victory {
public:
	Victory_GetModifier(int modifier) : m_getModifier(modifier) {}

	void apply(Munchkin* munchkin) override;

	std::string getFullInfo() override { return "Get " + std::to_string(m_getModifier) + " random modifier"; }
	
private:
	int m_getModifier;
	ItemDeck* m_modifierDeck;
};