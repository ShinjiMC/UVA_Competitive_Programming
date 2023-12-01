#include <iostream>
#include <algorithm>
#include <vector>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return b.second < a.second;
}

int code()
{
    long n, cases = 1;
    while (std::cin >> n && n)
    {
        std::vector<std::pair<long, long>> list(n);
        long b, j;
        for (auto &c : list)
        {
            std::cin >> c.first >> c.second;
        }
        std::sort(list.begin(), list.end(), compare);
        long res = 0, time_B = 0;
        for (const auto &c : list)
        {
            time_B += c.first;
            res = std::max(res, time_B + c.second);
        }
        std::cout << "Case " << cases << ": " << res << "\n";
        cases++;
    }
    return 0;
}