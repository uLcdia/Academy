// https://www.learncpp.com/cpp-tutorial/chapter-13-summary-and-quiz/#:~:text=Yay!-,Question%20%231

#include <string>
#include <iostream>
#include <utility>  // for std::to_underlying

using namespace std::string_view_literals;

namespace Enemy
{
    enum class Type
    {
        human,
        humanoid,
        dragon,
        werewolf,
        vampire,
    };
    
    std::string_view typeList [5] {"human"sv, "humanoid"sv, "dragon"sv, "werewolf"sv, "vampire"sv};
    const double healthList [5] {100, 50, 500, 150, 200};

    struct Info
    {
        Type type {};
        std::string_view name {};
        double health {};
    };
}

void attack(Enemy::Info& source, double damage) // changes Enemy::Info, input & output
{
    if (source.health > damage)
    {
        source.health -= damage;
        std::cout << Enemy::typeList[std::to_underlying(source.type)] << " " << source.name << " received " << damage << " damage. (" << source.health << '/' << Enemy::healthList[std::to_underlying(source.type)] << ")\n";
    }
    else
    {
        source.health = 0.0;
        std::cout << Enemy::typeList[std::to_underlying(source.type)] << " " << source.name << " received " << damage << " damage. (" << source.health << '/' << Enemy::healthList[std::to_underlying(source.type)] << ")\n";
        std::cout << Enemy::typeList[std::to_underlying(source.type)] << " " << source.name << " sent to Sovngarde.\n";
    }
}

int main()
{
    Enemy::Info stormcloak {Enemy::Type::human, "Ulfric"sv, Enemy::healthList[std::to_underlying(Enemy::Type::human)]};
    Enemy::Info dragon {Enemy::Type::dragon, "sweet roll"sv, Enemy::healthList[std::to_underlying(Enemy::Type::dragon)]};

    attack(stormcloak, 50.0);
    attack(dragon, 100.0);
    attack(dragon, 1000.0);

    return 0;
}