#include <iostream>
#include <conio.h>
using namespace std;
int f(int i)
{
	setlocale(LC_ALL, "ru");
	if (i = 0)
	{
		return 1;
	}
	else return i * f(i - 1);
}
int main()
{
	int i, n;
	cout << "Введите число";
	cin >> n;
	cout << f(n);
}