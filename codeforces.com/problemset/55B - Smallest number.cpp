#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;
inline ll f(char c, ll a, ll b) {
    return c == '+' ? a + b : a * b;
}
int main() {
    speed;
    vector<char> ops(3);
    vector<ll> o(4);
    for (ll& i : o) cin >> i;
    for (char& c : ops) cin >> c;
    ll best = LLONG_MAX;
    sort(o.begin(), o.end());
    do best = min({ best, f(ops[2],f(ops[0],o[0],o[1]),f(ops[1],o[2],o[3])), f(ops[2],f(ops[1],f(ops[0],o[0],o[1]),o[2]),o[3]) });
    while (next_permutation(o.begin(), o.end()));
    cout << best << endl;
}