#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int n;
void calcDist(const vector<vector<int>>& g, vector<int>& dist, int s) {
    queue<int> q;
    q.push(s);
    dist.assign(n + 1, -1);
    dist[s] = 0;
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        for (int nei : g[curr]) {
            if (dist[nei] != -1) continue;
            dist[nei] = dist[curr] + 1;
            q.push(nei);
        }
    }
}
int main() {
    speed;
    int m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dista, distb;
    calcDist(g, dista, a);
    calcDist(g, distb, b);
    vector<pair<int, int>> indCombo(n);
    for (int i = 1; i <= n; i++) {
        indCombo[i - 1] = { dista[i] - distb[i],i };
    }
    sort(indCombo.begin(), indCombo.end());
    vector<int> isA(n + 1);
    for (int j = 0; j < n; j++) {
        auto [d, i] = indCombo[j];
        isA[i] = j < n / 2;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) res += isA[i] ? dista[i] : distb[i];
    cout << res << '\n';
    for (int i = 1; i <= n; i++) cout << "BA"[isA[i]];
}