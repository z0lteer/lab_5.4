#include <iostream>
#include <cmath>
using namespace std;

// Ітераційний спосіб
double P0(const int N) {
    double p = 1;
    for (int i = N; i <= 10; i++) {
        p *= (i + 1.0 / pow(i, 2)) / sqrt(1 + exp(1.0 * i));
    }
    return p;
}

// Рекурсивний спосіб (спуск, параметр зростає)
double P1(const int N, const int i) {
    if (i > 10)
        return 1;
    else
        return (i + 1.0 / pow(i, 2)) / sqrt(1 + exp(1.0 * i)) * P1(N, i + 1);
}

// Рекурсивний спосіб (спуск, параметр спадає)
double P2(const int N, const int i) {
    if (i < N)
        return 1;
    else
        return (i + 1.0 / pow(i, 2)) / sqrt(1 + exp(1.0 * i)) * P2(N, i - 1);
}

// Рекурсивний спосіб (підйом, параметр зростає)
double P3(const int N, const int i, double t) {
    t *= (i + 1.0 / pow(i, 2)) / sqrt(1 + exp(1.0 * i));
    if (i >= 10)
        return t;
    else
        return P3(N, i + 1, t);
}

// Рекурсивний спосіб (підйом, параметр спадає)
double P4(const int N, const int i, double t) {
    t *= (i + 1.0 / pow(i, 2)) / sqrt(1 + exp(1.0 * i));
    if (i <= N)
        return t;
    else
        return P4(N, i - 1, t);
}

int main() {
    int N;
    cout << "N = "; cin >> N;

    // Виведення результатів для всіх 5 способів
    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec down) P1 = " << P1(N, N) << endl;
    cout << "(rec down) P2 = " << P2(N, 10) << endl;
    cout << "(rec up) P3 = " << P3(N, N, 1) << endl;
    cout << "(rec up) P4 = " << P4(N, 10, 1) << endl;

    return 0;
}
