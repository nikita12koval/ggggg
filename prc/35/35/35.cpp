
#include <iostream>
using namespace std;
int main()
{
    int* arr = new int[30];
    for (int i = 0; i < 30; i++)
    {
        arr[i] = rand() % 30;
    }

    for (int i = 0; i < 30; i++)
    {
        cout << arr[1] << "\t" << endl;
    }
    delete[] arr;

    new int[50];

    for (int i = 0; i < 50; i++)
    {
        arr[i] = rand() % 50;
    }

    for (int i = 0; i < 50; i++)
    {
        cout << arr[1] << "\t" << endl;
    }
    delete[] arr;

    new int[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[1] << "\t" << endl;
    }

}
