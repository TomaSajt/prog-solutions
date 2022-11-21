#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        v[i] = tot;
        tot += a;
    }
    while (k--) {
        int q; cin >> q;
        cout << upper_bound(v.begin(), v.end(), (q - 1) % tot) - v.begin() << ' ';
    }
}