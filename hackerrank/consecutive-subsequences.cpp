#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    speed;
    ll t, n, k, a;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<ll> v(k);
        ll s1 = 0;
        v[s1]++;
        while (n--) {
            cin >> a;
            s1 += a;
            s1 %= k;
            v[s1]++;
        }
        ll s2 = 0;
        for (auto& i : v) s2 += i * (i - 1) / 2;
        cout << s2 << endl;
    }
}