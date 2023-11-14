#include <iostream>
#include <unordered_map>

int code()
{
    std::unordered_map<char, int> codeParse = {
        {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1}, {'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2}, {'D', 3}, {'T', 3}, {'L', 4}, {'M', 5}, {'N', 5}, {'R', 6}};
    std::string cad;
    while (std::cin >> cad)
    {
        std::string ans;
        int ant = -1;
        for (auto i : cad)
        {
            if (codeParse.find(i) != codeParse.end())
            {
                int code = codeParse[i];
                if (ant != code)
                {
                    ans += std::to_string(code);
                    ant = code;
                }
            }
            else
            {
                ant = -1;
            }
        }

        std::cout << ans << std::endl;
    }
    return 0;
}
