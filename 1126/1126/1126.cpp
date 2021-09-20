#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int M, inp, max;
    cin >> M;
    vector<int> vec;
    for (int i = 0; i < M; i++) {
        cin >> inp;
        vec.push_back(inp);
    }
    while (inp != -1) {
        max = *max_element(vec.begin(), vec.end());
        cout << max << endl;
        cin >> inp;
        vec.push_back(inp);
        vec.erase(vec.begin());
    }
}

