#include <iostream>                                             // cout, cin, endl
#include <cstdlib>                                              // abs, rand, srand
#include <iomanip>                                              // setw
#include <time.h>                                               // time
using namespace std;

void Fill(int* a, const int size, const int Low, const int High)// заповнює масив випадковими числами з діапазону [Low; High]
{
    int i;                                                      // індекс поточного елемента
    for (i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)                              // виводить масив у рядок
{
    int i;                                                      // індекс поточного елемента
    for (i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int MinAbs(int* a, const int size)                              // повертає мінімальний за модулем елемент
{
    int i;                                                      // індекс поточного елемента
    int m;                                                      // мінімальний за модулем елемент
    m = a[0];                                                   // спочатку беремо перший елемент
    for (i = 1; i < size; i++)
        if (abs(a[i]) < abs(m))                                 // якщо модуль елемента менший
            m = a[i];                                           // запам'ятовуємо його
    return m;                                                   // повертаємо результат
}

int FindFirstZero(int* a, const int size)                       // повертає індекс першого нульового елемента або -1
{
    int i;                                                      // індекс поточного елемента
    for (i = 0; i < size; i++)
        if (a[i] == 0)                                          // знайшли нульовий елемент
            return i;                                           // повертаємо його індекс
    return -1;                                                  // нульових елементів немає
}

int SumAbsFrom(int* a, const int size, const int start)         // повертає суму модулів елементів, починаючи з індексу start
{
    int i;                                                      // індекс поточного елемента
    int S = 0;                                                  // сума модулів
    for (i = start; i < size; i++)
        S += abs(a[i]);                                         // додаємо модуль елемента
    return S;                                                   // повертаємо суму
}

void EvenFirst(int* a, const int size)                          // спочатку елементи з парними індексами, потім з непарними
{
    int i;                                                      // індекс поточного елемента
    int k = 0;                                                  // індекс у допоміжному масиві
    int* t = new int[size];                                     // допоміжний динамічний масив
    for (i = 0; i < size; i += 2)
        t[k++] = a[i];                                          // записуємо елемент у допоміжний масив
    for (i = 1; i < size; i += 2)
        t[k++] = a[i];                                          // записуємо елемент у допоміжний масив
    for (i = 0; i < size; i++)
        a[i] = t[i];                                            // копіюємо результат назад
    delete[] t;                                                 // звільняємо допоміжний масив
}

int main()
{
    int n;                                                      // кількість елементів, вводиться з клавіатури
    int* a;                                                     // вказівник на динамічний масив
    int Low = -10;                                              // нижня межа діапазону
    int High = 10;                                              // верхня межа діапазону
    int z;                                                      // індекс першого нульового елемента

    srand((unsigned)time(NULL));                                // ініціалізація генератора випадкових чисел
    cout << "n = ";                                             // запит кількості елементів
    cin >> n;                                                   // вводимо n
    a = new int[n];                                             // створюємо динамічний масив
    Fill(a, n, Low, High);                                      // формуємо масив
    cout << "a = ";                                             // підпис масиву
    Print(a, n);                                                // виводимо масив

    cout << "Min by abs = " << MinAbs(a, n) << endl;            // виводимо мінімальний за модулем елемент
    z = FindFirstZero(a, n);                                    // шукаємо перший нуль
    if (z == -1)                                                // нуля немає
        cout << "No zero element" << endl;                      // повідомляємо, що нуля немає
    else
        cout << "Sum of abs after first zero = " << SumAbsFrom(a, n, z + 1) << endl;// виводимо суму модулів після першого нуля

    EvenFirst(a, n);                                            // перетворюємо масив
    cout << "a = ";                                             // підпис масиву
    Print(a, n);                                                // виводимо масив

    delete[] a;                                                 // знищуємо динамічний масив
    return 0;                                                   // успішне завершення програми
}
