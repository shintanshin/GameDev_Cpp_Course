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



DeckBase::DeckBase()
{
}

DeckBase::~DeckBase()
{
}

MonsterDeck::MonsterDeck()
{
    m_monstersDatabase =
    {
		new Monster{"Grape Old Ones", 12, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {100}, new Victory_LvlUp {2}},
		new Monster{"Ozathoth", 18, Tribe::Amorphous, new Runaway_LevelDowngradeIf {1, 4}, new Victory_LvlUp{2}},
		new Monster{"Tht Whch Hs N Vwls", 18, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {2}, new Victory_GetModifier{2}},
		new Monster{"Foggot", 6, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {1}, new Victory_GetModifier {2}},

		new Monster{"Shog Goth", 1, Tribe::Human, new Runaway_LevelDowngradeIf {1, 1}, new Victory_GetModifier {1}},
		//new Monster{"Eldride Hawrer", 1, Tribe::Human, new Runaway_ItemEquipedRemoval {1}},
		new Monster{"Tchoo-Tchoo People", 6, Tribe::Human, new Runaway_ItemEquipedRemoval {1}, new Victory_GetModifier {2}},

		new Monster{"Froggoth", 12, Tribe::Dark_Creature, new Runaway_LevelDowngradeIf {3, 1}, new Victory_LvlUp{2}},
		//new Monster{"Nyuhees", 8, Tribe::Dark_Creature, new  Runaway_LevelDowngradeIf {2, 1}},
		//new Monster{"Coggoth", 8, Tribe::Dark_Creature, new Runaway_ItemEquipedRemoval {1}},
		//new Monster{"Nighty Gaunts", 14, Tribe::Dark_Creature, new Runaway_ModifierFromHandRemoval {3}},

		new Monster{"The King in Pink", 16, Tribe::Undead, new Runaway_LevelDowngradeIf {3, 3}, new Victory_LvlUp{2}},
		new Monster{"The Unpronounceable Evil", 10, Tribe::Undead, new Runaway_LevelDowngradeIf {2, 1}, new Victory_GetModifier {2}},
		new Monster{"Aughost Derwrinht", 2, Tribe::Undead, new Runaway_LevelDowngradeIf {1, 1}, new Victory_GetModifier {1}},
		//new Monster{"Vampire", 3, Tribe::Undead, new Runaway_ModifierFromHandRemoval {1}},

		//new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_ModifierFromHandRemoval {3}},
		new Monster{"Great Cthulhu", 20, Tribe::God, new Runaway_ItemEquipedRemoval {3}, new Victory_LvlUp{2}}
		////new Monster{"Chibithulhu", 2, Tribe::God, new Runaway_ModifierFromHandRemoval {3}}
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
	// Here you can include any common code for generating cards,
	// or leave it empty if there's nothing specific to include.

	// For now, I'll just call the specific generateMonster method.
	generateMonster();
}

//Monster* MonsterDeck::generateMonster() 
//{
//	if (m_monstersDatabase.empty()) {
//		return nullptr;
//	}
//	const int choice = std::rand() % m_monstersDatabase.size();
//	Monster* selectModofier = m_monstersDatabase[choice];
//	m_monstersDatabase.erase(m_monstersDatabase.begin() + choice);
//	return selectModofier;
//}

Monster* MonsterDeck::generateMonster() {   // return unic monster each iteration
	if (m_monstersDatabase.empty()) {
		return nullptr;
	}

	 int choice = std::rand() % m_monstersDatabase.size();
	Monster* selectedMonster = m_monstersDatabase[choice];

	// Перевіряємо, чи монстр ще не розігрувався
	while (m_usedMonsterNames.count(selectedMonster->getName()) > 0) {
		// Якщо монстр уже розігрувався, вибираємо новий випадковий монстр
		choice = std::rand() % m_monstersDatabase.size();
		selectedMonster = m_monstersDatabase[choice];
	}

	// Додаємо ім'я розіграного монстра до контейнера використаних монстрів
	m_usedMonsterNames.insert(selectedMonster->getName());

	// Видаляємо монстра з бази даних
	m_monstersDatabase.erase(m_monstersDatabase.begin() + choice);

	return selectedMonster;
}

ModifierDeck::ModifierDeck()
{
	m_modifiersDatabase =
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
	for (Modifier* modifier : m_modifiersDatabase)
	{
		delete modifier;
	}
	m_modifiersDatabase.clear();
}

//#TODO: This code is similar to the one used in MonsterDeck
//Combine it under one hierarchy using inheritance
//Or move duplicated code into its own Helper Class and use composition of it
//In ModifierDeck and MonsterDeck

//Modifier* ModifierDeck::generateModifier()const  // base code
//{
//
//	unsigned int idx = std::rand() % m_modifiersDatabase.size();
//	return m_modifiersDatabase[idx];
//	/*if (m_modifiersDatabase.empty()) {
//		return nullptr;
//	}
//
//	unsigned int idx = std::rand() % m_modifiersDatabase.size();
//	Modifier* selectModofier = m_modifiersDatabase[idx];
//	m_modifiersDatabase.erase(m_modifiersDatabase.begin() + idx);
//
//	return selectModofier;*/
//}

//std::vector<Modifier*> ModifierDeck::generateModifier()  //this code is works too!!!
//{
//	std::vector<Modifier*> selectModifier;
//
//	if (m_modifiersDatabase.empty()) {
//		return selectModifier;
//	}
//
//	std::random_device rd;
//	std::default_random_engine rng(rd());
//
//	std::shuffle(m_modifiersDatabase.begin(), m_modifiersDatabase.end(), rng);
//
//	selectModifier.push_back(m_modifiersDatabase.back());
//	m_modifiersDatabase.pop_back();
//
//	return selectModifier;
//}

//std::vector<Modifier*>  ModifierDeck::generateModifier() // this code is works!!!
//{
//	std::vector<Modifier*>  selectModifier;
//	if (m_modifiersDatabase.empty()) {
//		return selectModifier;
//	}
//	
//	unsigned int idx = std::rand() % m_modifiersDatabase.size();
//	selectModifier.push_back(m_modifiersDatabase[idx]);
//	m_modifiersDatabase.erase(m_modifiersDatabase.begin() + idx);
//
//	return selectModifier;
//}

//std::vector<Modifier*> ModifierDeck::generateModifiers() this code is works
//{
//	std::vector<Modifier*> modifiersCopy = m_modifiersDatabase;
//
//	std::vector<Modifier*> generatedModifiers;
//
//	while (!modifiersCopy.empty()) {
//		unsigned int idx = std::rand() % modifiersCopy.size();
//		Modifier* selectedModifier = modifiersCopy[idx];
//		generatedModifiers.push_back(selectedModifier);
//
//		// Видаляємо обраний модифікатор з копії
//		modifiersCopy.erase(modifiersCopy.begin() + idx);
//	}
//
//	return generatedModifiers;
//}

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

	//TODO: Move item's database to file in format:
	// type;name; additional if needed params for the type
	//For example:
	//UndeadWeapon;"Holy Grenade";4		//should call UndeadWeapon("Holy Grenade", 4);

	//TODO: Setup more items of diferent types
	/*m_itemsDataBase =
	{ new Weapon{"The Sword of DOOM", 5},
	new UndeadWeapon{"Stinky knife", 2},
	new UndeadWeapon{"Holy grenade", 4},
	new AmorphousWeapon{"Railroad Spike", 3},
	new GodWeapon{"List of Humiliation", 1}	
	};*/
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

	int choice = std::rand() % m_itemsDataBase.size();
	Item* selectedItem = m_itemsDataBase[choice];

	// Перевіряємо, чи монстр ще не розігрувався
	while (m_usedItemNames.count(selectedItem->getName()) > 0) {
		// Якщо монстр уже розігрувався, вибираємо новий випадковий монстр
		choice = std::rand() % m_itemsDataBase.size();
		selectedItem = m_itemsDataBase[choice];
	}

	// Додаємо ім'я розіграного монстра до контейнера використаних монстрів
	m_usedItemNames.insert(selectedItem->getName());

	// Видаляємо монстра з бази даних
	m_itemsDataBase.erase(m_itemsDataBase.begin() + choice);

	return selectedItem;

	/*unsigned int idx = std::rand() % m_itemsDataBase.size(); //base code
	return  m_itemsDataBase[idx];*/
}

