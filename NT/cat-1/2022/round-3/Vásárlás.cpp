#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n), b(n), d(n);
  for (int& ai : a) cin >> ai;
  for (int& bi : b) cin >> bi;
  for (int i = 0; i < n; i++) d[i] = b[i] - a[i];

  int best_d_sum = 0, best_l = 0, best_r = -1;
  int d_sum = 0, l = 0;
  for (int r = 0; r < n; r++) {
    if (d_sum + d[r] <= 0) {
      l = r + 1;
      d_sum = 0;
    }
    else {
      d_sum += d[r];
      if (best_d_sum < d_sum) {
        best_d_sum = d_sum;
        best_l = l;
        best_r = r;
      }
    }
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    if (best_l <= i && i <= best_r)
      res += a[i];
    else
      res += b[i];
  }

  cout << res;
}
