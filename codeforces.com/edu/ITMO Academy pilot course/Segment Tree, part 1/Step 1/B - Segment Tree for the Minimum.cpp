// This solution uses a dynamic segtree, because why not

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

struct Node {
    int lx, rx;
    Node* lc{}, * rc{};
    int val{ INT_MAX };
    Node(int lx, int rx): lx{ lx }, rx{ rx } {}
    void extend() {
        int m = (lx + rx) / 2;
        lc = lc ? lc : new Node{ lx, m };
        rc = rc ? rc : new Node{ m, rx };
    }
    void set(int i, int v) {
        if (lx + 1 == rx) {
            val = v;
            return;
        }
        extend();
        int m = (lx + rx) / 2;
        if (i < m) lc->set(i, v);
        else rc->set(i, v);
        val = min(lc->val, rc->val);
    }
    int get(int l, int r) {
        if (rx <= l || r <= lx) return INT_MAX;
        if (l <= lx && rx <= r) return val;
        extend();
        return min(lc->get(l, r), rc->get(l, r));
    }
};

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    Node root{ 0, n };
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