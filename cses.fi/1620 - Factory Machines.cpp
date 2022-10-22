#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto& a : v) cin >> a;
    ll curr = 0;
    for (int i = 62; i >= 0; i--) {
        ll next = curr + (1ll << i);
        ll cnt = 0;
        bool b = 1;
        for (int a : v) {
            cnt += next / a;
            if (cnt >= m) {
                b = 0;
                break;
            }
        }
        if (b) curr = next;
    }
    cout << curr + 1;
}