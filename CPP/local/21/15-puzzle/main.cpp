// https://www.learncpp.com/cpp-tutorial/chapter-21-project/

#include <iostream>
#include "keyInput.h"
#include "random.h"
#include "tile.h"
#include "board.h"

int main()
{
    Board foo {};
    KeyInput::Action action {};

    while (true)
    {
        std::cout << foo << std::endl;
        action = KeyInput::get();
        if (action != KeyInput::Action::quit)
        {
            foo.move(action);
            std::cout << foo;
            if (foo.isCompleted())
            {
                std::cout << "Completed. " << std::endl;
                break;
            }
        }
        else
        {
            std::cout << "Aborted. " << std::endl;
            break;
        }
    }

    system("pause");

    return 0;
}