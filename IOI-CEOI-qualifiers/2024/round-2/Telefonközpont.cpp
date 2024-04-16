#include <bits/stdc++.h>
#define int long long
using namespace std;

struct segtree {
  int len = 0;
  vector<int> v;

  segtree(const vector<int>& data)
      : len(data.size()), v(data.size() * 4, INT_MIN) {
    build(data, 0, len, 0);
  }

  void build(const vector<int>& data, int lx, int rx, int x) {
    if (lx + 1 == rx) {
      v[x] = data[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(data, lx, m, 2 * x + 1);
    build(data, m, rx, 2 * x + 2);
    v[x] = max(v[2 * x + 1], v[2 * x + 2]);
  }

  int get(int ql, int qr) {
    return get(ql, qr, 0, len, 0);
  }

  int get(int ql, int qr, int xl, int xr, int x) {
    if (qr <= xl || xr <= ql) return INT_MIN;
    if (ql <= xl && xr <= qr) return v[x];
    int m = (xl + xr) / 2;
    return max(get(ql, qr, xl, m, 2 * x + 1), get(ql, qr, m, xr, 2 * x + 2));
  }
};

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int m, n, q;
  cin >> m >> n >> q;

  vector<int> diffs(m + 2), x(m + 2);
  while (n--) {
    int s, e;
    cin >> s >> e;
    diffs[s]++;
    diffs[e + 1]--;
  }

  partial_sum(diffs.begin(), diffs.end(), x.begin());
  segtree st(x);

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << st.get(l, r + 1) << '\n';
  }
}
