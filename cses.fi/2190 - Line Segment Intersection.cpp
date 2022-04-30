#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
};

bool betw(int a, int b, int n) {
    return (a >= n && n >= b) || (a <= n && n <= b);
}

int dir(point a, point b, point c) {
    ll r1 = (b.x - a.x) * (c.y - a.y);
    ll r2 = (b.y - a.y) * (c.x - a.x);
    return r1 == r2 ? 0 : r1 < r2 ? -1 : 1;
}

bool onseg(point a, point b, point c) {
    return dir(a, b, c) == 0 && betw(a.x, b.x, c.x) && betw(a.y, b.y, c.y);
}

bool intersect(point a, point b, point c, point d) {
    return ((dir(a, b, c) * dir(a, b, d) == -1) && (dir(c, d, a) * dir(c, d, b) == -1))
        || onseg(a, b, c)
        || onseg(a, b, d)
        || onseg(c, d, a)
        || onseg(c, d, b);
}

int main() {
    speed;
    int t;
    cin >> t;
    while (t--) {
        point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
        cout << (intersect(p1, p2, p3, p4) ? "YES" : "NO") << endl;
    }

}