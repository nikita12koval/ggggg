 

#include <iostream>
#include <string>
using namespace std;

using std::endl;

int main()
{
    setlocale(LC_ALL, "ru");
    int a;
    cin >> a;

    int arr[37];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    arr[4] = 4;
    arr[5] = 5;
    arr[36] = 0, 0;
    
    if (a == arr[1] || a == arr[3] || a == arr[5] || a == arr[7] || a == arr[12])
    {
        cout << "Красная линия\n";
    }

    for (int b = 0; b < 41; ++b)
    {
        cout << arr[b] << " ";
    }
    cout << endl;
}


