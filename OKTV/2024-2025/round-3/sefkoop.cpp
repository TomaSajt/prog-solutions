// NOT CORRECT!!!

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = 1e9;

int n;
vector<array<int, 2>> X;

int32_t main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  X.resize(n + 1);
  for (int i = 1; i <= n; i++) cin >> X[i][0];
  for (int i = 1; i <= n; i++) cin >> X[i][1];

  // dp[i][s][c]
  vector<vector<array<int, 2>>> dp(n + 1, vector<array<int, 2>>(n + 1, {INF, INF}));
  // dp[i][c] = min(dp[i][...][c])
  vector<array<int, 2>> dp2(n + 1, {INF, INF});
  dp[1][1] = X[1];
  dp2[0] = {0, 0};
  dp2[1] = X[1];
  for (int i = 1; i < n; i++) {
    for (int s = 1; s <= i; s++) {
      for (int c = 0; c < 2; c++) {

        dp[i + 1][s][c] = min(dp[i + 1][s][c], dp[i][s][c] + X[i + 1][c]);
        dp[i + 1][i + 1][c] = min(dp[i + 1][i + 1][c], max(dp[i][s][1 - c], dp2[s - 1][c] + X[i + 1][c]));
        dp2[i + 1][c] = min(dp2[i + 1][c], dp[i + 1][s][c]);
        dp2[i + 1][c] = min(dp2[i + 1][c], dp[i + 1][i + 1][c]);
      }
      cout << "i = " << i << "; s = " << s << endl;
      cout << "calculating dp[i+1][s][c] and dp[i+1][i+1][c]" << endl;
      for (int ii = 1; ii <= n; ii++) {
        for (int ss = 1; ss <= n; ss++) {
          cout << dp[ii][ss][0] << ' ';
        }
        cout << endl;
      }
      cout << endl;
      for (int ii = 1; ii <= n; ii++) {
        for (int ss = 1; ss <= n; ss++) {
          cout << dp[ii][ss][1] << ' ';
        }
        cout << endl;
      }
      cout << endl;
      cout << "------" << endl;
      getchar();
    }
  }

  for (int ii = 1; ii <= n; ii++) {
    for (int ss = 1; ss <= ii; ss++) {
      cout << dp[ii][ss][0] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 1; i <= n; i++) {
    cout << dp2[i][0] << ' ';
  }
  cout << endl;

  for (int i = 1; i <= n; i++) {
    cout << dp2[i][1] << ' ';
  }
  cout << endl;
  cout << min(dp2[n][0], dp2[n][1]);
}
