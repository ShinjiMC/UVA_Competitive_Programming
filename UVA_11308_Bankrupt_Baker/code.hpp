#include <iostream>
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
        for (char &c : name)
        {
            c = std::toupper(c);
        }
        long m, n, b;
        std::cin >> m >> n >> b;
        std::cin.ignore();
        std::unordered_map<std::string, long> objects;
        while (m--)
        {
            std::string ingredient;
            long price;
            std::cin >> ingredient >> price;
            objects[ingredient] = price;
        }
        std::set<std::pair<long, std::string>> recipes;
        while (n--)
        {
            long priceT = 0;
            std::string recipe;
            std::getline(std::cin >> std::ws, recipe);
            long cantIngredients;
            std::cin >> cantIngredients;
            std::cin.ignore();
            while (cantIngredients--)
            {
                std::string product;
                long cant;
                std::cin >> product >> cant;
                auto it = objects.find(product);
                if (it != objects.end())
                {
                    priceT += (it->second) * cant;
                }
            }
            recipes.insert({priceT, recipe});
        }
        std::cout << name << "\n";
        bool can = true;
        for (const auto &i : recipes)
        {
            if (b >= i.first)
            {
                std::cout << i.second << "\n";
                can = false;
            }
        }
        if (can)
        {
            std::cout << "Too expensive!\n";
        }
        std::cout << "\n";
    }
    return 0;
}
