#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

ll f(char c, ll a, ll b) {
    return c == '+' ? a + b : a * b;
}

int main() {
    speed;
    vector<ll> v(4);
    vector<char> ops(3);
    for (ll& i : v)cin >> i;
    for (char& c : ops)cin >> c;
    ll best = LLONG_MAX;
    for (int i = 0;i < 4;i++) {
        for (int j = i + 1; j < 4;j++) {
            for (int k = 0;k < 3;k++) {
                for (int l = k + 1; l < 3;l++) {
                    auto vc = v;
                    vc[j] = f(ops[0], vc[i], vc[j]);
                    vc.erase(vc.begin() + i);
                    vc[l] = f(ops[1], vc[k], vc[l]);
                    vc.erase(vc.begin() + k);
                    ll res = f(ops[2], vc[0], vc[1]);
                    best = min(best, res);
                }
            }
        }
    }
    cout << best;
}