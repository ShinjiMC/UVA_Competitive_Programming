#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira

void Rotar(std::vector<std::vector<char>> &Right){ //90 grados
    std::vector<std::vector<char>> R = Right;
    for (int i = 0; i < Right.size(); ++i) {
        for (int j = 0; j < Right.size(); ++j) {
            Right[j][(Right.size()-i)-1] = R[i][j];
        }
    }
}

void voltear(std::vector<std::vector<char>> &Right){ //espejo vertical
    std::vector<std::vector<char>> R = Right;
    for (int i = 0; i < R.size(); ++i) {
        Right[i] = R[(Right.size()-i)-1];
    }
}

int main(){
    int a, count=1;
    while (std::cin >> a) {
        std::string b;
        std::vector<std::vector<char>> Left (a,std::vector<char>(a)), Right(a,std::vector<char>(a));
        for(int i=0;i<a;i++){
            std::cin >> b;
            for(int j=0;j<a;j++) {
                Left[i][j] = b[j];
            }
            std::cin >> b;
            for(int j=0;j<a;j++) {
                Right[i][j] = b[j];
            }
        }
        int grades =0;
        bool volteado=0;
        while(grades != 360 || !volteado){
            bool sonIguales = std::equal(Left.begin(), Left.end(), Right.begin());
            if(sonIguales) break;
            if(grades == 360 && volteado !=1){
                volteado = 1, grades = 0;
                voltear(Left);
            }
            else{
                grades += 90;
                Rotar(Left);
            }
        }
        if (grades == 0) {
            if (volteado == 0) {
                std::cout << "Pattern " << count << " was preserved." << std::endl;
            } else if (volteado == 1) {
                std::cout << "Pattern " << count << " was reflected vertically." << std::endl;
            }
        } else if (grades == 360) {
            std::cout << "Pattern " << count << " was improperly transformed." << std::endl;
        } else {
            if (volteado == 1) {
                std::cout << "Pattern " << count << " was reflected vertically and rotated " << grades << " degrees." << std::endl;
            } else {
                std::cout << "Pattern " << count << " was rotated " << grades << " degrees." << std::endl;
            }
        }
        count++;
    }
    return 0;
}