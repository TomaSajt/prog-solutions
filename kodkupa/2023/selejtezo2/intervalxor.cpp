// 100/100
#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

ll smallest_pow2_greater_than(ll n) {
    return 1ll << (64 - __builtin_clzll(n));
}

ll xor_range_to(ll n) {
    switch (n % 4) {
    case 0: return n;
    case 1: return 1;
    case 2: return n + 1;
    default: return 0;
    }
}

ll xor_range_to_drop_1(ll n) {
    if (n % 2 == 0) return smallest_pow2_greater_than(n) - 1;
    return n;
}

int main() {
    speed;
    ll a;
    for (cin >> a; cin >> a;) {
        cout << xor_range_to(a) << ' ' << xor_range_to_drop_1(a) << '\n';
    }
}