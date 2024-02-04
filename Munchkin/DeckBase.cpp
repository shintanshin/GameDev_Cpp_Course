#include "DeckBase.h"
#include "Monster.h"
#include "Modifier.h"
#include "Item.h"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm> 
#include "Victory.h"
#include <vector>
#include <set>


MonsterDeck::MonsterDeck()
{
    m_monstersDatabase =
    {
		new Monster{"Grape Old Ones", 10, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {100}, new Victory_GetModifier {2}},
		new Monster{"Ozathoth", 16, Tribe::Amorphous, new Runaway_LevelDowngradeIf {1, 4}, new Victory_LvlUp{2}},
		new Monster{"Tht Whch Hs N Vwls", 8, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {2}, new Victory_LvlUp {2}},
		new Monster{"Foggot", 6, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {1}, new Victory_GetModifier {2}},

		new Monster{"Shog Goth", 1, Tribe::Human, new Runaway_LevelDowngradeIf {1, 1}, new Victory_GetModifier {1}},
		new Monster{"Eldride Hawrer", 1, Tribe::Human, new Runaway_ItemEquipedRemoval {1}, new Victory_GetItem{1}},
		new Monster{"Tchoo-Tchoo People", 4, Tribe::Human, new Runaway_ItemEquipedRemoval {1}, new Victory_GetModifier {2}},

		new Monster{"Froggoth", 12, Tribe::Dark_Creature, new Runaway_LevelDowngradeIf {3, 4}, new Victory_LvlUp{2}},
		new Monster{"Nyuhees", 4, Tribe::Dark_Creature, new  Runaway_LevelDowngradeIf {1, 1}, new Victory_GetModifier {2}},
		new Monster{"Coggoth", 8, Tribe::Dark_Creature, new Runaway_ItemEquipedRemoval {1}, new Victory_GetItem{1}},
		new Monster{"Nighty Gaunts", 10, Tribe::Dark_Creature, new Runaway_ModifierFromHandRemoval {3}, new Victory_GetItem{1}},

		new Monster{"The King in Pink", 16, Tribe::Undead, new Runaway_LevelDowngradeIf {3, 3}, new Victory_LvlUp{2}},
		new Monster{"The Unpronounceable Evil", 10, Tribe::Undead, new Runaway_LevelDowngradeIf {2, 5}, new Victory_GetModifier {2}},
		new Monster{"Aughost Derwrinht", 2, Tribe::Undead, new Runaway_LevelDowngradeIf {1, 1}, new Victory_GetModifier {1}},
		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_ModifierFromHandRemoval {1}, new Victory_GetItem{1}},

		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_ModifierFromHandRemoval {3}, new Victory_LvlUp{3}},
		new Monster{"Great Cthulhu", 20, Tribe::God, new Runaway_LevelDowngradeIf {3, 5}, new Victory_LvlUp{2}},
		new Monster{"Chibithulhu", 2, Tribe::God, new Runaway_ItemEquipedRemoval {1}, new Victory_GetItem{1}}
    };
}
MonsterDeck::~MonsterDeck()
{
	for (Monster* monster : m_monstersDatabase)
	{
		delete monster;
	}
	m_monstersDatabase.clear();
}

void MonsterDeck::generate() 
{
	generateMonster();
}

Monster* MonsterDeck::generateMonster() { 
	if (m_monstersDatabase.empty()) {
		return nullptr;
	}

	 int choice = std::rand() % m_monstersDatabase.size();
	Monster* selectedMonster = m_monstersDatabase[choice];

	while (m_usedMonsterNames.count(selectedMonster->getName()) > 0) {
		choice = std::rand() % m_monstersDatabase.size();
		selectedMonster = m_monstersDatabase[choice];
	}

	m_usedMonsterNames.insert(selectedMonster->getName());

	m_monstersDatabase.erase(m_monstersDatabase.begin() + choice);

	return selectedMonster;
}

ModifierDeck::ModifierDeck()
{
	m_modifiersDataBase =
	{
		{new SimpleModifier{3}},
		{new SimpleModifier{3}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{2}},
		{new SimpleModifier{4}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new SimpleModifier{1}},
		{new DoubleMunchkinLevel{}},
		{new DoubleMunchkinLevel{}},
		{new HalvesMonsterLevel{Tribe::Undead}},
		{new HalvesMonsterLevel{Tribe::God}}
	};

}

ModifierDeck::~ModifierDeck()
{
	for (Modifier* modifier : m_modifiersDataBase)
	{
		delete modifier;
	}
	m_modifiersDataBase.clear();
}

Modifier* ModifierDeck::generateModifier()
{
	if (m_modifiersDataBase.empty()) {
		return nullptr;
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<size_t> distribution(0, m_modifiersDataBase.size() - 1);
	size_t randomIndex = distribution(gen);

	if (randomIndex < m_modifiersDataBase.size()) {
		Modifier* generatedModifier = m_modifiersDataBase.at(randomIndex);
		m_modifiersDataBase.erase(m_modifiersDataBase.begin() + randomIndex);
		return generatedModifier;
	}
}

std::vector<Modifier*> ModifierDeck::generateModifiers()
{
	std::vector<Modifier*> result;

	if (!m_modifiersDataBase.empty()) {
		Modifier* generatedModifier = generateModifier();

		if (generatedModifier) {
			result.push_back(generatedModifier); 
		}
	}

	return result;
}

ItemDeck::ItemDeck()
{
	std::ifstream file("items_database.txt");

	if (file.is_open())
	{
		std::string line;

		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			std::string type, name, params;

			if (std::getline(iss, type, ';') && std::getline(iss, name, ';') && std::getline(iss, params))
			{
				if (type == "Weapon")
				{
					int power = std::stoi(params);
					m_itemsDataBase.push_back(new Weapon(name, power));
				}
				else if (type == "UndeadWeapon")
				{
					int power = std::stoi(params);
					m_itemsDataBase.push_back(new UndeadWeapon(name, power));
				}
				else if (type == "AmorphousWeapon")
				{
					int power = std::stoi(params);
					m_itemsDataBase.push_back(new AmorphousWeapon(name, power));
				}
				else if (type == "GodWeapon")
				{
					int power = std::stoi(params);
					m_itemsDataBase.push_back(new GodWeapon(name, power));
				}
			}
		}
		file.close();
	}
}

ItemDeck::~ItemDeck()
{
	for (Item* item : m_itemsDataBase)
	{
		delete item;
	}
	m_itemsDataBase.clear();
}

Item* ItemDeck::generateItem() 
{
	if (m_itemsDataBase.empty()) {
		return nullptr;
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<size_t> distribution(0, m_itemsDataBase.size() - 1);
	size_t randomIndex = distribution(gen);

	if (randomIndex < m_itemsDataBase.size()) {
		Item* generatedItem = m_itemsDataBase.at(randomIndex);
		m_itemsDataBase.erase(m_itemsDataBase.begin() + randomIndex);
		return generatedItem;
	}
}

std::vector<Item*> ItemDeck::generateItems()
{
	std::vector<Item*> result;

	if (!m_itemsDataBase.empty()) {
		Item* generatedItem = generateItem();

		if (generatedItem) {
			result.push_back(generatedItem);  
		}
	}
	return result;
}
