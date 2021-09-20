#include <iostream>
using namespace std;

int main()
{
    int rems[10];

    for (int i = 0; i <= 9; i++) {rems[i] = 0; }
    int num;
    cin >> num;
    long long final = 0;

    if (num == 0) {
        cout << 10;
        return(0);
    }
    if (num == 1) {
        cout << 1;
        return(0);
    }

    for (int i = 9; i >= 2; ) {
        if (num % i == 0) {
            num = num / i;
            rems[i]++;
        }
        else {
            i--;
        }
    }
    if (num > 1) {
        final = -1;
    }
       


    if (final != -1) {
        for (int i = 2; i < 10; i++) {
            while (rems[i] != 0) {
                final = final * 10 + i;
                rems[i]--;
            }
        }
    }
    cout << final;
    return 0;
}