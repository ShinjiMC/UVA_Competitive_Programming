#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

int code()
{
    std::string cad;
    int cases = 1;
    while (std::cin >> cad && cad != "end")
    {
        std::vector<std::stack<char>> pilas;
        for (auto i : cad)
        {
            bool insert = true;
            for (auto &c : pilas)
            {
                if (i <= c.top() && insert)
                {
                    c.push(i);
                    insert = false;
                    break;
                }
            }
            if (insert)
            {
                pilas.push_back(std::stack<char>());
                pilas.back().push(i);
            }
        }
        std::cout << "Case " << cases << ": " << pilas.size() << std::endl;
        cases++;
    }
    return 0;
}