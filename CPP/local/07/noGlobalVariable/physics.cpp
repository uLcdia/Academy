#include <cmath>
/*  // OPTION_2
namespace constants
{
    // if value is changed, this cpp will be the only one that needs recompiling
    extern const double gravity { 9.8 };    // the only definition. this is a const, not a constexpr, which means it's treated as a runtime const
}
*/

double timeToFall(double height, double gravity)
{
    return (std::sqrt((2 * height) / gravity ));
}