#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n;
    cin >> n;
    ll t = n * (n + 1) / 2, s = 0;
    while (cin >> n) s += n;
    cout << t - s;
}