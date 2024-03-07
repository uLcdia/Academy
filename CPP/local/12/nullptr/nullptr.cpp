// https://www.learncpp.com/cpp-tutorial/null-pointers/

// Favor references over pointers whenever possible

#include <iostream>

void dereferencePtr(int* ptr)
{
    if (ptr)
    {
        std::cout << "ptr: " << ptr << " -> " << *ptr << '\n';
    }
    else
    {
        std::cout << "nullptr: " << "Exception has occurred. Segmentation fault.\n";
    }
}

int main()
{
    int* intNullptr {};
    dereferencePtr(intNullptr);


    // set all pointers to objects that have been destroyed to nullptr to avoid dangling
    // reason: dangling pointers can't be determined, nullptr can be determined
    int* intSetNullptr {};

    {
        int intDestroy {1};
        intSetNullptr = &intDestroy;
    }   // intDestroy is destroyed here
    intSetNullptr = nullptr;
    dereferencePtr(intSetNullptr);

    return 0;
}