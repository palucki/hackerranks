#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <deque>

int sherlockAndAnagrams(std::string s) 
{
    std::unordered_map<std::string, int> freqs;
    int count = 0;

    for(int i = 0; i < s.size(); ++i)
    {
        for(int len = 1; len <= s.size() - i; ++len)
        {
            auto substr = s.substr(i, len);
            std::sort(substr.begin(), substr.end());

            if(freqs.find(substr) != freqs.end())
            {
                count += freqs[substr];

            }
            ++freqs[substr];
        }
    }

    return count;
}

int main()
{


    std::cout << sherlockAndAnagrams("mom") << " expected 2"<< '\n';
    std::cout << sherlockAndAnagrams("abba") << " expected 4"<< '\n';
    std::cout << sherlockAndAnagrams("abcd") << " expected 0"<< '\n';
    std::cout << sherlockAndAnagrams("ifailuhkqq") << " expected 3"<< '\n';
    std::cout << sherlockAndAnagrams("kkkk") << " expected 10"<< '\n';
    std::cout << sherlockAndAnagrams("cdcd") << " expected 5"<< '\n';
    
    return 0;
}