std::vector<Item*> ItemDeck::generateItems()  // base code
{
	
		std::vector<Item*> result;

		if (!m_itemsDataBase.empty()) {
			// Використовуємо випадковий генератор
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<size_t> distribution(0, m_itemsDataBase.size() - 1);

			// Випадковий індекс для вибору елемента
			size_t randomIndex = distribution(gen);

			// Додаємо випадковий елемент до результату
			result.push_back(m_itemsDataBase[randomIndex]);
		}

		return result;
	
	//return m_itemsDataBase; // base code
}
 
//std::vector<Item*> ItemDeck::generateItems() 
//{
//	if (m_itemsDataBase.empty()) {
//		return nullptr;
//	}
//
//	int choice = std::rand() % m_itemsDataBase.size();
//	Item* selectedItem = m_itemsDataBase[choice];
//
//	// Перевіряємо, чи монстр ще не розігрувався
//	while (m_usedItemNames.count(selectedItem->getName()) > 0) {
//		// Якщо монстр уже розігрувався, вибираємо новий випадковий монстр
//		choice = std::rand() % m_itemsDataBase.size();
//		selectedItem = m_itemsDataBase[choice];
//	}
//
//	// Додаємо ім'я розіграного монстра до контейнера використаних монстрів
//	m_usedItemNames.insert(selectedItem->getName());
//
//	// Видаляємо монстра з бази даних
//	m_itemsDataBase.erase(m_itemsDataBase.begin() + choice);
//
//	return selectedItem;
//
//}