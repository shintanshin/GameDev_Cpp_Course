#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Item;
class Modifier;
class ModifierDeck;

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

	void addItem(Item* item);
	void setItems(const std::vector<Item*>& items); //base code
	std::vector<Item*>& getItems();

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