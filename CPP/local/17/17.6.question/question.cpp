// https://www.learncpp.com/cpp-tutorial/stdarray-and-enumerations/

#include <iostream>
#include <array>
#include <string>

namespace Host
{
    enum Type
    {
        dolores,
        bernard,
        angela,
        lawrence,
        maeve,
        teddy,
        clementine,
        max_hosts
    };

    struct Data
    {
        std::string_view name {};
        int id {};
    };

    constexpr std::array<std::string_view, max_hosts> hostNames {"Dolores Abernathy", "Bernard Lowe", "Angela", "Lawrence", "Maeve Millay", "Teddy Flood", "Clementine Pennyfeather"};

    constexpr std::array<Data, max_hosts> data {{{hostNames[dolores], 0}, {hostNames[bernard], 1}, {hostNames[angela], 2}, {hostNames[lawrence], 3}, {hostNames[maeve], 4}, {hostNames[teddy], 5}, {hostNames[clementine], 6}}};

    static_assert(std::size(hostNames) == max_hosts);
    static_assert(std::size(data) == max_hosts);
};

std::istream& operator>> (std::istream& in, Host::Type& host)
{
    std::string input {};
    in >> std::ws;
    std::getline(in, input);

    for (std::size_t index {0}; index < Host::data.size(); index++)
    {
        if (input == Host::data[index].name)
        {
            host = static_cast<Host::Type>(index);
            return in;
        }
    }
    
    host = Host::max_hosts;
    return in;
}

void printHostData(Host::Type type)
{
    const Host::Data& host {Host::data[type]};
    std::cout << "Host " << host.name << " has ID " << host.id << ". \n";
}

int main()
{
    std::cout << "Welcome to Westworld.\n";
    Host::Type type {};
    std::cin >> type;

    if (type == Host::max_hosts)
    {
        std::cin.clear();
        std::cout << "Ford wants a word with you.";
        type = Host::max_hosts;
    }
    else
    {
        printHostData(type);
    }

    return 0;
}
