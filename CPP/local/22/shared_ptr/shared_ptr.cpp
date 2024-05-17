// https://www.learncpp.com/cpp-tutorial/stdshared_ptr/
// https://en.cppreference.com/w/cpp/memory/shared_ptr/shared_ptr

#include <iostream>
#include <memory>
 
struct Foo
{
    int id{0};
    Foo(int i = 0) : id{i} { std::cout << "Foo::Foo(" << i <<  ")\n"; }
    ~Foo() { std::cout << "Foo::~Foo(), id=" << id << '\n'; }
};
 
struct D
{
    void operator()(Foo* p) const
    {
        std::cout << "Call delete from function object. Foo::id=" << p->id << '\n';
        delete p;
    }
};
 
int main()
{
    {
        std::cout << "1) constructor with no managed object\n";
        std::shared_ptr<Foo> sh1 {}; // uses default constructor, holding nullptr
        if (!sh1) // overloaded operator bool: Checks if *this stores a non-null pointer, i.e. whether get() != nullptr. 
            std::cout << "sh1 has nullptr. \n";
    }
 
    {
        std::cout << "2) constructor with object\n";
        // std::shared_ptr<Foo> sh2(new Foo{10});
        auto sh2 {std::make_shared<Foo>(10)};
        std::cout << "sh2.use_count(): " << sh2.use_count() << '\n';
        std::shared_ptr<Foo> sh3(sh2);
        std::cout << "sh2.use_count(): " << sh2.use_count() << '\n';
        std::cout << "sh3.use_count(): " << sh3.use_count() << '\n';
        if (sh2)
            std::cout << "sh2 holds dynamically allocated Foo, sh2->id = " << sh2->id << ". \n"; // * | -> : Dereferences the stored pointer. The behavior is undefined if the stored pointer is null. 
    }
 
    {
        std::cout << "3) constructor with object and deleter\n";
        std::shared_ptr<Foo> sh4(new Foo{11}, D());
        std::shared_ptr<Foo> sh5(new Foo{12}, [](auto p)
        {
            std::cout << "Call delete from lambda... p->id=" << p->id << '\n';
            delete p;
        });
    }
}

/* 
    In a typical implementation, shared_ptr holds only two pointers:

    the stored pointer (one returned by get());
    a pointer to control block. 

    The control block is a dynamically-allocated object that holds:

    either a pointer to the managed object or the managed object itself;
    the deleter (type-erased);
    the allocator (type-erased);
    the number of shared_ptrs that own the managed object;
    the number of weak_ptrs that refer to the managed object. 
 */