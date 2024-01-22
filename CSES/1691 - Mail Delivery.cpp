#include <bits/stdc++.h>
using namespace std;

vector<set<int>> g;
vector<int> path;

void traverse(int curr) {
  while (!g[curr].empty()) {
    int next = *g[curr].begin();
    g[curr].erase(next);
    g[next].erase(curr);
    traverse(next);
  }
  path.push_back(curr);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  g.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].insert(b);
    g[b].insert(a);
  }

  for (int i = 1; i <= n; i++) {
    if (g[i].size() % 2 != 0) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  traverse(1);

  if (path.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  for (int x : path) cout << x << ' ';
}
