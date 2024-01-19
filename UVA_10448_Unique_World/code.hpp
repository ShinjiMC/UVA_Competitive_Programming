#include <iostream>
#include <vector>
#include <functional>
#include <climits>
const int limit_MAX = 2097152;

bool DFS(int actual, std::vector<bool> &visitado, std::vector<std::pair<int, int>> grafo[], std::vector<int> &costos, int &restante, int destino)
{
    if (actual == destino)
        return true;
    if (visitado[actual])
        return false;
    visitado[actual] = true;
    for (auto &vecino : grafo[actual])
    {
        if (DFS(vecino.first, visitado, grafo, costos, restante, destino))
        {
            costos.push_back(vecino.second);
            restante -= vecino.second;
            return true;
        }
    }
    return false;
}

int find(int n, int origen, int destino, int restante, std::vector<std::pair<int, int>> grafo[])
{
    std::vector<bool> visitado(n, false);
    std::vector<int> costos;
    if (!DFS(origen, visitado, grafo, costos, restante, destino) || restante < 0 || restante % 2 == 1)
        return limit_MAX;
    if (restante == 0)
        return costos.size();
    costos.erase(costos.begin());
    if (costos.empty())
        return limit_MAX;
    restante /= 2;
    std::vector<std::vector<int>> dp(costos.size(), std::vector<int>(restante + 1, 0));
    for (int i = 0; i < costos.size(); i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= restante; j++)
        {
            dp[i][j] = limit_MAX;
            if (j - costos[i] >= 0)
                dp[i][j] = std::min(dp[i][j], dp[i][j - costos[i]] + 1);
            if (i > 0)
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
        }
    }
    return (dp[costos.size() - 1][restante] == limit_MAX) ? limit_MAX : dp[costos.size() - 1][restante] * 2 + costos.size() + 1;
}

int code()
{
    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++)
    {
        if (i != 0)
            std::cout << "\n";
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> grafo[n];
        for (int i = 0; i < m; i++)
        {
            int origen, destino, costo;
            std::cin >> origen >> destino >> costo;
            origen--;
            destino--;
            grafo[origen].push_back({destino, costo});
            grafo[destino].push_back({origen, costo});
        }
        int consultas;
        std::cin >> consultas;
        for (int i = 0; i < consultas; i++)
        {
            int origen, destino, costo;
            std::cin >> origen >> destino >> costo;
            origen--;
            destino--;
            int resultado = find(n, origen, destino, costo, grafo);
            std::cout << ((resultado == limit_MAX) ? "No" : "Yes " + std::to_string(resultado)) << "\n";
        }
    }
    return 0;
}