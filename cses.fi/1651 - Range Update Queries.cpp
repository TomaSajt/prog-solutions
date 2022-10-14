#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

struct segtree {
    int size;
    vector<ll> incS;
    segtree(const vector<int>& o) : size(o.size()), incS(4 * o.size()) { build(o, 0, 0, size); }
    void build(const vector<int>& o, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            incS[x] = o[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(o, 2 * x + 1, lx, mid);
        build(o, 2 * x + 2, mid, rx);
    }
    void push(int x) {
        incS[2 * x + 1] += incS[x];
        incS[2 * x + 2] += incS[x];
        incS[x] = 0;
    }
    void inc(int v, int l, int r) { inc(v, l, r, 0, 0, size); }
    void inc(int v, int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return;
        if (l <= lx && rx <= r) {
            incS[x] += v;
            return;
        }
        int mid = (lx + rx) / 2;
        inc(v, l, r, 2 * x + 1, lx, mid);
        inc(v, l, r, 2 * x + 2, mid, rx);
    }
    ll get(int i) { return get(i, 0, 0, size); }
    ll get(int i, int x, int lx, int rx) {
        if (lx + 1 == rx) return incS[x];
        push(x);
        int mid = (lx + rx) / 2;
        if (i < mid) return get(i, 2 * x + 1, lx, mid);
        return get(i, 2 * x + 2, mid, rx);
    }

};

int main() {
    speed;
    int n, o, x, y, z;
    cin >> n >> o;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    segtree st(v);
    while (cin >> o >> x) {
        if (o == 1) {
            cin >> y >> z;
            st.inc(z, x - 1, y);
            continue;
        }
        cout << st.get(x - 1) << '\n';
    }
}