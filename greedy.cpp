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

int minimumAbsoluteDifference(std::vector<int> arr) 
{
    int minimum_abs_diff = std::numeric_limits<int>::max();
    
    std::sort(arr.begin(), arr.end());

    for(int i = 1; i < arr.size(); i++)
    {
        if(std::abs(arr[i-1] - arr[i]) < minimum_abs_diff)
        {
            minimum_abs_diff = std::abs(arr[i-1] - arr[i]);
        }
    }

    return minimum_abs_diff;
}

int main()
{
    // std::cout << luckBalance(2, {{5,1}, {1,1}, {4,0}}) << '\n';
    // std::cout << luckBalance(3, {{5,1}, {2,1}, {1,1}, {8,1}, {10,0}, {5,0}}) << '\n';

    std::cout << minimumAbsoluteDifference({3, -7, 0}) << '\n';
    std::cout << minimumAbsoluteDifference({-59, -36, -13, 1, -53, -92, -2, -96, -54, 75}) << '\n';
    std::cout << minimumAbsoluteDifference({1, -3, 71, 68, 17}) << '\n';

    return 0;
}