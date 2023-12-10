#include <iostream>
using namespace std;

int findMinAttempts(int n, int k) {
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid < k) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }

    return left;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int n, k;
    cout << "Введите количество ступенек (n): ";
    cin >> n;
    cout << "Введите количество орехов (k): ";
    cin >> k;

    int minAttempts = findMinAttempts(n, k);

    cout << "Минимальное количество попыток: " << minAttempts << endl;

    return 0;
}