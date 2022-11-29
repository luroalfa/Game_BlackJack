#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> listPts;
    int a = 2;
    int b = 21;
    int c = 20;

    if (a > b)
    {
        if (a > c)
        {
            cout << "A es el mayor";
        }
        else
        {
            cout << "C es el mayor";
        }
    }
    else
    {
        if (b > c)
        {
            cout << "B es el mayor";
        }
        else
        {
            cout << "C es el mayor";
        }
    }
}