#include <iostream>
#include <vector>
#include <algorithm>
//By Braulio Nayap Maldonado Casilla
int main() {
    std::vector<long> numbers;
    long num;
    while (std::cin >> num) {
        numbers.push_back(num);
        std::sort(numbers.begin(), numbers.end());
        int size = numbers.size();
        long median;
        if (size % 2 == 0) {
            median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2;
        }
        else {
            median = numbers[size / 2];
        }
        std::cout << median << std::endl;
    }

    return 0;
}