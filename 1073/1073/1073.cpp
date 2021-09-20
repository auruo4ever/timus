#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    vector<int> min_roots;
    cin >> N;
    min_roots.push_back(0); //0 вариантов для 0
    for (int i = 1; i <= N; i++) {
        min_roots.push_back(i);
        for (int j = 0; j*j <= i; j++) {
            min_roots[i] = min(min_roots[i], (min_roots[i - j*j] + 1)); //находим минимум среди всех возможных квадратов,
        }                                               //которые можно добавить, чтобы получить данное число и заполняем массив
    }
    cout << min_roots[N];
    
    return 0;
}
