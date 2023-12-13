#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int code()
{
    int a;
    while (cin >> a && a != 0)
    {
        vector<string> list(a);
        for (auto &c : list)
        {
            cin >> c;
        }
        sort(list.begin(), list.end());
        // Obtiene dos strings s1 y s2 que se encuentran en la mitad del vector ordenado
        string s1 = list[a / 2 - 1], s2 = list[a / 2], res;
        // Obtiene las longitudes mínima y máxima de s1 y s2
        int min = s1.length(), max = s2.length();
        for (int i = 0; i < min; ++i)
        {
            if (s1[i] == s2[i]) // Si el caracter en la posición 'i' es igual en ambas cadenas, lo agrega al resultado 'res'
                res += s1[i];
            else
            {
                if (i == min - 1) // Si es la ultima letra de s1
                    res += s1[i];
                else if (s2[i] - s1[i] > 1 || i != max - 1) // Hay distancia mayor a 1 entre las dos cadenas o si no es el ultimo valor de s2
                    res += s1[i] + 1;
                else // Si tienen una distancia de 1
                {
                    res += s1[i];
                    for (int j = i + 1; j < min; ++j)
                    {
                        if (j == min - 1) // Ultimo valor de cadena s1
                        {
                            res += s1[j];
                            break;
                        }
                        if (s1[j] != 'Z') // Si es diferente al Z
                        {
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
