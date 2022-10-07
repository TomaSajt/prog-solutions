#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({ v,0 });
        g[v].push_back({ u,1 });
    }
    deque<int> dq{ 1 };
    vector<int> revc(n + 1, -1);
    revc[1] = 0;
    while (!dq.empty()) {
        int u = dq.back(); dq.pop_back();
        if (u == n) break;
        for (auto [v, w] : g[u]) {
            int c = revc[u] + w;
            if (revc[v] > c || revc[v] == -1) {
                revc[v] = c;
                if (w) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    cout << revc[n];
}