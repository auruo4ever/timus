#include <vector>
#include <iostream>
using namespace std;

int main()
{

    int ary[10001][10][10] = { 0 };

    int N;
    cin >> N;
    vector<bool> isSimple(1001, 0);

    int osn;
    long long modul = 1000000009;

    for (int i = 100; i < 1000; i++) {
        osn = 2;
        isSimple[i] = 1;
        while ((osn * osn <= i) && (isSimple[i])) {
            if (i % osn == 0) {
                isSimple[i] = 0; //заполнение отдельного массива простых 3хзначных чисел
            }
            osn++;
        }
        if (isSimple[i]) {
            int j = (i % 100) / 10;
            int k = i % 10;
            ary[3][k][j]++; //заполнение общего массива простыми 3хзначными числами
        }
    }
 
    /*
    //проверка чтобы простых чисел было ровно 143
    int sum = 0; 
    for (int i = 100; i < 1000; i++) {
        sum += isSimple[i];
    }
    cout << sum << endl;
    */

    for (int num = 4; num <= N; num++) { //заполняем массив для 4хзначных и далее чисел
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k <= 9; k++) {
                    if (isSimple[i * 100 + j * 10 + k]) {
                        ary[num][k][j] = ((ary[num][k][j] + ary[num - 1][j][i]) % modul);
                    }

                }
            }
        }
    }

    long long fin = 0;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            fin = (ary[N][i][j] + fin) % modul; //в процессе берем ответ по модулю
        }
    }
    cout << fin;
}