#ifndef GAMES_H
#define GAMES_H

void print();

namespace Persona
{
    // generally don't define variables in headers. in this case? just for fun.
    // inline keyword tells the compiler to create a separate instance of the variable for each file that includes the header

    inline int makoto { 3 };
    inline int kotone { 3 };
    inline int yu { 4 };
    inline int testValue { 0 };

    int testFunction(int a, int b);
    void summon();
}

namespace Witcher
{
    inline int geralt { 0 };
    inline int testValue { 1 };

    int testFunction(int a, int b);

    namespace WitcherIII
    {
        inline int testValue { 2 };
        int testFunction(int a, int b);
    }
}

#endif