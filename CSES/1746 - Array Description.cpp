#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    speed;
    int m, a;
    cin >> m >> m;
    cin >> a;
    vector<ll> curr(m + 1, 0), prev(m + 1, 0);
    if (a != 0) curr[a] = 1;
    else fill(curr.begin() + 1, curr.end(), 1);
    while (cin >> a) {
        swap(curr, prev);
        curr.assign(m + 1, 0);
        if (a != 0) {
            for (int k : {a - 1, a, a + 1}) {
                if (k >= 1 && k <= m) curr[a] += prev[k];
            }
            curr[a] %= mod;
            continue;
        }
        for (int j = 1; j <= m; j++) {
            for (int k : {j - 1, j, j + 1}) {
                if (k >= 1 && k <= m) curr[j] += prev[k];
            }
            curr[j] %= mod;
        }
    }
    ll res = 0;
    for (int j = 1; j <= m; j++) {
        res += curr[j];
        res %= mod;
    }
    cout << res;
}