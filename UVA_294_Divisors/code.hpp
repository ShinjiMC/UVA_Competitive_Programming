#include <iostream>
#include <cmath>

int countDivisors(long n)
{
    int count = 0;
    for (int i = 1; i <= std::sqrt(n); ++i)
        if (n % i == 0)
            count += (n / i == i) ? 1 : 2;
    return count;
}

int code()
{
    long n;
    std::cin >> n;
    while (n--)
    {
        long L, U;
        std::cin >> L >> U;
        long max = 0, max_i = 0;
        for (auto i = L; i <= U; i++)
        {
            int divisors = countDivisors(i);
            if (divisors > max)
            {
                max = divisors;
                max_i = i;
            }
        }
        std::cout << "Between " << L << " and " << U << ", " << max_i << " has a maximum of " << max << " divisors.\n";
    }
    return 0;
}