#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    vector<ll> limits{ 0 };
    ll m9 = 9;
    for (int i = 1; i < 17; i++, m9 *= 10) limits.push_back(limits.back() + i * m9);
    ll q; cin >> q;
    while (cin >> q) {
        auto it = lower_bound(limits.begin(), limits.end(), q);
        int digits = it - limits.begin();
        ll offset = *(it - 1) + 1;
        ll a = q - offset;
        int dig = digits - (a % digits) - 1;
        ll n = a / digits;
        ll shift = 1;
        for (int i = 0; i < dig; i++) shift *= 10;
        int res = (n / shift) % 10;
        if (dig == digits - 1) res++;
        cout << res << '\n';
    }
}