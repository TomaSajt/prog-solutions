#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    float f;
    cin >> n >> m;
    vector<int> v(n);
    for (int& a : v) cin >> a >> f;
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[i]) continue;
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << n - *max_element(dp.begin(), dp.end());
}