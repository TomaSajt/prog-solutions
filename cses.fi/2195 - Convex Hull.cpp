#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point {
    ll x, y;
};
inline ll turn(point& a, point& b, point& c) {
    return (b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x);
}
inline ll md(const point& a, const point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
    int n; cin >> n;
    vector<point> pv(n);
    for (int i = 0; i < n; i++) {
        cin >> pv[i].x >> pv[i].y;
    }
    iter_swap(pv.begin(), min_element(pv.begin(), pv.end(), [](auto& a, auto& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }));
    sort(pv.begin() + 1, pv.end(),
        [&](auto& a, auto& b) {
            ll t = turn(pv[0], a, b);
            return t < 0 || (t == 0 && md(pv[0], a) < md(pv[0], b));
        }
    );
    reverse(find_if(pv.begin() + 1, pv.end(), [&](auto& a) {return turn(pv[0], pv[n - 1], a) == 0;}), pv.end());
    vector<point> sol = { pv[0], pv[1] };
    auto ss = [&]() { return sol.size(); };
    for (int i = 2; i < n;i++) {
        while (ss() >= 2 && turn(sol[ss() - 2], sol[ss() - 1], pv[i]) > 0) {
            sol.pop_back();
        }
        sol.push_back(pv[i]);
    }
    cout << ss() << endl;
    for (auto& p : sol) cout << p.x << ' ' << p.y << endl;

}