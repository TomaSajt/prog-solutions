#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<bool> vis;
vector<int> cm, sz;
int c = 0;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    cm[u] = c;
    sz[c]++;
    for (int v : g[u]) dfs(v);
}
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1);
    cm.resize(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        sz.push_back(0);
        dfs(i);
        c++;
    }
    int tar = (n + 1) / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(c + 1));
    dp[0][0] = 1;
    for (int j = 1; j <= c; j++) {
        for (int i = 0; i <= n; i++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= sz[j - 1]) dp[i][j] = dp[i][j] || dp[i - sz[j - 1]][j - 1];
        }
    }
    int curr;
    for (int i = tar; i <= n; i++) {
        if (!dp[i][c]) continue;
        curr = i;
        break;
    }
    cout << curr * 2 - n << '\n';
    set<int> sol;
    for (int j = c; j >= 1; j--) {
        if (dp[curr][j - 1]) continue;
        sol.insert(j - 1);
        curr -= sz[j - 1];
    }
    for (int i = 1; i <= n; i++) {
        if (sol.count(cm[i])) cout << i << ' ';
    }
}