
#include <bits/stdc++.h>
#define int int64_t

const int BIG = 1e16;

using namespace std;

int read_pizza() {
  int res = 0;
  int k;
  cin >> k;
  while (k--) {
    int mat;
    cin >> mat;
    res |= (1ll << mat);
  }
  return res;
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  vector<int> add_cost(n), del_cost(n);
  for (int i = 0; i < n; i++) cin >> add_cost[i] >> del_cost[i];

  auto get_neis = [&](int p) {
    vector<pair<int, int>> neis;
    for (int i = 0; i < n; i++) {
      int b = 1ll << i;
      if (p & b) neis.push_back({del_cost[i], p - b});
      else neis.push_back({add_cost[i], p + b});
    }
    return neis;
  };

  vector<int> dist(1ll << n, BIG);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  while (m--) {
    int p = read_pizza();
    dist[p] = 0;
    pq.push({0, p});
  }

  while (!pq.empty()) {
    auto [d, p] = pq.top();
    pq.pop();
    if (d > dist[p]) continue;
    for (auto [w, p2] : get_neis(p)) {
      if (dist[p2] > dist[p] + w) {
        dist[p2] = dist[p] + w;
        pq.push({dist[p2], p2});
      }
    }
  }

  while (q--) {
    int p = read_pizza();
    cout << dist[p] << '\n';
  }
}
