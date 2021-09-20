#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

//#define maxN 50001
using namespace std;

vector< vector < int > > graph;
const int MAX = 50009;
int time_in[MAX], time_out[MAX];
long long dist[MAX];
//vector<pair<int, long long> > g[MAX];
int l = 0, timer = 0;
int binary_par[MAX][20]; //20??


int breadthSearch(int startNode, int nodeAmount) {
    queue<int> queue;
    queue.push(startNode);
    vector<bool> used(nodeAmount);
    vector<int> rootToNode(nodeAmount), parent(nodeAmount);
    used[startNode] = true;
    parent[startNode] = -1;
    int maxLength = 0, maxLengthNode = 0;
    while (!queue.empty()) {
        int currentNode = queue.front();
        if (rootToNode[currentNode] > maxLength) {
            maxLength = rootToNode[currentNode];
            maxLengthNode = currentNode;
        }
        queue.pop();
        for (int i = 0; i < graph[currentNode].size(); ++i) {
            int nextNode = graph[currentNode][i];
            if (!used[nextNode]) {
                used[nextNode] = true;
                queue.push(nextNode);
                rootToNode[nextNode] = rootToNode[currentNode] + 1;
                parent[nextNode] = currentNode;
            }
        }
    }

    return maxLengthNode;
}

void dfs(int v, int parent, int len)
{
    int to;
    time_in[v] = timer++;
    binary_par[v][0] = parent;
    for (int i = 1; i <= l; i++) { //binary_par[i][j] - это 2j-й предок вершины i, i = 1..N, j = 0..⌈logN⌉
        binary_par[v][i] = binary_par[binary_par[v][i - 1]][i - 1];
        cout << binary_par[v][i] << " ";
    }
    cout << "\n";
    dist[v] = len;

    for (int i = 0; i < graph.size(); i++)
    {
        to = graph[v][i];
        if (to != parent) {
            dfs(to, v, len + 1);
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

vector<int> rootToNode1;
vector<int> rootToNode2;


int main() {
    int u, v, N, Q;
    cin >> N >> Q;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; i++) { // по итогу имеем вектор для каждой вершины, где записаны пары [вершина, до которой есть ребро; вес этого ребра]
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int furthestNode1, furthestNode2;
    furthestNode1 = breadthSearch(1, N + 1);
    furthestNode2 = breadthSearch(furthestNode1, N + 1);

    cout << furthestNode1 << " & " << furthestNode2 << endl;
    l = log2(N) + 1;
    dfs(0, 0, 0);

    for (int i = 0; i < Q; i++) {
        int depth1 = 0, depth2 = 0, tasamaya, res1, res2;
        cin >> v >> u;

        res1 = dist[u] + dist[v];
        depth1 = dist[LCA(u, v)];
        res1 = res1 - 2 * depth1;
        res2 = dist[u] + dist[v];
        depth2 = dist[LCA(u, v)];
        res2 = res2 - 2 * depth2;
        cout << res1 << " " << res2 << endl;
    }
    return 0;
}