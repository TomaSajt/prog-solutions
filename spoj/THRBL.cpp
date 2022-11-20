#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct segtree {
    vector<int> vec;
    int size;
    segtree(const vector<int>& o) : vec(4 * o.size()), size(o.size()) { build(o, 0, 0, size); }
    void build(const vector<int>& o, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = o[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(o, 2 * x + 1, lx, m);
        build(o, 2 * x + 2, m, rx);
        vec[x] = max(vec[2 * x + 1], vec[2 * x + 2]);
    }
    int get(int l, int r) { return get(l, r, 0, 0, size); }
    int get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return INT_MIN;
        if (l <= lx && rx <= r) return vec[x];
        int m = (lx + rx) / 2;
        return max(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    segtree st(v);
    int l, r, res = 0;
    while (cin >> l >> r) {
        if (v[l - 1] >= st.get(l, r - 1)) res++;
    }
    cout << res;
}