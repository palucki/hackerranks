#include <vector>
#include <string>
#include <sstream>

namespace helpers 
{

std::string vecToString(const std::vector<int>& v)
{
    std::stringstream ss;
    for(const auto& e : v)
    {
        ss << e << " ";
    }

    return ss.str();
}

}
