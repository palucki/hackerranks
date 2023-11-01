#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

int luckBalance(int k, std::vector<std::vector<int>> contests) 
{
    int result = 0;

    std::sort(contests.begin(), contests.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs)
    {
        if(lhs[1] == rhs[1])
        {
            return lhs[0] > rhs[0];
        }

        return lhs[1] > rhs[1];
    });

    for(const auto v : contests)
    {
        if(v[1] == 0)
        {
            result += v[0];
            continue;
        }

        if(k > 0)
        {
            result += v[0];
            k--;
        }
        else
        {
            result -= v[0];
        }

    }

    return result;
}

int main()
{
    // std::cout << luckBalance(2, {{5,1}, {1,1}, {4,0}}) << '\n';
    std::cout << luckBalance(3, {{5,1}, {2,1}, {1,1}, {8,1}, {10,0}, {5,0}}) << '\n';

    return 0;
}