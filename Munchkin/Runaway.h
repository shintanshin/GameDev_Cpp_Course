#pragma once
#include <string>

class Munchkin;

class Runaway
{
public:
	virtual void apply(Munchkin* munchkin) = 0;

	virtual std::string getFullInfo() { return ""; }
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

class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
	Runaway_ModifierFromHandRemoval(int item = 1) : m_ModifierToDowngrade(item) {}
	void apply(Munchkin* munchkin) override;
	std::string getFullInfo() override{ return "Lose " + std::to_string(m_ModifierToDowngrade) + " random cards from your hand"; }

private:
	int  m_ModifierToDowngrade;
};

class Runaway_ItemEquipedRemoval : public Runaway
{
public:
	Runaway_ItemEquipedRemoval(int item = 0) : m_itemToDowngrade (item){}
	void apply(Munchkin* munchkin)override;
	std::string getFullInfo() override { return "Lose " + std::to_string(m_itemToDowngrade) + " random items from your hand"; }

private:
	int m_itemToDowngrade;
};