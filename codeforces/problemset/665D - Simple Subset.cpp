#include <bits/stdc++.h>
using namespace std;
const int MAX_SUM = 2000000;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);

  vector<bool> is_prime(MAX_SUM + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i * i <= MAX_SUM; i++) {
    if (!is_prime[i]) continue;
    for (int j = i * i; j <= MAX_SUM; j += i) is_prime[j] = 0;
  }

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& ai : a) cin >> ai;

  int one_cnt = count(a.begin(), a.end(), 1);
  if (one_cnt >= 2) {
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) continue;
      if (!is_prime[a[i] + 1]) continue;
      cout << one_cnt + 1 << '\n';
      while (one_cnt--) cout << 1 << ' ';
      cout << a[i];
      return 0;
    }
    cout << one_cnt << '\n';
    while (one_cnt--) cout << 1 << ' ';
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!is_prime[a[i] + a[j]]) continue;
      cout << 2 << '\n';
      cout << a[i] << ' ' << a[j];
      return 0;
    }
  }

  cout << 1 << '\n';
  cout << a[0];
}
