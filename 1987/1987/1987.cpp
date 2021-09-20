#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

struct otr {
    int cor, num, check;
    otr(int cor, int num, short check) {
        this->cor = cor;
        this->num = num;
        this->check = check;
    }
    
};

bool comparator(otr a, otr b)
{
    if (a.cor == b.cor) {
        return a.num < b.num;
    }
    else {
        return a.cor < b.cor;
    }
}

int main()
{
    vector < otr > vec;
    int a, b, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        vec.push_back(otr(a, i, 1));
        vec.push_back(otr(b, i, 0));
    }

    sort(vec.begin(), vec.end(), comparator);

    int m;
    cin >> m;
    int sum = 0;
    int l = vec[0].cor;
    int r = vec.back().cor;

    for (int i = 0; i < m; i++) {
        cin >> a;
        if ((a > r) || (a < l)) {
            cout << "-1" << endl;
        }
        else {
            int top = upper_bound(vec.begin(), vec.end(), otr(a, INT32_MAX, 0), comparator) - vec.begin();
            if (a == vec[top - 1].cor) {
                cout << vec[top - 1].num << endl;
                continue;
            }
            sum = 0;
            for (int i = top; i < vec.size(); i++) {
                if (vec[i].check) {
                    sum ++;
                }
                else {
                    sum--;
                }
                if (sum == -1) {
                    cout << vec[i].num << endl;
                    break;
                }
            }
        }
    }
}