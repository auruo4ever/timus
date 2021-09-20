#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
vector <vector <int> > parents(1000); //предки
vector <vector <int> >children(1000); //потомки
vector<bool> check;

struct tree {
    int par1, par2;
    bool used;
};
void deleteParEvidence(int killed) { //не может съесть потомков
    check[killed] = 1;
    for (int i = 0; i < parents[killed].size(); ++i)
    {
        int node = parents[killed][i];
        if (!check[node]) {
            deleteParEvidence(node);
        }
    }
}
void deleteChEvidence(int killed) {  //не может съесть предков
    check[killed] = 1;
    for (int i = 0; i < children[killed].size(); ++i)
    {
        int node = children[killed][i];
        if (!check[node]) {
            deleteChEvidence(node);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    parents.resize(N+1);
    children.resize(N+1);
    check.resize(N+1);
    string str;
    int ch, pr;
    getline(cin, str);
    while (true)
    {
        getline(cin, str);
        if (str == "BLOOD")
            break;
        istringstream iss(str);
        iss >> ch >> pr;
        parents[ch].push_back(pr);
        children[pr].push_back(ch);
    }


    /*
    for (int i = 1; i < N; i++) {
        cout << i << " : ";
        for (int j = 0; j < parents[i].size(); j++) {
            cout << parents[i][j] << " ";
        }
        cout << endl;
    }
    */
    int sym;
    while (true)
    {
        cin >> sym;
        if (!cin) {
            break;
        }
        if (sym == -1) {
            break;
        }
        deleteParEvidence(sym);
        deleteChEvidence(sym);
    }

    bool all = false;
    for (int i = 1; i < check.size(); i++) {
        if (!check[i])
        {
            all = true;
            cout << i << ' ';
        }
    }
    if (!all) {
        cout << 0;
    }
    return 0;
}