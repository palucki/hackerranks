#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int lcs(const std::string& s1, int s1_idx, const std::string& s2, int s2_idx, std::vector<std::vector<int>>& results)
{
    if(s1_idx == -1 || s2_idx == -1)
    {
        return 0;
    }

    // std::cout << " handling " << s1.substr(0, s1_idx+1) << " " << s2.substr(0, s2_idx+1) << '\n';
    
    if(results[s1_idx][s2_idx] != -1)
    {
        // std::cout << s1.substr(0, s1_idx+1) << " " << s2.substr(0, s2_idx+1) 
        //           << " seen before with result " << results[s1_idx][s2_idx] << '\n';
        
        return results[s1_idx][s2_idx];
    }

    if(s1[s1_idx] == s2[s2_idx])
    {
        results[s1_idx][s2_idx] = 1 + lcs(s1, s1_idx - 1, s2, s2_idx - 1, results);
        return results[s1_idx][s2_idx];
    }

    auto count = std::max({lcs(s1, s1_idx, s2, s2_idx - 1, results), 
                           lcs(s1, s1_idx - 1, s2, s2_idx, results)}); 

    results[s1_idx][s2_idx] = count;
    
    return results[s1_idx][s2_idx];
}

int commonChild(std::string s1, std::string s2) 
{
    int result = 0;
    std::vector<std::vector<int>> cached_results{s1.size()};
    for(int i = 0; i < s1.size(); ++i)
    {
        // -1 means uninitialized
        cached_results[i] = std::vector<int>(s2.size(), -1);
    }

    result = lcs(s1, s1.size() - 1, s2, s2.size() - 1, cached_results);

    return result;
}

int main()
{
    std::cout << commonChild("HARRY", "SALLY") << '\n'; // expect 2
    std::cout << commonChild("ABCD", "ABDC") << '\n'; // expect 3
    std::cout << commonChild("AA", "BB") << '\n'; // expect 0
    std::cout << commonChild("SHINCHAN", "NOHARAAA") << '\n'; // expect 3
    std::cout << commonChild("ABCDEF", "FBDAMN") << '\n'; // expect 2
}