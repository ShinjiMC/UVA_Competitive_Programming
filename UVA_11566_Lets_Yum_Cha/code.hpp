#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

void processInput(int N, int X, int T, int K, std::vector<int> &price, std::vector<int> &favor)
{
    for (int i = 0; i < K; i++)
    {
        int p;
        std::cin >> p;
        price.push_back(p);
        price.push_back(p);
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            int dish;
            std::cin >> dish;
            sum += dish;
        }
        favor.push_back(sum);
        favor.push_back(sum);
    }
}

void calculateMaxFavor(int N, int X, int T, int K)
{
    N++;
    std::vector<int> price;
    std::vector<int> favor;
    processInput(N, X, T, K, price, favor);

    int maxDimSum = std::min(2 * N, static_cast<int>(price.size())) + 1;
    int maxPrice = static_cast<int>(10.0 * static_cast<double>(N * X) / 11.0 - static_cast<double>(N * T) + 1);
    std::vector<std::vector<int>> dp(maxDimSum, std::vector<int>(maxPrice, INT_MIN));
    for (int i = 0; i < maxDimSum; i++)
        dp[i][0] = 0;
    for (int i = 0; i < maxPrice; i++)
        dp[0][i] = 0;
    for (int i = 0; i < price.size(); i++)
    {
        std::vector<std::vector<int>> tmp = dp;
        for (int j = 0; j < maxDimSum; j++)
            for (int k = 0; k < maxPrice; k++)
                if (dp[j][k] != INT_MIN && j + 1 < maxDimSum && k + price[i] < maxPrice)
                    tmp[j + 1][k + price[i]] = std::max(dp[j + 1][k + price[i]], dp[j][k] + favor[i]);
        dp = tmp;
    }

    int maxFavor = 0;
    for (const auto &row : dp)
        for (const auto &cell : row)
            if (cell > maxFavor)
                maxFavor = cell;
    double averageFavor = static_cast<double>(maxFavor) / static_cast<double>(N);
    std::cout << std::fixed << std::setprecision(2) << averageFavor << std::endl;
}

int code()
{
    int N, X, T, K;

    while (std::cin >> N >> X >> T >> K && !(X == 0 && T == 0 && K == 0))
    {
        calculateMaxFavor(N, X, T, K);
    }
    return 0;
}