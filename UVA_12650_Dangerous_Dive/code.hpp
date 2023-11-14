#include <iostream>
#include <unordered_set>

int code()
{
    int n, r;
    while (std::cin >> n >> r)
    {
        if (n == r)
        {
            std::cout << "*";
        }
        std::unordered_set<int> voluntario(r);
        for (int i = 0; i < r; ++i)
        {
            int num;
            std::cin >> num;
            voluntario.insert(num);
        }
        for (int i = 1; i <= n; i++)
        {
            if (voluntario.find(i) == voluntario.end())
                std::cout << i << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
