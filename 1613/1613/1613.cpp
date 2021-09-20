
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std;

/*int isContain(long long x, vector<long long> vek) {

    bool wow = 0;
    vector<long long>::iterator it = find(vek.begin(), vek.end(), x);

    if (it != vek.end()) {
        int index = distance(vek.begin(), it);
        //cout << "Element Found" << "index: " << index << endl;
        wow = true;
       
    }
    

    return wow;
} */

int main()
{
    int size;
    cin >> size;
    long long x;
    vector<long long> vek(size);

    for (int i = 0; i < vek.size(); i++) {
        cin >> vek[i];
    }

    int count, a, b;
    string str;
    cin >> count;

    /*
    for (int i = 0; i < count; i++) {
        cin >> a >> b >> x;
        auto first = vek.begin() + (a - 1);
        auto last = vek.begin() + (b);
        vector<long long> newVek(first, last);

        vector<long long>::iterator it = find(newVek.begin(), newVek.end(), x);

        if (it != newVek.end()) {
            
            str = str + "1";

        }
        else {
            str = str + "0";
        }
    }

    cout << str;
    return 0;
    */

    for (int i = 0; i < count; i++) {
        cin >> str;
        cout << str << " ";
    }
}

