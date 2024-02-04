#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "DeckBase.h"

class Item;
class Modifier;

using uint = unsigned int;

class Munchkin
{
public:
	Munchkin() = default;
	Munchkin(const std::string& name) : m_name(name) {}

	void setName(const std::string& name) { m_name = name; }
	const std::string& getName() const { return m_name; }

	int getLevel() const { return m_level; }
	void updateLevelBy(int levels);

	void addItem(Item* item) {m_items.push_back(item);} // base code
	void setItems(const std::vector<Item*>& items) {m_items = items;} // base code
	std::vector<Item*>& getItems(){ return m_items; } //base code
	
	void removeModifierFromHand() {}
	void removeItemEquipped() {}

	Modifier* popModifier(int idx);

	void addModifier(Modifier* modifier) {m_modifiers.push_back(modifier);}
	void setModifiers(const std::vector<Modifier*>& modifiers) { m_modifiers = modifiers; }// base code
	std::vector<Modifier*>& getModifiers()  { return m_modifiers; } // base code

private:
	uint m_level = 1;
	std::string m_name;

	std::vector<Item*> m_items; //base code
	std::vector<Modifier*> m_modifiers;

};