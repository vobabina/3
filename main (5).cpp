#include <iostream>
#include <cmath>
using namespace std;

// If38. Дано дійсне число x.
// Знайти r(x): 
// r = x^2 - 4, якщо x < -2;
// r = x, якщо -2 ≤ x ≤ 2;
// r = 4, якщо x > 2.
void task_if38(); // завдання 1 декларація функції

// Варіант 3. Дано координати точки (x, y).
// Визначити, чи потрапляє точка у жовту фігуру — 
// трикутник або жовту частину кола (але не в червоне коло).
void task_geom3(); // завдання 2 декларація функції


int main() {
    int menu;
    cout << "Task number (1 - If38, 2 - Geometry): ";
    cin >> menu;

    // перемикання між завданнями
    switch (menu)
    {
    case 1: 
        task_if38(); 
        break; // Завдання 1
    case 2: 
        task_geom3(); 
        break; // Завдання 2
    default: 
        cout << "Wrong task! (Only 1, 2)" << endl; // повідомлення про помилку
    }

    system("pause");
    return 0;
}

//  Завдання 1 
void task_if38()
{
    cout << "************* If38 *****************" << endl;

    double x;
    int r;

    cout << "Введіть дійсне число x: ";
    cin >> x;

    if (cin.fail()) { // перевірка на коректність введення
        cout << "Wrong input! Введіть число." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    if (x < -2)
        r = x * x - 4;
    else if (x <= 2)
        r = x;
    else
        r = 4;

    cout << "Результат: r = " << r << endl;
}

//  Завдання 2 
void task_geom3()
{
    cout << "************* Geometry (Variant 3) *****************" << endl;

    double a, R; // сторона трикутника і радіус кола
    double x, y; // координати точки

    cout << "Введіть сторону трикутника a (>0): ";
    cin >> a;
    cout << "Введіть радіус кола R (>0): ";
    cin >> R;

    if (cin.fail() || a <= 0 || R <= 0)
    {
        cerr << "Некоректні дані для a або R!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cout << "Введіть координати точки (x, y): ";
    cin >> x >> y;

    if (cin.fail())
    {
        cout << "Некоректні координати!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // Обчислення відстані до центра кола (a, 0)
    double circleEq = pow(x - a, 2) + pow(y, 2);

    // Перевірка потрапляння у трикутник (кут 45°, у І чверті)
    bool inTriangle = (x >= 0 && y >= 0 && y <= a - x);

    // Перевірка потрапляння у частину кола зліва (жовта частина)
    bool inYellowArc = (x < a && circleEq <= R * R);

    // Перевірка, чи точка в червоному колі
    bool inRedCircle = (circleEq < R * R && x >= a);

    // Загальна умова: у жовтій фігурі, якщо точка або в трикутнику,
    // або у лівій частині кола, але не в червоному колі.
    bool inFigure = ((inTriangle || inYellowArc) && !inRedCircle);

    if (inFigure)
        cout << "Точка належить ЖОВТІЙ фігурі." << endl;
    else
        cout << "Точка НЕ належить жовтій фігурі." << endl;

    return;
}
