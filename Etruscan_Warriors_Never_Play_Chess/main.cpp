#include <iostream>
#include <cmath>
//By Braulio Maldonado Casilla

int main(){
    int a;
    std::cin >> a;
    while (a--) {
        long int g;
        std::cin >> g;
        long int result = (std::sqrt(g*8+1)-1)/2;
        std::cout << result << std::endl;
    }
    return 0;
}