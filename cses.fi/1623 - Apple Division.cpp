#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n;
    cin >> n;
    vector<ll> v(n);
    ll total = 0;
    for (auto& p : v) {
        cin >> p;
        total += p;
    }
    ll best = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++) {
        ll s = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) s += v[j];
            best = min(best, abs(total - 2 * s));
        }
    }
    cout << best;

}