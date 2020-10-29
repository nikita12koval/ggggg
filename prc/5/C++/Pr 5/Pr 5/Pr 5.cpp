#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int t, v, x;
	double a = 9.8;
	cout << "Введите значение t" << (char)32 << "Введите значение v" << (char)32 << "Введите значение x ";
	cin >> t;
	cin >> v;
	cin >> x;
	int c = x + v * t - a * t * t / 2;
	cout << c << endl;