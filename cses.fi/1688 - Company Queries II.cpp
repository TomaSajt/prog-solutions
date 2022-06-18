#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;

int jump[200001][19], be[200001], ki[200001], n, q, t = 1;
vector<int> g[200001];

inline bool is_ancestor(int anc, int desc) {
    return be[anc] <= be[desc] && be[desc] <= ki[anc];
}

void dfs(int u) {
    be[u] = t++;
    for (int v : g[u]) {
        if (be[v]) continue;
        dfs(v);
    }
    ki[u] = t++;
}

int solve(int a, int b) {
    if (is_ancestor(b, a)) return b;
    if (is_ancestor(a, b)) return a;
    for (int i = 18; i >= 0;i--) {
        if (jump[a][i] && !is_ancestor(jump[a][i], b)) a = jump[a][i];
    }
    return jump[a][0];
}

int main() {
    speed;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> jump[i][0];
        g[jump[i][0]].pb(i);
    }
    dfs(1);
    for (int j = 1;j <= 18;j++) {
        for (int i = 1; i <= n; i++) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
}