// https://www.learncpp.com/cpp-tutorial/overloading-the-subscript-operator/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

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

// https://www.geeksforgeeks.org/map-vs-unordered_map-c/
// https://en.cppreference.com/w/cpp/container/unordered_map
// https://en.cppreference.com/w/cpp/container/map
std::map<std::string, char> map {};

int main()
{
    // custom implementation GradeMap:
    GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << std::endl;
	std::cout << "Frank has a grade of " << grades["Frank"] << std::endl;

    // std::map map:
    map.emplace("Max", 'A');
    map.emplace("Kotone", 'A');

	std::cout << "Max has a grade of " << map["Max"] << std::endl;
	std::cout << "Kotone has a grade of " << map["Kotone"] << std::endl;

    return 0;
}