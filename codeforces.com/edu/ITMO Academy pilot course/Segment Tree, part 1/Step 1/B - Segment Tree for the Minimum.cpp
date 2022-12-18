// This solution uses a dynamic segtree, because why not

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct Node {
    int l, r;
    Node* lc{};
    Node* rc{};
    int val{ INT_MAX };
    Node(int l, int r): l{ l }, r{ r } {}
    void extend() {
        int m = (l + r) / 2;
        lc = lc ? lc : new Node(l, m);
        rc = rc ? rc : new Node(m, r);
    }
    void set(int i, int v) {
        if (l + 1 == r) {
            val = v;
            return;
        }
        extend();
        int m = (l + r) / 2;
        if (i < m) lc->set(i, v);
        else rc->set(i, v);
        val = min(lc->val, rc->val);
    }
    int get(int ql, int qr) {
        if (r <= ql || qr <= l) return INT_MAX;
        if (ql <= l && r <= qr) return val;
        extend();
        return min(lc->get(ql, qr), rc->get(ql, qr));
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    Node root(0, n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        root.set(i, a);
    }
    while (m--) {
        int o, a, b; cin >> o >> a >> b;
        if (o == 1) root.set(a, b);
        else cout << root.get(a, b) << '\n';
    }
}