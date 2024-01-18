#include <iostream>
#include <algorithm>
#include <vector>

int code()
{
    long n;
    while (std::cin >> n && n)
    {
        std::vector<long> values(n);
        for (auto &c : values)
            std::cin >> c;
        std::sort(values.begin(), values.end());
        long cost = 0;
        while (values.size() > 1)
        {
            long a = values[0], b = values[1];
            values.erase(values.begin(), values.begin() + 2);
            cost += a + b;
            values.insert(std::upper_bound(values.begin(), values.end(), a + b), a + b);
        }
        std::cout << cost << "\n";
    }
    return 0;
}