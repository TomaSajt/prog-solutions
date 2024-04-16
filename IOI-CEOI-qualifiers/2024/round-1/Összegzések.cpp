#include <bits/stdc++.h>
#define int long long
using namespace std;

void earlier(vector<int> x, int n) {
  int sum = 0;
  for (int i = n; i >= 1; i--) {
    if (x[i] == 1) sum++;
    else {
      for (int j = 1; j < i; j++) cout << x[j] << ' ';
      int h = x[i] - 1;
      cout << h << ' ';
      sum++;
      while (sum > h) {
        cout << h << ' ';
        sum -= h;
      }
      cout << sum << '\n';
      return;
    }
  }
  cout << "0\n";
}

void later(vector<int> x, int n) {
  int sum = 0;
  if (n == 1) {
    cout << "0\n";
    return;
  }
  for (int i = n; i >= 1; i--) {
    if (sum < 1 || x[i - 1] <= x[i]) sum += x[i];
    else {
      for (int j = 1; j < i; j++) cout << x[j] << ' ';
      cout << x[i] + 1 << ' ';
      sum--;
      while (sum--) cout << "1 ";
      cout << '\n';
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<int> x(n + 1);
  for (int i = 1; i <= n; i++) cin >> x[i];
  x[0] = INT_MAX;
  later(x, n);
  earlier(x, n);
}
