#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
#define int long long

struct p {
    int x, y;
};

inline int dist(p a, p b) {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}
#undef int
int main() {
#define int long long
    speed;
    int n;
    cin >> n;
    vector<p> points(n);
    for (auto& p : points) cin >> p.x >> p.y;
    vector<bool> used(n);
    int prev = 0;
    for (int i = 0;i < n;i++) {
        int res = -1;
        int maxd = -1;
        for (int curr = 0; curr < n; curr++) {
            int d = dist(points[prev], points[curr]);
            if (!used[curr] && d > maxd) {
                maxd = d;
                res = curr;
            }
        }
        cout << res + 1 << ' ';
        used[res] = true;
        prev = res;
    }
    cout << endl;
}