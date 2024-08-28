#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> children;
vector<long long> w, d, max_dom, min_dom;

void calc(int u) {
  for (int v : children[u]) calc(v);

  sort(children[u].begin(), children[u].end(), [&](int v1, int v2) { return max_dom[v1] + min_dom[v1] < max_dom[v2] + min_dom[v2]; });

  max_dom[u] = min_dom[u] = w[u];

  int m = children[u].size();
  for (int i = 0; i < m; i++) {
    int v = children[u][i];

    if (i >= m - d[u]) min_dom[u] -= max_dom[v]; // disagree
    else min_dom[u] += min_dom[v]; // agree

    if (i < d[u]) max_dom[u] -= min_dom[v]; // disagree
    else max_dom[u] += max_dom[v]; // agree
  }
}

int main() {
  int n;
  cin >> n;

  children.resize(n + 1);
  max_dom.resize(n + 1);
  min_dom.resize(n + 1);
  w.resize(n + 1);
  d.resize(n + 1);

  for (int u = 2; u <= n; u++) {
    int p;
    cin >> p;
    children[p].push_back(u);
  }
  for (int u = 1; u <= n; u++) cin >> w[u];
  for (int u = 1; u <= n; u++) cin >> d[u];

  calc(1);
  cout << max(max_dom[1], -min_dom[1]);
}
