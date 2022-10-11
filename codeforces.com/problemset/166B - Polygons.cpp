#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
struct point {
    ll x, y;
};

inline bool betw(ll a, ll b, ll n) {
    return max(a, b) >= n && n >= min(a, b);
}

inline int turn(point& a, point& b, point& c) { // -1 left; 0 on; 1 right
    ll res = (b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x);
    return (res > 0) - (res < 0);
}

inline bool on_seg(point& a, point& b, point& c) {
    return turn(a, b, c) == 0 && betw(a.x, b.x, c.x) && betw(a.y, b.y, c.y);
}

inline bool in_tri(point& a, point& b, point& c, point& p) {
    int r = turn(a, b, p);
    return r == turn(b, c, p) && r == turn(c, a, p);
}

int main() {
    speed;
    int n;
    cin >> n;
    vector<point> v(n);
    for (auto& p : v) cin >> p.x >> p.y;
    point p;
    cin >> p.x;
    while (cin >> p.x >> p.y) {
        // only check points inside main sector
        if (turn(v[0], v[n - 1], p) != -1 || turn(v[0], v[1], p) != 1) {
            cout << "NO";
            return 0;
        }
        // binary search for possible (0,l,l+1) triangle
        int l = 1, r = n - 1;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (turn(v[0], v[c], p) == -1) r = c;
            else l = c;
        }
        // check triangle and (0,l) side
        if (in_tri(v[0], v[l], v[l + 1], p) || on_seg(v[0], v[l], p)) continue;
        cout << "NO";
        return 0;
    }
    cout << "YES";
}