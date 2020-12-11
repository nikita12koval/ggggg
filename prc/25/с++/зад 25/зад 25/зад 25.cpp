#include <iostream>
#include <vector>
using namespace std;
bool isSorted(int t[], int x)
{
    setlocale (LC_ALL, "ru");
    while (--x > 1)
        if (t[x] < t[x - 1])
            return false;
    return true;
}
void shuffle(int t[], int x)
{
    for (int i = 0; i < x; i++)
        swap(t[i], t[rand() % x]);
}
void bogosort(int t[], int x)
{

    while (!isSorted(t, x))
        shuffle(t, x);
}

void printArray(int t[], int x)
{
    for (int i = 0; i < x; i++)
        printf("%d ", t[i]);
    printf("\n");
}
double double_layer_massive(int m, int x)
{
    setlocale(0, "");
    srand(unsigned(NULL));
    int n, m;
    cout << "Укажите размер вашей матрицы";
    cin >> m >> x;
    int** A = new int* [x];
    for (int i = 0; i < x; i++)
        A[i] = new int[m];

    for (int i = 0; i < x; i++)
        for (int j = 0; j < m; j++)
            A[i][j] = ((rand() % 10));


    cout << "Ваша матрица" << endl;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < m; j++)
            cout << A[i][j] << " ";
        cout << endl;
        return A[i];
    }

    cout << endl;
    for (int i = 0; i < x; i++)
        delete[] A[i];
    delete[] A;
}
int main()
{
    double k, x;
    std::vector <double> t{ 4,5,12,34,35,54,78,90,67 };
    std::vector <double> double_layer_massive(x);
    int x = sizeof k / sizeof k[0];
    bogosort(k, x);
    printArray(k, x);
    
}
