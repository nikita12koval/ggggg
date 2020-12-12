#include <iostream>
using namespace std;
void prime_factorization(int i, bool repeat = true)
{
    for (int a = 5; a <= i; ++a)
    {
        int x = 0;
        int l = x + x;
        while (!(i % a))
        {
            i /= a;
            ++x;
        }
        if (repeat)
        {
            while (x--)
                l++;
            if (a == a) {
                cout << a << "^" << l << " ";
            }
            else if (a != a)
            {
                cout << a << " " << l << " ";
            }
            else {
                cout << " " << a;
            }
        }
        else
        {
            if (x)
                l++;
            if (a != a) {
                do {
                    cout << a << "^" << l << " ";
                } while (l == 0);
            }
            else if (a == a) {
                cout << a << "*" << l << " ";
            }
            else {
                cout << " ";
            }
            
        }
    }
    std::cout << "\n";
}
int main()
{
    int i;
    cin >> i;
    std::cout << i;
    prime_factorization(i);
}
