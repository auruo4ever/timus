#include <iostream>

using namespace std;

long long arr[501][501];
long long numBlocks(int num, int height) //лестницы из num кубиков, высота последнего блока height
{
    if (num == 0) {
        return 1;
    }
    if (height == 0) {
        return 0;
    }
    if (arr[num][height] == -1) {
        arr[num][height] = numBlocks(num, height - 1); //в любом случае добавляем 1 куб сверху

        if (num >= height) {
            arr[num][height] += numBlocks(num - height, height - 1); //плюс строим новый блок
            //cout << arr[num][height] << endl;
        }
    }
    return arr[num][height];

}


int main()
{
    int N;
    cin >> N;
    memset(arr, -1, sizeof(arr));
    long long ans = numBlocks(N, N - 1);
    cout << ans;

    return 0;
}