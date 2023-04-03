#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll x, y;
    cin >> x;
    while (cin >> x >> y) {
        ll m = max(x, y), ox = m, oy = 1;
        if (m % 2 == 1) swap(ox, oy);
        ll dist = abs(ox - x) + abs(oy - y);
        cout << m * m - dist << '\n';
    }

}