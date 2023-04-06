#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {

  vector<ll> data, lazy;
  int size;

  segtree(const vector<int> &vec)
      : data(vec.size() * 4), lazy(vec.size() * 4), size(vec.size()) {
    build(vec, 0, 0, size);
  }

  void build(const vector<int> &vec, int x, int lx, int rx) {
    if (lx + 1 == rx) {
      data[x] = vec[lx];
      return;
    }

    int m = (lx + rx) / 2;
    build(vec, 2 * x + 1, lx, m);
    build(vec, 2 * x + 2, m, rx);

    data[x] = min(data[2 * x + 1], data[2 * x + 2]);
  }

  void push(int x, int lx, int rx) {
    if (lx + 1 != rx) {
      lazy[2 * x + 1] += lazy[x];
      lazy[2 * x + 2] += lazy[x];
      data[2 * x + 1] += lazy[x];
      data[2 * x + 2] += lazy[x];
    }
    lazy[x] = 0;
  }

  ll get(int l, int r) { return get(l, r, 0, 0, size); }

  ll get(int l, int r, int x, int lx, int rx) {
    if (r <= lx || rx <= l)
      return INT_MAX;

    if (l <= lx && rx <= r)
      return data[x];

    push(x, lx, rx);

    int m = (lx + rx) / 2;

    return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
  }

  void inc(int l, int r, int v) { inc(l, r, v, 0, 0, size); }

  void inc(int l, int r, int v, int x, int lx, int rx) {
    if (r <= lx || rx <= l)
      return;

    if (l <= lx && rx <= r) {
      data[x] += v;
      lazy[x] += v;
      return;
    }

    push(x, lx, rx);

    int m = (lx + rx) / 2;

    inc(l, r, v, 2 * x + 1, lx, m);
    inc(l, r, v, 2 * x + 2, m, rx);

    data[x] = min(data[2 * x + 1], data[2 * x + 2]);
  }
};

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &a : v)
    cin >> a;
  segtree st(v);
  int m;
  cin >> m;
  cin.ignore();
  while (m--) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int l, r, v;
    ss >> l >> r;
    if (ss >> v) {
      if (l <= r) {
        st.inc(l, r + 1, v);
      } else {
        st.inc(l, n, v);
        st.inc(0, r + 1, v);
      }
    } else {
      if (l <= r) {
        cout << st.get(l, r + 1) << endl;
      } else {
        cout << min(st.get(l, n), st.get(0, r + 1)) << endl;
      }
    }
  }
}
