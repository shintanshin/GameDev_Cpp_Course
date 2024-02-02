#pragma once
#include <string>

//forwad declaration
class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	//#TODO: Implement in all children classes, see class Item for reference
	virtual std::string getFullInfo() { return ""; }
	//virtual std::string getFullInfo() const = 0;
};

class Runaway_LevelDowngrade : public Runaway
{
public:
	Runaway_LevelDowngrade(int level = 1) : m_levelToDowngrade(level) {}
	void apply(Munchkin* munchkin)override;
	std::string getFullInfo() override { return ""; }

protected:
	int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
	Runaway_LevelDowngradeIf(int level, int minimalMunchkinLevel)
		: Runaway_LevelDowngrade(level), m_minimalMunchkinLevelToApply(minimalMunchkinLevel){}
	void apply(Munchkin* munchkin);
	std::string getFullInfo() override{ return "Your lvl will be downgrade by " + std::to_string(m_levelToDowngrade); }

private:
	int m_minimalMunchkinLevelToApply;
};

//Remove a card from hand(modifier) at random
class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	Runaway_ModifierFromHandRemoval(int item = 1) : m_ModifierToDowngrade(item) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override{ return "Lose " + std::to_string(m_ModifierToDowngrade) + " random cards from your hand"; }

private:
	int  m_ModifierToDowngrade;
};

//Remove equiped item from Outfit with biggest base power
class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	Runaway_ItemEquipedRemoval(int item = 0) : m_itemToDowngrade (item){}
	void apply(Munchkin* munchkin)override;
	std::string getFullInfo() override { return "Lose " + std::to_string(m_itemToDowngrade) + " random items from your hand"; }

private:
	int m_itemToDowngrade;
};