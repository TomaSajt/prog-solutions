#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
  int size;
  vector<int> v;
  segtree(int size) : size(size), v(size * 4, INT_MAX) {}
  void set(int i, int val) { set(i, val, 0, 0, size); }

  void set(int i, int val, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      v[x] = val;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      set(i, val, 2 * x + 1, lx, m);
    else
      set(i, val, 2 * x + 2, m, rx);

    v[x] = min(v[2 * x + 1], v[2 * x + 2]);
  }

  int get(int l, int r) { return get(l, r, 0, 0, size); }
  int get(int l, int r, int x, int lx, int rx) {
    if (rx <= l || r <= lx)
      return INT_MAX;
    if (l <= lx && rx <= r)
      return v[x];
    int m = (lx + rx) / 2;
    return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
  }
};

int main() {
  cin.tie(0), cin.sync_with_stdio(0);
  int n;
  cin >> n;
  segtree st(200001);

  int bestDist = -1;
  set<pair<int, int>> sols;

  for (int i = 0; i < n; i++) {
    int vi;
    cin >> vi;
    vi += 100000;
    int j = st.get(vi + 1, 200001);
    if (st.get(vi, vi + 1) == INT_MAX)
      st.set(vi, i);
    if (j == INT_MAX)
      continue;
    int dist = i - j + 1;
    if (dist >= bestDist) {
      if (dist != bestDist)
        sols.clear();
      bestDist = dist;
      sols.insert({j, i});
    }
  }
  if (sols.size() == 0) {
    cout << "-1";
    return 0;
  }
  cout << sols.begin()->first + 1 << ' ' << sols.begin()->second + 1;
  return 0;
}
