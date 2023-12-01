#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

int code()
{
    std::set<long long> lista;
    for (int i = 0; i < 33; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            lista.insert(std::pow(2, i) * std::pow(3, j));
        }
    }
    long long n;
    while (std::cin >> n, n)
    {
        auto it = lista.lower_bound(n);
        std::cout << *it << std::endl;
    }
    return 0;
}