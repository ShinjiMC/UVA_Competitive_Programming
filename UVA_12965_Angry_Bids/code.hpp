#include <iostream>
#include <algorithm>
#include <vector>

int code()
{
    long T;
    std::cin >> T;
    while (T--)
    {
        long n, m;
        std::cin >> n >> m;
        std::vector<long> a(n), b(m);
        for (auto &c : a)
            std::cin >> c;
        for (auto &c : b)
            std::cin >> c;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        long p = 0, j = n;
        for (long i = 0; i < n; ++i)
        {
            long tmp = n - i - 1 + std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (tmp < j)
                j = tmp, p = a[i];
        }
        std::cout << p << " " << j << "\n";
    }
    return 0;
}