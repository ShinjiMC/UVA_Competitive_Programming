#include <iostream>
#include <vector>

int code()
{
    int n = 0;
    std::vector<int> arr(1005);
    while (std::cin >> n && n != 0)
    {
        while (std::cin >> arr[1] && arr[1] != 0)
        {
            for (int i = 2; i <= n; i++)
                std::cin >> arr[i];
            std::vector<int> s;
            int cont = 1;
            for (int i = 1; i <= n; i++)
            {
                s.push_back(i);
                while (!s.empty() && s.back() == arr[cont])
                {
                    s.pop_back();
                    cont++;
                }
            }
            if (s.empty() && cont == n + 1)
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
        std::cout << "\n";
    }
    return 0;
}