#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "DeckBase.h"

class Item;
class Modifier;
class ModifierDeck;
class ItemDeck;

using uint = unsigned int;

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name/*, ItemDeck* itemDeck*/) : m_name(name) /* m_itemDeck(itemDeck)*/{}

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	int getLevel() const { return m_level; }
	void updateLevelBy(int levels);

	void addItem(Item* item) {m_items.push_back(item);} // base code
	/*std::vector<Item*>& addItem(Item* item) {
		m_items.push_back(item);
		return m_items;
	}*/

	void setItems(const std::vector<Item*>& items) //base code
	{
		m_items = items;/*m_items.insert(m_items.end(), items.begin(), items.end());*/
	}

	std::vector<Item*>& getItems(){ return m_items; } //base code
	

	void removeModifierFromHand() {}
	void removeItemEquipped() {}

	Modifier* popModifier(int idx);

	std::vector<Modifier*>& getModifiers()  { return m_modifiers; } // base code
	void addModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }// base code

private:
	uint m_level = 1;
	std::string m_name;

	std::vector<Item*> m_items; //base code
	std::vector<Modifier*> m_modifiers;

};