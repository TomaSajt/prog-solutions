#include<bits/stdc++.h>
using namespace std;
struct point { long long x, y; };
int n;
vector<point> p;
inline bool online(int a, int b, int c) { return (p[c].y - p[a].y) * (p[a].x - p[b].x) == (p[c].x - p[a].x) * (p[a].y - p[b].y); }
bool check(int a, int b) {
    vector<int> r;
    for (int i = 0;i < n;i++) {
        if (i != a && i != b && !online(a, b, i)) r.push_back(i);
    }
    if (r.size() < 3) return true;
    for (int i = 2;i < r.size();i++) {
        if (!online(r[0], r[1], r[i])) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    p.resize(n);
    for (auto& a : p) cin >> a.x >> a.y;
    cout << (n < 5 || check(0, 1) || check(0, 2) || check(1, 2) ? "YES" : "NO");
}