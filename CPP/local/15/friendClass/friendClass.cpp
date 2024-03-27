// https://www.learncpp.com/cpp-tutorial/friend-classes-and-friend-member-functions/

// friendship is not reciprocal nor transitive nor inherited

#include <iostream>

class Storage; 

class Display
{
public:
    Display(bool displaylntFirst)
        : m_displayIntFirst {displaylntFirst}
    {} 

    void displayStorage(const Storage& storage); // needs "class Storage:" forward declaration 

    void setDisplayIntFirst(bool b) {m_displayIntFirst = b;}

private:
    bool m_displayIntFirst {};
}; 

class Storage
{
public:
    Storage(int nValue, double dValue)
        : m_nValue {nValue}, m_dValue {dValue}
    {} 

    // friend class Display; // makes the Display class a friend of Storage; if not: error: member "Storage::m_nValue" is inaccessible, member "Storage::m_dValue" is inaccessible 

    friend void Display::displayStorage(const Storage& storage); // needs to see full definition of class Display to understand what Display::displayStorage() is 

private:
    int m_nValue {};
    double m_dValue {};
}; 

void Display::displayStorage(const Storage& storage) // needs to see full definition of class Storage to understand what m_nvalue and m_dValue are 
{ 
    if (m_displayIntFirst)
        std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
    else
        std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
} 

// These above looks stupid. A better solution is to put each class definition in a separate header file, with the member function definitions in corresponding .cpp files. 

int main()
{ 
    Storage storage {5, 6.7};
    Display display {false};

    display.displayStorage(storage);

    display.setDisplayIntFirst(true);
    display.displayStorage(storage); 

    return 0;
}

