#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

vector<vector<ll>> capacity;
vector<vector<int>> graph;
vector<int> parent;

int n, m;

ll bfs(int s, int t) {
    parent.assign(n + 1, -1);
    queue<pair<int, ll>> q;
    q.push({ s, LLONG_MAX });
    parent[s] = -2;
    while (!q.empty()) {
        auto [u, flow] = q.front(); q.pop();
        for (int v : graph[u]) {
            if (parent[v] == -1 && capacity[u][v] > 0) {
                parent[v] = u;
                ll new_flow = min(flow, capacity[u][v]);
                if (v == t) return new_flow;
                q.push({ v, new_flow });
            }
        }
    }
    return 0;
}

ll max_flow(int s, int t) {
    ll maxFlow = 0;
    while (true) {
        ll flow = bfs(s, t);
        if (flow == 0) break;
        int u = t;
        maxFlow += flow;
        while (u != s) {
            int v = parent[u];
            capacity[v][u] -= flow;
            capacity[u][v] += flow;
            u = v;
        }
    }
    return maxFlow;
}

int main() {
    speed;
    cin >> n >> m;
    capacity.resize(n + 1, vector<ll>(n + 1, 0));
    graph.resize(n + 1);
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] += c;
    }
    cout << max_flow(1, n);
}