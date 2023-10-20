#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int activityNotifications(std::vector<int> expenditure, int d) 
{
    auto getMedian = [](const std::deque<int>& sorted_expenditure) {
        
        const int half = sorted_expenditure.size() / 2;
        if(sorted_expenditure.size() % 2 == 0)
        {
            return (sorted_expenditure[half] + sorted_expenditure[half-1]) / 2.0;
        }
        else
        {
            return static_cast<double>(sorted_expenditure[half]);
        }
    };

    int notifications = 0;
    std::deque<int> sorted_expenditure{expenditure.begin(), expenditure.begin() + d};
    std::sort(sorted_expenditure.begin(), sorted_expenditure.end());

    for(int i = d; i < expenditure.size(); ++i)
    {
        const int new_expense = expenditure[i];
        const double median = getMedian(sorted_expenditure);
        
        if(new_expense >= 2 * median)
        {
            notifications++;
        }

        // update sorted expenditures
        int to_remove = expenditure[i - d];
        auto to_remove_it = std::lower_bound(sorted_expenditure.begin(), sorted_expenditure.end(), to_remove);
        sorted_expenditure.erase(to_remove_it);

        auto insert_at = std::upper_bound(sorted_expenditure.begin(), sorted_expenditure.end(), new_expense);        
        sorted_expenditure.insert(insert_at, new_expense);
    }

    return notifications;
}

int main()
{
    std::cout << activityNotifications({2, 3, 4, 2, 3, 6, 8, 4, 5}, 5) << '\n'; // expect 2
    std::cout << activityNotifications({1, 2, 3, 4, 4}, 4) << '\n'; // expect 0
}