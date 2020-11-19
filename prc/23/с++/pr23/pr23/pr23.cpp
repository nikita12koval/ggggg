#include <iostream>
#include <fact.h>
#include <taylor.h>
#include <c.h>
int a, b, d, f;
long nt;
double x, s;
using namespace std;

long fact(long nt)
{
    if (nt < 1)
        return 1;

    else return fact(nt -= 1) * f;
}
double taylor(double x, double s, int i) {
    s = 0.0;
    i = 1;
    do
    {
        s += a;
        a *= -1 * x * x / ((2 * i) * (2 * i + 1));
        i++;
    } while ((a > 0.0 ? a : a) > 1E-10);
    cout << s; return s;

}
int c(int b, int k)
{
    cin >> b;
    cin >> d;
    if ((b == 0) || (b == d))
 {
        cout << 1;
  }
    else
    {

        return c(b, d - 1) + c(b - 1, d - 1);
    }
}

int main()
{
    cin >> a;
    cin >> s;
    cin >> f;
    cout << fact(a) << endl;
    cout << taylor(s) << endl;
    cout << c(f) << endl;
}