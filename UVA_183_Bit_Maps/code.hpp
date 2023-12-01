#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
void BD(const std::vector<std::vector<int>> &ans, int minF, int maxF, int minC, int maxC, int &count)
{
    if (minF == maxF || minC == maxC)
        return;
    int zeros = 0;
    for (int i = minF; i < maxF; i++)
    {
        zeros += std::count(ans[i].begin() + minC, ans[i].begin() + maxC, 0);
    }
    if (0 < count && count % 50 == 0)
        std::cout << "\n";
    count++;
    if (zeros == (maxF - minF) * (maxC - minC))
        std::cout << "0";
    else if (zeros == 0)
        std::cout << "1";
    else
    {
        std::cout << "D";
        int midF = (minF + maxF + 1) / 2;
        int midC = (minC + maxC + 1) / 2;
        BD(ans, minF, midF, minC, midC, count);
        BD(ans, minF, midF, midC, maxC, count);
        BD(ans, midF, maxF, minC, midC, count);
        BD(ans, midF, maxF, midC, maxC, count);
    }
}

void DB(std::vector<std::vector<int>> &ans, int minF, int maxF, int minC, int maxC)
{
    if (minF == maxF || minC == maxC)
        return;
    int ch = std::cin.get();
    if (ch == '0' || ch == '1')
    {
        for (int i = minF; i < maxF; i++)
        {
            for (int j = minC; j < maxC; j++)
            {
                ans[i][j] = ch - '0';
            }
        }
        return;
    }
    else
    {
        int midF = (minF + maxF + 1) / 2;
        int midC = (minC + maxC + 1) / 2;
        DB(ans, minF, midF, minC, midC);
        DB(ans, minF, midF, midC, maxC);
        DB(ans, midF, maxF, minC, midC);
        DB(ans, midF, maxF, midC, maxC);
    }
}

int code()
{
    char T;
    while (std::cin >> T && T != '#')
    {
        int f, c;
        std::cin >> f >> c;
        std::cin.ignore();
        std::cout << (T == 'B' ? "D" : "B") << std::right << std::setw(4) << f << std::right << std::setw(4) << c << "\n";

        std::vector<std::vector<int>> ans(f, std::vector<int>(c));
        if (T == 'B')
        {
            std::string bm;
            while (bm.size() < (f * c))
            {
                std::string line;
                std::getline(std::cin, line);
                bm += line;
            }

            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    ans[i][j] = bm[i * c + j] - '0';
                }
            }

            int count = 0;
            BD(ans, 0, f, 0, c, count);
            std::cout << "\n";
        }
        else
        {
            DB(ans, 0, f, 0, c);
            for (int i = 0; i < f; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (0 < i + j && (i * c + j) % 50 == 0)
                    {
                        std::cout << "\n";
                    }
                    std::cout << ans[i][j];
                }
            }
            std::cout << "\n";
        }
    }
    return 0;
}
