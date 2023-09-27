#include <iostream>
using namespace std;
//By Braulio Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira


int main() 
{
    string input;
    while (cin >> input) {
        int size = input.size();
        int a = 0;
        int maxC = 0;
        int foundX = 0;

        for (int i = 0; i < size; i++) 
        {
            if (input[i] == 'X') 
            {
                if(foundX){
                    if((a+1)/2-1 >= maxC)
                        maxC = (a+1)/2-1;
                    a = 0;
                }
                else{
                    foundX = true;
                    if(a-1 >= maxC)
                        maxC = a-1;
                    a = 0;
                }
            }
            else
                a++;
        }
        if(a-1>=maxC)
            maxC = a-1;
        if(!foundX)
            maxC = 0;
        cout<<maxC<<endl;
    }
}