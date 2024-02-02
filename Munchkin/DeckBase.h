﻿#pragma once
#include <vector>
#include <set>
#include <string>

class Item;
class Modifier;
class Monster;
class Victory_GetModifier;

class DeckBase
{
public:
    DeckBase();
    ~DeckBase();

    virtual void generate() = 0;

protected:
    std::vector<void*> m_database;

};

class MonsterDeck : public DeckBase
{
public:
    MonsterDeck();
    ~MonsterDeck();

    void generate()  override;
    Monster* generateMonster();

private:
    
    std::vector<Monster*> m_monstersDatabase ;
    std::set<std::string> m_usedMonsterNames;
};

class ModifierDeck : public DeckBase
{
public:
    ModifierDeck();
    ~ModifierDeck();
       
    void generate() override {}
    //Modifier* generateModifier()const;//base code

    //std::vector<Modifier*> generateModifier();
    std::vector<Modifier*> generateModifiers() const{ return m_modifiersDatabase; };
    
   /* size_t getModifiersDatabaseSize() const {
        return m_modifiersDatabase.size();
    }*/

private:

    std::vector<Modifier*> m_modifiersDatabase;
};

class ItemDeck : public DeckBase
{
public:
    ItemDeck();
    ~ItemDeck();

    void generate() override{}
    Item* generateItem();
    std::vector<Item*> generateItems() const { return m_itemsDataBase; }//base code
    //std::vector<Item*> generateItems();
private:
    std::vector<Item*> m_itemsDataBase;
    std::set<std::string> m_usedItemNames;
};