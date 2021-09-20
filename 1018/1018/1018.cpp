#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

const int MAX = 101;
int time_in[MAX], time_out[MAX];
long long dist[MAX];
int level[MAX];
vector<pair<int, long long> > g[MAX];
int l = 0, timer = 0;

int binary_par[MAX][20]; 


void dfs(int v, int parent, long long len, int lvl)
{
    int to;
    time_in[v] = timer++;
    binary_par[v][0] = parent;
    for (int i = 1; i <= l; i++) { 
        binary_par[v][i] = binary_par[binary_par[v][i - 1]][i - 1];

    }
    dist[v] = len;
    level[v] = lvl;

    for (int i = 0; i < g[v].size(); i++)
    {
        to = g[v][i].first;
        if (to != parent) {
            dfs(to, v, len + g[v][i].second, lvl + 1);
        }
    }

    time_out[v] = timer++;
}
bool is_parent(int par, int ch)
{
    return (time_in[par] <= time_in[ch]) && (time_out[par] >= time_out[ch]);
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

vector<int> used;
long long supermax = 0;
bool isGood(int a, vector<int>& used) {
    for (int i = 0; i < used.size(); i++) {
        if (is_parent(used[i], a) || is_parent(a, used[i])) {
            return false;
        }
    }
    return true;
}

int maxim = 0;
int sums[MAX];
int levelss[MAX];
int findMax(int a, int N, int Q, int lvls, long long sum) {
   // cout << "zahod v versh " << a << endl;
    used.push_back(a);
    levelss[a] = lvls; sums[a] = sum;
    for (int i = (a + 1); i <= N; i++) {
        if (isGood(i, used)) { //если вершина норм
            int local_lvl = level[LCA(i, a)];
            int near_v = a;
            for (int j = 0; j < used.size(); j++) { //находим ближайшую вершину для подсчета ребер
                int ll = level[LCA(i, used[j])];
                if (local_lvl < ll) {
                    local_lvl = ll;
                    near_v = used[j];
                }
            }

            lvls = levelss[a] + level[i] - level[LCA(i, near_v)];
            sum = sums[a] + dist[i] - dist[LCA(i, near_v)];

            //cout << "good v: " << i << " sum " << sum << " lvls " << lvls << endl;

            if (lvls < Q) {
                findMax(i, N, Q, lvls, sum);
                //break;
            }
            if (lvls == Q) {
                if (sum > maxim) { maxim = sum; }
                //cout << "finish obhod" << endl;
                
            }

        }
    }
    //cout << "vyhod iz versh " << a << endl;
    used.pop_back();
    return maxim;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u, v, N, M, Q;
    long long w;
    cin >> N >> Q;

    l = log2(N) + 1;
    //cout << l;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    dfs(1, 1, 0, 0);

    //cin >> u;
    //cout << "lvl u1: " << level[u] << " dist[u]: " << dist[u] << endl;

    long long fin_dist = -1, max = -1; //макс из тупа самых дальних 
    int ras;

    for (int i = 2; i <= N; i++) {
 
        if ((level[i] == Q) && (dist[i] > max)) {
            max = dist[i];
            continue;
        }

        
        fin_dist = findMax(i, N, Q, level[i], dist[i]);
        if (fin_dist > max) {
            max = fin_dist;
        }

    }
    cout << max;

    return 0;
}