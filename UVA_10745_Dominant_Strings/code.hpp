#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

int code()
{
    std::vector<std::vector<int>> cadsCount;
    std::vector<std::string> cads;
    std::string a;
    while (std::cin >> a)
    {
        std::vector<int> aux(26, 0);
        cads.push_back(a);
        for (char c : a)
            aux[c - 'a']++;
        cadsCount.push_back(aux);
    }
    std::vector<std::string> ans;
    for (int i = 0; i < cadsCount.size(); i++)
    {
        bool flag1 = true;
        for (int j = 0; j < cadsCount.size(); j++)
        {
            if (i == j)
                continue;
            bool isSubset = true;
            for (int k = 0; k < 26; k++)
            {
                if (cadsCount[i][k] > cadsCount[j][k])
                {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset)
            {
                flag1 = false;
                break;
            }
        }
        if (flag1)
            ans.push_back(cads[i]);
    }
    std::sort(ans.begin(), ans.end());
    for (const auto &i : ans)
        std::cout << i << "\n";
    return 0;
}