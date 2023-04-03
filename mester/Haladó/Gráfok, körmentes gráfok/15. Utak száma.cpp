#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
#define int long long

#define MOD 100000007

vector<vector<int> > g, gt;
vector<int> entered;
stack<int> t;

void dfs(int u) {
    entered[u] = 1;
    for (int w : g[u])
        if (!entered[w]) dfs(w);
    t.push(u);
}

#undef int
int main() {
#define int long long
    speed;
    int n, m, s, c;
    cin >> n >> m >> s >> c;
    
    g.resize(n + 1), gt.resize(n + 1), entered.resize(n + 1);
    vector<int> utak(n + 1, 0);
    utak[s] = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        gt[b].pb(a);
    }
    dfs(s);
    while (!t.empty()) {
        int i = t.top();
        t.pop();
        for (int a : gt[i]) utak[i] += utak[a], utak[i] %= MOD;
    }
    cout << utak[c] << endl;
}

