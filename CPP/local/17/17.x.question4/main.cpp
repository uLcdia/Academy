// https://www.learncpp.com/cpp-tutorial/chapter-17-summary-and-quiz/

#include <algorithm>
#include "random.h"
#include <iostream>
#include <array>
#include <vector>
#include <cassert>
#include <limits>

struct Card
{
    enum Rank
    {
        rank_ace,
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,

        max_ranks
    };
    enum Suit
    {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    Rank rank{};
    Suit suit{};

    // overload operator<< to print card
    friend std::ostream& operator<<(std::ostream& out, const Card &card)
    {

        out << s_rankNames[card.rank] << ' ' << s_suitNames[card.suit];
        return out;
    }

    // return value of the card
    int getValue() const
    {
        return s_rankValues[rank];
    }

    // These need to be static so they are only created once per program, not once per Card
    static constexpr std::array s_allRanks { rank_ace, rank_2, rank_3, rank_4, rank_5, rank_6, rank_7, rank_8, rank_9, rank_10, rank_jack, rank_queen, rank_king };
    static constexpr std::array s_allSuits { suit_club, suit_diamond, suit_heart, suit_spade };
    static constexpr std::array s_rankValues { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
    static constexpr std::array s_rankNames {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    static constexpr std::array s_suitNames {"Club", "Diamond", "Heart", "Spade"};
    static_assert(std::ssize(s_allRanks) == static_cast<int>(max_ranks));
    static_assert(std::ssize(s_allSuits) == static_cast<int>(max_suits));
    static_assert(std::ssize(s_rankValues) == static_cast<int>(max_ranks));
    static_assert(std::ssize(s_rankNames) == static_cast<int>(max_ranks));
    static_assert(std::ssize(s_suitNames) == static_cast<int>(max_suits));
};

class Deck
{
public:
    Deck()
    {
        std::size_t count {0};
        for (auto suit : Card::s_allSuits)
        {
            for (auto rank : Card::s_allRanks)
            {
                m_cards[count++] = Card{rank, suit};
            }
        }
    }

    // shuffle the deck
    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::s_mt);
        m_nextCardIndex = 0;
    }

    // return next card
    Card dealCard()
    {
        assert(m_nextCardIndex != 52 && "Deck::dealCard ran out of cards");
        return m_cards[m_nextCardIndex++];
    }

private:
    std::array<Card, 52> m_cards {};
    std::size_t m_nextCardIndex {0};
};

namespace Settings
{
    auto bustValue {21};
    auto stopDrawingValue {17};
};

class Dealer
{
public:
    Dealer()
    {
        m_deck.shuffle();
        // The dealer gets one card to start.
        draw();
    }

    // draw new card with info
    void draw()
    {
        Card card {m_deck.dealCard()};
        std::cout << "Dealer: gets " << card << std::endl;
        m_value += card.getValue();
    }

    // over stopDrawingValue ? return true : return false
    bool checkStop() const
    {
        if (m_value >= Settings::stopDrawingValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // over bustValue ? return true : return false
    bool checkBust() const
    {
        if (m_value > Settings::bustValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // return m_value
    int getValue() const
    {
        return m_value;
    }

private:
    int m_value {0};
    Deck m_deck {};
};

class Player
{
public:
    Player()
    {
        m_deck.shuffle();
        // The player gets two cards to start.
        draw();
        draw();
    }

    // draw new card with info
    void draw()
    {
        Card card {m_deck.dealCard()};
        std::cout << "Player: gets " << card << std::endl;
        m_value += card.getValue();
    }

    // over bustValue ? return true : return false
    bool checkBust() const
    {
        if (m_value > Settings::bustValue)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // return m_value
    int getValue() const
    {
        return m_value;
    }
private:
    int m_value {0};
    Deck m_deck {};
};

void ignoreLine()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

class Console
{
public:
    enum class Role
    {
        player,
        dealer,
        tie
    };
    enum class Action
    {
        hit,
        stand
    };

    // call start() from main, return nothing back to main
    void start()
    {
        checkBust(); // check if player busts with first 2 card drawing
        printPlayerValue();

        Action action {getPlayerAction()}; // store player actions
        while (action == Action::hit) // keep getting player's action if not stand
        {
            m_player.draw();
            printPlayerValue();
            if(checkBust())
                return;
            action = getPlayerAction();
        }
        std::cout << "Player: stop drawing. \n";
        printPlayerValue();

        while (!m_dealer.checkStop()) // dealer keeps drawing until hits stopDrawingValue
        {
            m_dealer.draw();
            printDealerValue();
            if(checkBust())
                return;
        }
        
        // check who wins
        if (m_dealer.getValue() < m_player.getValue())
            printLose(Role::dealer);
        else if (m_dealer.getValue() > m_player.getValue())
            printLose(Role::player);
        else
            printLose(Role::tie);
        return;
    }

private:
    Dealer m_dealer {};
    Player m_player {};

    // check bust for both player and dealer
    bool checkBust() const
    {
        if (m_player.checkBust())
        {
            printLose(Role::player);
            return true;
        }
        else if (m_dealer.checkBust())
        {
            printLose(Role::dealer);
            return true;
        }
        return false;
    }

    // std::cin hit or stand, return Action::hit or Action::stand
    Action getPlayerAction()
    {
        std::cout << "Player: hit or stand: ";
        char input {};
        std::cin >> input;
        input = tolower(input);
        if (input == 'h')
        {
            ignoreLine();
            return Action::hit;
        }
        else if (input == 's')
        {
            ignoreLine();
            return Action::stand;
        }
        else
        {
            ignoreLine();
            std::cout << "Invalid input, try again with 'h' or 's'. \n";
            return getPlayerAction();
        }
    }

    void printPlayerValue() const
    {
        std::cout << "Player: has value " << m_player.getValue() << std::endl;
    }
    void printDealerValue() const
    {
        std::cout << "Dealer: has value " << m_dealer.getValue() << std::endl;
    }

    // get Role, print who loses, return nothing
    void printLose(Role who) const
    {
        if (who == Role::player)
        {
            std::cout << "Player: loses. " << std::endl;
        }
        else if (who == Role::dealer)
        {
            std::cout << "Dealer: loses. " << std::endl;
        }
        else
        {
            std::cout << "Console: tie. " << std::endl;
        }
    }
};

int main()
{
    Console foo {};
    foo.start();

    return 0;
}