#pragma once

class PlayerClass
{
public:
	virtual float getDamageMultiplier() const = 0;
	virtual float getArmorMultiplier() const = 0;
	virtual float getMissChance() const = 0;

	virtual ~PlayerClass() {}	//virtual c-tor for proper destruction of the objects in hierarchy
};

class DefaultClass : public PlayerClass
{
public:
	virtual float getDamageMultiplier() const override { return 1.0f; }
	virtual float getArmorMultiplier() const override { return 1.0f; }
	virtual float getMissChance() const override { return 0.0f; }

private:
	
};

class Defender : public PlayerClass
{
public:
	
	virtual float getDamageMultiplier() const override { return 1.0f; }
	virtual float getArmorMultiplier() const override { return 1.2f; }
	virtual float getMissChance() const override { return 0.1f; } 
};

class Attacker : public PlayerClass
{
	virtual float getDamageMultiplier() const override { return 1.1f; }
	virtual float getArmorMultiplier() const override { return 1.0f; }
	virtual float getMissChance() const override { return 0.0f; }
};

class DefenderClass : public Defender
{

};

class AttackerClass : public Attacker
{
 
};

class LuckyManClass : public Defender
{
	virtual float getMissChance() const override { return 0.3f; }
};

class BerserkClass : public AttackerClass, public LuckyManClass
{
	virtual float getDamageMultiplier() const override { return 1.1f; }
	virtual float getMissChance() const override { return 0.3f; }
	virtual float getArmorMultiplier() const override { return 0.8f; }

};