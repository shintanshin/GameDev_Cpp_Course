#include "Runaway.h"
#include "Munchkin.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
	munchkin->updateLevelBy(-m_levelToDowngrade);
}


void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
	if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
	{
		Runaway_LevelDowngrade::apply(munchkin);
	}
}


void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)  
{
    std::vector<Modifier*>& modifiers = munchkin->getModifiers();

    if (modifiers.size() >= m_ModifierToDowngrade)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));

        std::random_shuffle(modifiers.begin(), modifiers.end());

        modifiers.erase(modifiers.begin(), modifiers.begin() + m_ModifierToDowngrade);

    }
    else
    {
        modifiers.clear();
    }
}

void Runaway_ItemEquipedRemoval::apply(Munchkin* munchkin)
{
    std::vector<Item*>& items = munchkin->getItems();

    if (items.size() >= m_itemToDowngrade)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));

        std::random_shuffle(items.begin(), items.end());

        items.erase(items.begin(), items.begin() + m_itemToDowngrade);
    }
    else
    {
        items.clear();
    }
}
