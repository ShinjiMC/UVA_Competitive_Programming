#include <iostream>
#include <algorithm>
int code()
{
    std::string input;
    while (std::cin >> input)
    {
        int a = 0, maxC = 0;
        bool foundX = false;
        for (const auto &c : input)
        {
            if (c == 'X')
            {
                if (foundX)
                {
                    maxC = std::max(maxC, (a + 1) / 2 - 1);
                }
                else
                {
                    foundX = true;
                    maxC = std::max(maxC, a - 1);
                }
                a = 0;
            }
            else
                a++;
        }
        maxC = std::max(maxC, a - 1);
        std::cout << maxC << "\n";
    }
    return 0;
}