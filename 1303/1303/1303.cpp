#include <map>
#include <iostream>
#include <string> 

using namespace std;

int main()
{

    map<int, int> m;
    int num, l = 1, r = 1, len;
   
    cin >> len;

    while ((l != 0) || (r != 0))
    {
        cin >> l >> r;
        if ((r <= 0) || (l >= len)) {
            continue; //лежит до 0 или после len
        }
        if (m.find(l) == m.end()) {
            m[l] = r;
        }
        else {
            if (m[l] < r) {
                m[l] = r;
            }
        }
        
    }
    
    /* проверка ввода
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << "check: " << it->first << " " << it->second << endl;
    }*/


    num = 0;
    int r_check = 0, r_max = -1;
    string str;
    auto max_it = m.begin();
    bool check = 0, samo = 0;

    for (auto it = m.begin(); it != m.end(); ++it) {

        if ((it->first <= r_check) && (it->second > r_max)) { //если л левее левой точки ищем макс
            r_max = it->second;
            max_it = it;
            //cout << "zapisan vector " << it->first << " " << it->second << endl;
            
        }
        if ((it->first > r_check) && (it->first > r_max)) {
            cout << "No solution";
            return 0;
        }
        if ((it->first > r_check) && (it->second > r_max) && (it->first <= r_max)) {
            str = str + "\n" + to_string(max_it->first) + " " + to_string(max_it->second);
            r_check = r_max;
            r_max = it->second;
            max_it = it;
            //cout << "zapisan vector2 " << it->first << " " << it->second << endl;
            num++;
        }
        if (r_max >= len) { 
            str = str + "\n" + to_string(it->first) + " " + to_string(it->second);
            num++;
            samo = 1;
            break;
        }
    }

    if (samo) {
        cout << num << str;
    }
    else {
        cout << "No solution";
    }

    return 0;
}


