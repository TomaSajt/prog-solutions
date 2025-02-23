#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = LLONG_MAX;

vector<vector<int>> g;

vector<int> cols;

void dfs(int u, int c) {
  if (cols[u] != 0) {
    if (cols[u] != c) {
      cout << "-1";
      exit(0);
    }
    return;
  }
  cols[u] = c;
  for (int v : g[u]) {
    dfs(v, 3 - c);
  }
}

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  g.resize(n + 1);
  cols.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int a;
      cin >> a;
      if (a == 1) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (cols[i] == 0) dfs(i, 1);
  }

  cout << count(cols.begin(), cols.end(), 1) << endl;
  for (int i = 1; i <= n; i++) {
    if (cols[i] == 1) {
      cout << i << ' ';
    }
  }
}
