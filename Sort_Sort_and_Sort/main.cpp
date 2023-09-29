#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira
using namespace std;
bool comparar(int a, int b, int m) {
    int modA = a % m;
    int modB = b % m;
    if (modA != modB) return modA < modB;
    else if ((abs(a) % 2) != (abs(b) % 2)) return (abs(a) % 2) > (abs(b) % 2); 
    else if (a % 2 != 0 && b %2!=0) return a > b;
    else if (a%2==0&&b%2==0) {return b > a;}
}

int main() {
    int N, M;
    while (cin >> N >> M && !(N == 0 && M == 0)) {
        vector<int> lista(N);
        for (auto &c:lista) {
            cin >> c;
        }
        cout << N << " " << M << endl;
        sort(lista.begin(), lista.end(), [M](int a, int b) { return comparar(a, b, M); });
        for (auto c:lista) {
            cout << c << endl;
        }
    }
    cout << "0 0" << endl;
    return 0;
}