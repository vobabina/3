#include <iostream>
#include <cmath>
using namespace std;

// If38. Для заданого дійсного x знайти значення функції r(x), що приймає значення цілого типу:
// r(x) = x^2 - 4, якщо x < -2;
// r(x) = x, якщо -2 ≤ x ≤ 2;
// r(x) = 4, якщо x > 2.
void task_if38();  // завдання 1 декларація функції

// Варіант 3. Дано координати точки (x, y).
// Визначити, чи потрапляє точка у жовтий трикутник з кутом 45°,
// розташований у першій чверті.
void task_geom3(); // завдання 2 декларація функції

int main() {
    int menu;
    cout << "Task number (1 - If38, 2 - Geometry): ";
    cin >> menu;

    // перемикання між завданнями
    switch (menu)
    {
    case 1:
        task_if38(); // Завдання 1
        break;
    case 2:
        task_geom3(); // Завдання 2
        break;
    default:
        cout << "Wrong task! (Only 1 or 2)" << endl; // повідомлення про помилку
    }

    system("pause");
    return 0;
}

// Завдання 1  (If38)
void task_if38()
{
    cout << "************* If38 *****************" << endl;

    double x;  // дійсне число
    int r;     // результат цілого типу

    cout << "Введіть x: ";
    cin >> x;

    if (!cin) { // перевірка правильності введення
        cout << "Wrong input! Введіть число." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // обчислення за умовами
    if (x < -2)
        r = x * x - 4;
    else if (x <= 2)
        r = x;
    else
        r = 4;

    cout << "Результат: r = " << r << endl;
}

//  Завдання 2  ( варіант 3) 
void task_geom3()
{
    cout << "************* Geometry (var.3) *****************" << endl;

    double a; // сторона трикутника
    double x, y; // координати точки

    cout << "Введіть сторону трикутника a (>0): ";
    cin >> a;

    // перевірка на коректність
    if (cin.fail() || a <= 0)
    {
        cerr << "Некоректні дані для a!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    cout << "Введіть координати точки (x, y): ";
    cin >> x >> y;

    if (!cin)
    {
        cout << "Некоректні координати!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }

    // Умови потрапляння у жовтий трикутник 
    bool inside = (x >= 0 && y >= 0 && y <= a - x);

    if (inside) {
        cout << "Точка потрапляє у жовту фігуру (трикутник)." << endl;
    } else {
        cout << "Точка не потрапляє у фігуру." << endl;
    }

    return;
}
