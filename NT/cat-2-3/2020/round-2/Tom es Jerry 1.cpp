#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n, m, tom_start, attempts, goal;
  cin >> n >> m >> tom_start >> attempts >> goal;
  vector<vector<int>> graph(n + 1), tom_graph(n + 1);
  while (m--) {
    int u, v, s;
    cin >> u >> v >> s;
    graph[u].push_back(v);
    graph[v].push_back(u);
    if (s == 2) {
      tom_graph[u].push_back(v);
      tom_graph[v].push_back(u);
    }
  }

  vector<int> dist_from_tom(n + 1, INT_MAX);
  queue<int> tq;
  tq.push(tom_start);
  dist_from_tom[tom_start] = 0;
  while (!tq.empty()) {
    int u = tq.front();
    tq.pop();
    for (auto v : tom_graph[u]) {
      if (dist_from_tom[v] != INT_MAX)
        continue;
      dist_from_tom[v] = dist_from_tom[u] + 1;
      tq.push(v);
    }
  }
  vector<bool> can_jerry_start_at(n + 1);
  can_jerry_start_at[goal] = true;
  priority_queue<array<int, 2>> pq;
  pq.push({dist_from_tom[goal], goal});
  while (!pq.empty()) {
    auto [u_t, u] = pq.top();
    pq.pop();
    if (u_t < 0)
      continue;
    can_jerry_start_at[u] = true;
    for (int v : graph[u]) {
      if (can_jerry_start_at[v])
        continue;
      // jerry should be at position `v`
      // not later than `T = dist_from_tom[v] - 1` to avoid getting caught
      // not later than `T = u_t - 1` so that they can step to `u` right after
      pq.push({min(dist_from_tom[v] - 1, u_t - 1), v});
    }
  }

  while (attempts--) {
    int jerry_start;
    cin >> jerry_start;
    cout << (can_jerry_start_at[jerry_start] ? "IGEN" : "NEM") << endl;
  }
}
