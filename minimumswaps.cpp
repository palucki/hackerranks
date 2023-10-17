#include <bits/stdc++.h>
#include <iostream>
#include "common.h"

// Complete the minimumSwaps function below.
int minimumSwaps(std::vector<int> arr) 
{
    //returns int: the minimum number of swaps to sort the array
    int min_swaps = 0;

    for(int current = 0; current < arr.size() - 1; ++current)
    {
        bool stop = false;
        int desired = current + 1;
        if(arr[current] != desired)
        {
            for(int candidate = current + 1; candidate < arr.size() && !stop; ++candidate)
            {
                if(arr[candidate] == desired)
                {
                    if(false)
                        std::cout << "Swapping " << arr[current] << " with " << arr[candidate] << '\n';
                    arr[candidate] = arr[current];
                    // std::swap(arr[current], arr[candidate]);
                    min_swaps++;
                    stop = true;
                }
            }
        }
    }

    return min_swaps;
}

int main()
{
    for(const std::vector<int>& v: std::initializer_list<std::vector<int>>{
        {1}, // 0
        {1, 2, 3, 4}, // 0
        {2, 1}, // 1
        {3, 2, 1}, // 1
        {4, 3, 2, 1}, // 2
        {7, 1, 3, 2, 4, 5, 6}, // 5
        {4, 3, 1, 2}, // 3
        {2, 3, 4, 1, 5}, // 3
        {1, 3, 5, 2, 4, 6, 7} // 3
    })
    {
        std::cout << "Input: " << helpers::vecToString(v) << " number of swaps: ";
        std::cout << minimumSwaps(v) << '\n';
    }
    
    return 0;
}
