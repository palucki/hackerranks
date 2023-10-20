#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int lcs(const std::string& s1, int s1_idx, const std::string& s2, int s2_idx, int count)
{
    if(s1_idx == -1 || s2_idx == -1)
    {
        return count;
    }

    if(s1[s1_idx] == s2[s2_idx])
    {
        return lcs(s1, s1_idx - 1, s2, s2_idx - 1, count + 1);
    }

    count = std::max({count, 
        lcs(s1, s1_idx - 1, s2, s2_idx, count), 
        lcs(s1, s1_idx, s2, s2_idx - 1, count)}); 
    return count;
}

int commonChild(std::string s1, std::string s2) 
{
    int result = 0;

    result = lcs(s1, s1.size() - 1, s2, s2.size() - 1, 0);

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