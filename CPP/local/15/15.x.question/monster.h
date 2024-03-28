#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std::string_view_literals;

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types,
    };

public:
    Monster(Type type, std::string_view name, std::string_view shout, int damage);

    std::string_view getTypeString();
    void print();

private:
    Type m_type {dragon};
    std::string m_name {"Alduin"sv};
    std::string m_shout {"Fus Ro Dah"sv};
    int m_damage {100};

};

namespace MonsterGenerator
{
    static constexpr std::string_view typeStringList[Monster::max_monster_types] {"dragon"sv, "goblin"sv, "ogre"sv, "orc"sv, "skeleton"sv, "troll"sv, "vampire"sv, "zombie"sv};
    static constexpr std::string_view nameList[10] {"Alduin"sv, "Nazeem"sv, "Frostbite Spider"sv, "Ice Wraith"sv, "Troll"sv, "Falmer"sv, "Chaurus"sv, "Carl Johnson"sv, "Big Smoke"sv, "Illithid"sv};
    static constexpr std::string_view shoutList[10] {"Fus Ro Dah"sv, "Wuld Nah Kest"sv, "Tiid Klo Ul"sv, "Krii Lun Aus"sv, "Yol Toor Shul"sv, "Su Grah Dun"sv, "Hun Kaal Zoor"sv, "Gol Hah Dov"sv, "Feim Zii Gron"sv, "Raan Mir Tah"sv};

    Monster generate();
}

#endif