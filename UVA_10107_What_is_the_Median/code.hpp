#include <iostream>
#include <vector>
#include <algorithm>
int mediam()
{
    std::vector<long> numbers;
    long num, size = 0;
    while (std::cin >> num)
    {
        auto it = std::lower_bound(numbers.begin(), numbers.end(), num);
        numbers.insert(it, num);
        size++;
        if (size % 2 == 0)
            std::cout << (numbers[size / 2 - 1] + numbers[size / 2]) / 2 << std::endl;
        else
            std::cout << numbers[size / 2] << std::endl;
    }
    return 0;
}