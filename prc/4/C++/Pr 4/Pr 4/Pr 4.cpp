#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b;

	std::cout << "Введите два значения: ";

	if (std::cin >> a >> b)
	{
		std::cout << "Исходное значение: a = " << a << ", b = " << b << std::endl;
		int tmp = a;
		a = b;
		b = tmp;
		std::cout << "После замены: a = " << a << ", b = " << b << std::endl;
	}
	else
	{
		std::cout << "Произошла непредвиденная ошибка" << std::endl;
	}
}
