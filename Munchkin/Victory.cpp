#include "Victory.h"
#include "Runaway.h"
#include "Munchkin.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "DeckBase.h"
#include "Item.h"
#include <random>

void Victory_LvlUp::apply(Munchkin* munchkin)
{
    munchkin->updateLevelBy(+m_lvlToUp);
}

void Victory_GetModifier::apply(Munchkin* munchkin)
{
    size_t itemCountBefore = munchkin->getModifiers().size();
    std::cout << "number of items before: " << itemCountBefore << std::endl;

    for (int i = 0; i < m_getModifier; ++i) {
        Modifier* newModifier = ModifierDeck::getInstance().generateModifier();

        if (newModifier) {
            munchkin->addModifier(newModifier);
        }
    }
}


void Victory_GetItem::apply(Munchkin* munchkin)
{
    size_t itemCountBefore = munchkin->getItems().size();
    std::cout << "number of items before: " << itemCountBefore  << std::endl;

    for (int i = 0; i < m_getItem; ++i) {
        Item* newItem = ItemDeck::getInstance().generateItem();
       
        if (newItem) {
            munchkin->addItem(newItem);
        }
    }
}

