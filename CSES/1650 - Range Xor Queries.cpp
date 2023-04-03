#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct segtree {
    int size;
    vector<int> vec;
    segtree(const vector<int>& o) : size(o.size()), vec(4 * o.size()) { build(o, 0, 0, size); }
    void build(const vector<int>& o, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = o[lx];
            return;
        }
        int mid = (lx + rx) / 2;
        build(o, 2 * x + 1, lx, mid);
        build(o, 2 * x + 2, mid, rx);
        vec[x] = vec[2 * x + 1] ^ vec[2 * x + 2];
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return 0;
        if (l <= lx && rx <= r) return vec[x];
        int mid = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, mid) ^ get(l, r, 2 * x + 2, mid, rx);
    }
};

int main() {
    speed;
    int n, x, y;
    cin >> n >> x;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    segtree st(v);
    while (cin >> x >> y) cout << st.get(x - 1, y) << '\n';
}