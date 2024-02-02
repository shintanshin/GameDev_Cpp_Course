#include "MonsterDeck.h"

#include "Monster.h"
#include "Runaway.h"

//MonsterDeck::MonsterDeck()
//{
//	m_monstersDatabase =
//	{
//		//#TODO: Think of new monsters, feel free to use official Munchkin games as a reference
//		new Monster{"Tht Whch Hs N Vwls", 18, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {3}},
//		new Monster{"Grape Old Ones", 12, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {15}},
//		new Monster{"Ozathoth", 18, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {1}},
//		new Monster{"Foggot", 6, Tribe::Amorphous, new Runaway_ModifierFromHandRemoval {1}},
//
//		new Monster{"Shog Goth", 1, Tribe::Human, new Runaway_LevelDowngrade{1}},
//		new Monster{"Eldride Hawrer", 1, Tribe::Human, new Runaway_ModifierFromHandRemoval {1}},
//		new Monster{"Tchoo-Tchoo People", 6, Tribe::Human, new Runaway_ModifierFromHandRemoval {1}},
//
//		new Monster{"Froggoth", 12, Tribe::Dark_Creature, new Runaway_ModifierFromHandRemoval {2}},
//		new Monster{"Nyuhees", 8, Tribe::Dark_Creature, new Runaway_ItemEquipedRemoval {1}},
//		new Monster{"Coggoth", 8, Tribe::Dark_Creature, new Runaway_ModifierFromHandRemoval {2}},
//		new Monster{"Nighty Gaunts", 14, Tribe::Dark_Creature, new Runaway_ModifierFromHandRemoval {2}},
//
//		new Monster{"The King in Pink", 16, Tribe::Undead, new Runaway_ModifierFromHandRemoval {2}},
//		new Monster{"The Unpronounceable Evil", 10, Tribe::Undead, new Runaway_ModifierFromHandRemoval {2}},
//		new Monster{"Aughost Derwrinht", 2, Tribe::Undead, new Runaway_ModifierFromHandRemoval {1}},
//		new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}, new Runaway_ModifierFromHandRemoval {1}},
//
//		new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngrade{1},new Runaway_ModifierFromHandRemoval {3}},
//		new Monster{"Great Cthulhu", 20, Tribe::God, new Runaway_LevelDowngrade{1}, new Runaway_ModifierFromHandRemoval {3}},
//		new Monster{"Chibithulhu", 2, Tribe::God, new Runaway_LevelDowngrade{1}, new Runaway_ModifierFromHandRemoval {3}}
//	};
//}
//
//MonsterDeck::~MonsterDeck()
//{
//	//TODO: Clear memory
//}

//Monster* MonsterDeck::generateMonster() const
//{
//	//#TODO: this call should return new monster every time
//	//either for as long as the same game is being played
//	//or unless ALL cards were generated from database to the game - in this case 
//	//make ALL cards available again
//
//	const int choice = std::rand() % m_monstersDatabase.size();
//	return m_monstersDatabase[choice];
//}