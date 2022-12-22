#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct segtree {
    int size;
    vector<long long> val, lazy;
    segtree(int size): size(size), val(4 * size, 0), lazy(4 * size, -1) {}
    void push(int x, int lx, int rx) {
        if (lazy[x] == -1) return;
        val[x] = (rx - lx) * lazy[x];
        if (lx + 1 != rx) {
            lazy[2 * x + 1] = lazy[x];
            lazy[2 * x + 2] = lazy[x];
        }
        lazy[x] = -1;
    }
    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, size);
    }
    void set(int l, int r, int v, int x, int lx, int rx) {
        push(x, lx, rx);
        if (r <= lx || rx <= l) return;
        if (l <= lx && rx <= r) {
            lazy[x] = v;
            push(x, lx, rx);
            return;
        }
        int m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        val[x] = val[2 * x + 1] + val[2 * x + 2];
    }
    long long get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
    long long get(int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (r <= lx || rx <= l) return 0;
        if (l <= lx && rx <= r) return val[x];
        int m = (lx + rx) / 2;
        return get(l, r, 2 * x + 1, lx, m) + get(l, r, 2 * x + 2, m, rx);
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    segtree st(n);
    while (m--) {
        int o, l, r; cin >> o >> l >> r;
        if (o == 1) {
            int v; cin >> v;
            st.set(l, r, v);
        }
        else cout << st.get(l, r) << '\n';
    }
}