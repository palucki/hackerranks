#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

bool debug = true;

// Complete the maxCircle function below.
// https://www.hackerrank.com/challenges/friend-circle-queries
vector<int> maxCircle(vector<vector<int>> queries) 
{
   std::vector<int> result{};
   result.reserve(queries.size());
   std::list<std::unordered_set<int>> circles;
   
   unsigned int max_circle_size = 2;

   for(const auto& q : queries)
   {
      const auto a = q[0];
      const auto b = q[1];
      
      const auto a_circle_it = std::find_if(begin(circles), end(circles), 
      [elem=a](const std::unordered_set<int>& circle)
      {
         return circle.count(elem) == 1;
      });
      
      const auto b_circle_it = std::find_if(begin(circles), end(circles), 
      [elem=b](const std::unordered_set<int>& circle)
      {
         return circle.count(elem) == 1;
      });
      
      if(a_circle_it == end(circles) && b_circle_it == end(circles))
      {
         //not found in neither of circles - start a new one :)
         if(debug)
            std::cout << "adding new with " << a << " " << b << "\n";
         circles.push_back({a, b});
      }
      else if(a_circle_it != end(circles) && b_circle_it != end(circles))
      {
         // circles for both found, if equal -> skip
         // if not equal -> merge a+b and remove b
         if(a_circle_it != b_circle_it)
         {
            if(debug)
               std::cout << "merging\n";
            
            //pre C++17
            a_circle_it->insert(b_circle_it->begin(), b_circle_it->end());

            //with C++17
            // a_circle_it->merge(*b_circle_it);

            //check if that works
            circles.erase(b_circle_it);

            if(max_circle_size < a_circle_it->size())
            {
               max_circle_size = a_circle_it->size();
            }
         }
      }
      else if(a_circle_it != end(circles))
      {
         if(debug)
            std::cout << "Adding " << b << " to set A\n";
         a_circle_it->insert(b);

         if(max_circle_size < a_circle_it->size())
         {
            max_circle_size = a_circle_it->size();
         }
      }
      else if(b_circle_it != end(circles))
      {
         if(debug)
            std::cout << "Adding " << a << " to set B\n";
         b_circle_it->insert(a);

         if(max_circle_size < b_circle_it->size())
         {
            max_circle_size = b_circle_it->size();
         }
      }

      if(debug)
         for(const auto& c : circles)
         {
            std::cout << "circle: ";
            for(const auto& e : c)
            {
               std::cout << e << ',';
            }
            std::cout << '\n';
         }

      if(debug)
         std::cout << "max circle size is: " << max_circle_size << '\n';

      result.push_back(max_circle_size);
   }

   return result;
}

int main()
{
   {
      std::cout << "Test 1\n";
      vector<vector<int>> queries {
         {1, 2},
         {1, 3},
      };
      vector<int> ans = maxCircle(queries);
      for (int i = 0; i < ans.size(); i++)
      {
         std::cout << ans[i] << '\n';
      }
   }

   {
      std::cout << "Test 2\n";
      vector<vector<int>> queries { 
         {1000000000, 23},
         {11, 3778},
         {7, 47},
         {11, 1000000000},
      };
      vector<int> ans = maxCircle(queries);
      for (int i = 0; i < ans.size(); i++)
      {
         std::cout << ans[i] << '\n';
      }
   }
   
   {
      std::cout << "Test 3\n";
      vector<vector<int>> queries { 
         {1, 2},
         {3, 4},
         {1, 3},
         {5, 7},
         {5, 6},
         {7, 4},
      };
      vector<int> ans = maxCircle(queries);
      for (int i = 0; i < ans.size(); i++)
      {
         std::cout << ans[i] << '\n';
      }
   }

   return 0;
}