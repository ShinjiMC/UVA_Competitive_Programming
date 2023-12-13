#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira
//  Refactor
int areEqual(vector<string> names, int pos)
{

    char j = names[0][pos];

    for (auto i : names)
    {
        if (pos < i.size())
        {
            if (j != i[pos])
            {
                return 0;
            }
        }
        else
        {

            return 2;
        }
    }
    return 1;
}

char findSecondMinor(vector<string> names, int pos)
{
    int rpos = (names.size() - 1) / 2;
    return (names[rpos + 1][pos] == names[rpos][pos] + 1) ? names[rpos][pos] : names[rpos][pos] + 1;
}

int main()
{
    int n = -1;
    while (cin >> n && n > 0)
    {
        vector<string> names(n);
        for (int i = 0; i < n; i++)
            cin >> names[i];
        sort(names.begin(), names.end());
        int i = 0;
        string result;
        int equality;
        while ((equality = areEqual(names, i)) == 1)
        {
            result += names[0][i];
            i++;
        }
        if (equality == 0)
        {
            result += findSecondMinor(names, i);
        }
        else if (equality == 2)
            result += findSecondMinor(names, i - 1);
        cout << result << endl;
    }
}