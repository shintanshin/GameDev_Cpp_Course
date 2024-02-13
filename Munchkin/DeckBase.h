#pragma once
#include <vector>
#include <set>
#include <string>

class Item;
class Modifier;
class Monster;

class DeckBase
{
public:
    DeckBase(){}
    ~DeckBase(){}

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

    static ModifierDeck& getInstance() { static ModifierDeck instance; return instance; }
       
    void generate() override {}

    Modifier* generateModifier();
    std::vector<Modifier*> generateModifiers();
    
 
private:
    int m_modifiers;
    std::vector<Modifier*> m_modifiersDataBase;
};

class ItemDeck : public DeckBase
{
public:
    ItemDeck();
    ~ItemDeck();

    static ItemDeck& getInstance() { static ItemDeck instance; return instance; }

    void generate() override{}
    
    Item* generateItem(); 
    std::vector<Item*> generateItems(); 
  
private:
    int m_items;
    std::vector<Item*> m_itemsDataBase;
};