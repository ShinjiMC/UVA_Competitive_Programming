#include <iostream>
#include <algorithm>
#include <vector>

struct Point
{
    int left, right;
};

bool cmp(const Point &a, const Point &b)
{
    return a.left < b.left;
}

int code()
{
    int N = 0;
    std::cin >> N;
    while (N--)
    {
        std::vector<Point> points(100000);
        int M = 0, cont = 0, a, b;
        std::cin >> M;
        while (std::cin >> a >> b)
        {
            if (!a && !b)
                break;
            points[cont].left = a;
            points[cont].right = b;
            cont++;
        }
        std::sort(points.begin(), points.begin() + cont, cmp);
        std::vector<int> indPoints(cont);
        int actu = 0, count = 0, sig = 0, ansCount = 0;
        bool trazo = false;
        while (count < cont)
        {
            int next = actu; // Siguiente valor de cobertura
            int i = count;   // Índice de inicio del bucle for
            for (; i < cont && points[i].left <= actu; i++)
            {
                if (points[i].right > next)
                {
                    next = points[i].right; // Actualiza el próximo valor de cobertura
                    sig = i;                // Índice del siguiente intervalo
                }
            }
            if (i == count)
                break;                   // Sale del bucle si no hay más intervalos para revisar
            actu = next;                 // Actualiza el valor de cobertura actual
            count = i;                   // Actualiza el índice de inicio para el próximo bucle
            indPoints[ansCount++] = sig; // Guarda el índice del intervalo seleccionado
            if (M <= actu)
            {
                trazo = true; // Activa la bandera si la cobertura alcanza o supera el límite
                break;        // Sale del bucle si se alcanza el límite
            }
        }

        if (trazo)
        {
            std::cout << ansCount << std::endl;
            for (int j = 0; j < ansCount; ++j)
            {
                std::cout << points[indPoints[j]].left << " " << points[indPoints[j]].right << std::endl;
            }
        }
        else
        {
            std::cout << "0" << std::endl;
        }
        if (N > 0)
            std::cout << std::endl;
    }
    return 0;
}
