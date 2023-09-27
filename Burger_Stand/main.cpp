#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira

int main(){
    int a;
    std::cin >> a;
    int cases=1;
    while (a--) {
        std::string b;
        std::cin >> b;
        int size = b.size();
        std::vector <bool> stats (size, true);
        int n=0;
        for (char c : b){
            if(c!='-'){
                stats[n]=false;
            }
            if(c == 'B'){
                if(n-2>=0){
                    stats[n-2]=false;
                }
                if(n-1>=0){
                    stats[n-1]=false;
                }
            }
            if(c == 'S'){
                if(size>n+1){
                    stats[n+1]=false;
                }
                if(n-1>=0){
                    stats[n-1]=false;
                }
            }
            n++;
        }
        //'-'vacio - enfrente 'D' Entrada Buses - enfrente a 5 metros antes y 10 metros antes de una parada 'B'stop bus - enfrente y a 5 metros aft and befores 'S' calle lateral
        int res=std::count(stats.begin(), stats.end(), true);
        std::cout << "Case "<<cases<<": "<<res<<std::endl;
        cases++;
    }
    return 0;
}