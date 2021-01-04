

#include <iostream>
using namespace std;
int main()

{
	setlocale(LC_ALL, "ru");
	int a, b;
	cout << "Введите число"<<endl;
	cin >> a;
	cout << "Введите степень числа" << endl;
	cin >> b;
	int c = pow(a, b);
	cout << c;
}

