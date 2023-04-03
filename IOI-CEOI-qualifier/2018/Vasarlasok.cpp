#include <bits/stdc++.h>

using namespace std;
#pragma GCC optimize ("O3")
#define int long long
#define INF (LLONG_MAX/2)

signed main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> data(k, vector<int>(n + 1, 0));
    for (auto& v : data) {
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
    }
    vector<vector<int>> dp(1 << k, vector<int>(n + 1, INF)); // dp[items bitmask][jelenlegi nap]
    vector<vector<int>> lastItem(1 << k, vector<int>(n + 1, 0)); // prevItem
    vector<vector<int>> dayBeforeLastItem(1 << k, vector<int>(n + 1, -1)); // prevDay
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int mask = 1; mask < (1 << k); mask++) {
            dp[mask][i] = dp[mask][i - 1];
            dayBeforeLastItem[mask][i] = dayBeforeLastItem[mask][i - 1];
            lastItem[mask][i] = lastItem[mask][i - 1];
            for (int j = 0; j < k + 1; j++) {
                if (!((mask >> j) & 1)) continue;
                int prevMask = mask - (1 << j);
                int uj = dp[prevMask][i - 1] + data[j][i];
                if (dp[mask][i] > uj) {
                    dp[mask][i] = uj;
                    dayBeforeLastItem[mask][i] = i - 1;
                    lastItem[mask][i] = j;
                }

            }
        }
    }
    int currmask = (1 << k) - 1;
    int currDay = n;
    int curritem = 0;

    vector<int> res(k, -1);
    while (currmask) {
        curritem = lastItem[currmask][currDay];
        res[curritem] = dayBeforeLastItem[currmask][currDay] + 1;

        currDay = dayBeforeLastItem[currmask][currDay];
        currmask = currmask - (1 << curritem);
    }
    cout << dp[(1 << k) - 1][n] << endl;
    for (int i = 0; i < k; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
}

