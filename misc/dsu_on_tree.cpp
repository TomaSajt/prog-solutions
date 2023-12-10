// https://codeforces.com/blog/entry/44351

#include <bits/stdc++.h>
using namespace std;

vector<int> col, sz, cnt;
vector<vector<int>> g;

void cnt_st(int u, int p, int d) {
  cnt[col[u]] += d;
  for (int v : g[u]) {
    if (v != p) cnt_st(v, u, d);
  }
}

void dfs(int u, int p, bool keep) {
  // cnt is 0'd out
  int big_child = -1;
  for (int v : g[u]) {
    if (v != p && sz[v] > sz[big_child]) big_child = v;
  }
  for (int v : g[u]) {
    if (v != p && v != big_child) dfs(v, u, 0); // doesn't change cnt
  }
  if (big_child != -1) dfs(big_child, u, 1); // cnt is now cnt of big_child
  for (int v : g[u]) {
    if (v != p && v != big_child) cnt_st(v, u, 1); // increase cnt of non-big subtrees
  }
  cnt[col[u]]++;
  // cnt is now correct for u
  if (!keep) {
    cnt[col[u]]--;
    for (int v : g[u]) {
      if (v != p) cnt_st(v, u, -1);
    }
  }
}

int main() {
  // store queries per vertex
}
