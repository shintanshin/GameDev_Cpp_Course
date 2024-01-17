#include "Weapon.h"

float SniperRifle::getPrecision(int distance) const
{
	if (distance > 2000)
	{
		return 0.2f;
	}
	if (distance > 1000)
	{
		return 1.5f;
	}
	if (distance > 300)
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

float Pistol::getPrecision(int distance) const
{
	if (distance > 300)
	{
		return 0.2f;
	}
	if (distance > 150)
	{
		return 1.5f;
	}
	if (distance > 10)
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

float AssaultRifle::getPrecision(int distance) const
{
	if (distance > 900)
	{
		return 0.2f;
	}
	if (distance > 450)
	{
		return 1.5f;
	}
	if (distance >100)
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

float BareHand::getHit(int distance) const
{
	if (distance > 5)
	{
		return 0.2f;
	}
	if (distance > 3)
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

float Axe::getHit(int distance) const
{
	if (distance > 20)
	{
		return 0.2f;
	}
	if (distance > 10)
	{
		return 1.5f;
	}
	if (distance > 5)
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
