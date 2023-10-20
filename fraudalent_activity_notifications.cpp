#include <iostream>
#include <vector>
#include <set>

// void countSwaps(std::vector<int> a) 
// {
//     int num_swaps = 0;
//     for(int i = 0; i < a.size(); ++i)
//     {
//         bool swapped = false;
//         for(int j = 0; j < a.size() - 1; ++j)
//         {
//             if(a[j] > a[j+1])
//             {
//                 std::swap(a[j], a[j+1]);
//                 swapped = true;
//                 num_swaps++;
//             }
//         }
        
//         if(!swapped)
//         {
//             // std::cout << "No swap, breaking\n";
//             break;
//         }
//     }
    
//     std::cout << "Array is sorted in " << num_swaps << " swaps.\n";
//     std::cout << "First Element: " << a[0] << '\n';
//     std::cout << "Last Element: " << a[a.size()-1] << '\n';
// }

int activityNotifications(std::vector<int> expenditure, int d) 
{
    int notifications = 0;
    
    for(int i = d; i < expenditure.size(); ++i)
    {
        std::multiset<int> sorted_expenditure(expenditure.begin() + i - d, expenditure.begin() + i);
        const double median = [&sorted_expenditure](){
            if(sorted_expenditure.size() % 2 == 0)
            {
                auto it = sorted_expenditure.begin();
                std::advance(it, sorted_expenditure.size() / 2);
                return (*it + *std::prev(it)) / 2.0;
            }
            else
            {
                auto it = sorted_expenditure.begin();
                std::advance(it, sorted_expenditure.size() / 2);
                return double(*it);
            }
        }();
        
        // std::cout << "Median is " << median << '\n';

        if(expenditure[i] >= 2 * median)
        {
            notifications++;
        }
    }

    return notifications;
}

int main()
{
    std::cout << activityNotifications({2, 3, 4, 2, 3, 6, 8, 4, 5}, 5) << '\n'; // expect 2
    std::cout << activityNotifications({1, 2, 3, 4, 4}, 4) << '\n'; // expect 0
}