#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    speed;
    ll x, k, A, B, c = 0;
    cin >> x >> k >> A >> B;
    while (x > 1) {
        ll r = x % k;
        x -= r;
        c += r * A;
        if (A * x * (k - 1) <= B * k)
            break;
        x /= k;
        c += B;
    }
    c += x * A;
    c -= A;
    cout << c;
}