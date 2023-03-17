#include <bits/stdc++.h>


// Complete the substrCount function below.
long substrCount(int n, const std::string& s) 
{
    bool debug = false;
    std::cout << '\n';
    
    static int iterations = 0;
    const auto is_special = [&s, &debug](int start, int end)
    {
        iterations++;

        if(start == end)
            return true;

        const auto window = end-start;
        const auto middle_index = window % 2 == 0 ? -1 : start + window/2;
        if(debug)
        {
            std::cout << "substr " << start << " to " << end  << " skipped " << middle_index << '\n';
        }

        for(int i = start; i < end; ++i)
        {
            if(i == middle_index)
                continue;

            if(s[start] != s[i])
                return false;
        }

        // //remove middle character - does not change anything
        // if(s.size() > 1 && s.size() % 2 != 0)
        //     s.erase(s.size() / 2, 1);

        //now all needs to be equal to first
        // return std::all_of(s.begin(), s.end(), [&] (auto const &c) {
        //     return c == s.front();
        // });

        if(debug)
            std::cout << "OK\n";
        return true;
    };

    iterations = 0;
    auto result = 0;
    
    for(int w = s.size(); w >= 1; --w)
    {
        if(debug)
            std::cout << "window " << w << " from " << 0 << " to " << s.size() - w << '\n';
        
        for(int i = 0; i < s.size() - w + 1; ++i)
        {
            // const auto substr = s.substr(i, w);
            
            // if(debug)
            //     std::cout << substr << '\n';
            
            if(is_special(i, i+w))
            {
                ++result;
            }
        }
    }

    std::cout << "iterations " << iterations << '\n';

    return result;
}

int main()
{
    std::string input{"aaa"};
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 6 << '\n';

    input = "abc";
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 3  << '\n';

    input = "aba";
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 4 << '\n';

    input = "mnonopoo";
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 12 << '\n';

    input = "aabaaca";
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 12 << '\n';

    // input = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"; 
    // std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 12 << '\n';

    return 0;
}