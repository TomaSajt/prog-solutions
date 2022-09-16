#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;


ll dig(ll n, int a) {
    ll hp = 1ll << a;
    ll c = n / (2 * hp);
    ll d = n % (2 * hp);
    ll r = hp * c;
    if (d >= hp) r += d - hp + 1;
    return r;
}

int main() {
    speed;
    ll n; cin >> n;
    ll r = 0;
    for (int i = 0; i <= 51; i++) r += dig(n, i);
    cout << r;
}