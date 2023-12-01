#include <iostream>
#include <vector>
#include <algorithm>

int positionFind(int i, int j, std::vector<long long> &input, std::vector<long long> &BST)
{
    int pos = i;
    long long mn = 10000, mx = 0;
    for (int k = i; k <= j; k++)
    {
        if (k != j && input[k] == input[k + 1])
            continue;
        long long l = BST[k - 1] - BST[i - 1], r = BST[j] - BST[k];
        long long diff = std::abs(l - r);
        if (diff < mn)
        {
            mn = diff;
            mx = l;
            pos = k;
        }
        if (l > mx && diff == mn)
        {
            mx = l;
            pos = k;
        }
    }
    return pos;
}

void construction(int i, int j, std::vector<long long> &input, std::vector<long long> &BST)
{
    if (j < i)
        return;
    int pos = positionFind(i, j, input, BST);
    long long data = BST[pos] - BST[pos - 1];
    std::cout << data;
    if (i != j)
    {
        std::cout << "(";
        construction(i, pos - 1, input, BST);
        if (i != pos && j != pos)
            std::cout << ",";
        construction(pos + 1, j, input, BST);
        std::cout << ")";
    }
}

int code()
{
    int T, count = 1;
    std::cin >> T;
    while (T--)
    {
        int n;
        std::cin >> n;
        std::vector<long long> input(n);
        for (int i = 0; i < n; i++)
            std::cin >> input[i];
        std::sort(input.begin(), input.end());
        std::vector<long long> BST(n + 1, 0);
        for (int i = 1; i <= n; i++)
            BST[i] = BST[i - 1] + input[i - 1];
        std::cout << "Case #" << count++ << ": ";
        construction(1, n, input, BST);
        std::cout << "\n";
    }

    return 0;
}