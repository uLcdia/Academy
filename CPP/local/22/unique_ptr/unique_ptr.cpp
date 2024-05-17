// https://www.learncpp.com/cpp-tutorial/stdunique_ptr/
// https://en.cppreference.com/w/cpp/memory/unique_ptr/unique_ptr

#include <iostream>
#include <memory>
 
struct Foo // object to manage
{
    Foo(int num = 0) : number {num} { std::cout << "Foo ctor\n"; }
    Foo(const Foo&) { std::cout << "Foo copy ctor\n"; }
    Foo(Foo&&) { std::cout << "Foo move ctor\n"; }
    ~Foo() { std::cout << "~Foo dtor\n"; }

    int number {};
};

std::unique_ptr<Foo> createFoo(int num)
{
     return std::make_unique<Foo>(num);
}

// This function takes ownership of the Foo, which isn't what we want
void takeOwnership(std::unique_ptr<Foo> foo)
{
    std::cout << "takeOwenership(), number = " << foo->number << '\n';
} // the Foo is destroyed here

// The function only uses the Foo, so we'll accept a pointer to the Foo, not a reference to the whole std::unique_ptr<Foo>
void useFoo(const Foo* foo)
{
	if (foo)
		std::cout << foo->number << '\n';
	else
		std::cout << "nullptr\n";
}

int main()
{
    std::cout << "Example 1 constructor. \n";
    {
        std::unique_ptr<Foo> up1; // up1 is empty, uses default constructor, holding nullptr
        std::unique_ptr<Foo> up1b(nullptr); // up1b is empty
        if (!up1) // overloaded operator bool: Checks whether *this owns an object, i.e. whether get() != nullptr. 
            std::cout << "up1 has nullptr. \n";
    }
 
    std::cout << "Example 2 constructor. \n";
    {
        // std::unique_ptr<Foo> up2(new Foo);
        auto up2 {std::make_unique<Foo>(2)}; // up2 now owns a Foo
    } // Foo deleted
 
    std::cout << "Example 3 constructor. \n";
    {
        auto up3a {std::make_unique<Foo>(3)};
        std::unique_ptr<Foo> up3b {std::move(up3a)}; // ownership transfer
        // up3a holds nullptr
        // up3b is the new owner of Foo object of number 3
        up3a = std::move(up3b);
        // up3b holds nullptr
        // up3a is the new owner of Foo object of number 3
    }
 
    std::cout << "Example 4 returning std::unique_ptr from function. \n";
    {
        auto up4 {createFoo(4)};
    }
 
    std::cout << "Example 5 passing std::unique_ptr to function. \n";
    {
        auto up5 {createFoo(5)};
        takeOwnership(std::move(up5));
        // up5 Foo has already been destroyed in takeOwnership(), before this block ends
    }
 
    std::cout << "Example 6 passing Foo to function. \n";
    {
        auto up6 {createFoo(6)};
        useFoo(up6.get()); // Returns a pointer to the managed object or nullptr if no object is owned. 
    }
 
    std::cout << "Example 7 misusing unique_ptr. \n";
    {
        Foo* foo {new Foo(7)};
        std::unique_ptr<Foo> up7a {foo};    // when up7a goes out of scope, foo is deleted
        // std::unique_ptr<Foo> up7b {foo}; // when up7b goes out of scope, foo is deleted again, which causes undefined behavior

        // std::unique_ptr up7a {foo}; // error: cannot deduce class template argumentsC/C++(3158).
        // ChatGPT is wrong: starting from C++17, std::unique_ptr supports class template argument deduction (CTAD)
        // Gemini: unique_ptr currently (C++17 and beyond) does not support Class Template Argument Deduction (CTAD). 
        // cppreference: no deduction guides.

        // note that std::shared_ptr does support CTAD // https://en.cppreference.com/w/cpp/memory/shared_ptr/deduction_guides
    }

    std::cout << "Example 8 array. \n";
    {
        auto up8 {std::make_unique<Foo[]>(2)};
        // std::unique_ptr is smart enough to know whether to use scalar delete or array delete
        // However, std::array or std::vector (or std::string) are almost always better choices than using std::unique_ptr with a fixed array, dynamic array, or C-style string.
    }
}
