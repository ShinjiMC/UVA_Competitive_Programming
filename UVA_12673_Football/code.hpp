#include <iostream>
#include <algorithm>
#include <vector>

int code()
{
    long n, g;
    while (std::cin >> n >> g && n)
    {
        std::vector<int> list;
        int s, r, res = 0;
        for (int i = 0; i < n; i++)
        {
            std::cin >> s >> r;
            if (s > r)
                res += 3;
            else
                list.push_back(r - s);
        }
        std::sort(list.begin(), list.end());
        for (int i = 0; i < list.size() && g >= list[i]; i++)
        {
            if (g >= list[i] + 1)
            {
                res += 3;
                g -= list[i] + 1;
            }
            else
            {
                res += 1;
                g -= list[i];
            }
        }
        std::cout << res << "\n";
    }
    return 0;
}