#pragma once
class Weapon
{
public:
	virtual int getDamageRate(int distance) const = 0;

	virtual int getEffectiveRange() const { return effectiveRange; }
	virtual int getDamageLevel() const { return damageLevel; }
protected:
	int effectiveRange = 0; 
	int damageLevel = 0;    
};

class RangedWeapon : public Weapon
{
public:
	virtual int getDamageRate(int distance) const override;

protected:
	virtual float getPrecision(int distance, int effectiveRange) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance, int effectiveRange) const override;
public:
	SniperRifle();
};

class Pistol : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance, int effectiveRange) const override;
public:
	Pistol();
};

class AssaultRifle : public RangedWeapon
{
protected:
	virtual float getPrecision(int distance, int effectiveRange) const override;
public:
	AssaultRifle();
};

class MeleeWeapon : public Weapon
{
public:
	virtual int getDamageRate(int distance) const override;
	
protected: 
	virtual float getHit(int distance, int effectiveRange) const { return 1.0f; }
};

class BareHand : public MeleeWeapon
{
protected:
	virtual float getHit(int distance, int effectiveRange) const override;

public:
	BareHand();
};

class Axe : public MeleeWeapon
{
protected:
	virtual float getHit(int distance, int effectiveRange) const override;
public:
	Axe();
};