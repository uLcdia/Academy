// class Employee: name, address, city, postcode; setName(), display();

#include <iostream>
#include <string>

class Employee
{
public:
    Employee(std::string_view name, std::string_view address, std::string_view city, std::string_view postcode)
        : name_m {name}
        , address_m {address}
        , city_m {city}
        , postcode_m {postcode}
    {}

    void setName(std::string_view name)
    {
        name_m = name;
    }

    void display() const
    {
        std::cout << "name:     " << name_m << '\n'
                  << "address:  " << address_m << '\n'
                  << "city:     " << city_m << '\n'
                  << "postcode: " << postcode_m << std::endl;
    }
private:
    std::string name_m {};
    std::string address_m {};
    std::string city_m {};
    std::string postcode_m {};
};

int main()
{
    using namespace std::string_view_literals;
    Employee bob {"Robert Paulson"sv, "1537 Paper St."sv, "Wilmington"sv, "19886"sv};
    bob.setName("bob");
    bob.display();
    
    return 0;
}