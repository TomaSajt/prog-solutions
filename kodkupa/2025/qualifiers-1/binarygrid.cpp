// 9/100
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - '0';
    }
  }

  auto check = [&](int nmask, int mmask) {
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m; j++) {
        int b1 = a[i][j];
        int b2 = a[i + 1][j];
        int b3 = a[i + 2][j];
        if (nmask >> i & 1) b1 = 1 - b1;
        if (nmask >> (i + 1) & 1) b2 = 1 - b2;
        if (nmask >> (i + 2) & 1) b3 = 1 - b3;
        int s1 = b1 + b2 + b3;
        if (s1 == 0 || s1 == 3) return false;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m - 2; j++) {
        int c1 = a[i][j];
        int c2 = a[i][j + 1];
        int c3 = a[i][j + 2];
        if (mmask >> j & 1) c1 = 1 - c1;
        if (mmask >> (j + 1) & 1) c2 = 1 - c2;
        if (mmask >> (j + 2) & 1) c3 = 1 - c3;
        int s2 = c1 + c2 + c3;
        if (s2 == 0 || s2 == 3) return false;
      }
    }
    return true;
  };

  int res = INT_MAX;
  for (int nmask = 0; nmask < (1 << n); nmask++) {
    for (int mmask = 0; mmask < (1 << m); mmask++) {
      if (check(nmask, mmask)) {
        int score = __builtin_popcount(nmask) + __builtin_popcount(mmask);
        if (res > score) {
          res = score;
        }
      }
    }
  }
  if (res == INT_MAX) cout << -1 << endl;
  else cout << res << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
