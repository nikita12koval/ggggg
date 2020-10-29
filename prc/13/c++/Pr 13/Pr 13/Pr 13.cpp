#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int a, b, c, d, e, n, i;
	c = 0;
	cin >> n;
	for (i = 1; i <= n; i++) {
		if (n % i == 0) {
			c = c + 1;
			cout << n % i << endl;
		}

	}
	cout << c;
	if (c != 2)
	{
		cout << "Число комплексное" << endl << c << endl;
	}


	else
	{
		cout << "Число простое" << endl;
	}
}
