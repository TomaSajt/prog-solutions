#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    ll n, m;
    cin >> n;
    while (cin >> n >> m) {
        vector<ll> sizes(m);
        vector<ll> pos(m);
        for (auto& i : pos) (cin >> i), i--;
        sort(pos.begin(), pos.end());
        for (ll i = 0; i < m - 1;i++) {
            sizes[i] = pos[i + 1] - pos[i] - 1;
        }
        sizes[m - 1] = n + pos[0] - pos[m - 1] - 1;
        sort(sizes.rbegin(), sizes.rend());
        ll alive = 0;
        for (ll i = 0; i < m; i++) {
            ll death = 4 * i + 1;
            ll rem = sizes[i] - death;
            if (rem == 0)alive++;
            if (rem <= 0)break;
            alive += rem;
        }
        cout << n - alive << '\n';
    }

}