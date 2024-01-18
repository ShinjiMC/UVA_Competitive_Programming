#include <iostream>
#include <algorithm>

long calculateValue(long cons, bool isConsumption)
{
    long price = 0;
    if (isConsumption)
    {
        price += std::min(std::max(static_cast<long>(0), cons / 2), static_cast<long>(100));
        cons -= 2 * 100;
        price += std::min(std::max(static_cast<long>(0), cons / 3), static_cast<long>(9900));
        cons -= 3 * 9900;
        price += std::min(std::max(static_cast<long>(0), cons / 5), static_cast<long>(990000));
        cons -= 5 * 990000;
        price += std::max(static_cast<long>(0), cons / 7);
    }
    else
    {
        price += std::min(std::max(static_cast<long>(0), cons * 2), static_cast<long>(2 * 100));
        cons -= 100;
        price += std::min(std::max(static_cast<long>(0), cons * 3), static_cast<long>(3 * 9900));
        cons -= 9900;
        price += std::min(std::max(static_cast<long>(0), cons * 5), static_cast<long>(5 * 990000));
        cons -= 990000;
        price += std::max(static_cast<long>(0), cons * 7);
    }
    return price;
}

int code()
{
    long a, b;
    while (std::cin >> a >> b, a || b)
    {
        long total = calculateValue(a, true);
        long begin = 0, end = total;
        long answer = 0;

        while (begin < end)
        {
            long mine = (begin + end) / 2;
            long diff = calculateValue(total - mine, false) - calculateValue(mine, false);
            if (diff > b)
                begin = mine;
            else if (diff < b)
                end = mine;
            else
            {
                answer = mine;
                break;
            }
        }
        std::cout << calculateValue(answer, false) << "\n";
    }
    return 0;
}