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
        vec[x] = max(vec[2 * x + 1], vec[2 * x + 2]);
    }
    void dec(int i, int d) {
        dec(i, d, 0, 0, size);
    }
    void dec(int i, int d, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] -= d;
            return;
        }
        int mid = (lx + rx) / 2;
        if (i < mid) dec(i, d, 2 * x + 1, lx, mid);
        else dec(i, d, 2 * x + 2, mid, rx);
        vec[x] = max(vec[2 * x + 1], vec[2 * x + 2]);
    }
    int find(int n) {
        return find(n, 0, 0, size);
    }
    int find(int n, int x, int lx, int rx) {
        if (vec[x] < n) return -1;
        if (lx + 1 == rx) return lx;
        int mid = (lx + rx) / 2;
        if (vec[2 * x + 1] >= n) return find(n, 2 * x + 1, lx, mid);
        return find(n, 2 * x + 2, mid, rx);
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
        int r;
        cin >> r;
        int i = st.find(r);
        cout << i + 1 << ' ';
        if (i != -1) st.dec(i, r);
    }
}