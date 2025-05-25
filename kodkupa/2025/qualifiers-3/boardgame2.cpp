#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int n, m;
vector<vector<array<int, 2>>> g;

struct idk {
  bool win;
  int min;
};

map<int, bool> mem;
map<int, int> mem2;
map<int, int> mem3;

bool win_from_here(int u) {
  if (mem.count(u)) return mem[u];

  bool res = false;
  for (auto& [v, w] : g[u]) {
    if (!win_from_here(v)) {
      res = true;
    }
  }

  return mem[u] = res;
}

int min_from_here(int u);
int max_children_min(int u) {
  if (mem2.count(u)) return mem2[u];
  int max_ch = 0;
  for (auto& [v, w] : g[u]) {
    max_ch = max(max_ch, min_from_here(v));
  }
  return mem2[u] = max_ch;
}

int min_from_here(int u) {
  if (mem3.count(u)) return mem3[u];

  int res = LLONG_MAX;
  for (auto& [v, w] : g[u]) {
    if (!win_from_here(v)) {
      res = min(res, w + max_children_min(v));
    }
  }

  return mem3[u] = res;
}

int32_t main() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }

  cout << (win_from_here(1) ? "Alice" : "Bob") << '\n';
  cout << (win_from_here(1) ? min_from_here(1) : max_children_min(1));
}
