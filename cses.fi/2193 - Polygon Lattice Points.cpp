#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
struct point { ll x, y; };
int main() {
    speed;
    int n; cin >> n;
    vector<point> v(n);
    for (auto& p : v) cin >> p.x >> p.y;
    ll area2 = 0;
    ll b = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area2 += (v[i].x - v[j].x) * (v[i].y + v[j].y);
        b += gcd(abs(v[i].x - v[j].x), abs(v[i].y - v[j].y));
    }
    area2 = abs(area2);
    // Picks theorem: A = i + b/2 - 1
    // Therefore 2i = 2A - b + 2
    cout << (area2 - b) / 2 + 1 << ' ' << b;
}