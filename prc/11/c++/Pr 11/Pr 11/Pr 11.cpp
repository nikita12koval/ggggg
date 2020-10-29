#include <iostream> 
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int a = 0, b = 0, square = 1;
	cout << " Введите число возводимое в степень: " << endl;
	cin >> a;
	cout << "Введите степень в которую нужно возвести число:" << endl;
	cin >> b;
	for (int i = 0; i < b; i++)
	{
		square *= a;
	}
	cout << "Square of " << a << " on power " << b << " is: " << square << endl;
	return 0;

}