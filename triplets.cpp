#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

// std::map<int, int> factors;

std::pair<bool, int> get_factor(int n, int r, int m = 0)
{
    
    // if(n == 0)
    // {
    //     return {false, 0};
    // }

    // if(n == 1)
    // {
    //     return {true, 0};
    // }

    // if(n == r)
    // {
    //     return {true, 1};
    // }

    if(n == m)
    {
        return {true, 1};
    }

    // if(m == 0)
    // {
        
    // }

    if(m < n)
    {
        auto res = get_factor(n, r, m * r);
        res.second += 1;
        return res;
    }

    return {false, 0};
}

long NCR(int n, int r)
{
    if (r == 0) return 1;

    /*
     Extra computation saving for large R,
     using property:
     N choose R = N choose (N-R)
    */
    if (r > n / 2) return NCR(n, n - r); 

    long res = 1; 

    for (int k = 1; k <= r; ++k)
    {
        res *= n - k + 1;
        res /= k;
    }

    return res;
}

// Complete the countTriplets function below.
long countTriplets(std::vector<int> arr, int r)
{
    std::unordered_map<long, long> right_side;
    std::unordered_map<long, long> left_side;
    long count = 0;

    for(const auto& n : arr)
    {
        // if(n != 1 && n % r != 0)
        //     continue;

        right_side[n]++;
    }

    if(r == 1)
    {
        for(const auto o : right_side)
        {
            std::cout << "Special case with r == 1 occurence " << o.first << " " << o.second << '\n';
            const auto n = o.second;
            count += NCR(n, 3);
        }

        return count;
    }

    for(const auto& n : arr)
    {
        right_side[n]--;

        if(n % r == 0)
            count += left_side[n/r] * right_side[n*r];
        
        left_side[n]++;
    }

    return count;
}

int main()
{
    //tu mamy problem
    std::cout << countTriplets({4, 1, 16}, 4) << " expected 0"<< '\n';
    std::cout << countTriplets({16, 4, 1}, 4) << " expected 0"<< '\n';

    std::cout << countTriplets({1, 4, 16, 64}, 4) << " expected 2"<< '\n';
    std::cout << countTriplets({1, 5, 5, 25, 125}, 5) << " expected 4"<< '\n';
    std::cout << countTriplets({1, 3, 9, 9, 27, 81}, 3) << " expected 6"<< '\n';
    std::cout << countTriplets({1, 1, 1, 1, 1}, 1) << " expected 1"<< '\n';
    std::cout << countTriplets({1237, 1237, 1237, 1237, 1237}, 1) << " expected 1"<< '\n';
    return 0;
}