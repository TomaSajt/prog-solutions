#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  // dependency graph where edge `i-->j` means `j` depends on `i`
  // `i = 2 * a` is the appearance of the `a` species
  // `i = 2 * a + 1` is the extinction of the `a` species
  vector<vector<int>> g(2 * n);

  // number of dependencies of node `i`
  vector<int> deps(2 * n);

  auto makeEdge = [&](int u, int v) {
    g[u].push_back(v);
    deps[v]++;
  };

  for (int i = 0; i < n; i++) {
    // `i` had to have appeared before going extinct
    makeEdge(2 * i, 2 * i + 1);
  }

  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;
    --a, --b;
    if (op == 1) {
      // `b` appeared before `a` went extinct
      makeEdge(2 * b, 2 * a + 1);
      // `a` appeared before `b` went extinct
      makeEdge(2 * a, 2 * b + 1);
    } else {
      // `a` went extinct before `b` appeared
      makeEdge(2 * a + 1, 2 * b);
    }
  }

  // try to traverse DAG

  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (deps[2 * i] == 0) {
      q.push(2 * i);
    }
  }

  int t = 0;
  vector<int> pos(2 * n);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    pos[u] = ++t;
    for (int v : g[u]) {
      if (--deps[v] == 0) {
        q.push(v);
      }
    }
  }

  // if not all nodes were traversed, it is impossible
  if (t != 2 * n) {
    cout << "NEM";
    return 0;
  }

  cout << "IGEN";
  for (int i = 0; i < n; i++) {
    cout << '\n' << pos[2 * i] << ' ' << pos[2 * i + 1];
  }
}
