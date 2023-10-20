#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int activityNotifications(std::vector<int> expenditure, int d) 
{
    int notifications = 0;
    
    for(int i = d; i < expenditure.size(); ++i)
    {
        std::vector<int> sorted_expenditure(expenditure.begin() + i - d, expenditure.begin() + i);
        std::sort(sorted_expenditure.begin(), sorted_expenditure.end());
        const double median = [&sorted_expenditure](){
            const int half = sorted_expenditure.size() / 2;
            
            if(sorted_expenditure.size() % 2 == 0)
            {
                return (sorted_expenditure[half] + sorted_expenditure[half-1]) / 2.0;
            }
            else
            {
                return static_cast<double>(sorted_expenditure[half]);
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