#include <iostream>
#include <vector>
#include <algorithm>

int longestIncreasingSubsequence(const std::vector<std::pair<int, int>> &blocks)
{
    int n = blocks.size();
    std::vector<int> lista(n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = std::upper_bound(lista.begin(), lista.begin() + result, blocks[i].second) - lista.begin();
        lista[idx] = blocks[i].second;
        if (idx == result)
            result++;
    }
    return result;
}

int code()
{
    int n;
    while (std::cin >> n && n != 0)
    {
        std::vector<std::pair<int, int>> blocks(n);
        for (auto &c : blocks)
        {
            std::cin >> c.first >> c.second;
        }
        std::sort(blocks.begin(), blocks.end());
        std::cout << longestIncreasingSubsequence(blocks) << "\n";
    }
    std::cout << "*\n";
    return 0;
}