#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int findMinDiff(std::vector<int> &numbers, std::vector<int> &accumulate, int l, int r, int &index, int &maxLeft)
{
    int minDiff = INT_MAX;
    int maxLeftLocal = INT_MIN;
    for (int i = l; i <= r; i++)
    {
        if (i != r && numbers[i] == numbers[i + 1])
            continue;
        int left;
        if (i - 1 < 0)
            left = (l - 1 < 0) ? 0 : -accumulate[l - 1];
        else
            left = (l - 1 < 0) ? accumulate[i - 1] : accumulate[i - 1] - accumulate[l - 1];
        int right = accumulate[r] - accumulate[i];
        int diff = std::abs(right - left);
        if (diff < minDiff)
        {
            minDiff = diff;
            index = i;
            maxLeftLocal = left;
        }
        else if (diff == minDiff && left > maxLeftLocal)
        {
            index = i;
            maxLeftLocal = left;
        }
    }
    maxLeft = maxLeftLocal;
    return minDiff;
}

void order(std::vector<int> &numbers, std::vector<int> &accumulate, int l, int r)
{
    if (r < l)
        return;
    int index, maxLeft;
    int minDiff = findMinDiff(numbers, accumulate, l, r, index, maxLeft);
    std::cout << numbers[index];
    if (l != r)
    {
        std::cout << "(";
        order(numbers, accumulate, l, index - 1);
        if (l != index && index != r)
            std::cout << ",";
        order(numbers, accumulate, index + 1, r);
        std::cout << ")";
    }
}

void resolve(std::vector<int> &numbers)
{
    int l = 0;
    int r = numbers.size() - 1;
    std::vector<int> accumulate(numbers.size());
    accumulate[0] = numbers[0];
    for (int j = 1; j < numbers.size(); j++)
        accumulate[j] = accumulate[j - 1] + numbers[j];
    order(numbers, accumulate, l, r);
    std::cout << "\n";
}

int code()
{
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int x;
        std::cin >> x;
        std::vector<int> numbers(x);
        for (auto &c : numbers)
            std::cin >> c;
        std::sort(numbers.begin(), numbers.end());
        std::cout << "Case #" << i << ": ";
        resolve(numbers);
    }
    return 0;
}
