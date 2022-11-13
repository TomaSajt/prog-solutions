#include <bits/stdc++.h>
#define speed ios::sync_with_stdio(0);cin.tie(0)
using namespace std;

int main() {
    speed;
    int n, m;
    cin >> n >> m;
    vector<pair<double, int>> v(n);
    for (auto& [d, a] : v) cin >> a >> d;
    sort(v.begin(), v.end());
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j].second > v[i].second) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << n - *max_element(dp.begin(), dp.end());
}