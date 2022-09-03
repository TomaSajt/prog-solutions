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
    ll total2 = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        total2 += (v[i].x - v[j].x) * (v[i].y + v[j].y);
    }
    cout << abs(total2) << endl;
}