#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
  segtree *lc{}, *rc{};
  int lx, rx;
  ll val = 0;
  segtree(int lx, int rx) : lx{lx}, rx{rx} {}

  void ensure_children() {
    int m = (lx + rx) / 2;
    if (!lc)
      lc = new segtree(lx, m);
    if (!rc)
      rc = new segtree(m, rx);
  }

  ll get(int l, int r) {
    if (rx <= l || r <= lx)
      return 0;
    if (l <= lx && rx <= r)
      return val;
    ensure_children();
    return max(lc->get(l, r), rc->get(l, r));
  }
  void set(int i, ll v) {
    if (lx + 1 == rx) {
      val = max(val, v);
      return;
    }
    ensure_children();
    if (i < lc->rx)
      lc->set(i, v);
    else
      rc->set(i, v);
    val = max(lc->val, rc->val);
  }
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<array<int, 3>> v(n);
  for (auto &[s, e, w] : v)
    cin >> s >> e >> w;
  sort(v.begin(), v.end());
  segtree st(0, 1e9 + 1);
  for (auto &[s, e, w] : v) {
    ll a = st.get(0, s);
    st.set(e, a + w);
  }
  cout << st.get(0, 1e9 + 1);
}
