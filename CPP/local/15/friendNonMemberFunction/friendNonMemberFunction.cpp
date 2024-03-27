// https://www.learncpp.com/cpp-tutorial/friend-non-member-functions/

#include <iostream>

// Prefer to implement a function as a non-friend when possible and reasonable.
// A friend function should prefer to use the class interface over direct access whenever possible.
class FriendNonMemberFunction
{
public:
    void printMember() const {std::cout << this->m_PI << '\n';} // *this implicitly passed

    friend void friendNonMember(const FriendNonMemberFunction& source); // source explicitly passed

    // friend keyword makes the function a non member function
    friend void friendNonMemberInside(const FriendNonMemberFunction& source) {std::cout << source.m_PI << '\n';}

private:
    const double m_PI {3.1415927};
};

void friendNonMember(const FriendNonMemberFunction& source)
{
    // if not befriended: error: member "FriendNonMemberFunction::m_PI" is inaccessible
    std::cout << source.m_PI << '\n';
}

int main()
{
    // these two functions are the same, both non member functions and both have class FriendNonMemberFunction's friendship
    std::cout << "friendNonMember(): \n";
    friendNonMember(FriendNonMemberFunction {});
    std::cout << "friendNonMemberInside(): \n";
    friendNonMemberInside(FriendNonMemberFunction {});

    return 0;
}