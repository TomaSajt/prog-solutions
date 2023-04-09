#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<bool> vis;

int dfs(int u) {
  if (vis[u])
    return u;
  vis[u] = 1;
  return dfs(par[u]);
}

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<bool> is_par(n + 1);
  par.resize(n + 1), vis.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> par[i];
    is_par[par[i]] = 1;
  }

  vector<int> beg, fin;

  // process non-cycles
  for (int i = 1; i <= n; i++) {
    if (is_par[i] || vis[i])
      continue;
    beg.push_back(i);
    fin.push_back(dfs(i));
  }

  // also process cycles
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    beg.push_back(i);
    fin.push_back(dfs(i));
  }

  int l = beg.size();

  // if every node is in one big cycle
  if (l == 1 && beg[0] == fin[0]) {
    cout << '0';
    return 0;
  }

  cout << l;
  for (int i = 0; i < l; i++) {
    cout << '\n' << fin[i] << ' ' << beg[(i + 1) % l];
  }
}
