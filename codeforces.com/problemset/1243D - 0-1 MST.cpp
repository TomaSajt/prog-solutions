// Progtábor 6 - Csapatverseny E
#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize ("O3")

vector<int> parent;
vector<int> siz;
set<int> compsLastEl;

int holvan(int a) {
    if (parent[a] == a) return a;
    return parent[a] = holvan(parent[a]);
}

void unio(int a, int b) {
    a = holvan(a);
    b = holvan(b);
    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
    siz.resize(n + 1, 1);
    int compCount = n;
    vector<vector<int> > g(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        map<int, int> cec;
        for (int u : g[i]) {
            if (u < i) cec[holvan(u)]++;
        }
        for (auto it = compsLastEl.begin(); it != compsLastEl.end();) {
            int compRoot = holvan(*it);
            int cnt = cec[compRoot];
            if (cnt < siz[compRoot]) {
                unio(i, compRoot);
                compsLastEl.erase(it++);
                compCount--;
            }
            else ++it;
        }
        compsLastEl.insert(i);
    }
    cout << compCount - 1;
}