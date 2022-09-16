#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll pow(int a, int b) {
    if (b == 0) return 1;
    ll r = pow(a, b / 2);
    r = (r * r) % mod;
    if (b % 2 == 1) r *= a;
    return r % mod;
}

int main() {
    speed;
    int a, b;
    for (cin >> a; cin >> a >> b;) cout << pow(a, b) << '\n';
}