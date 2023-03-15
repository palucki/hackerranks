#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) 
{
    std::map<char, int> occurences;
    for(const auto&c : s)
    {
        occurences[c]++;
    }
     
    std::map<int, int> final_occurences;
    for(const auto& oc : occurences)
    {
        std::cout << "letter " << oc.first << " found: " << oc.second << " times\n";
        final_occurences[oc.second]++;
    }

    for(const auto& oc : final_occurences)
    {
        std::cout << "key " << oc.first << " found: " << oc.second << " times\n";
    }
    //expect YES

    if(final_occurences.size() <= 1)
        return "YES";

    if(final_occurences.size() > 2)
        return "NO";

    std::cout << "in progress\n";

    const auto elem_1 = final_occurences.begin();
    const auto elem_2 = std::next(final_occurences.begin());

    if((elem_1->first == 1 && elem_1->second == 1) || (elem_2->first == 1 && elem_2->second == 1))
    {
        return "YES";
    }

    if((elem_1->second == 1 || elem_2->second == 1) && std::abs(elem_1->first - elem_2->first) == 1)
    {
        return "YES";
    }

    return "NO";    
}

int main()
{
    std::string input{"ibfdgaeadiaefgbhbdghhhbgdfgeiccbiehhfcggchgghadhdhagfbahhddgghbdehidbibaeaagaeeigffcebfbaieggabcfbiiedcabfihchdfabifahcbhagccbdfifhghcadfiadeeaheeddddiecaicbgigccageicehfdhdgafaddhffadigfhhcaedcedecafeacbdacgfgfeeibgaiffdehigebhhehiaahfidibccdcdagifgaihacihadecgifihbebffebdfbchbgigeccahgihbcbcaggebaaafgfedbfgagfediddghdgbgehhhifhgcedechahidcbchebheihaadbbbiaiccededchdagfhccfdefigfibifabeiaccghcegfbcghaefifbachebaacbhbfgfddeceababbacgffbagidebeadfihaefefegbghgddbbgddeehgfbhafbccidebgehifafgbghafacgfdccgifdcbbbidfifhdaibgigebigaedeaaiadegfefbhacgddhchgcbgcaeaieiegiffchbgbebgbehbbfcebciiagacaiechdigbgbghefcahgbhfibhedaeeiffebdiabcifgccdefabccdghehfibfiifdaicfedagahhdcbhbicdgibgcedieihcichadgchgbdcdagaihebbabhibcihicadgadfcihdheefbhffiageddhgahaidfdhhdbgciiaciegchiiebfbcbhaeagccfhbfhaddagnfieihghfbaggiffbbfbecgaiiidccdceadbbdfgigibgcgchafccdchgifdeieicbaididhfcfdedbhaadedfageigfdehgcdaecaebebebfcieaecfagfdieaefdiedbcadchabhebgehiidfcgahcdhcdhgchhiiheffiifeegcfdgbdeffhgeghdfhbfbifgidcafbfcd"};
    std::cout << isValid(input)  << " expected: YES"<< '\n';

    input = "aabbcd";
    std::cout << isValid(input) << " expected: NO" << '\n';

    input = "aabbccddeefghi";
    std::cout << isValid(input) << " expected: NO" << '\n';

    input ="abcdefghhgfedecba";
    std::cout << isValid(input) << " expected: YES" << '\n';

    return 0;
}