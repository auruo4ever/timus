#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

struct otr {
    int l, r, num, len;
    otr* par;
    otr(int l, int r, int num) {
        this->l = l;
        this->r = r;
        this->num = num;
        par = 0;
        len = 0;
    }

};

bool compare(otr a, otr b) //компаратор по длине или по номеру отрезка
{
    if ((a.r - a.l) == (b.r - b.l)) {
        return a.num < b.num;
    }
    else {
        return (a.r - a.l) > (b.r - b.l);
    }
}

int main()
{
    vector < otr > vec;
    int l, r, n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        if (r < l) {
            int change = r;
            r = l;
            l = change;
        }
        vec.push_back(otr(l, r, i));
    }

    sort(vec.begin(), vec.end(), compare); //сортировка по длине отрезков от большего к меньшим

   /* for (auto i = vec.begin(); i != vec.end(); i++) { //проверка
        std::cout << i->l << " " << i->r << " " << i->num << std::endl;
    }  */

    bool check = false;
    int otr_max = -1;
    otr* shortest_otr = &vec[0];
    for (int i = 0; i < n; i++)
    {
        int deapest = -1;
        for (int j = 0; j < i; j++)
        {
            if (vec[i].l > vec[j].l && vec[i].r < vec[j].r) //если отрезок вложенный
            {
                if (vec[j].len + 1 >= deapest) //если он вложен глубже
                {
                    vec[i].len = vec[j].len + 1;
                    deapest = vec[i].len;
                    vec[i].par = &vec[j];
                    if (deapest > otr_max) //если больше общего максимума
                    {
                        //cout << "doshlo" << endl;
                        check = true;
                        otr_max = deapest;
                        shortest_otr = &vec[i];
                    }
                }
            }
        }
    }

    if (check) {
        cout << otr_max + 1 << endl;
    }
    else { 
        cout << 1 << endl; //ни разу не зашло в цикл
    }
    otr* i = shortest_otr;
    while (i != 0) {
        cout << i->num << " ";
        i = i->par;
    }


    return 0;
}