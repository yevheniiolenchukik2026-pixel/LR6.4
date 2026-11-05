#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;

void Fill(int* a, const int size, const int Low, const int High)
{
    int i;
    for (i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int MinAbs(int* a, const int size)
{
    int i;
    int m;
    m = a[0];
    for (i = 1; i < size; i++)
        if (abs(a[i]) < abs(m))
            m = a[i];
    return m;
}

int FindFirstZero(int* a, const int size)
{
    int i;
    for (i = 0; i < size; i++)
        if (a[i] == 0)
            return i;
    return -1;
}

int SumAbsFrom(int* a, const int size, const int start)
{
    int i;
    int S = 0;
    for (i = start; i < size; i++)
        S += abs(a[i]);
    return S;
}

void EvenFirst(int* a, const int size)
{
    int i;
    int k = 0;
    int* t = new int[size];
    for (i = 0; i < size; i += 2)
        t[k++] = a[i];
    for (i = 1; i < size; i += 2)
        t[k++] = a[i];
    for (i = 0; i < size; i++)
        a[i] = t[i];
    delete[] t;
}

int main()
{
    int n;
    int* a;
    int Low = -10;
    int High = 10;
    int z;

    srand((unsigned)time(NULL));
    cout << "n = ";
    cin >> n;
    a = new int[n];
    Fill(a, n, Low, High);
    cout << "a = ";
    Print(a, n);

    cout << "Min by abs = " << MinAbs(a, n) << endl;
    z = FindFirstZero(a, n);
    if (z == -1)
        cout << "No zero element" << endl;
    else
        cout << "Sum of abs after first zero = " << SumAbsFrom(a, n, z + 1) << endl;

    EvenFirst(a, n);
    cout << "a = ";
    Print(a, n);

    delete[] a;
    return 0;
}
