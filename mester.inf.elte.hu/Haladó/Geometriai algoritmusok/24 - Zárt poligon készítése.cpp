#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct pont {
    ll x, y, ind;
};
inline bool turnp(pont a, pont b, pont c) {
    return (b.y - a.y) * (c.x - a.x) > (c.y - a.y) * (b.x - a.x);
}
int main() {
    int n; cin >> n;
    vector<pont> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].ind = i + 1;
    }
    sort(p.begin(), p.end(), [](auto& a, auto& b) {return a.x < b.x || (a.x == b.x && a.y < b.y);});
    for (int i = 0; i < n; i++) {
        if (turnp(p[0], p.back(), p[i])) cout << p[i].ind << ' ';
    }
    for (int i = n - 1; i >= 0; i--) {
        if (!turnp(p[0], p.back(), p[i])) cout << p[i].ind << ' ';
    }
}