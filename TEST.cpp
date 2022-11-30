#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> listPts;
    int a = 16;
    int b = 18;
    int c = 17;

    if (a == b || a == c || b == c)
    {
        if (a == b)
        {
            if (a > c)
            {
                cout << "a y b ha ganado";
            }
            else
            {
                cout << "C ha ganado";
            }
        }
        else if (a == c)
        {
            if (a > b)
            {
                cout << "a y c ha ganado";
            }
            else
            {
                cout << "b ha ganado";
            }
        }
        else if (b == c)
        {
            if (b > a)
            {
                cout << "b y c ha ganado";
            }
            else
            {
                cout << "a ha ganado";
            }
        }
    }
    else
    {

        cout << "Se ordena acendentemente y el ultimo es el ganador";
    }
}

// if (a > b)
//     {
//         if (a > c)
//         {
//             cout << "A es el mayor";
//         }
//         else
//         {
//             cout << "C es el mayor";
//         }
//     }
//                 else
//                 {
//                     if (b > c)
//                     {
//                         cout << "B es el mayor";
//                     }
//                     else
//                     {
//                         cout << "C es el mayor";
//                     }
//                 }
//             }
//         }
//     }