#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

bool debug = false;

// Reference: https://cp-algorithms.com/data_structures/disjoint_set_union.html

int find_set(std::unordered_map<int, int>& parent, int v) 
{
   if (v == parent[v])
      return v;

   return parent[v] = find_set(parent, parent[v]);
}

void union_sets(std::unordered_map<int, int>& parent, std::unordered_map<int, int>& sizes_per_leader, int& max_circle_size, int a, int b) 
{
   int pa = find_set(parent, a);
   int pb = find_set(parent, b);

   if(debug)
   {
      std::cout << "Union for " << a << "," << b << '\n';
      std::cout << "Parents " << pa << "," << pb << '\n';
      std::cout << "Sizes " << sizes_per_leader[pa] << ',' << sizes_per_leader[pb] << '\n';
   }

   if (pa != pb)
   {
      parent[pb] = pa;
      sizes_per_leader[pa] = sizes_per_leader[pb] = sizes_per_leader[pa] + sizes_per_leader[pb];

      if(debug)
      {
         std::cout << "    merging\n";
         std::cout << "    new sizes " << sizes_per_leader[pa] << ',' << sizes_per_leader[pb] << '\n';
      }

      if(max_circle_size < sizes_per_leader[pa])
         max_circle_size = sizes_per_leader[pa];
   }
}

void make_set(std::unordered_map<int, int>& parent, std::unordered_map<int, int>& sizes_per_leader, int v) 
{
   //ok since 0 is not allowed as input
   if(find_set(parent, v))
      return;
   
   parent[v] = v;
   sizes_per_leader[v] = 1;
}

// Complete the maxCircle function below.
// https://www.hackerrank.com/challenges/friend-circle-queries
vector<int> maxCircle(vector<vector<int>> queries) 
{
   std::vector<int> result{};
   result.reserve(queries.size());
   
   int max_circle_size = 2;
   std::unordered_map<int, int> parent;
   std::unordered_map<int, int> sizes_per_leader;

   for(const auto& q : queries)
   {
      const auto a = q[0];
      const auto b = q[1];

      make_set(parent, sizes_per_leader, a);
      make_set(parent, sizes_per_leader, b);

      union_sets(parent, sizes_per_leader, max_circle_size, a, b);

      if(debug)
         std::cout << "max circle size: " << max_circle_size << '\n';

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