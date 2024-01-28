#include "Weapon.h"

float SniperRifle::getPrecision(int distance, int effectiveRange) const
{
	if (distance > effectiveRange)
	{
		return 0.2f;
	}
	if (distance > effectiveRange/2)
	{
		return 1.5f;
	}
	if (distance > effectiveRange/4)
	{
		return 5.0f;
	}
	return 1.0f;
}
SniperRifle::SniperRifle()
{
	effectiveRange = 2000;
	damageLevel = 5;
}

float Pistol::getPrecision(int distance, int effectiveRange) const
{
	if (distance > effectiveRange)
	{
		return 0.2f;
	}
	if (distance > effectiveRange/2)
	{
		return 1.5f;
	}
	if (distance > effectiveRange/4)
	{
		return 5.0f;
	}
	return 1.0f;
}

Pistol::Pistol()
{
	effectiveRange = 300;
	damageLevel = 2;
}

float AssaultRifle::getPrecision(int distance, int effectiveRange) const
{
	if (distance > effectiveRange)
	{
		return 0.2f;
	}
	if (distance > effectiveRange/2)
	{
		return 1.5f;
	}
	if (distance > effectiveRange/4)
	{
		return 5.0f;
	}
	return 1.0f;
}

AssaultRifle::AssaultRifle()
{
	effectiveRange = 900;
	damageLevel = 4;
}

float BareHand::getHit(int distance, int effectiveRange) const
{
	if (distance > effectiveRange)
	{
		return 0.2f;
	}
	if (distance > effectiveRange/2)
	{
		return 1.5f;
	}
	if (distance > 0)
	{
		return 5.0f;
	}
	return 1.0f;
}

BareHand::BareHand()
{
	effectiveRange = 5;
	damageLevel = 1;
}

float Axe::getHit(int distance, int effectiveRange) const
{
	if (distance > effectiveRange)
	{
		return 0.2f;
	}
	if (distance > effectiveRange/2)
	{
		return 1.5f;
	}
	if (distance > effectiveRange/4)
	{
		return 5.0f;
	}
	return 1.0f;
}

Axe::Axe()
{
	effectiveRange = 20;
	damageLevel = 3;
}

int RangedWeapon::getDamageRate(int distance) const
{
	if (distance <= getEffectiveRange()) {
		return static_cast<int>(getPrecision(distance, getEffectiveRange()) * 10);
	}
	else {
		return 0;
	}
}

int MeleeWeapon::getDamageRate(int distance) const
{
	if (distance <= getEffectiveRange()) {
		return static_cast<int>(getHit(distance, getEffectiveRange()) * 5);
	}
	else {
		return 0;
	}
}
