#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int N, ball, next_ball;
    bool ok = true;
    cin >> N;

    set<int> balls;

    for (int i = 1; i <= N; i++) {
        balls.insert(i);
    }
 
    multiset<int>::iterator it = balls.begin();
    cin >> ball;

    for (int i = 1; i < N; i++) {
        cin >> next_ball;
        it = balls.find(ball);

        if (next_ball < ball) {
            
            if (*prev(it) != next_ball) {
                ok = false;
            }
        }
        balls.erase(it);
        //it = balls.begin();
        ball = next_ball;
    }

    if (ok) {
        cout << "Not a proof";
    }
    else cout << "Cheater";


    return 0;
}
//оаоаоа ммммм
