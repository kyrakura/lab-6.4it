#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

void Create(int a[], const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(int a[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int MaxElement(int a[], const int size) {
    if (size == 0) {
        return 0;
    }

    int max = a[0];

    for (int i = 1; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    return max;
}

int Sum(int a[], const int size) {
    int sum = 0;
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] > 0) {
            index = i;
        }
        if (index == -1) {
            sum += a[i];
        }
    }

    return sum;
}

void ModArray(int a[], int& size, int aVal, int bVal) {
    int newSize = size;
    for (int i = 0; i < newSize; i++) {
        if (abs(a[i]) >= aVal && abs(a[i]) <= bVal) {
            for (int j = i; j < newSize - 1; j++) {
                a[j] = a[j + 1];
            }
            newSize--;
            i--;
        }
    }

    for (int i = newSize; i < size; i++) {
        a[i] = 0;
    }

    size = newSize;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть розмір масиву (n): ";
    cin >> n;

    int *a = new int[n];

    int Low = -11;
    int High = 13;

    Create(a, n, Low, High);

    cout << "Початковий масив: ";
    Print(a, n);

    int maxElement = MaxElement(a, n);
    cout << "Максимальний елемент масиву: " << maxElement << endl;

    int sumBefore = Sum(a, n);
    cout << "Сума елементів масиву до останнього додатного елементу: " << sumBefore << endl;

    int aVal, bVal;
    cout << "Введіть значення a: ";
    cin >> aVal;
    cout << "Введіть значення b: ";
    cin >> bVal;

    int newSize = n;
    ModArray(a, newSize, aVal, bVal);

    cout << "Модифікований масив після стиснення: ";
    Print(a, newSize);

    return 0;
}
