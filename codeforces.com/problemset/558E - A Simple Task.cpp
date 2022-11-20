#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int tree[400005][26], lazy[400005][26];

void build(const string& str, int x, int lx, int rx) {
    if (lx + 1 == rx) {
        tree[x][str[lx] - 'a'] = 1;
        for (int j = 0; j < 26; j++) lazy[x][j] = -1;
        return;
    }
    int m = (lx + rx) / 2;
    build(str, x * 2 + 1, lx, m);
    build(str, x * 2 + 2, m, rx);
    for (int j = 0; j < 26; j++) {
        lazy[x][j] = -1;
        tree[x][j] = tree[x * 2 + 1][j] + tree[x * 2 + 2][j];
    }
}

void push(int x, int lx, int rx, int j) {
    tree[x][j] = lazy[x][j] * (rx - lx);
    if (lx + 1 != rx) {
        lazy[x * 2 + 1][j] = lazy[x][j];
        lazy[x * 2 + 2][j] = lazy[x][j];
    }
    lazy[x][j] = -1;
}

void set_range(int l, int r, int val, int x, int lx, int rx, int j) {
    if (lazy[x][j] != -1) push(x, lx, rx, j);
    if (l <= lx && rx <= r) {
        lazy[x][j] = val;
        push(x, lx, rx, j);
        return;
    }
    if (r <= lx || rx <= l) return;
    int m = (lx + rx) / 2;
    set_range(l, r, val, x * 2 + 1, lx, m, j);
    set_range(l, r, val, x * 2 + 2, m, rx, j);
    tree[x][j] = tree[x * 2 + 1][j] + tree[x * 2 + 2][j];
}

int get_range(int l, int r, int x, int lx, int rx, int j) {
    if (lazy[x][j] != -1) push(x, lx, rx, j);
    if (l <= lx && rx <= r)
        return tree[x][j];
    if (r <= lx || rx <= l) return 0;
    int m = (lx + rx) / 2;
    return get_range(l, r, x * 2 + 1, lx, m, j) + get_range(l, r, x * 2 + 2, m, rx, j);
}

void make_str(string& str, int x, int lx, int rx, int j) {
    if (lazy[x][j] != -1) push(x, lx, rx, j);
    if (tree[x][j] == 0) return;
    if (lx + 1 == rx) {
        str[lx] = j + 'a';
        return;
    }
    int m = (lx + rx) / 2;
    make_str(str, x * 2 + 1, lx, m, j);
    make_str(str, x * 2 + 2, m, rx, j);
}

int main() {
    int n, q;
    string str;
    cin >> n >> q >> str;
    build(str, 0, 0, n);
    while (q--) {
        int l, r, up;
        cin >> l >> r >> up;
        l--;
        vector<int> cnt(26);
        for (int j = 0; j < 26; j++) cnt[j] = get_range(l, r, 0, 0, n, j);
        int curr = up ? l : r;
        for (int j = 0; j < 26; j++) {
            if (!cnt[j]) continue;
            set_range(l, r, 0, 0, 0, n, j);
            if (up) {
                set_range(curr, curr + cnt[j], 1, 0, 0, n, j);
                curr += cnt[j];
            }
            else {
                set_range(curr - cnt[j], curr, 1, 0, 0, n, j);
                curr -= cnt[j];
            }
        }
    }
    for (int i = 0; i < 26; i++) make_str(str, 0, 0, n, i);
    cout << str;
    return 0;
}