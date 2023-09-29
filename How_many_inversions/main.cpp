#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla - Sebastián Agenor Zamalloa Molina - Luciana Julissa Huaman Coaquira

void merge(std::vector<int>& array, long long& res, int low, int mid, int high) {
    int n1 = low, n2 = mid + 1, n3 = 0, n4 = 0;
    std::vector<int> list(high - low + 1);
    while (n1 <= mid && n2 <= high) {
        if (array[n1] <= array[n2]) {
            list[n3++] = array[n1++];
            res += n4;
        } else {
            list[n3++] = array[n2++];
            n4++;
        }
    }

    while (n1 <= mid) {
        list[n3++] = array[n1++];
        res += n4;
    }

    while (n2 <= high) {
        list[n3++] = array[n2++];
    }

    for (int i = 0; i < n3; i++) {
        array[low + i] = list[i];
    }
}

void mergeSort(std::vector<int>& array,long long& res, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(array, res, low, mid);
        mergeSort(array, res, mid + 1, high);
        merge(array,res, low, mid, high);
    }
}

int main(){
    int a;
    while(std::cin >> a && a!=0){
        std::vector<int> list(a);
        long long res=0;
        for(int i = 0; i < a; ++i){
            std::cin>>list[i];
        }
        mergeSort(list,res,0,a-1);
        std::cout << res << std::endl;
    }
    return 0;
}