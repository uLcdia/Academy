// https://www.learncpp.com/cpp-tutorial/static-member-functions/

#include <iostream>

/* 
 * Pure static classes are potentially dangerous:
 * 1. Global State: 
 * Static members are essentially global variables.
 * They maintain their state across the entire lifetime of the program. 
 * This can lead to problems because any part of the code can change the state of these variables, making it hard to reason about the program's behavior.
 * 
 * 2. Multithreading Issues: 
 * If multiple threads access and modify static variables simultaneously, it can lead to race conditions and data inconsistencies. 
 * You would need to use synchronization mechanisms like mutexes to prevent this, which adds complexity.
 * 
 * 3. Testing and Dependency Injection: 
 * Static methods can't be overridden, which makes it hard to replace them for unit testing or to change their behavior at runtime. 
 * This makes testing and dependency injection more difficult.
 * 
 * 4. Object-Oriented Programming Principles: 
 * Pure static classes don't fit well with the principles of object-oriented programming, such as encapsulation, inheritance, and polymorphism. 
 * They are more akin to procedural programming.
 * 
 */

class Foo
{
public:
    Foo()
        : m_id {s_idGenerator++}
    {}

    // static inline int getIdGenerator() {return s_idGenerator;}
    // don't make function inline or constexpr for no reason, this varies from static member variables

    static int getIdGenerator() {return s_idGenerator;}

    // constexpr int getIdNonStatic() {return s_idGenerator;} // error: constexpr function never produces a constant expression [-Winvalid-constexpr]
    int getIdNonStatic() {return s_idGenerator;}

    // static int callGetIdNonStatic() {return getIdNonStatic();} // error: a nonstatic member reference must be relative to a specific object; explain: static member functions have no *this pointer, thus *this.getIdNonStatic() could not apply
    static int callGetIdNonStatic(Foo source) {return source.getIdNonStatic();}
    // static inline int getIdNonStatic() {return m_id;} // error: a nonstatic member reference must be relative to a specific object; explain: static member functions have no *this pointer, thus *this.m_id could not apply
    static int getIdNonStatic(Foo source) {return source.m_id;}
    // static void testThis() {std::cout << this.getPI();} // error: 'this' may only be used inside a nonstatic member function

    // static int getIdGenerator() const {return s_idGenerator;} // error: a type qualifier is not allowed on a static member function

    static constexpr double getPI();

private:
    // Best practice: Make your static members inline or constexpr so they can be initialized inside the class definition.
    static inline int s_idGenerator {1};
    static constexpr double s_PI {3.1415927};

    int m_id;
};

constexpr double Foo::getPI() // static constexpr double Foo::getPI() : error: a storage class may not be specified here
{
    return Foo::s_PI;
}

int main()
{
    std::cout << "static inline int getIdGenerator(): " << Foo::getIdGenerator() << '\n';
    std::cout << "static constexpr double getPI(): " << Foo::getPI() << '\n';
    // std::cout << "inline int getIdNonStatic(): " << Foo::getIdNonStatic() << '\n'; // error: a nonstatic member reference must be relative to a specific object
    Foo foo1{};
    std::cout << "constexpr int getIdNonStatic(): " << foo1.getIdNonStatic() << '\n';
    std::cout << "static constexpr int callGetIdNonStatic(Foo source): " << Foo::callGetIdNonStatic(foo1) << '\n';

    return 0;
}