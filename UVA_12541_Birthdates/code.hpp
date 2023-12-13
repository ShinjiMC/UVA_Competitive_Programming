#include <iostream>
#include <vector>
#include <limits>
using namespace std;
struct Person
{
    string name;
    int day;
    int month;
    int year;
};

int code()
{
    int n;
    cin >> n;
    Person viejo = {"", 0, 0, numeric_limits<int>::max()};
    Person joven = {"", 0, 0, 0};
    for (int i = 0; i < n; i++)
    {
        Person temp;
        cin >> temp.name >> temp.day >> temp.month >> temp.year;
        if (temp.year < viejo.year ||
            (temp.year == viejo.year && temp.month < viejo.month) ||
            (temp.year == viejo.year && temp.month == viejo.month && temp.day < viejo.day))
            viejo = temp;
        else if (temp.year > joven.year ||
                 (temp.year == joven.year && temp.month > joven.month) ||
                 (temp.year == joven.year && temp.month == joven.month && temp.day > joven.day))
            joven = temp;
    }
    cout << joven.name << "\n"
         << viejo.name << endl;
    return 0;
}