#pragma once
#include "Tribe.h"
#include <string>
#include "Monster.h"

//class Monster;

class Item
{
public:
	virtual int getPower(Tribe monsterTribeModifier) const { return getBasePower(); }
	virtual int getPower(Monster* monster) const { return getBasePower(); }
	virtual int getBasePower() const { return 0; }

	void setName(const std::string& name) { m_name = name; }
	const std::string getName() const { return m_name; }
	virtual std::string getFullInfo() const = 0;

protected:
	std::string m_name;
	//other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
	Weapon(const std::string& name, int power)
	{
		setName(name);
		m_power = power;
	}

	int getBasePower() const override
	{
		return m_power;
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: None\n";
	}

protected:
	int m_power = 0;
};

class UndeadWeapon : public Weapon
{
public:
	UndeadWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Tribe monsterTribeModifier) const override
	{
		switch (monsterTribeModifier)
		{
		case Tribe::Undead:
			return getBasePower() * 2;
		case Tribe::Human:
		case Tribe::Amorphous:
		case Tribe::God:
		case Tribe::Dark_Creature:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: x2 vs UNDEADS!\n";
	}
};

class AmorphousWeapon : public Weapon
{
public:
	AmorphousWeapon(const std::string& name, int power) : Weapon(name, power) {}

	virtual int getPower(Monster* monster) const override
	{
		switch (monster->getTribe())
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::Amorphous:
			return monster->getLevel()/ 2;
		case Tribe::God:
		case Tribe::Dark_Creature:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Reduce lvl of Amorphous by 2!\n";
	}
};

class GodWeapon : public Weapon
{
public:
	GodWeapon (const std::string& name, int power): Weapon (name, power){}

	virtual int getPower(Monster* monster) const override
	{
		switch (monster->getTribe())
		{
		case Tribe::Undead:
		case Tribe::Human:
		case Tribe::Amorphous:
		case Tribe::God:
			return  transformMonsterLevel(monster->getLevel());
		case Tribe::Dark_Creature:
		default:
			return getBasePower();
		}
	}

	virtual std::string getFullInfo() const override
	{
		return "\"" + getName() + "\"" + ", power:" + std::to_string(getBasePower()) + ", skills: Turns lvl of Gods into 10!\n";
	}
private:
	int transformMonsterLevel(int level) const {return 5;}
};
//TODO: Add new Item type with unique properties