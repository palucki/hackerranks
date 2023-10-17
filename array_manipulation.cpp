#include <iostream>
#include "common.h"

long arrayManipulation(int n, std::vector<std::vector<int>> queries)
{
    std::vector<long> data(n);
    // long max_value = 0;
    // // brute force: simply calculate
    // for(const auto& q : queries)
    // {
    //     int left_idx = q[0] - 1;
    //     int right_idx = q[1] - 1;
    //     int value = q[2];

    //     std::cout << "adding " << value << " between " << left_idx << "," << right_idx << '\n';

    //     for(int i = left_idx; i <= right_idx; ++i)
    //     {
    //         data[i] += value;
    //         if(data[i] > max_value)
    //         {
    //             max_value = data[i];
    //         }
    //     }
    // }

    // clever way: prefix sums
    long max_sum = 0;
    for(const auto& q : queries)
    {
        int left_idx = q[0] - 1;
        int right_idx = q[1] - 1;
        int value = q[2];

        std::cout << "left " << left_idx << " right " << right_idx << " val " << value << '\n';

        data[left_idx] += value;
        
        if(right_idx + 1 < n)
            data[right_idx + 1] -= value;
    }

    for(int i = 1; i < n; ++i)
    {
        data[i] = data[i] + data[i-1];
        if(data[i] > max_sum)
        {
            max_sum = data[i];
        }
    }

    return max_sum;
}

int main()
{
    {
        std::vector<std::vector<int>> queries = {
            {1, 5, 3},
            {4, 8, 7},
            {6, 9, 1}
        };
        
        std::cout << arrayManipulation(10, queries) << " expected is 10\n";
    }

    {
        std::vector<std::vector<int>> queries = {
            {1, 2, 100},
            {2, 5, 100},
            {3, 4, 100}
        };
        
        std::cout << arrayManipulation(5, queries) << " expected is 200\n";
    }
    
    return 0;
}