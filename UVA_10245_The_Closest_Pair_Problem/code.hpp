#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

double Euclidean(const std::pair<double, double> &p1, const std::pair<double, double> &p2)
{
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return std::sqrt(dx * dx + dy * dy); // Igual a std::hypot(dx, dy); solo q es mucho costo
}

double closestPairDistance(const std::vector<std::pair<double, double>> &points)
{
    double minDist = std::numeric_limits<double>::infinity(); // valor MAX posible

    for (auto i = points.begin(); i != points.end(); i++)
    {
        for (auto j = std::next(i); j != points.end(); j++) // itera a partir del valor next del i
        {
            minDist = std::min(minDist, Euclidean(*i, *j)); // compara min
        }
    }

    return minDist;
}

int code()
{
    int N;

    while (std::cin >> N && N != 0)
    {
        std::vector<std::pair<double, double>> points(N);

        for (auto &point : points)
        {
            std::cin >> point.first >> point.second;
        }

        double minDistance = closestPairDistance(points);

        if (minDistance < 10000)
        {
            std::cout << std::fixed;
            std::cout.precision(4); // Limitar a 4 decimales
            std::cout << minDistance << std::endl;
        }
        else
        {
            std::cout << "INFINITY" << std::endl;
        }
    }

    return 0;
}