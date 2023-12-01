#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>

bool Dominant(const std::string &str1, const std::string &str2)
{
    std::string sorted_str1 = str1;
    std::string sorted_str2 = str2;
    std::sort(sorted_str1.begin(), sorted_str1.end());
    std::sort(sorted_str2.begin(), sorted_str2.end());
    return std::includes(sorted_str2.begin(), sorted_str2.end(), sorted_str1.begin(), sorted_str1.end());
}

int code()
{
    std::set<std::string> dominant;
    std::string cad;
    while (std::getline(std::cin, cad))
    {
        if (cad.empty())
        {
            break;
        }
        bool can = 1;
        for (const auto &i : dominant)
        {
            if (Dominant(cad, i))
            {
                can = !can;
                break;
            }
        }
        if (can)
        {
            dominant.insert(cad);
        }
    }
    for (const auto &i : dominant)
    {
        std::cout << i << "\n";
    }
    return 0;
}