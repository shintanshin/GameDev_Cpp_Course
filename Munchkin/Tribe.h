#pragma once
enum class Tribe
{
	Human,
	Undead,
	Amorphous,
	God,
	Dark_Creature,
	Count	//call static_cast<int>(Tribe::Count) to get the number of entries in enum
};