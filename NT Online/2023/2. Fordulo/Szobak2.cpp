#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> val, valAcc, exits;
vector<vector<int>> g;
void dfs(int u) {
    for (auto v : g[u]) {
        valAcc[v] = valAcc[u] + val[v];
        dfs(v);
    }
}
int main() {
    speed;
    int n;
    cin >> n;
    g.resize(n + 1), val.resize(n + 1), valAcc.resize(n + 1);
    vector<int> exits;
    for (int i = 1, l, r; i <= n; i++) {
        cin >> val[i] >> r >> l;
        if (r >= 1) g[i].push_back(r);
        if (l >= 1) g[i].push_back(l);
        if (r == 0) exits.push_back(i);
        if (l == 0) exits.push_back(i);
    }
    valAcc[1] = val[1];
    dfs(1);
    int best = 0;
    for (auto i : exits) best = max(best, valAcc[i]);
    cout << best;
}