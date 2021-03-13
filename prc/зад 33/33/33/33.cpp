 #include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void Sort(int*, int);

int main()
{
     int N ;
     cout << "Razmer massiva";
     cin >> N;
    int *array=new int[N];

    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        array[i] = rand() % 100;
        cout << array[i] << ' ';
    }
    Sort(array, N);

    cout << endl << endl;
    for (int i = 0; i < N; ++i) {
        cout << array[i] << ' ';
    }

    cout << endl;
    return 0;
}


void Sort(int* array, int N)
{
    int temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return;
}
