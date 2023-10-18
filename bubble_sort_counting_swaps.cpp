#include <iostream>
#include <vector>

void countSwaps(std::vector<int> a) 
{
    int num_swaps = 0;
    for(int i = 0; i < a.size(); ++i)
    {
        bool swapped = false;
        for(int j = 0; j < a.size() - 1; ++j)
        {
            if(a[j] > a[j+1])
            {
                std::swap(a[j], a[j+1]);
                swapped = true;
                num_swaps++;
            }
        }
        
        if(!swapped)
        {
            // std::cout << "No swap, breaking\n";
            break;
        }
    }
    
    std::cout << "Array is sorted in " << num_swaps << " swaps.\n";
    std::cout << "First Element: " << a[0] << '\n';
    std::cout << "Last Element: " << a[a.size()-1] << '\n';
}

int main()
{
    countSwaps({6, 4, 1});
}