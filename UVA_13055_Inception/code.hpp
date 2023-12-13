#include <iostream>
#include <stack>

int code()
{
    int n = 0;
    std::stack<std::string> dreams;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::string command;
        std::cin >> command;
        if (command == "Sleep")
        {
            std::string name;
            std::cin >> name;
            dreams.push(name);
        }
        else if (command == "Kick")
        {
            if (!dreams.empty())
                dreams.pop();
        }
        else
        {
            if (dreams.empty())
                std::cout << "Not in a dream\n";
            else
                std::cout << dreams.top() << "\n";
        }
    }
    return 0;
}