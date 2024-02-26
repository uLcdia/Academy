#include <iostream>
#include <bitset>

int main()
{   
    for (int i = 0; i <= 7; i++)
    {
        std::cout << i << " | " << std::bitset<4>(i) << " | " << std::bitset<4>(~i) << " | " << (~i) << "\n";
    }
    return 0;
}