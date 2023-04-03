#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

struct segtree {
    int size;
    vector<ll> vec;
    segtree(const vector<int>& o) : size(o.size()), vec(4 * o.size()) { build(o, 0, 0, size); }
    void build(const vector<int>& o, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = o[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(o, 2 * x + 1, lx, m);
        build(o, 2 * x + 2, m, rx);
        vec[x] = vec[2 * x + 1] + vec[2 * x + 2];
    }

    ll get(int l, int r) { return get(l, r, 0, 0, size); }
    ll get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return vec[x];
        int m = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, m) + get(l, r, 2 * x + 2, m, rx);
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }
    void set(int i, int v, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        vec[x] = vec[2 * x + 1] + vec[2 * x + 2];
    }
};


int main() {
    speed;
    int n, x, y, z;
    cin >> n >> x;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    segtree st(v);
    while (cin >> x >> y >> z) {
        if (x == 1) st.set(y - 1, z);
        else cout << st.get(y - 1, z) << '\n';
    }
}