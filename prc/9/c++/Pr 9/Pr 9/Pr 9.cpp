#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int h, m;
	int H, M;



	cout << "Введите часы и минуты прихода первого человека";
	cin >> h >> m;
	cout << "Введите часы и минуты прихода второго человека";
	cin >> H >> M;



	if (0 <= h, H <= 23)
	{

	}
	else
	{
		cout << "Введенное число часов не подходит" << endl;
	}
	if (0 <= m, M <= 59)
	{

	}
	else
	{
		cout << "Введенное число минут не подходит" << endl;
	}


	int a = h;
	int A = H;
	int b = m;
	int B = M;
	int c = b + 15;

	if (a = A, c <= B)
	{
		cout << "Встречка состоится" << endl;
	}
	else
	{
		cout << "Встреча не состоится" << endl;
	}





}



