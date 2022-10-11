#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

template<typename T>
struct segtree {
    int size;
    vector<T> vec;
    std::function<T(T, T)> op;
    T neutral;
    segtree(const vector<T>& o, const T& neutral, std::function<T(T, T)> op) : size(o.size()), vec(4 * o.size()), op(op), neutral(neutral) { build(o, 0, 0, size); }
    void set(int i, T v) { set(i, v, 0, 0, size); }
    T query(int l, int r) { return query(l, r, 0, 0, size); }
private:
    void build(const vector<T>& o, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = o[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(o, 2 * x + 1, lx, m);
        build(o, 2 * x + 2, m, rx);
        vec[x] = op(vec[2 * x + 1], vec[2 * x + 2]);
    }
    void set(int i, T v, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            vec[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        vec[x] = op(vec[2 * x + 1], vec[2 * x + 2]);
    }
    T query(int l, int r, int x, int lx, int rx) {
        if (rx <= l || r <= lx) return neutral;
        if (l <= lx && rx <= r) return vec[x];
        int m = (lx + rx) / 2;
        return op(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (auto& a : v) cin >> a;
    segtree<ll> st(v, 0ll, [](ll a, ll b) { return a + b; });
    while (m--) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 1) st.set(a, b);
        else cout << st.query(a, b) << '\n';
    }
}