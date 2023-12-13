#include <iostream>
#include <vector>
#include <set>
using namespace std;

int code()
{
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++)
    {
        int M, N;
        cin >> M >> N;
        cin.ignore();
        vector<string> vec1(M), vec2(N);
        for (auto &c : vec1)
        {
            getline(cin, c);
        }
        for (auto &c : vec2)
        {
            getline(cin, c);
        }
        set<string> lista;
        for (const auto &x : vec1)
        {
            for (const auto &y : vec2)
            {
                lista.insert(x + y);
            }
        }
        cout << "Case " << i << ": " << lista.size() << endl;
    }
    return 0;
}