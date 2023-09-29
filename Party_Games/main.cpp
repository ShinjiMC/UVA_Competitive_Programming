#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira
using namespace std;

int main() {
    int a;
    while (cin >> a && a != 0) {
        vector<string> list(a);
        for (auto &c:list) {
            cin >> c;
        }
        sort(list.begin(), list.end());
        string s1 = list[a / 2 - 1], s2 = list[a / 2], res;
        int min = s1.length(), max = s2.length();
        for (int i = 0; i < min; ++i) {
            if (s1[i] == s2[i]) res += s1[i];
            else {
                if (i == min - 1) res += s1[i];
                else if (s2[i] - s1[i] > 1 || i != max - 1) res += s1[i] + 1;
                else {
                    res += s1[i];
                    for (int j = i + 1; j < min; ++j) {
                        if (j == min - 1) {
                            res += s1[j];
                            break;
                        }
                        if (s1[j] != 'Z') {
                            res += s1[j] + 1;
                            break;
                        }
                        res += 'Z';
                    }
                }
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
