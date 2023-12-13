#include <iostream>
int code()
{
    int N, R, C, K, valor;
    int movimientos[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    while (true)
    {
        std::cin >> N >> R >> C >> K;
        if (N == 0)
            break;
        int tablero[R][C];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                std::cin >> valor;
                tablero[i][j] = valor;
            }
        }
        while (K--)
        {
            int temp[R][C];
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    temp[i][j] = tablero[i][j];

            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    for (int m = 0; m < 4; m++)
                    {
                        int y = i + movimientos[m][0];
                        int x = j + movimientos[m][1];
                        if (y >= 0 && y < R && x >= 0 && x < C)
                        {
                            if ((tablero[i][j] + 1) % N == tablero[y][x])
                                temp[y][x] = tablero[i][j];
                        }
                    }
            for (int i = 0; i < R; i++)
                for (int j = 0; j < C; j++)
                    tablero[i][j] = temp[i][j];
        }
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                std::cout << tablero[i][j];
                if (j < C - 1)
                {
                    std::cout << " ";
                }
            }
            std::cout << std::endl;
        }
    }
    return 0;
}