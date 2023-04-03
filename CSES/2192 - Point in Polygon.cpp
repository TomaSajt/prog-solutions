#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;


struct p {
    ll x, y;
};

bool betw(int a, int b, int n) {
    return max(a, b) >= n && n >= min(a, b);
}

int dir(p a, p b, p c) {
    ll x = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (x > 0) - (x < 0);
}

bool onseg(p a, p b, p c) {
    return dir(a, b, c) == 0 && betw(a.x, b.x, c.x) && betw(a.y, b.y, c.y);
}

bool intersect(p a, p b, p c, p d) {
    return (dir(a, b, c) * dir(a, b, d) == -1) && (dir(c, d, a) * dir(c, d, b) == -1);
}

const ll beeg = 1e9 + 1;
int n, m;

int main() {
    speed;
    cin >> n >> m;
    vector<p> poly(n);
    for (auto& p : poly) cin >> p.x >> p.y;
    while (m--) {
        p tp;
        cin >> tp.x >> tp.y;
        bool stop = false;
        for (int i = 0;i < n;i++) {
            if (onseg(poly[i], poly[(i + 1) % n], tp)) {
                stop = true;
                cout << "BOUNDARY" << endl;
                break;
            }
        }
        if (stop) continue;
        int counter = 0;
        for (int i = 0;i < n;i++) {
            counter += intersect(poly[i], poly[(i + 1) % n], tp, { tp.x + 1,beeg });
        }
        cout << (counter % 2 == 0 ? "OUTSIDE" : "INSIDE") << endl;

    }

}