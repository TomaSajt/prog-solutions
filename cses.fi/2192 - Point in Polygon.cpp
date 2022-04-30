#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

const ll beeg = 1e9 + 1;

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
    //most nem kell onseg hívás itt
    return ((dir(a, b, c) * dir(a, b, d) == -1) && (dir(c, d, a) * dir(c, d, b) == -1));
}

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<point> poly(n);
    for (auto& p : poly) cin >> p.x >> p.y;
    while (m--) {
        point tp;
        cin >> tp.x >> tp.y;
        bool stop = false;
        for (int i = 0;i < n;i++) {
            int j = (i + 1) % n;
            if (onseg(poly[i], poly[j], tp)) {
                stop = true;
                cout << "BOUNDARY" << endl;
                break;
            }
        }
        if (stop) continue;
        int counter = 0;
        for (int i = 0;i < n;i++) {
            int j = (i + 1) % n;
            if (intersect(poly[i], poly[j], tp, { tp.x + 1,beeg })) {
                counter++;
            }
        }
        cout << (counter % 2 == 0 ? "OUTSIDE" : "INSIDE") << endl;

    }

}