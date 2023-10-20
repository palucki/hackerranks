#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int lcs(std::string s1, std::string s2, int count)
{
    // std::cout << count << " handling " << s1 << " " << s2 << '\n';
    if(s1.empty() || s2.empty())
    {
        return count;
    }

    if(s1[s1.size() - 1] == s2[s2.size() - 1])
    {
        // std::cout << "A MATCH!\n";
        return lcs(s1.substr(0, s1.size() - 1), s2.substr(0, s2.size() - 1), count + 1);
    }

    count = std::max({count, lcs(s1.substr(0, s1.size() - 1), s2, count), lcs(s1, s2.substr(0, s2.size() - 1), count)});
    return count;
}

int commonChild(std::string s1, std::string s2) 
{
    int result = 0;

    result = lcs(s1, s2, 0);

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