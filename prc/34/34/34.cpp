#include <iostream>

using namespace std;



int main()
{
    int n, d, x;
    cout << "vvedite nachalnui element" << endl;
    cin >> x;

    cout << "vvedite arifm progr" << endl;
    cin >> d;

    cout << "vvedite kolichestvo elementov" << endl;
    cin >> n;

    int *a = new int [n];
    a[0] = x;
    cout << a[0] << ' ';


    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + d; 
        cout << a[i] << ' ';
    }
    delete [] a ;//очищаем память
}

