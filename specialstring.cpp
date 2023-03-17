#include <bits/stdc++.h>


// Complete the substrCount function below.
// https://www.hackerrank.com/challenges/special-palindrome-again/problem
long substrCount(int n, const std::string& s) 
{
    bool debug = false;
    std::cout << '\n';
    
    auto result = 0;

    const auto consecutive_count = [](int n)
    {
        return n * (n + 1) / 2.0;
    };

    for(int i = 0; i < s.size(); ++i)
    {
        int right_index = i + 1;
        int consecutive_same_length = 1;
        
        while(right_index < s.size() && s[i] == s[right_index])
        {
            consecutive_same_length++;
            right_index++;
            i++;
        }

        // i = i + right_index;
        if(i >= s.size())
        {
            if(debug)
            {
                std::cout << "idx " << i << " adding consecutive count: " << consecutive_count(consecutive_same_length) << "\n";
                std::cout << "Reached end iterating right\n";
            }
            result += consecutive_count(consecutive_same_length);
            break;
        }

        auto neighbours_count = 0;
        int left_offset = i - 1;
        int right_offset = i + 1;
        char last = 0;
        while(left_offset >= 0 && right_offset < s.size() && s[left_offset] == s[right_offset] && (last == 0 || s[left_offset] == last))
        {
            last = s[left_offset];
            neighbours_count++;
            left_offset--;
            right_offset++;
        }

        if(debug)
        {
            std::cout << "idx " << i << " adding consecutive count: " << consecutive_count(consecutive_same_length) 
                                    << " neighbouts count: " << neighbours_count << "\n";
        }
        result += consecutive_count(consecutive_same_length) + neighbours_count;
    }

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

    input = "abcbaba";
    std::cout << "input: " << input << " result: " << substrCount(input.size(), input)  << " expected: " << 10 << '\n';


    return 0;
}