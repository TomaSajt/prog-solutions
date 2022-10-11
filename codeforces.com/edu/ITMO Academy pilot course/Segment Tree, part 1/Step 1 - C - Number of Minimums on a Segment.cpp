#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef pair<int, int> pii;

struct segtree {
    int size;
    vector<pii> mins;
    segtree(const vector<int>& vec) : size(vec.size()), mins(4 * vec.size()) {
        build(vec, 0, 0, size);
    }
    void build(const vector<int>& vec, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            mins[x] = { vec[lx],1 };
            return;
        }
        int mid = (lx + rx) / 2;
        build(vec, 2 * x + 1, lx, mid);
        build(vec, 2 * x + 2, mid, rx);
        mins[x] = op(mins[2 * x + 1], mins[2 * x + 2]);
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            mins[x] = { v,1 };
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) set(i, v, 2 * x + 1, lx, mid);
        else set(i, v, 2 * x + 2, mid, rx);
        mins[x] = op(mins[2 * x + 1], mins[2 * x + 2]);
    }
    pii query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
    pii query(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return { INT_MAX,0 };
        if (l <= lx && rx <= r) return mins[x];
        int mid = (lx + rx) / 2;
        return op(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid, rx));
    }
    pii op(const pii& a, const pii& b) {
        auto [min1, cnt1] = a;
        auto [min2, cnt2] = b;
        if (min1 < min2) return { min1,cnt1 };
        if (min1 > min2) return { min2,cnt2 };
        return { min1,cnt1 + cnt2 };
    }
};


int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    segtree st(v);
    while (m--) {
        int o, x, y;
        cin >> o >> x >> y;
        if (o == 1) st.set(x, y);
        else {
            auto [mi, cnt] = st.query(x, y);
            cout << mi << ' ' << cnt << '\n';
        }
    }
}