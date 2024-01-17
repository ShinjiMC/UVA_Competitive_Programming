#include <iostream>
#include <cmath>

bool primo(long n)
{
    if (n <= 1)
        return false;
    long limite = static_cast<long>(sqrt(n));
    for (auto i = 2; i <= limite; i++)
        if (n % i == 0)
            return false;
    return true;
}

long nextP(long n)
{
    do
    {
        ++n;
    } while (!primo(n));
    return n;
}

long backP(long n)
{
    do
    {
        --n;
    } while (n > 1 && !primo(n));
    return n;
}

int code()
{
    long n;
    while (std::cin >> n && n != 0)
    {
        if (primo(n))
            std::cout << "0\n";
        else
        {
            std::cout << nextP(n) - backP(n) << "\n";
        }
    }
    return 0;
}