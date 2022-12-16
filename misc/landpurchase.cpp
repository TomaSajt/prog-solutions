#include <bits/stdc++.h>
#define pb push_back
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, k;
    cin >> n >> k;
    vector<ll> plots(n);
    for (auto& i : plots) cin >> i;
    vector<ll> pref(n + 1, 0);
    for (size_t i = 0; i < n; i++) pref[i + 1] = pref[i] + plots[i];
    ll min = LLONG_MAX;
    ll count = -1;
    for (size_t i = 0; i <= n - k; i++) {
        ll curr = pref[i + k] - pref[i];
        if (curr < min) {
            count = 0;
            min = curr;
        }
        if (curr == min) count++;

    }
    cout << min << "\n" << count;



}