#include <bits/stdc++.h>
using namespace std;
struct p {
    long long x, y;
};
inline long long rightness(const p& o, const p& a, const p& b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<p> v(n);
    for (auto& p : v) cin >> p.x >> p.y;
    string s; cin >> s;
    int a = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i].x > v[a].x) a = i;
    }
    vector<bool> used(n);
    used[a] = 1;
    cout << a + 1;
    for (int j = 0, b; j < n - 1; j++, a = b) {
        b = -1;
        int sign = s[j] == 'L' ? 1 : -1;
        for (int i = 0; i < n;i++) {
            if (!used[i] && (b == -1 || rightness(v[a], v[i], v[b]) * sign > 0)) b = i;
        }
        used[b] = 1;
        cout << ' ' << b + 1;
    }
}