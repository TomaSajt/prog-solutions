#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SZ = 100001, PD = 17, BS = 450;

bool is_toggled[SZ];
int type[SZ], fav[SZ], in_t[SZ], out_t[SZ], cnts[2][SZ], par[SZ][PD];
vector<int> adj[SZ], order;

void dfs(int u, int p) {
  in_t[u] = order.size();
  order.push_back(u);
  par[u][0] = p;
  for (int v : adj[u]) {
    if (par[v][0] == 0) dfs(v, u);
  }
  out_t[u] = order.size();
  order.push_back(u);
}

struct query {
  int lt, rt, i;
  bool needs_lca;

  bool operator<(query other) {
    int b1 = lt / BS, b2 = other.lt / BS;
    if (b1 != b2) return b1 < b2;
    if (b1 % 2 == 0) return rt < other.rt;
    return rt > other.rt;
  }
};

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> type[i];
  for (int i = 1; i <= n; i++) cin >> fav[i];

  // compress fav numbers
  map<int, int> fav_s;
  for (int i = 1; i <= n; i++) {
    if (!fav_s.count(fav[i])) fav_s[fav[i]] = fav_s.size();
    fav[i] = fav_s[fav[i]];
  }

  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);

  // binary lifting
  for (int i = 1; i < PD; i++) {
    for (int u = 1; u <= n; u++) {
      par[u][i] = par[par[u][i - 1]][i - 1];
    }
  }

  auto is_above = [&](int u, int v) {
    return in_t[u] <= in_t[v] && in_t[v] <= out_t[u];
  };

  auto lca = [&](int u, int v) {
    if (is_above(u, v)) return u;
    if (is_above(v, u)) return v;
    for (int i = PD - 1; i >= 0; i--) {
      int uu = par[u][i];
      if (!is_above(uu, v)) u = uu;
    }
    return par[u][0];
  };

  int q;
  cin >> q;
  vector<query> queries(q);
  for (int i = 0; i < q; i++) {
    queries[i].i = i;
    int l, r;
    cin >> l >> r;
    if (in_t[l] > in_t[r]) swap(l, r);
    if (is_above(l, r)) queries[i] = {in_t[l], in_t[r], i, false};
    else queries[i] = {out_t[l], in_t[r], i, true};
  }
  sort(queries.begin(), queries.end());

  vector<ll> sols(q);
  ll curr_sol = 0;
  auto toggle = [&](int u) {
    is_toggled[u] = !is_toggled[u];
    int s = is_toggled[u] ? 1 : -1;
    curr_sol += s * cnts[1 - type[u]][fav[u]];
    cnts[type[u]][fav[u]] += s;
  };

  int curr_l = 1, curr_r = 0;
  for (auto [lt, rt, i, needs_lca] : queries) {
    while (curr_r < rt) toggle(order[++curr_r]);
    while (curr_l < lt) toggle(order[curr_l++]);
    while (curr_r > rt) toggle(order[curr_r--]);
    while (curr_l > lt) toggle(order[--curr_l]);
    int a = lca(order[lt], order[rt]);
    if (needs_lca) toggle(a);
    sols[i] = curr_sol;
    if (needs_lca) toggle(a);
  }
  for (ll sol : sols) cout << sol << '\n';
}
