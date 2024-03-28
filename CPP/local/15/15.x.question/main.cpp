// https://www.learncpp.com/cpp-tutorial/chapter-15-summary-and-quiz/

#include <iostream>
#include <string>
#include "monster.h"

int main()
{
    Monster m{MonsterGenerator::generate()};
	m.print();

	return 0;
}

