// https://www.learncpp.com/cpp-tutorial/aggregation/

#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Teacher
{
public:
    Teacher(const std::string_view name)
        : m_name {name}
    {}
    const std::string_view getName() const {return m_name;}
    void setName(std::string_view name) {m_name = name;}
private:
    std::string m_name {};
};

class Department
{
public:
    Department();
    void add(Teacher& teacher);

    friend std::ostream& operator<< (std::ostream& out, const Department& source);

private:
    static constexpr int defaultTeacherCount {5};
    std::vector<std::reference_wrapper<Teacher>> m_teachers {};
};
Department::Department()
{
    m_teachers.reserve(defaultTeacherCount);
}
void Department::add(Teacher& teacher)
{
    m_teachers.emplace_back(teacher);
}
std::ostream& operator<<(std::ostream& out, const Department& department)
{
    out << "department: ";
    for (auto item : department.m_teachers)
    {
        out << item.get().getName() << ", ";
    }
    out << std::endl;
    return out;
}

int main()
{
    Teacher jefferson {"Mark Jefferson"};
    Teacher grant {"Michelle Grant"};
    Teacher wells {"Raymond Wells"};

    {
        Department blackwellAcademy {};

        blackwellAcademy.add(jefferson);
        blackwellAcademy.add(grant);
        blackwellAcademy.add(wells);

        std::cout << blackwellAcademy;
    }

    std::cout << jefferson.getName() << " still exists!\n";
    std::cout << grant.getName() << " still exists!\n";
    std::cout << wells.getName() << " still exists!\n";

    return 0;
}