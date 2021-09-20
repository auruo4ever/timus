#include <iostream>
#include <algorithm>

using namespace std;
int sum[901][8101], num[901][8101]; //max из возможной суммы всех цифр и их произведения

int main() {

    num[0][0] = 1;
    for (int i = 1; i <= 900; i++) {
        for (int j = 1; j <= 8100; j++) {
            sum[i][j] = 101; //max из возможной 
            for (int k = 1; k <= 9; k++) {
                int a = i - k;
                int b = j - k * k;
                if (a >= 0 && b >= 0) {
                    if ((num[a][b]) && ((sum[a][b] + 1) < sum[i][j])) {
                        //min путь для добавления 1 цифры
                        num[i][j] = k; //матрица сумм и квадратов
                        sum[i][j] = sum[a][b] + 1; 
                    }
                }
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int s1, s2;
        cin >> s1 >> s2;

        if ((s1 > s2) || (s1 > 900) || (s2 > 8100)) {  //выходит за пределы суммы
            cout << "No solution" << endl;
            continue;
        }
        if (sum[s1][s2] > 100) { //больше 100 цифр ответа
            cout << "No solution" << endl;
            continue;
        }

        int s = sum[s1][s2];
        for (int i = 0; i < s; i++) {
            int n = num[s1][s2];
            cout << n;
            s1 -= n; //поднимаемся на n по матрице сумм цифр и квадратов
            s2 -= n*n;
        }
        cout << "\n";
    }
}