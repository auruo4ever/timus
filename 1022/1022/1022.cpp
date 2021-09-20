#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int N;
    cin >> N;
    vector< vector<int>> child;
    vector<int> a;
    vector<int> number(N+1, 0);
    vector<bool> isPrinted(N + 1, 0);
   
    int x = -1;
    for (int i = 1; i <= N; i++) {
        cin >> x;
        while (x != 0) {
            a.push_back(x);
            number[x]++;
            cin >> x;
            
        }
        child.push_back(a);
        a.clear();
    }
    /*
    for (int i = 0; i < N; i++) {
        cout << i << ": ";
        for (int j = 0; j < child[i].size(); j++) {
            cout << child[i][j] << " " ;
        }
        cout << endl;
    }
    cout << "num";
    for (int i = 1; i <= N; i++) {
        cout << i << ": " << number[i] << endl;
    }
    */
    int count = 0;
    while (count != N) {
        for (int i = 1; i <= N; i++) {
            if ((number[i] == 0) && (!isPrinted[i])) {
                cout << i << " ";
                isPrinted[i] = 1;
                count++;
                for (int j = 0; j < child[i-1].size(); j++) {
                    number[child[i-1][j]]--;
                }
            }
        }
    }
}
