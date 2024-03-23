// https://www.learncpp.com/cpp-tutorial/the-hidden-this-pointer-and-member-function-chaining/

// "this" is a const pointer to a non-const value

#include <iostream>

class Calc
{
public:
    Calc(int value = 1) 
        : m_value {value}
    {}
    
    // Calc& creates a reference of this Calc object, it doesn't create a new Calc object

    Calc& add(int value) {m_value += value; return *this;}
    Calc& sub(int value) {m_value -= value; return *this;}
    Calc& mult(int value) {m_value *= value; return *this;}

    int getValue() const {return this->m_value;} // same as return m_value;

    void reset() {*this = Calc {};} // creates a temporary default Calc object, then copy the temporary Calc object to *this

private:
    int m_value {};
};

int main()
{
    Calc value {1};

    value.add(5).mult(2).sub(1);
    std::cout << value.getValue() << '\n';

    value.reset();
    std::cout << value.getValue() << '\n';

    return 0;
}