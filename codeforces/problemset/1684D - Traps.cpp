#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n;
    while (cin >> n >> k) {
        vector<ll> traps(n);
        vector<pair<ll, int>> save(n);
        for (auto& i : traps) cin >> i;
        for (int i = 0; i < n;i++) save[i] = { traps[i] - n + i + 1,i };
        sort(save.rbegin(), save.rend());
        vector<bool> jump(n);
        for (int i = 0; i < k; i++) {
            jump[save[i].second] = true;
        }
        ll pen = 0, cost = 0;
        for (int i = 0; i < n; i++) {
            if (jump[i]) pen++;
            else cost += traps[i] + pen;
        }
        cout << cost << '\n';
    }
}