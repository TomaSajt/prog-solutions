#include <bits/stdc++.h>
using namespace std;

vector<int> g[500001];
int sz[500001];
int ch[500001];
int cnt[500001][26];
vector<int> vert_query_inds[500001];
bool query_sols[500001];
int query_deps[500001];

void setup_sz(int u) {
  sz[u] = 1;
  for (int v : g[u]) {
    setup_sz(v);
    sz[u] += sz[v];
  }
}

bool check_palin(int dep) {
  bool was_odd = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[dep][i] % 2 == 0) continue;
    if (was_odd) return 0;
    was_odd = 1;
  }
  return 1;
}

void cnt_st(int u, int dep, int diff) {
  cnt[dep][ch[u]] += diff;
  for (int v : g[u]) {
    cnt_st(v, dep + 1, diff);
  }
}

void dfs(int u, int dep, bool keep) {
  int big_child = -1;
  for (int v : g[u]) {
    if (sz[v] > sz[big_child]) big_child = v;
  }
  for (int v : g[u]) {
    if (v != big_child) dfs(v, dep + 1, 0);
  }

  if (big_child != -1) dfs(big_child, dep + 1, 1);
  for (int v : g[u]) {
    if (v != big_child) cnt_st(v, dep + 1, 1);
  }
  cnt[dep][ch[u]]++;
  // cnt is correct at this point

  for (int i : vert_query_inds[u]) {
    query_sols[i] = check_palin(query_deps[i]);
  }

  if (!keep) cnt_st(u, dep, -1);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;

  for (int u = 2; u <= n; u++) {
    int p;
    cin >> p;
    g[p].push_back(u);
  }
  setup_sz(1);

  for (int u = 1; u <= n; u++) {
    char c;
    cin >> c;
    ch[u] = c - 'a';
  }

  for (int i = 0; i < m; i++) {
    int u;
    cin >> u >> query_deps[i];
    vert_query_inds[u].push_back(i);
  }

  dfs(1, 1, 0);

  for (int i = 0; i < m; i++) {
    cout << (query_sols[i] ? "Yes\n" : "No\n");
  }
}
