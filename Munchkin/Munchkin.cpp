#include "Munchkin.h"
#include "Item.h"
#include "Modifier.h"
#include "DeckBase.h"

void Munchkin::updateLevelBy(int levels)
{
    if (m_level + levels <= 0)
    {
        m_level = 1;
    }
    else
    {
        m_level += levels;
    }

}

Modifier* Munchkin::popModifier(int idx)
{
    if (idx >= m_modifiers.size() || idx < 0)
    {
        return nullptr;
    }

    Modifier* modifier = m_modifiers[idx];


    m_modifiers.erase(m_modifiers.begin() + idx);
    return modifier;

}
