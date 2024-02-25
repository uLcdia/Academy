// https://www.learncpp.com/cpp-tutorial/bit-manipulation-with-bitwise-operators-and-bit-masks/
// bit masks

#include <bitset>
#include <cstdint>
#include <iostream>

int main()
{
    [[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };      // 0b0'0001
    [[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };      // 0b0'0010
    [[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };   // 0b0'0100
    [[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };      // 0b0'1000
    [[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };     // 0b1'0000

    std::uint8_t myArticleFlags{ option_favorited };                    // default: favorited. 0b00100
    setbuf(stdout, 0);
    myArticleFlags |= option_viewed;                                                                    // set isViewed to 1
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    std::cout << std::boolalpha << "isDeleted: " << (myArticleFlags & option_deleted) << std::endl;     // query isDeleted
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';

    myArticleFlags &= ~option_favorited;
    std::cout << std::bitset<8>{ myArticleFlags } << '\n';                                              // set isFavorited to 0

    return 0;
}