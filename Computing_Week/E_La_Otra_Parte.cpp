#include <iostream>
#include <cmath>
#include <vector>

int main()
{
    int x, y, z, n;
    while (std::cin >> x >> y >> z >> n)
    {
        int total = x * y, sfalta = x - z, hfalta = sfalta * y, min = std::ceil(total * 0.6), meta = min - n;
        if ((hfalta + n) < min)
        {
            std::cout << "No" << std::endl;
            continue;
        }
        else
            std::cout << "Yes" << std::endl;
        int c = 0;
        std::vector<int> l(sfalta);
        while (meta > 0)
        {
            if (meta - y >= 0)
            {
                l[c] = y;
                c++;
                meta -= y;
            }
            else
            {
                l[c] = meta;
                meta = 0;
            }
        }
        for (int i = l.size() - 1; i >= 0; i--)
        {
            std::cout << l[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}