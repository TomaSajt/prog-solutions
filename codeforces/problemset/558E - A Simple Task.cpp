#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

class segtree {
    char ch;
    int size;
    vector<int> vec;
    vector<int> lazy;
    void build(const string& str, int x, int lx, int rx) {
        if (lx + 1 == rx) {
            if (str[lx] == ch) vec[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(str, x * 2 + 1, lx, m);
        build(str, x * 2 + 2, m, rx);
        vec[x] = vec[x * 2 + 1] + vec[x * 2 + 2];
    }
    void push(int x, int lx, int rx) {
        vec[x] = lazy[x] * (rx - lx);
        if (lx + 1 != rx) {
            lazy[x * 2 + 1] = lazy[x];
            lazy[x * 2 + 2] = lazy[x];
        }
        lazy[x] = -1;
    }
    void set_range(int l, int r, int val, int x, int lx, int rx) {
        if (lazy[x] != -1) push(x, lx, rx);
        if (l <= lx && rx <= r) {
            lazy[x] = val;
            push(x, lx, rx); // also push because we need vec[x] to be calculated to be used after returning
            return;
        }
        if (r <= lx || rx <= l) return;
        int m = (lx + rx) / 2;
        set_range(l, r, val, x * 2 + 1, lx, m);
        set_range(l, r, val, x * 2 + 2, m, rx);
        vec[x] = vec[x * 2 + 1] + vec[x * 2 + 2];
    }
    int get_range(int l, int r, int x, int lx, int rx) {
        if (lazy[x] != -1) push(x, lx, rx);
        if (l <= lx && rx <= r) return vec[x];
        if (r <= lx || rx <= l) return 0;
        int m = (lx + rx) / 2;
        return get_range(l, r, x * 2 + 1, lx, m) + get_range(l, r, x * 2 + 2, m, rx);
    }
    void make_str(string& str, int x, int lx, int rx) {
        if (lazy[x] != -1) push(x, lx, rx);
        if (vec[x] == 0) return; // no 1 in interval
        if (lx + 1 == rx) {
            str[lx] = ch;
            return;
        }
        int m = (lx + rx) / 2;
        make_str(str, x * 2 + 1, lx, m);
        make_str(str, x * 2 + 2, m, rx);
    }
public:
    segtree(const string& str, char ch) : ch(ch), size(str.size()), vec(str.size() * 4), lazy(str.size() * 4, -1) { build(str, 0, 0, size); }
    void set_range(int l, int r, int val) { set_range(l, r, val, 0, 0, size); }
    int get_range(int l, int r) { return get_range(l, r, 0, 0, size); }
    void make_str(string& str) { make_str(str, 0, 0, size); }
};

int main() {
    int n, q;
    string str;
    vector<segtree> stv;
    cin >> n >> q >> str;
    for (int i = 0; i < 26; i++) stv.emplace_back(str, 'a' + i);
    while (q--) {
        int l, r, inc;
        cin >> l >> r >> inc; l--;
        int curr = l;
        for (int i = 0; i < 26; i++) {
            int j = inc ? i : 25 - i;
            int cnt = stv[j].get_range(l, r);
            if (!cnt) continue;
            stv[j].set_range(l, r, 0);
            stv[j].set_range(curr, curr + cnt, 1);
            curr += cnt;
        }
    }
    for (int i = 0; i < 26; i++) stv[i].make_str(str);
    cout << str;
    return 0;
}