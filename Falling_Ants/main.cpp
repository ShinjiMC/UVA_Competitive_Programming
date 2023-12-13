#include <iostream>
// By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira
//  Refactor
int main()
{
    int total_hormigas;
    while (std::cin >> total_hormigas)
    {
        if (total_hormigas == 0)
        {
            break;
        }
        int longitud, anchura, altura, volumen, max_altura = 0, max_volumen = 0;
        for (int i = 0; i < total_hormigas; ++i)
        {
            std::cin >> longitud >> anchura >> altura;
            volumen = longitud * anchura * altura;
            if (altura > max_altura || (altura == max_altura && volumen > max_volumen))
            {
                max_altura = altura;
                max_volumen = volumen;
            }
        }
        std::cout << max_volumen << std::endl;
    }

    return 0;
}