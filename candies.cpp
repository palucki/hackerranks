#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, std::vector<int> arr) 
{
    std::vector<long> candies(n, 1);

    //right pass
    for(int i = 1; i < candies.size(); ++i)
    {
        if(arr[i-1] < arr[i])
        {
            candies[i] = candies[i-1] + 1;
        }
    }

    //left pass
    for(int i = candies.size() - 2; i >= 0; --i)
    {
        if(arr[i] > arr[i+1] && candies[i] <= candies[i+1])
        {
            candies[i] = candies[i+1] + 1;
        }
    }

    return std::accumulate(candies.begin(), candies.end(), 0L);
}

int main()
{
    {
        std::vector<int> arr{4,6,4,5,6,2};
        std::cout << candies(arr.size(), arr) << " expected 10"<< '\n';
    }

    {
        std::vector<int> arr{2,4,2,6,1,7,8,9,2,1};
        std::cout << candies(arr.size(), arr) << " expected 19"<< '\n';
    }

    {
        
        std::vector<int> arr{2,4,3,5,2,6,4,5};
        std::cout << candies(arr.size(), arr) << " expected 12"<< '\n';
    }

    return 0;
}