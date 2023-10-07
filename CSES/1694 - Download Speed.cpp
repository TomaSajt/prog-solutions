#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> capacity;
vector<int> parent;

int n;

ll augment(int s, int t) {
  parent.assign(n + 1, 0);
  queue<pair<int, ll>> q;
  q.push({s, LLONG_MAX});
  parent[s] = s;
  while (!q.empty()) {
    auto [u, flow] = q.front();
    q.pop();
    for (int v = 1; v <= n; v++) {
      if (!capacity[u][v] || parent[v]) continue;
      parent[v] = u;
      ll new_flow = min(flow, capacity[u][v]);
      if (v == t) return new_flow;
      q.push({v, new_flow});
    }
  }
  return 0;
}

ll max_flow(int s, int t) {
  ll res = 0;
  while (true) {
    ll flow = augment(s, t);
    if (flow == 0) break;
    int u = t;
    res += flow;
    while (u != s) {
      int v = parent[u];
      capacity[v][u] -= flow;
      capacity[u][v] += flow;
      u = v;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int m;
  cin >> n >> m;
  capacity.resize(n + 1, vector<ll>(n + 1, 0));
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    capacity[u][v] += c;
  }
  cout << max_flow(1, n);
}
