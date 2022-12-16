#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<bool> visited;
vector<bool> searched;
vector<vector<int>> g;
vector<vector<int>> trg;
void clean(int u) {
    visited[u] = true;
    for (auto v : trg[u]) {
        if (!visited[v]) {
            clean(v);
        }
    }
}
int search(int u) {
    while (true) {
        searched[u] = true;
        int next = -1;
        for (auto v : g[u]) {
            if (!visited[v] && !searched[v]) {
                next = v;
                break;
            }
        }
        if (next == -1) return u;
        else u = next;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s;
    cin >> n >> m >> s;
    visited.resize(n + 1);
    searched.resize(n + 1);
    g.resize(n + 1);
    trg.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        trg[v].pb(u);
    }
    clean(s);
    int erc = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            clean(search(i));
            erc++;
        }
    }

    cout << erc << endl;
}