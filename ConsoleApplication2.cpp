#include <iostream>
#include <vector>
using namespace std;

long long int k_ans(long long int n) {
    if (n == 1 or n == 2)
        return 1;
    return (k_ans(n - 1) + k_ans(n - 2)) * (n - 1);
}

// Функция для обмена значениями в массиве
void swap(long long int& a, long long int& b) {
    long long int temp = a;
    a = b;
    b = temp;
}

// Рекурсивная функция для генерации перестановок
void generatePermutations(vector<long long int>& arr, long long int start, vector<vector<long long int>>& result) {
    if (start == arr.size() - 1) {
        // Добавляем текущую перестановку в результат
        result.push_back(arr);
        return;
    }

    for (long long int i = start; i < arr.size(); ++i) {
        // Меняем местами текущий элемент с каждым из последующих
        swap(arr[start], arr[i]);

        // Рекурсивно генерируем перестановки для подмассива
        generatePermutations(arr, start + 1, result);

        // Возвращаем массив в исходное состояние для следующих итераций
        swap(arr[start], arr[i]);
    }
}

// Функция для вызова генерации перестановок
vector<vector<long long int>> getAllPermutations(vector<long long int>& arr) {
    vector<vector<long long int>> result;
    generatePermutations(arr, 0, result);
    return result;
}

int main() {
    setlocale(LC_ALL, "Rus");
    while (true) {
        long long int n;
        cout << "Введите кол-во шариков в коробке: ";
        cin >> n;
        vector<long long int> input;
        for (long long int i = 0; i < n; ++i)
            input.push_back(i + 1);
        long long int count = 0; // Счетчик соответствий номера шарика и порядка его вытаскивания

        vector<vector<long long int>> permutations = getAllPermutations(input);
        // Выводим все перестановки
        for (const auto& perm : permutations) {
            vector<long long int> tmp;
            for (long long int num : perm)
                tmp.push_back(num);
            for (long long int i = 0; i < tmp.size(); ++i) {
                if (tmp[i] == i + 1) {
                    count += 1;
                    break;
                }
            }
        }

        if (k_ans(n) == count)
            cout << count << endl;
        else
            cout << "Error " << count << " != " << k_ans(n) << endl;
    }
    return 0;
}
