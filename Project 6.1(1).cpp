#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Сформувати масив (рекурсивно)
void Create(int* c, const int size, const int Low, const int High, int i = 0) {
    c[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1) {
        Create(c, size, Low, High, i + 1);
    }
}

// Вивести масив у вигляді рядка з форматним виведенням (рекурсивно)
void Print(const int* c, const int size, int i = 0) {
    cout << setw(4) << c[i];
    if (i < size - 1) {
        Print(c, size, i + 1);
    }
    else {
        cout << endl;
    }
}

// Перевірка критерію
bool Criterion(int element, int index) {
    return !(element % 2 == 0 || index % 13 == 0);
}

// Обчислити кількість елементів (рекурсивно)
int Count(const int* c, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    if (Criterion(c[i], i)) {
        return 1 + Count(c, size, i + 1);
    }
    else {
        return Count(c, size, i + 1);
    }
}

// Обчислити суму елементів (рекурсивно)
int Sum(const int* c, const int size, int i = 0) {
    if (i >= size) {
        return 0;
    }
    if (Criterion(c[i], i)) {
        return c[i] + Sum(c, size, i + 1);
    }
    else {
        return Sum(c, size, i + 1);
    }
}

// Замінити нулями елементи (рекурсивно)
void Zero(int* c, const int size, int i = 0) {
    if (Criterion(c[i], i)) {
        c[i] = 0;
    }
    if (i < size - 1) {
        Zero(c, size, i + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(NULL)));

    const int N = 21;
    int c[N];
    const int Low = 15;
    const int High = 85;

    Create(c, N, Low, High, 0);

    cout << "Initial array:" << endl;
    Print(c, N, 0);

    int count = Count(c, N, 0);
    int sum = Sum(c, N, 0);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Zero(c, N, 0);

    cout << "Modified array:" << endl;
    Print(c, N, 0);

    return 0;
} 