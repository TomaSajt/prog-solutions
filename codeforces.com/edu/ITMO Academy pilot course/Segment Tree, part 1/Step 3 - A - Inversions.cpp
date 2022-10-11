#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct segtree {
    int size;
    vector<int> vec;
    segtree(int size) : size(size), vec(4 * size, 0) {}
    void set(int i) { set(i, 0, 0, size); }
    void set(int i, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, 2 * x + 1, lx, m);
        else set(i, 2 * x + 2, m, rx);
        vec[x] = vec[2 * x + 1] + vec[2 * x + 2];
    }
    int query(int i) { return query(i, 0, 0, size); }
    int query(int i, int x, int lx, int rx) {
        if (rx <= i) return 0;
        if (i <= lx) return vec[x];
        int m = (lx + rx) / 2;
        return query(i, 2 * x + 1, lx, m) + query(i, 2 * x + 2, m, rx);
    }
};

int main() {
    speed;
    int n;
    cin >> n;
    segtree st(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << st.query(--a) << ' ';
        st.set(a);
    }
}