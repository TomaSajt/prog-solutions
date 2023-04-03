// 100/100

#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, d;
    cin >> n >> d;
    ll top = 1;
    for (int i = 0; i < n; i++) top *= 10;

    if (2 * d >= top) {
        cout << "0 0\n";
        return 0;
    }
    ll a = 2 * d, b = d;
    while (2 * a < top) a *= 2;
    while (3 * b < top) b *= 3;
    cout << a << ' ' << b << '\n';
}