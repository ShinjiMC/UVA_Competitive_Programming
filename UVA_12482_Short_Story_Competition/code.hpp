#include <iostream>
#include <algorithm>
#include <vector>

int code()
{
    long n, l, c;
    while (std::cin >> n >> l >> c)
    {
        std::vector<long> words(n);
        for (auto &i : words)
        {
            std::string word;
            std::cin >> word;
            i = word.size();
        }
        long size = words[0], line = 1;
        for (int i = 1; i < words.size(); i++)
        {
            size += words[i] + 1;
            if (size > c)
            {
                size = words[i];
                line++;
            }
            else if (size == c && i + 1 < words.size())
            {
                size = words[i + 1];
                i++;
                line++;
            }
        }
        long ans = line / l + (line % l != 0);
        std::cout << ans << std::endl;
    }
    return 0;
}