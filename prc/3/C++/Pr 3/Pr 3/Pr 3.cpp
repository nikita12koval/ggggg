#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");

    int a,b,selection;
    double A, B;

    cout << "Введите первое целое число : ";
    cin >> a;
    cout << "Введите второе целое число  : ";
    cin >> b;
    cout << "Выберите математическую операцию" << endl <<
        "1. Сложение" <<endl <<
        "2. Вычитание" << endl <<
        "3. Умножение" << endl <<
        "4. Деление" << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "Результат сложения " << a + b <<endl;
        break;
    case 2:
        cout << "Результат вычитания " << a - b<< endl;
        break;
    case 3:
        cout << "Результат уменожения " << a * b << endl;
        break;
    case 4:
        cout << "Результат деления " << (float)a / b << endl;
        
        break;

    default:
        cout << "Ошибка! Пункт меню отсутствует!" << endl;
        break;
    }
    
    cout << "Введите первое дробное число : ";
    cin >> A;
    cout << "Введите второе  дробное число : ";
    cin >> B;
    cout << "Выберите математическую операцию" << endl <<
        "1. Сложение" << endl <<
        "2. Вычитание" << endl <<
        "3. Умножение" << endl <<
        "4. Деление" << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "Результат сложения " <<A + B << endl;
        break;
    case 2:
        cout << "Результат вычитания " <<A - B << endl;
        break;
    case 3:
        cout << "Результат уменожения " <<A * B << endl;
        break;
    case 4:
        cout << "Результат деления " << (float)A / B << endl;

        break;

    default:
        cout << "Ошибка! Пункт меню отсутствует!" << endl;
        break;
    }

    cout << "Введите первое цулое число : ";
    cin >>a;
    cout << "Введите второе дробное число : ";
    cin >> B;
    cout << "Выберите математическую операцию" << endl <<
        "1. Сложение" << endl <<
        "2. Вычитание" << endl <<
        "3. Умножение" << endl <<
        "4. Деление" << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "Результат сложения " << a + B << endl;
        break;
    case 2:
        cout << "Результат вычитания " << a - B << endl;
        break;
    case 3:
        cout << "Результат уменожения " << a * B << endl;
        break;
    case 4:
        cout << "Результат деления " << (float)a / B << endl;

        break;

    default:
        cout << "Ошибка! Пункт меню отсутствует!" << endl;
        break;
    }


    cout << "Введите первое дробное число : ";
    cin >>A;
    cout << "Введите второе челое число : ";
    cin >> b;
    cout << "Выберите математическую операцию" << endl <<
        "1. Сложение" << endl <<
        "2. Вычитание" << endl <<
        "3. Умножение" << endl <<
        "4. Деление" << endl;
    cin >> selection;

    switch (selection)
    {
    case 1:
        cout << "Результат сложения " << A + b << endl;
        break;
    case 2:
        cout << "Результат вычитания " << A - b << endl;
        break;
    case 3:
        cout << "Результат уменожения " << A * b << endl;
        break;
    case 4:
        cout << "Результат деления " << (float)A / b << endl;

        break;

    default:
        cout << "Ошибка! Пункт меню отсутствует!" << endl;
        break;
    }


}