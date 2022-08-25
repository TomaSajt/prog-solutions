#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
typedef long long ll;

int main() {
    speed;
    int n, k;
    cin >> n;
    while (cin >> n >> k) {
        vector<ll> traps(n);
        vector<pair<ll, int>> trapsDiff(n);
        for (auto& i : traps) cin >> i;
        if (k == n) {
            cout << "0\n";
            continue;
        }
        for (int i = 0; i < n;i++) trapsDiff[i].second = i, trapsDiff[i].first = traps[i] - n + i + 1;
        sort(trapsDiff.rbegin(), trapsDiff.rend());
        vector<bool> jump(n);
        for (int i = 0; i < k; i++) {
            jump[trapsDiff[i].second] = true;
        }
        ll pen = 0;
        ll cost = 0;
        for (int i = 0; i < n; i++) {
            if (jump[i]) pen++;
            else cost += traps[i] + pen;
        }
        cout << cost << '\n';
    }
}