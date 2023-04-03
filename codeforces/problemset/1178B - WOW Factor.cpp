#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
typedef long long ll;
int main() {
    speed;
    string str;
    cin >> str;
    int n = str.size();
    vector<ll> vvl(n), vvr(n);
    for (int i = 2; i < n; i++) {
        vvl[i] = vvl[i - 1] + (str[i - 1] == 'v' && str[i - 2] == 'v');
    }
    for (int i = n - 3; i >= 0; i--) {
        vvr[i] = vvr[i + 1] + (str[i + 1] == 'v' && str[i + 2] == 'v');
    }
    ll ans = 0;
    for (int i = 2; i < n - 2; i++) {
        if (str[i] == 'o') ans += vvr[i] * vvl[i];
    }
    cout << ans;

}