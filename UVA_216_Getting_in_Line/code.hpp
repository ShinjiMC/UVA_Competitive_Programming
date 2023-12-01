#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <cmath>
#include <algorithm>

double distance(const std::pair<int, int> &p1, const std::pair<int, int> &p2)
{
    int dx = p2.first - p1.first;
    int dy = p2.second - p1.second;
    return std::sqrt(dx * dx + dy * dy);
}

double calculateTotalDistance(const std::vector<std::pair<int, int>> &points, const std::vector<int> &order)
{
    double totalDistance = 0.0;
    for (int i = 1; i < points.size(); i++)
        totalDistance += distance(points[order[i]], points[order[i - 1]]);
    return totalDistance;
}

int code()
{
    int n;
    int caseNum = 1;
    while (std::cin >> n && n != 0)
    {
        std::vector<std::pair<int, int>> points(n);
        std::vector<int> order(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> points[i].first >> points[i].second;
            order[i] = i;
        }
        double minDistance = INT_MAX;
        std::vector<int> bestOrder;
        do
        {
            double totalDistance = calculateTotalDistance(points, order);
            if (totalDistance < minDistance)
            {
                minDistance = totalDistance;
                bestOrder = order;
            }
        } while (std::next_permutation(order.begin(), order.end()));

        std::cout << "**********************************************************\n";
        std::cout << "Network #" << caseNum++ << "\n";
        for (int i = 1; i < n; i++)
        {
            double dist = distance(points[bestOrder[i - 1]], points[bestOrder[i]]) + 16.0;
            std::cout << "Cable requirement to connect (" << points[bestOrder[i - 1]].first << "," << points[bestOrder[i - 1]].second << ") to (" << points[bestOrder[i]].first << "," << points[bestOrder[i]].second << ") is " << std::fixed << std::setprecision(2) << dist << " feet.\n";
        }
        std::cout << "Number of feet of cable required is " << std::fixed << std::setprecision(2) << minDistance + 16.0 * (n - 1) << ".\n";
    }

    return 0;
}