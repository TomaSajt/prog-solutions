#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g; // an a-subgraph-node's neighbours in the b-subgraph
vector<bool> vis;
vector<int> pair_in_a; // a b-supgraph-node's pair in the a-subgraph

bool try_kuhn(int u) { // u is a node from the a-subgraph
  if (vis[u]) return 0;
  vis[u] = 1;
  for (int v : g[u]) { // v is a node from the b-subgraph
    if (pair_in_a[v] == -1 || try_kuhn(pair_in_a[v])) {
      pair_in_a[v] = u;
      return 1;
    }
  }
  return 0;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);
  for (int& ai : a) cin >> ai;
  for (int& bi : b) cin >> bi;

  g.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (__gcd(a[i], b[j]) != 1) g[i].push_back(j);
    }
  }

  int cnt = 0;
  pair_in_a.assign(m, -1);
  for (int i = 0; i < n; i++) {
    vis.assign(n, 0);
    if (try_kuhn(i)) cnt++; // if we found an augmenting path
  }

  cout << n + m - cnt; // Kőnig's theorem
}
