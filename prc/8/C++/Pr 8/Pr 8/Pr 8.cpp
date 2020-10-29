#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b, selection;

	cout << "Введите значение a";
	cin >> a;
	cout << "Введите значение b";
	cin >> b;
	cout << "Укажите математическую операцию" << endl
		<< "1 сочетание" << endl
		<< "2 вычитание" << endl
		<< "3 умножение" << endl
		<< "4 деление" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		cout << "Результат сложения" << a + b << endl;
		break;
	case 2:
		cout << "Результат вычитания" << a - b << endl;
		break;
	case 3:
		cout << "Результат умножения" << a * b << endl;
		break;
	case 4:
		cout << "Результат деления" << a / b << endl;
		break;
	default:
		cout << "Ошибка!Пункт меню отсутствует" << endl;
		break;
	}
