#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string str2, str3, str4, str5;

    //для четной строки
    if (str.size() % 2 == 0) {
        int half = (str.size() / 2);
        int full = str.size();
        for (int i = half; i < full; i++) {
            str2 = str.substr(i, (full - i));
            str3 = str.substr(i - (full - i), (full - i));
            reverse(str3.begin(), str3.end());

            //cout << str2 << " and " << str3 << endl;
            //cout << (str2 == str3) << endl;

            str4 = str.substr(i + 1, (full - (i + 1)));
            str5 = str.substr((i - (full - i) + 1), (full - (i + 1)));
            reverse(str5.begin(), str5.end());

           // cout << str4 << " and " << str5 << endl;
            //cout << (str4 == str5) << endl;

            if ((str2 == str3) && (i > half)) {
                string strFin = str.substr(0, full - (2 * str2.size()));
                reverse(strFin.begin(), strFin.end());
                cout << str << strFin;
                return 0;
            }

            if ((str4 == str5) && (i < full - 1)) {
                string strFin = str.substr(0, full - (2 * str4.size() + 1));
                reverse(strFin.begin(), strFin.end());
                cout << str << strFin;
                return 0;
            }
        }
        string strFin = str.substr(0, full - 1);
        reverse(strFin.begin(), strFin.end());
        cout << str << strFin;
        return 0;
    }
    //для нечетной строки
    else {
        int half = (str.size() / 2) + 1;
        int full = str.size();
        if (full == 1) {
            cout << str << str;
            return 0;
        }

        for (int i = half+1; i < str.size(); i++) {
            str2 = str.substr(i-1, (full - i +1));
            str3 = str.substr(i - (full - i) - 2, (full - i+ 1));
            reverse(str3.begin(), str3.end());

            //cout << str2 << " and " << str3 << endl;
           // cout << (str2 == str3) << endl;

            str4 = str.substr(i, (full - i));
            str5 = str.substr((i - (full - i) - 1), (full - i));
            reverse(str5.begin(), str5.end());

            //cout << str4 << " and " << str5 << endl;
            //cout << (str4 == str5) << endl;


            if (str2 == str3) {
                string strFin = str.substr(0, full - (2 * str2.size()));
                reverse(strFin.begin(), strFin.end());
                cout << str << strFin;
                return 0;
            }
            if (str4 == str5) {
                string strFin = str.substr(0, full - (2 * str4.size() + 1));
                reverse(strFin.begin(), strFin.end());
                cout << str << strFin;
                return 0;
            }
        }
        string strFin = str.substr(0, full - 1);
        reverse(strFin.begin(), strFin.end());
        cout << str << strFin;
        return 0;

    }
}

