#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, m, x;
    cin >> n >> m >> x;
    vector<ll> s1(n), s2(m);
    for (auto& i : s1) cin >> i;
    for (auto& i : s2) cin >> i;
    if (s1[0] + s2[0] > x) {
        cout << x << endl;
        return 0;
    }
    ll best = -1;
    ll l = 0, r = m - 1;
    while (l < n && r >= 0) {
        ll curr = s1[l] + s2[r];
        if (curr > best && curr <= x) {
            best = curr;
        }
        if (curr > x) r--;
        else l++;
    }
    cout << x - best << endl;





}