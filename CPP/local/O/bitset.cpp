// https://www.learncpp.com/cpp-tutorial/bit-flags-and-bit-manipulation-via-stdbitset/


#include <iostream>
#include <iomanip>
#include <bitset>

int main()
{
    // std::bitset<4> bits4 { 15 };
    std::bitset<4> bits4 { 0b1111 }; // 0b for binary number, 0b1111 is identical to 15 decimal
    std::bitset<8> bits8 { 0b0000'0000 };
    std::bitset<16> bits16 { 0b1010'0101'1111'0000 };
    std::bitset<32> bits32 { 0b1010'0101'1111'0000'1010'0101'1111'0011 };
    std::bitset<64> bits64 { 0b1010'0101'1111'0000'1010'0101'1111'0000'1010'0101'1111'0000'1010'0101'1111'0000 };
    std::bitset<32> bits32_64 { 0b1010'0101'1111'0000'1010'0101'1111'0011'0000'0000'1111'0000'0000'0000'1111'1111 }; // flag 32-63 truncated

    std::cout << std::setw(7) << "4 bits" << " | " << std::setw(2) << bits4.size() << " | " << sizeof(bits4) << " | "  << bits4 << std::endl;
    std::cout << std::setw(7) << "8 bits" << " | " << std::setw(2) << bits8.size() << " | " << sizeof(bits8) << " | "  << bits8 << std::endl;
    std::cout << std::setw(7) << "16 bits" << " | " << std::setw(2) << bits16.size() << " | " << sizeof(bits16) << " | "  << bits16 << std::endl;
    std::cout << std::setw(7) << "32 bits" << " | " << std::setw(2) << bits32.size() << " | " << sizeof(bits32) << " | "  << bits32 << std::endl;
    std::cout << std::setw(7) << "64 bits" << " | " << std::setw(2) << bits64.size() << " | " << sizeof(bits64) << " | "  << bits64 << std::endl;
    std::cout << std::setw(7) << "32_64 bits" << " | " << std::setw(2) << bits32_64.size() << " | " << sizeof(bits32_64) << " | "  << bits32_64 << std::endl;

    std::cout << std::endl << std::boolalpha;
    std::cout << "4 bits: " << bits4 << std::endl;
    std::cout << "all 1: " << bits4.all() << " | all 0: " << bits4.none() << " | any 1: " << bits4.any() << std::endl;

    std::cout << std::endl;
    bits4.flip(0);
    std::cout << "4 bits: " << bits4 << std::endl;
    std::cout << "all 1: " << bits4.all() << " | all 0: " << bits4.none() << " | any 1: " << bits4.any() << std::endl;

    return 0;
}