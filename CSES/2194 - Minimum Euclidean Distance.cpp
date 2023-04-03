#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    ll x, y;
    bool operator<(const point& b) const {
        if (x != b.x) return x < b.x;
        return y < b.y;
    }
};

bool cmp(const point& a, const point& b) {
    if (a.y != b.y) return a.y < b.y;
    return a.x < b.x;
}

ll dist2(const point& a, const point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<point> v(n);
    for (auto& p : v) cin >> p.x >> p.y;
    sort(v.begin(), v.end(), cmp);
    set<point> s{ v[0] };
    ll d = LLONG_MAX;
    int j = 0;
    for (int i = 1; i < n; i++) {
        ll dd = ceil(sqrt(d));
        while (j < i && v[j].y < v[i].y - dd) s.erase(v[j++]);
        auto l = s.lower_bound({ v[i].x - dd, 0 });
        auto r = s.upper_bound({ v[i].x + dd, 0 });
        for (auto it = l; it != r; it++) d = min(d, dist2(*it, v[i]));
        s.insert(v[i]);
    }
    cout << d;
}