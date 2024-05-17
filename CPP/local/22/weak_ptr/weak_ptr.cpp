// https://www.learncpp.com/cpp-tutorial/circular-dependency-issues-with-stdshared_ptr-and-stdweak_ptr/
// https://stackoverflow.com/questions/44282893/stdweak-ptr-assignment-with-stdmake-shared

#include <iostream>
#include <memory>

struct Foo
{
    Foo(int num)
        : number {num}
    {
        std::cout << "Constructing Foo(" << number << ")..." << std::endl;
    }
    ~Foo()
    {
        std::cout << "Destructing Foo(" << number << ")..." << std::endl;
    }

    int number {};
};

int main()
{
    // std::weak_ptr::lock() effectively returns expired() ? shared_ptr<T>() : shared_ptr<T>(*this), executed atomically. 

    auto shared {std::make_shared<Foo>(42)};
    std::weak_ptr<Foo> weak {shared};

    if (auto sp = weak.lock()) // sp is constructed with Foo(42)
    {
        std::cout << "1 number = " << sp->number << std::endl;
    }
    else
    {
        std::cout << "1 weak is expired" << std::endl;
    }
    // std::cout << "1 number = " << weak.lock()->number << std::endl;



    weak = std::make_shared<Foo>(23); // weak is assigned with a temporary std::shared_ptr which will be destroyed immediately after assignment

    // FAULTY LINE
    // std::cout << "2 number = " << weak.lock()->number << std::endl; // this may output "number = 23", it's actually an undefined behavior. This line may corrupt the program's state which leads to the if statement below to output "3 number = something"
    // weak.lock() tries to convert weak to a shared_ptr, but the shared_ptr it's trying to convert is already expired, so it throws an exception



    // Always check the validity of the std::shared_ptr returned by weak.lock() before using it. 
    if (auto sp = weak.lock()) // sp is default constructed (check line 24), holding nullptr
    {
        std::cout << "3 number = " << sp->number << std::endl;
    }
    else
    {
        std::cout << "3 weak is expired" << std::endl;
    }

    return 0;
}

/* 
    Possible faulty output:

    Constructing Foo(42)... // normal
    number = 42             // normal
    Constructing Foo(23)... // normal
    Destructing Foo(23)...  // normal
    number = 23             // undefined behavior, weak.lock() returns an empty shared_ptr because weak is expired. Dereferencing it may still output 23 (a memory artifact) before the object is actually destroyed.
    Destructing Foo(23)...  // undefined behavior, same reason as above (a memory artifact)
    number = -17891602      // undefined behavior, caused by dereferencing a nullptr (check line 48)
    Destructing Foo(42)...  // normal
 */

/* 
    std::shared_ptr is a smart pointer that manages the lifetime of an object through reference counting. When the last std::shared_ptr owning an object is destroyed or reset, the managed object is also destroyed.
   
    std::weak_ptr is a smart pointer that provides a non-owning ("weak") reference to an object managed by std::shared_ptr. A std::weak_ptr does not contribute to the reference count, thus it does not affect the lifetime of the managed object.


    Relationship Between std::weak_ptr and std::shared_ptr

    Creation and Linking:
        A std::weak_ptr can be created from an existing std::shared_ptr.
        The std::weak_ptr does not increase the reference count of the std::shared_ptr.

    Accessing the Managed Object:
        std::weak_ptr cannot be used directly to access the managed object.
        To safely access the managed object, std::weak_ptr must be converted to a std::shared_ptr using the lock() method. This method returns a std::shared_ptr if the managed object still exists (i.e., it is not expired), otherwise, it returns an empty std::shared_ptr.

    Checking Expiration:
        std::weak_ptr can check if the managed object has been destroyed using the expired() method, which returns true if the object has been destroyed, and false otherwise.
 */