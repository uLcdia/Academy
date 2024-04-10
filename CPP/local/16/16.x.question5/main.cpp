// https://www.learncpp.com/cpp-tutorial/chapter-16-summary-and-quiz/

#include "random.h"
#include <iostream>
#include <vector>
#include <string>

namespace NameList
{
    std::vector<std::string_view> words {"kotone", "makoto", "saori", "ryoji", "max", "geralt", "ciri", "aurora"};
    std::string_view getWord() {return words[Random::get(std::ssize(words))];}
}

class Session
{
public:
    bool run()
    {
        // resize / reserve vectors
        progress_m.resize(word_m.length());
        correct_m.reserve(word_m.length());
        incorrect_m.reserve(chances_m);

        while (chances_m > 0)
        {
            print();
            checkGuess(getGuess());
            if (checkCompletion())
            {
                print();
                std::cout << "You made it in " << incorrect_m.size() + correct_m.size() << " guesses. \n";
                return true;
            }
        }
        print();
        std::cout << word_m << "You made " << incorrect_m.size() << " incorrect guesses. \n";
        return false;
    }

    Session(std::string_view word, int chances)
        : word_m {word}
        , chances_m {chances}
    {}
private:
    // printWord() and printChances() formatted output, which contains words and chances and incorrect guesses
    void print() const
    {
        std::cout << '\n';
        printWord();
        std::cout << " | ";
        printChances();
        std::cout << '\n';
    }

    // print the unlocked characters and locked as '_'
    void printWord() const
    {
        for (size_t i {0}; i < word_m.length(); i++)
        {
            // unlocked
            if (progress_m[i])
            {
                std::cout << word_m[i];
            }
            // locked
            else 
            {
                std::cout << '_';
            }
        }
    }

    // print remaining chances as "+", then print incorrect guesses
    void printChances() const
    {
        for (int i {0}; i < chances_m; i++)
        {
            std::cout << '+';
        }
        for (char item : incorrect_m)
        {
            std::cout << item;
        }
    }

    // get guess from user and validate it, return guess as char
    char getGuess() const
    {
        std::cout << "Guess: ";

        char guess {};
        std::cin >> guess;

        // one char input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // if invalid input
        if (!(('a' <= guess && guess <= 'z' ) || ( 'A' <= guess && guess <= 'Z')))
        {
            std::cout << guess << " is invalid. Try again. \n";
            return getGuess();
        }
        // if guessed
        else if ((std::find(std::begin(correct_m), std::end(correct_m), guess) != std::end(correct_m)) || (std::find(std::begin(incorrect_m), std::end(incorrect_m), guess) != std::end(incorrect_m)))
        {
            std::cout << guess << " is guessed. Try again. \n";
            return getGuess();
        }
        // normal
        else
        {
            return tolower(guess);
        }
    }

    // check if guess is in the word
    void checkGuess(char guess)
    {
        bool isCorrect {false};
        for (size_t i {0}; i < word_m.length(); i++)
        {
            if (word_m[i] == guess)
            {
                isCorrect = true;
                progress_m[i] = 1; // digit marked as unlocked
            }
        }

        // guess marked as guessed, correct or incorrect
        if (isCorrect)
        {
            correct_m.emplace_back(guess);
            std::cout << guess << " is correct. \n";
        }
        else
        {
            chances_m--;
            incorrect_m.emplace_back(guess);
            std::cout << guess << " is incorrect. \n";
        }
    }

    // check if completed, return false if not completed, true if completed
    bool checkCompletion() const
    {
        for (int item : progress_m)
        {
            if (item == 0)
            {
                return false; // at least one digit locked
            }
        }
        return true; // all digits unlocked
    }

    std::string word_m {}; // Copilot: Use of std::string_view for word_m: The word_m member variable is a std::string_view that is initialized with a std::string_view returned by NameList::getWord(). This could potentially lead to a dangling string_view if the words vector in NameList is modified or destroyed, because string_view does not own the string it views. If the lifetime of the words in NameList is not guaranteed to exceed the lifetime of a Session object, it would be safer to use std::string for word_m.
    int chances_m {};
    std::vector<int> progress_m {};
    std::vector<char> correct_m {};
    std::vector<char> incorrect_m {};
};

int main()
{
    while (true)
    {
        // run the session
        int chances {5};
        Session session {NameList::getWord(), chances};
        if (session.run())
        {
            std::cout << "Good job. Wanna try again? (Y/N) ";
        }
        else
        {
            std::cout << "What a noob. Try again? (Y/N) ";
        }

        // check whether run again or not
        char again {};
        std::cin >> again;
        again = toupper(again);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // make sure "again" doesn't pollute the game
        if (again != 'Y')
        {
            break;
        }
    }

    return 0;
}