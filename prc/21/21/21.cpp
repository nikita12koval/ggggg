

#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");

    double a, b;
    cout << "введите массу человека";
    cin >> a;
    cout << "введите рост человека";
    cin >> b;
    double r = pow(b, 2);
    double c=a/r;
    double t = a / r;
    double x= a / r;
    double v= a / r;

    if (c < 18)
    {
        cout << "недостаточная масса" << " " << c;
    }
    else(t < 25 && t < !18);
    {
        cout << "нормальная масса" << " " << t;
    }

    if (x = 25 && x < 30)
    {
        cout << "избыточная масса" << " " << x;

    }
    else (v >= 30);
    {
        cout << "ожирение" << " " << v;
    }

}

