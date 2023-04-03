#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
#define int long long

struct point {
    int x, y, id, col;
    bool operator<(const point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

int turn(const point& a, const point& b, const point& c) {
    return (b.y - a.y) * (c.x - a.x) - (c.y - a.y) * (b.x - a.x);
}

signed main() {
    speed;
    int n; cin >> n;
    vector<point> pv(n);
    for (int i = 0; i < n; i++) {
        auto& p = pv[i];
        cin >> p.x >> p.y;
        p.id = i + 1;
        p.col = 0;
    }
    int m; cin >> m;
    pv.resize(n + m);
    for (int i = 0; i < m; i++) {
        auto& p = pv[n + i];
        cin >> p.x >> p.y;
        p.id = i + 1;
        p.col = 1;
    }
    iter_swap(min_element(pv.begin(), pv.end()), pv.begin());
    sort(pv.begin() + 1, pv.end(), [&](auto& a, auto& b) { return turn(pv[0], b, a) > 0 || (turn(pv[0], a, b) == 0 && a.x < b.x); });
    reverse(find_if(pv.begin() + 1, pv.end(), [&](auto& p) { return turn(pv[0], pv.back(), p) == 0; }), pv.end());
    vector<int> res;
    for (int i = 0; i < n + m; i++) {
        while (res.size() >= 2 && turn(pv[res[res.size() - 2]], pv[res[res.size() - 1]], pv[i]) > 0) {
            res.pop_back();
        }
        res.push_back(i);
    }
    for (int ri = 0; ri < res.size(); ri++) {
        int i = res[ri];
        int j = res[(ri + 1) % res.size()];
        if (pv[i].col != pv[j].col) {
            if (pv[i].col == 1) swap(i, j);
            cout << pv[i].id << ' ' << pv[j].id << endl;
            return 0;
        }
    }
    cout << "0 0" << endl;
}