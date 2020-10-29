#include <iostream>
#include <windows.h>
#include<time.h>
using namespace std;
void main()

{
	setlocale(LC_ALL, "ru");
	{
		srand(unsigned(time(NULL)));
		int r, b, i, a;
		char c;
		r = rand() % 100 + 1;
		cout << "Пожалуйста, введите свой номер.\n";
		for (i = 1; i < 19; i++)
		{
			cin >> b;
			if (b == r)
			{
				cout << "Вы победили\n";
				break;
			}
			if (b > r)
			{
				cout << "Ваше число больше \n";
			}
			if (b < r)
			{
				cout << "Ваше число меньше\n";
			}
		}
		if (i == 4)
		{
			cout << "ВЫ проиграли \n";

		}
	}
