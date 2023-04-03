#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

#define int long long

int n, m, a, b, kellkettooo = 0;
vector<int> entered, leaved, is_back_edge;
vector<vector<pair<int, int> > > g;

void dfs(int u) {
    entered[u] = 1;
    for (auto w : g[u])
        if (!entered[w.first]) dfs(w.first);
        else if (!leaved[w.first]) {
            is_back_edge[w.second] = 1;
            kellkettooo = 1;
        }
    leaved[u] = 1;
}

#undef int
int main() {
#define int long long
    speed;
    cin >> n >> m;
    g.resize(n + 1), entered.resize(n + 1), leaved.resize(n + 1), is_back_edge.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].pb({ b, i });
    }
    for (int i = 1; i <= n; i++) if (!entered[i]) dfs(i);
    cout << kellkettooo + 1 << endl;
    for (int i = 0; i < m; i++) {
        cout << is_back_edge[i] + 1 << " ";
    }
    cout << endl;
}