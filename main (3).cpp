#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    //  Задача If38
    
    double x;    
    int r;      

    cout << " Задача If38 " << endl;
    cout << "Введіть значення x: ";
    cin >> x;

    if (x < -2)
        r = int(x * x - 4);
    else if (x <= 2)
        r = int(x);
    else
        r = 4;

    cout << "Значення функції r(x) = " << r << endl << endl;


    
    //  Задача (3 варіант) 
   
    double a, radius;
    cout << " Задача (3 варіант)" << endl;
    cout << "Введіть сторону трикутника a: ";
    cin >> a;

    // Формула для радіуса вписаного кола у прямокутний рівнобедрений трикутник
    radius = (a * (sqrt(2) - 1)) / 2;

    cout << "Радіус вписаного кола r = " << radius << endl;

    return 0;
}
