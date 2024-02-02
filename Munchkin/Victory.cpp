#include "Victory.h"
#include "Runaway.h"
#include "Munchkin.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
//#include "ModifierDeck.h" 
#include <iostream>
#include "DeckBase.h"
#include <random>


class ModifierDeck;
class DeckBase;

void Victory_LvlUp::apply(Munchkin* munchkin)
{
    munchkin->updateLevelBy(+m_lvlToUp);
}

void Victory_GetItem::apply(Munchkin* munchkin)
{
    std::vector<Item*>& items = munchkin->getItems();

    if (m_itemsDatabase.size() >= m_getItem)
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        // Shuffle the database to get random cards
        std::random_shuffle(m_itemsDatabase.begin(), m_itemsDatabase.end());

        // Take m_getModifier number of elements from the beginning
        std::vector<Item*> selectedItems(
            m_itemsDatabase.begin(), m_itemsDatabase.begin() + m_getItem
        );

        // Erase the selected modifiers from the database
        m_itemsDatabase.erase(
            m_itemsDatabase.begin(), m_itemsDatabase.begin() + m_getItem
        );

        // Add the selected modifiers to the player's modifiers
        items.insert(items.end(), selectedItems.begin(), selectedItems.end());
    }
    else
    {
        // If not enough modifiers in the database, take all of them
        items.insert(items.end(), m_itemsDatabase.begin(), m_itemsDatabase.end());
        m_itemsDatabase.clear();
    }
}

//void Victory_GetModifier::apply(Munchkin* munchkin) // it works2!!!
//{
//    std::vector<Modifier*>& modifiers = munchkin->getModifiers();
//
//    if (m_modifiersDatabase.size() >= m_getModifier)
//    {
//        std::srand(static_cast<unsigned int>(std::time(0)));
//        // Shuffle the database to get random cards
//        std::random_shuffle(m_modifiersDatabase.begin(), m_modifiersDatabase.end());
//        // Vector to store indices of selected modifiers
//        std::vector<int> selectedIndices;
//
//        for (int i = 0; i < m_getModifier; ++i)
//        {
//            // Iterate until an unplayed modifier is found
//            int selectedIndex;
//            do {
//                // Randomly choose an index
//                selectedIndex = std::rand() % m_modifiersDatabase.size();
//            } while (std::find(selectedIndices.begin(), selectedIndices.end(), selectedIndex) != selectedIndices.end());
//            // Mark the modifier as selected
//            selectedIndices.push_back(selectedIndex);
//            // Take an existing item from the shuffled database
//            Modifier* selectedModifier = m_modifiersDatabase[selectedIndex];
//            // Add the selected modifier to the player's modifiers
//            modifiers.push_back(selectedModifier);
//        }
//        for (int i : selectedIndices) {
//            m_modifiersDatabase.erase(m_modifiersDatabase.begin() + i);
//        }
//    }
//
//    else
//    {
//
//        modifiers.insert(modifiers.end(), m_modifiersDatabase.begin(), m_modifiersDatabase.end());
//        m_modifiersDatabase.clear();
//    }
//
//}

//void Victory_GetModifier::apply(Munchkin* munchkin) // it works!!! best code
//{
//    std::vector<Modifier*>& modifiers = munchkin->getModifiers();
//
//    if (m_modifiersDatabase.size() >= m_getModifier)
//    {
//        std::srand(static_cast<unsigned int>(std::time(0)));
//        // Shuffle the database to get random cards
//        std::random_shuffle(m_modifiersDatabase.begin(), m_modifiersDatabase.end());
//
//        // Take m_getModifier number of elements from the beginning
//        std::vector<Modifier*> selectedModifiers(
//            m_modifiersDatabase.begin(), m_modifiersDatabase.begin() + m_getModifier
//        );
//
//        // Erase the selected modifiers from the database
//        m_modifiersDatabase.erase(
//            m_modifiersDatabase.begin(), m_modifiersDatabase.begin() + m_getModifier
//        );
//
//        // Add the selected modifiers to the player's modifiers
//        modifiers.insert(modifiers.end(), selectedModifiers.begin(), selectedModifiers.end());
//    }
//    else
//    {
//        // If not enough modifiers in the database, take all of them
//        modifiers.insert(modifiers.end(), m_modifiersDatabase.begin(), m_modifiersDatabase.end());
//        m_modifiersDatabase.clear();
//    }
//}

void Victory_GetModifier::apply(Munchkin* munchkin)
{
    //std::vector<Modifier*>& modifiers = munchkin->getModifiers();

    //for (int i = 0; i < m_getModifier; ++i)
    //{
    //    std::vector<Modifier*> selectedModifiers;

    //    if (!m_modifiersDatabase.empty()) {
    //        // Generate a modifier and add it to the selectedModifiers vector
    //        std::random_device rd;
    //        std::default_random_engine rng(rd());
    //        std::shuffle(m_modifiersDatabase.begin(), m_modifiersDatabase.end(), rng);

    //        selectedModifiers.push_back(m_modifiersDatabase.back());
    //        m_modifiersDatabase.pop_back();
    //    }

    //    if (!selectedModifiers.empty()) {
    //        // Add the selected modifiers to the player's modifiers
    //        modifiers.insert(modifiers.end(), selectedModifiers.begin(), selectedModifiers.end());
    //    }
    //}
    // 
    //// Clear the database after selecting modifiers
    //m_modifiersDatabase.clear();
}