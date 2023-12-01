#include <iostream>
#include <vector>
#include <algorithm>
// By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira

void merge(std::vector<int> &array, long long &res, int low, int mid, int high)
{
    int n1 = low, n2 = mid + 1, n3 = 0, n4 = 0;
    // Se crea un vector temporal para almacenar la fusión ordenada de los subarrays
    // Se realiza la mezcla ordenada de los subarrays
    std::vector<int> list(high - low + 1);
    while (n1 <= mid && n2 <= high)
    {
        if (array[n1] <= array[n2]) // Si n1 es menor igual a n2 se ingresa a lista
        {
            list[n3++] = array[n1++];
            res += n4; // Se actualiza el número de inversiones porque no hay inversiones
        }
        else // n2 es es el mayor y lo ingresa a lista, por lo que encontro una inversion
        {
            list[n3++] = array[n2++];
            n4++;
        }
    }

    while (n1 <= mid)
    {
        list[n3++] = array[n1++]; // ingresan valores restantes de la primera mitd
        res += n4;                // Se actualiza el número de inversiones
    }

    while (n2 <= high)
    {
        list[n3++] = array[n2++]; // ingresan valores restantes de la primera mitd
    }

    for (int i = 0; i < n3; i++)
    {
        array[low + i] = list[i]; // Se copia el contenido del vector temporal al original
    }
}

void mergeSort(std::vector<int> &array, long long &res, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;     // hallar mitad
        mergeSort(array, res, low, mid);      // Llamada recursiva para la mitad izquierda del array
        mergeSort(array, res, mid + 1, high); // Llamada recursiva para la mitad derecha del array
        merge(array, res, low, mid, high);    // Une y ordena las mitades del array
    }
}

int code()
{
    int a;
    while (std::cin >> a && a != 0)
    {
        std::vector<int> list(a);
        long long res = 0;
        for (int i = 0; i < a; ++i)
        {
            std::cin >> list[i];
        }
        mergeSort(list, res, 0, a - 1);
        std::cout << res << std::endl;
    }
    return 0;
}