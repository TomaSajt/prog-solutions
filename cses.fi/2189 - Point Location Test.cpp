#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll res = (x3 - x1) * (y1 - y2) - (y3 - y1) * (x1 - x2);
        cout << (res > 0 ? "LEFT" : res == 0 ? "TOUCH" : "RIGHT") << endl;
    }

}