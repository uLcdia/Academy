// https://www.learncpp.com/cpp-tutorial/member-functions-returning-references-to-data-members/

#include <iostream>
#include <string>

class Foo
{
public:
    void setName(std::string_view name) { m_name = name; }

    // Returning a std::string_view would require a temporary std::string_view to be created and returned every time the function was called.
    // don't replace std::string& with auto&
    // don't remove the first const, otherwise some reference below might be able to change m_name directly
    // don't remove the second const, otherwise const Foo won't be able to use getName()
    const std::string& getName() const { return m_name; }   // const ... const

private:
    std::string m_name {};

    // Declare public members first, protected members next, and private members last. This spotlights the public interface and de-emphasizes implementation details.

};

int main()
{
    Foo foo;
    
    foo.setName("Aigis");

    std::string bar {foo.getName()};
    bar = "Koromaru";

    // const std::string& goo {foo.getName()};  // don't do this
    // std::string& goo {foo.getName()};   // error: qualifiers dropped in binding reference of type "std::string &" to initializer of type "const std::string"    // don't do this

    std::cout << "foo: " << foo.getName() << '\n';
    std::cout << "bar: " << bar << '\n';

    return 0;
}