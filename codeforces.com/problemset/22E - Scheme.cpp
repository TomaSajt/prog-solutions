#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

vector<int> par, beg, fin;
vector<bool> vis;

void dfs(int u) {
    if (vis[u]) {
        fin.push_back(u);
        return;
    }
    vis[u] = 1;
    dfs(par[u]);
}

int main() {
    speed;
    int n;
    cin >> n;
    vector<bool> ispar(n + 1);
    vis.resize(n + 1);
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> par[i];
        ispar[par[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (ispar[i] || vis[i]) continue;
        beg.push_back(i);
        dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        beg.push_back(i);
        dfs(i);
    }
    int l = beg.size();
    if (l == 1 && beg[0] == fin[0]) {
        cout << '0';
        return 0;
    }
    cout << l << '\n';
    for (int i = 0; i < l; i++) {
        cout << fin[i] << ' ' << beg[(i + 1) % l] << '\n';
    }
}