#include <iostream>
#include <cmath>

long GDC(long a, long b)
{
    while (b != 0)
    {
        long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int code()
{
    long n;
    while (std::cin >> n && n != 0)
    {
        long G = 0;
        for (auto i = 1; i < n; i++)
            for (auto j = i + 1; j <= n; j++)
                G += GDC(i, j);
        std::cout << G << "\n";
    }
    return 0;
}