#include <map>
#include <iostream>
#include <iostream>
#include <string> 

using namespace std;

int main()
{

    map<int, int> m;
    int num, l, r, lmin;
    

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> l >> r;
        if (l > r) {
            lmin = l;
            l = r;
            r = lmin;
        }
        if (m.find(r) == m.end()) {
            m[r] = l;
        }
        else {
            if (m[r] < l) {
                m[r] = l;
            }
        }
        
    }

    num = 0;
    string str;
    int gran = m.begin()->first;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (m.begin()->first == it->first) {
            str = str + to_string(it->second) + " " + to_string(it->first);
            num++;
            continue;
        }

        if (it->second >= gran) {
            gran = it->first;
            str = str + "\n" + to_string(it->second) + " " + to_string(it->first);
            num++;
        }

    }
    cout << num << "\n" << str;
    

    return 0;
}


