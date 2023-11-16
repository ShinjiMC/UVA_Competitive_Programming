#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <set>

int code()
{
    long T;
    std::cin >> T;
    std::cin.ignore();
    while (T--)
    {
        std::string name;
        std::getline(std::cin >> std::ws, name);
        std::transform(name.begin(), name.end(), name.begin(), ::toupper);
        long m, n, b;
        std::cin >> m >> n >> b;
        std::cin.ignore();
        std::string ingredient;
        long price;
        std::unordered_map<std::string, long> objects;
        while (m--)
        {
            std::cin >> ingredient >> price;
            objects[ingredient] = price;
        }
        std::string recipe, product;
        long cantIngredients, cant;
        std::set<std::pair<long, std::string>> recipes;
        std::cin.ignore();
        while (n--)
        {
            long priceT = 0;
            std::getline(std::cin >> std::ws, recipe);
            std::cin >> cantIngredients;
            std::cin.ignore();
            while (cantIngredients--)
            {
                std::cin >> product >> cant;
                auto it = objects.find(product);
                if (it != objects.end())
                {
                    priceT += (it->second) * cant;
                }
            }
            recipes.insert({priceT, recipe});
        }
        std::cout << name << std::endl;
        bool can = true;
        for (const auto &i : recipes)
        {
            if (b >= i.first)
            {
                std::cout << i.second << std::endl;
                can = false;
            }
        }
        if (can)
        {
            std::cout << "Too expensive!" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
