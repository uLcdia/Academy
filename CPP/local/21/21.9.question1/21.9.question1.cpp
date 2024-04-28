// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct StudentGrade
{
    std::string name {};
    char grade {};
};

class GradeMap
{
public:
    char& operator[] (std::string_view name);
private:
    std::vector<StudentGrade> m_map {};
};
char& GradeMap::operator[] (std::string_view name)
{
    auto found{ std::find_if(m_map.begin(), m_map.end(),
				[name](const auto& student) { // this is a lambda that captures name from the surrounding scope
					return (student.name == name); // so we can use name here
				}) };
    if (found != m_map.end())
    {
        return found->grade;
    }
    m_map.emplace_back(std::string {name});
    return m_map.back().grade;
}

int main()
{
    GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';
    
    return 0;
}