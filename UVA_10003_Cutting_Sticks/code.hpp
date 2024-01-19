#include <iostream>
#include <vector>
#include <algorithm>

int code()
{
    int l;
    while (std::cin >> l && l != 0)
    {
        int n;
        std::cin >> n;
        std::vector<int> cuts(n + 2);
        for (int i = 1; i <= n; ++i)
            std::cin >> cuts[i];
        cuts[n + 1] = l;
        std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));
        for (int i = 2; i <= n + 1; ++i)
            for (int j = i - 2; j >= 0; --j)
            {
                dp[j][i] = 1 << 30;
                for (int k = j + 1; k < i; ++k)
                    dp[j][i] = std::min(dp[j][i], dp[j][k] + dp[k][i] + cuts[i] - cuts[j]);
            }
        std::cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }
    return 0;
}