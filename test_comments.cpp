#include <cassert>                                              // assert
#include <iostream>                                             // cout, cin, endl
#define main program_main                                       // перейменовуємо main з main.cpp, щоб не було двох main
#include "main.cpp"
#undef main                                                     // повертаємо назву main для тесту

int main()
{
    const int n = 7;                                            // кількість елементів
    int a[n] = { 5, -3, 0, 4, -2, 7, -1 };                      // масив з нулем
    int b[5] = { 5, -3, -2, 4, -6 };                            // масив без нулів
    int e[n] = { 5, 0, -2, -1, -3, 4, 7 };                      // очікуваний масив після перетворення
    int i;                                                      // індекс поточного елемента

    assert(MinAbs(b, 5) == -2);                                 // мінімальний за модулем: -2
    assert(FindFirstZero(a, n) == 2);                           // перший нуль має індекс 2
    assert(FindFirstZero(b, 5) == -1);                          // нулів немає
    assert(SumAbsFrom(a, n, 3) == 14);                          // 4 + 2 + 7 + 1

    EvenFirst(a, n);                                            // перетворюємо масив
    for (i = 0; i < n; i++)
        assert(a[i] == e[i]);                                   // порівнюємо з очікуваним

    cout << "All tests passed" << endl;                         // усі тести пройдено
    return 0;                                                   // успішне завершення програми
}
