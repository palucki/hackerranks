#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

// Complete the maxSubsetSum function below.
int maxSubsetSum(std::vector<int> arr) 
{
    //represents best possible result at the given index
    std::vector<int> results(arr.size(), 0);
    
    int max_sum = 0;
    for(int i = 0; i < arr.size(); ++i)
    {
        if(i == 0) 
        {
            results[i] = std::max({arr[i], 0});
        }
        else if(i == 1)
        {
            results[i] = std::max({arr[i], arr[0], 0});
        }
        else 
        {
            results[i] = std::max({arr[i] + results[i-2], results[i-1], 0});
        }

        if(results[i] > max_sum)
            max_sum = results[i];
    }

    // for(const auto br : results)
    //     std::cout << br << " ";

    return max_sum;
}

int main()
{
    std::cout << maxSubsetSum({-1, 1, 3, -4, 5}) << '\n'; // expect 8
    std::cout << maxSubsetSum({3, 7, 4, 6, 5}) << '\n'; // expect 13
    std::cout << maxSubsetSum({2, 1, 5, 8, 4}) << '\n'; // expect 11
    std::cout << maxSubsetSum({3, 5, -7, 8, 10}) << '\n'; // expect 15

}