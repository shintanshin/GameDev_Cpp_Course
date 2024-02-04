#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "DeckBase.h"


class Munchkin;
class Modifier;
class ModifierDeck;
class ItemDeck;
class DeckBase;
class Item;

class Victory {
public:
	virtual void apply(Munchkin* munchkin)= 0;
	//#TODO: Implement in all children classes, see class Item for reference
	virtual std::string getFullInfo() { return ""; }

	//virtual void apply(Munchkin* munchkin, DeckBase* modifierDeck) = 0;
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
	Victory_GetItem(int item, ItemDeck* deck) : m_getItem(item), m_itemDeck(deck) {}
	//Victory_GetItem(int item): m_getItem(item){} // base code

	void apply(Munchkin* munchkin)override;
	
	std::string getFullInfo() override { return "Get " + std::to_string(m_getItem) + " random Items"; }


private:
	int m_getItem;
	//std::vector<Item*> m_itemsDatabase;
	ItemDeck* m_itemDeck;
};

class Victory_GetModifier : public Victory {
public:

	Victory_GetModifier(int item = 0) : m_getModifier(item) {}

	//int getGetModifier() const {return m_getModifier;}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override { return "Get " + std::to_string(m_getModifier) + " random modifier"; }
	


private:
	int m_getModifier;
	std::vector<Modifier*> m_modifiersDataase;
	//ModifierDeck* m_modifierDeck;
};