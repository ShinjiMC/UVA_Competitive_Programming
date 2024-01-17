#include <iostream>
#include <cmath>

int code()
{
    long n;
    while (std::cin >> n && n != 0)
    {
        long ans = n;
        n = std::abs(n);
        std::cout << ans << " = ";
        if (ans < 0)
            std::cout << "-1 x ";
        for (long i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                long cmp = 0;
                while (n % i == 0)
                {
                    cmp++;
                    n /= i;
                }
                while (cmp--)
                {
                    if (cmp == 0 && n == 1)
                        std::cout << i;
                    else
                        std::cout << i << " x ";
                }
            }
        }
        if (n > 1)
            std::cout << n;
        std::cout << "\n";
    }
    return 0;
}