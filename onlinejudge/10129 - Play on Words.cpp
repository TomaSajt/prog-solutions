#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int v : g[u]) dfs(v);
}

bool solve() {
    int n; cin >> n;
    g.assign(26, {});
    vis.assign(26, 0);
    vector<int> indeg(26), outdeg(26);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int u = s[0] - 'a';
        int v = s.back() - 'a';
        g[u].push_back(v);
        outdeg[u]++;
        indeg[v]++;
    }
    int start = -1;
    int sc = 0, ec = 0, nzc = 0;
    for (int i = 0; i < 26; i++) {
        if (outdeg[i] > 0 || indeg[i] > 0) {
            nzc++;
            if (start == -1) start = i;
        }
        int d = outdeg[i] - indeg[i];
        if (d == 0) continue;
        if (d == 1) sc++, start = i;
        else if (d == -1) ec++;
        else return 0;
    }
    if (!((sc == 0 && ec == 0) || (sc == 1 && ec == 1))) return 0;
    dfs(start);
    if (count(vis.begin(), vis.end(), 1) != nzc) return 0;
    return 1;
}
int main() {
    speed;
    int t; cin >> t;
    while (t--) cout << (solve() ? "Ordering is possible." : "The door cannot be opened.") << '\n';
}