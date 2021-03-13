#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



void Sort(int*, int);


int main()
{
    int n, d, x;
    cout << "vvedite nachalnui element" << endl;
    cin >> x;

    cout << "vvedite arifm progr" << endl;
    cin >> d;

    cout << "vvedite kolichestvo elementov" << endl;
    cin >> n;

    int* a = new int[n];
    a[0] = x;
    cout << a[0] << ' ';


    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + d;
        cout << a[i] << ' ';
    }

    void Sort(int*, int);

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        cout << a[i] << ' ';
    }

    Sort(a, n);
    Sort(a, n);

    cout << endl << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';

void Sort(int*, int);

int main()
{
    

    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
        cout << a[i] << ' ';
    }
    Sort(a, n);

    cout << endl << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';

    }

    cout << endl;
    return 0;

    void Sort(int* a, int n);
    {
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }

            }



        }



        void Sort(int* a, int n)
        {
            int temp;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (a[j] >a[j + 1]) {
                        temp =a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }
    }
