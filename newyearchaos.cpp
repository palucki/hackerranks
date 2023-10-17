#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_set>

/*
 * Complete the 'minimumBribes' function below.
 *
 * The function accepts INTEGER_ARRAY q as parameter.
 */

void minimumBribes(std::vector<int> input) 
{
    std::unordered_multiset<int> bribes_per_person;
    int overall_number_of_bribes = 0;
    bool swapped_in_last_turn;
        
    do 
    {
        swapped_in_last_turn = false;
        for (int i = 0; i < input.size() - 1; ++i) 
        {
            if (input[i] > input[i + 1]) 
            {
                // here we are swapping element input[i] with input[i+1]
                // that means input[i] bribed input[i+1]
                // std::cout << "Swapping " << input[i] << " with " << input[i+1] << '\n';
                    
                bribes_per_person.insert(input[i]);
                if(bribes_per_person.count(input[i]) > 2)
                {
                    std::cout << "Too chaotic\n";
                    return;
                }

                overall_number_of_bribes++;
                std::swap(input[i], input[i + 1]);
                swapped_in_last_turn = true;
            }
        }
    } 
    while (swapped_in_last_turn);

    std::cout << overall_number_of_bribes << '\n';
}

int main()
{
    for(const std::vector<int>& v: std::initializer_list<std::vector<int>>{
        {2, 1, 5, 3, 4}, // 3
        {2, 5, 1, 3, 4}, // too chaotic
        {5, 1, 2, 3, 7, 8, 6, 4}, // too chaotic 
        {1, 2, 5, 3, 7, 8, 6, 4}, // 7
        {1, 2, 5, 3, 4, 7, 8, 6} //4
    })
    {
        std::cout << "Input: " << vecToString(v) << " Result:          ";
        minimumBribes(v);
    }

    return 0;
}

