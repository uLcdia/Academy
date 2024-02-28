// https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/

#include <iostream>

int main()
{
    constexpr int condition {0};

    /*
    // you can define a variable before case (why do this anyway?)
    switch (condition)
    {
        int testSwitchVariable; // okay: definition is allowed before the case labels
        // int testInitializedSwitchVariable {0};  // note: jump bypasses variable initialization
        case 0:
            testSwitchVariable = 0;
            std::cout << testSwitchVariable << '\n';
            break;
        case 1:
            std::cout << testSwitchVariable << '\n';
            // std::cout << testInitializedSwitchVariable << '\n';
            break;
        default:    // error: cannot jump from switch statement to this case label
            break;
    }
    */

    /*
    // bad practice: definition is allowed within a case
    switch (condition)
    {
        case 0:
            int testCaseVariable;
            testCaseVariable = 0;
        case 1:
            testCaseVariable = 1;
        default:
            std::cout << testCaseVariable << '\n';
    }
    */

   /*
   // illegal: initialization is not allowed if subsequent cases exist
   switch (condition)
   {
        case 0:
            int testInitialized {1};        // note: jump bypasses variable initialization
        case 1:                             // error: cannot jump from switch statement to this case label
            std::cout << testInitialized;
   }
   */
    
    // best practice
    switch (condition)
    {
        case 0:
        {
            int testVariable {0};
            std::cout << testVariable << '\n';
            break;
        }
        case 1:
        {
            // std::cout << testVariable << '\n'; // testVariable not available here
            break;
        }
        default:
        {
            int testVariable {-1};
            std::cout << testVariable << '\n';
            break;
        }
    }

    return 0;
}