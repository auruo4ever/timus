#include <iostream>
#include <vector>
using namespace std;

inline bool isSimple(int num) //проверка простое ли число  
{
    if (num == 1)
        return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
}


//!!!!!! проблема Гольдбаха


int main()
{
    int arr[1000] = { 70 };
    int N, T;
    cin >> T;

    for (int count = 0; count < T; count++)
    {
        cin >> N;

        if (isSimple(N)) {
            cout << N << endl; //для простых выводим само число
        }
        else if (N % 2 == 0) //четное представляется в виде суммы 2 простых
        {
            if (isSimple(N - 2))
                cout << "2 " << N - 2 << endl; //два простых числа с разницей в 2
            else
            {
                int i = 3;
                while (true) {
                    if (isSimple(i) && isSimple(N - i))
                    {
                        cout << i << " " << N - i << endl;
                        break;
                    }
                    i += 2;
                }
            }
        }
        else //для нечетных - сумма 3х простых
        {
            if (isSimple(N - 2)) {
                cout << "2 " << N - 2 << endl; //два простых числа с разницей в 2
            }
            else
            {
                N -= 3;
                int i = N - 3;
                while (true) {
                    if (isSimple(i) && isSimple(N - i)) {
                        cout << "3 " << i << " " << N - i << endl; 
                        break;
                    }
                    i -= 2;
                }
            }
        }
    }
    return 0;
}