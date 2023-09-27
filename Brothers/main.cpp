#include <iostream>

int main() {
    int N; // Número de herederos
    int R; // Dimensión A del reino
    int C; // Dimensión B del reino
    int K; // Número de batallas
    int valor;
    
    int movimientos[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; // Movimientos arriba, izquierda, derecha, abajo.

    while (true) {
        std::cin >> N >> R >> C >> K;

        if (N == 0) {
            break;
        }

        int tablero[R][C];

        // Leer valores y llenar el tablero
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                std::cin >> valor;
                tablero[i][j] = valor;
            }
        }

        while (K--) // Realizar las batallas
        {
            int temp[R][C]; // Matriz temporal para almacenar el estado después de cada batalla.
            
            // Copiar el estado actual al temporal
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    temp[i][j] = tablero[i][j];
                }
            }

            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    for (int m = 0; m < 4; m++) // Explorar los movimientos en las cuatro direcciones.
                    {
                        int y = i + movimientos[m][0];
                        int x = j + movimientos[m][1];

                        if (y >= 0 && y < R && x >= 0 && x < C) {
                            // Verificar si el ataque ocurre según las reglas del problema
                            if ((tablero[i][j] + 1) % N == tablero[y][x]) {
                                temp[y][x] = tablero[i][j]; // Actualizar el estado temporal
                            }
                        }
                    }
                }
            }

            // Copiar el estado temporal de vuelta al tablero original
            for (int i = 0; i < R; i++) {
                for (int j = 0; j < C; j++) {
                    tablero[i][j] = temp[i][j];
                }
            }
        }
        
        // Imprimir el tablero resultante
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                std::cout << tablero[i][j];
                if (j < C - 1) {
                    std::cout << " ";
                }
            }
            std::cout << std::endl; // Añadir una nueva línea después de cada fila
        }
    }

    return 0;
}