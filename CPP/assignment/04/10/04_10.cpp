// design a Employee class with ID, gender, birthdate, idCard

#include <string>
#include <iostream>

using namespace std::string_view_literals;

class Employee
{
public:
    class Date
    {
    public:
        int day {1};
        int month {1};
        int year {1970};
    };

    Employee(std::string_view gender = "female"sv, std::string_view idCard = "110101197001010008", const Date& birthDate = {1, 1, 1970})
        : m_id {idGenerate()}
        , m_gender {gender}
        , m_idCard {idCard}
        , m_birthDate {birthDate}
    {}
    
    Employee(const Employee& source)
        : m_id {source.getID()}
        , m_gender {source.getGender()}
        , m_idCard {source.getIDCard()}
        , m_birthDate {source.getBirthDate()}
    {
        std::cout << "Why create a explicit copy constructor when an implicit one is available?\n";
    }

    ~Employee()
    {
        std::cout << "Employee " << m_id << " destroyed.\n";
    }

    int getID() const {return m_id;}
    std::string_view getGender() const {return m_gender;}
    std::string_view getIDCard() const {return m_idCard;}
    const Date& getBirthDate() const {return m_birthDate;}

    void setID(int id) {m_id = id;}

    void print() const
    {
        std::cout << "ID:        " << getID() << '\n'
                  << "Gender:    " << getGender() << '\n'
                  << "IDCard:    " << getIDCard() << '\n'
                  << "BirthDate: " << getBirthDate().day << '/' << getBirthDate().month << '/' << getBirthDate().year << '\n';
    }

    static int idGenerate() {return (s_idGenerator++);}

private:
    int m_id {};
    std::string_view m_gender {};
    std::string_view m_idCard {};
    Date m_birthDate {};

    static inline int s_idGenerator {1};
};

int main()
{
    Employee foo {};
    foo.print();

    Employee bar {foo};
    bar.setID(bar.idGenerate());
    bar.print();

    return 0;
}