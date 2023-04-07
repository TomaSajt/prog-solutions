#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct segtree {
    int size;
    vector<int> data;
    segtree(int size) : size(size), data(4 * size, INT_MAX) {}
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            data[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        data[x] = min(data[2 * x + 1], data[2 * x + 2]);
    }
    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
    int get(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return INT_MAX;
        if (l <= lx && rx <= r) return data[x];
        int m = (lx + rx) / 2;
        return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }
};

int main() {
    speed;
    int n;
    cin >> n;
    segtree st(n);
    int s = -1, si, sj;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        int j = st.get(a, n);
        if (j != INT_MAX) {
            if (i - j > s) {
                s = i - j;
                si = i;
                sj = j;
            }
        }
        st.set(a, i);
    }
    if (s == -1) cout << "-1";
    else cout << sj + 1 << ' ' << si + 1;
}