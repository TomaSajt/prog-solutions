#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct seg_tree {
  int val{INT_MAX};
  seg_tree *lc{}, *rc{};
  int lx, rx;
  seg_tree(int lx, int rx) : lx{lx}, rx{rx} {}

  void ensure_children_exist() {
    int m = (lx + rx) / 2;
    if (!lc)
      lc = new seg_tree(lx, m);
    if (!rc)
      rc = new seg_tree(m, rx);
  }
  int get(int l, int r) {
    if (rx <= l || r <= lx)
      return INT_MAX;
    if (l <= lx && rx <= r)
      return val;
    ensure_children_exist();
    return min(lc->get(l, r), rc->get(l, r));
  }
  void set(int i, int v) {
    if (lx + 1 == rx) {
      val = v;
      return;
    }
    ensure_children_exist();
    if (i < lc->rx)
      lc->set(i, v);
    else
      rc->set(i, v);
    val = min(lc->val, rc->val);
  }
};

int main() {
  cin.tie(0), cin.sync_with_stdio(0);
  int n;
  cin >> n;
  seg_tree st(-100000, 100001);
  int bestI = -1, bestJ = 0;
  for (int i = 0; i < n; i++) {
    int vi;
    cin >> vi;
    int j = st.get(vi + 1, 100001);
    if (st.get(vi, vi + 1) == INT_MAX)
      st.set(vi, i);
    if (j == INT_MAX)
      continue;
    int d = i - j;
    int bestD = bestI - bestJ;
    if (d > bestD || (d == bestD && j < bestJ)) {
      bestI = i, bestJ = j;
    }
  }
  if (bestI == -1) {
    cout << "-1";
    return 0;
  }
  cout << bestJ + 1 << ' ' << bestI + 1;
  return 0;
}
