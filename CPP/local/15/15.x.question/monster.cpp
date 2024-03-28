#include <iostream>
#include "monster.h"
#include "random.h"

Monster::Monster(Type type, std::string_view name, std::string_view shout, int damage)
    : m_type {type}
    , m_name {name}
    , m_shout {shout}
    , m_damage {damage}
{}

std::string_view Monster::getTypeString()
{
    return MonsterGenerator::typeStringList[m_type];
}

void Monster::print()
{
    std::cout << m_name << " the " << getTypeString() << " shouts " << m_shout << " and does " << m_damage << " points of damage.\n";
}

namespace MonsterGenerator
{
    Monster::Type getType()
    {
        return (Monster::Type (Random::get(Monster::max_monster_types)));
    }

    std::string_view getName()
    {
        return MonsterGenerator::nameList[Random::get(10)];
    }

    std::string_view getShout()
    {
        return MonsterGenerator::shoutList[Random::get(10)];
    }

    int getDamage()
    {
        return Random::get(1, 100);
    }

    Monster generate()
    {
        return (Monster {getType(), getName(), getShout(), getDamage()});
    }
}