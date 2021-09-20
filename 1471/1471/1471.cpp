#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 50009;
int time_in[MAX], time_out[MAX];
long long length_to_root[MAX];
vector<pair<int, long long> > g[MAX];
int l = 0, timer = 0;

int binary_par[MAX][18]; //20??

void dfs(int v, int parent, long long len)
{
    int next;
    time_in[v] = timer++;
    binary_par[v][0] = parent; 
    for (int i = 1; i <= l; i++) { //binary_par[i][j] - это 2j-й предок вершины i, i = 1..N, j = 0..⌈logN⌉
        binary_par[v][i] = binary_par[binary_par[v][i - 1]][i - 1];
        //cout << binary_par[v][i] << " ";
    }
    //cout << "\n";
    length_to_root[v] = len;

    for (int i = 0; i < g[v].size(); i++)
    {
        next = g[v][i].first;
        if (next != parent) {
            dfs(next, v, len + g[v][i].second);
        }
    }
    time_out[v] = timer++;
}
bool is_parent(int par, int ch)
{
    return (time_in[par] < time_in[ch]) && (time_out[par] > time_out[ch]);
}

int LCA(int a, int b)
{
    if (a == b) { return 0; }
    if (is_parent(a, b)) { return a; } 
    if (is_parent(b, a)) { return b; }
    for (int i = l; i >= 0; i--) {
        //cout << binary_par[a][i] << " " << b << " is par " << is_parent(binary_par[a][i], b) << endl;
        if (!is_parent(binary_par[a][i], b)) {
            a = binary_par[a][i];
        }
    }
    return binary_par[a][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v, N, M;
    long long w;
    cin >> N;

    l = log2(N) + 1;
    //cout << l;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    /*for (int i = 0; i < MAX; i++) {
        for (int j = 0; j <= l; j++) {
            binary_par[i][j] = 0;
        }
    }*/
    dfs(0, 0, 0);
    
    /*for (int i = 0; i < N; i++) {
        cout << "for i " << i << ": ";
        for (int j = 0; j <= l; j++)
        {
            cout << binary_par[i][j] << " ";
        }
        cout << " \n";
    } */
    /*
    for (int i = 0; i < N; i++) {
        cout << i << ": " << length_to_root[i] << endl;
    } 
    for (int i = 0; i < N; i++) {
        cout << i << ": timein " << time_in[i] << " timeout " << time_out[i] << endl;
    } */
   
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int depth = 0, res;
        cin >> u >> v;
        if (u == v) {
            res = 0;
            cout << res << endl;
            continue;
        } 
        res = length_to_root[u] + length_to_root[v];
        depth = length_to_root[LCA(u, v)];
        //cout << "res " << length_to_root[u] << " " << length_to_root[v] << " depttt " << depth << endl;
        res = res - 2*depth;
        cout << res << endl;
    }

    return 0;
}
