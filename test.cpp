#include <cassert>
#include <iostream>
#define main program_main
#include "main.cpp"
#undef main

int main()
{
    const int n = 7;
    int a[n] = { 5, -3, 0, 4, -2, 7, -1 };
    int b[5] = { 5, -3, -2, 4, -6 };
    int e[n] = { 5, 0, -2, -1, -3, 4, 7 };
    int i;

    assert(MinAbs(b, 5) == -2);
    assert(FindFirstZero(a, n) == 2);
    assert(FindFirstZero(b, 5) == -1);
    assert(SumAbsFrom(a, n, 3) == 14);

    EvenFirst(a, n);
    for (i = 0; i < n; i++)
        assert(a[i] == e[i]);

    cout << "All tests passed" << endl;
    return 0;
}
